#include "AST.h"
#include "SymTable.h"
ASTNode::ASTNode(string type, string value, string exprType){
    this->left=nullptr;
    this->right=nullptr;
    label=value;
    this->exprType=exprType;
    if(type=="bool"){
        this->type=astBOOL;
        this->value.bVal = value=="true" ? true : false;
    }
    else if(type=="int"){
        this->type=astINT;
        this->value.iVal=atoi(value.c_str());
    }
    else if(type=="float"){
        this->type=astFL;
        this->value.fVal=atof(value.c_str());
    }
    else if(type=="char"){
        this->type=astCH;
        this->value.cVal=value[0];
    }
    else if(type=="string"){
        this->type=astSTR;
        this->value.sVal=value;
        if (value.size() >= 2 && value.front() == '"' && value.back() == '"') {
            this->value.sVal = value.substr(1, value.size() - 2);
        } else {
            this->value.sVal = value;
        }
    }
    else if(type=="id"){
        this->type=astID;
        this->label=value;
        this->exprType=exprType;
        cout<<"AVEM ID-UL "<<value<<" CU TIPUL "<<exprType<<endl;

    }
    else if(type=="error"){
        this->type=astERROR;
        this->value.errorVal=value;
    }
    else{
        this->type=OP_BINAR;
        this->label=value;
    }
}

ASTNode::ASTNode(ASTNode* left,string op,ASTNode* right){
    this->left=left;
    this->right=right;
    this->label=op;
    this->exprType = (left != nullptr) ? left->exprType : ""; 
    this->type = OP_BINAR;
}

string ASTNode::get_type() {
    if(type==astINT){
        return "int";
    } else if(type==astFL){
        return "float";
    } else if(type==astCH){
        return "char";
    } else if(type==astSTR){
        return "string";
    } else if(type==astBOOL){
        return "bool";
    }
    return "error";
}
string ASTNode::getStringValue() {
    if (this->type == astINT) return to_string(this->value.iVal);
    if (this->type == astFL)  return to_string(this->value.fVal);
    if (this->type == astBOOL) return this->value.bVal ? "true" : "false";
    if (this->type == astSTR)  return this->value.sVal;
    if (this->type == astCH)  return string(1,this->value.cVal);
    return "";
}

void ASTNode::printAST(int level) {
    if (this == nullptr) return;

    for (int i = 0; i < level; i++) cout << "  |";

    cout << "-- [Label: " << (label.empty() ? "NONE" : label) 
         << " | Type: " << this->type 
         << " | ExprType: " << (exprType.empty() ? "NONE" : exprType) << "]" << endl;

    if (left) left->printAST(level + 1);
    if (right) right->printAST(level + 1);
}

ASTNode* ASTNode::evaluate(SymTable* currentScope){
    cout << "Evaluate nod: " << label << " | Type: " << this->type << endl;
    if(left==nullptr && right==nullptr){  //frunza, avem fie id, fie o valoarea
        
        if(this->type==astID){
            cout<<"INTRU VREODATA AICI??"<<endl;
            auto var=currentScope->searchVariable(label);
            if(var==nullopt){
                cout<<"Esti prost de puti tata"<<endl;
            }
            if(!var.has_value()){
                return new ASTNode("int","0","int");
            }
            auto [tip,valoare,clasa] = var.value();
            string valReal;
            if(tip=="int" || tip=="float"){
                valReal = valoare.value_or("0");
            } else if(tip=="bool"){
                valReal = valoare.value_or("true");
            } else if(tip=="char") {
                valReal = valoare.value_or(" ");
            } else if(tip=="string") {
                valReal = valoare.value_or("");
            }
            ASTNode* nod=new ASTNode(tip,valReal,tip);
            return nod;
        }
        else if (exprType == "int" || exprType == "float" || exprType == "bool" || exprType == "string" || exprType=="char") {
            if (this->exprType == "") this->exprType = label; 
            return this;
        }
    }

    //OPERATII UNARE
    else if(left!=nullptr && right==nullptr){
        if(label=="NOT"){
            ASTNode* res = left->evaluate(currentScope);
            
            if (res->type != astBOOL) {
                return new ASTNode("error", "Tried NOT operation on a non-boolean", "error");
            }

            bool valoareNegata = !(res->value.bVal);
            return new ASTNode("bool", valoareNegata ? "true" : "false","bool");
        }
        else if(label=="NEG"){
            ASTNode* res = left->evaluate(currentScope);

            if (res->type == astINT) {
                int valNegata = -(res->value.iVal);
                return new ASTNode("int", to_string(valNegata),"int");
            } 
            else if (res->type == astFL) {
                float valNegata = -(res->value.fVal);
                return new ASTNode("float", to_string(valNegata),"float");
            }
            else {
                return new ASTNode("error", "Tried NEG operation on a non-numeric", "error");
            }
        }
        //PRINT
        else if (label == "PRINT") {
            cout<<"intru aici??"<<endl;
            ASTNode* rezultat = left->evaluate(currentScope);
            if(rezultat==nullptr) return nullptr;
            if (rezultat->type == astERROR) {
                return rezultat;
            }

            cout << "[Output]: " << rezultat->getStringValue() << endl;
            return rezultat;
        }
        
    }

    // OPERATII BINARE
    else if(left!=nullptr && right!=nullptr){
    cout << "Evaluate nod BINAR: " << label << " | Type: " << this->type << endl;

        //IN STANGA CONDITIA, IN DREAPTA UN NOD BODY CARE IN STANGA ARE THEN, IAR IN DREAPTA RAMURILE ELSE
        if (label == "IF") {
            cout << "DEBUG: Conditie IF am INTRAT"<<endl;

            ASTNode* cond = left->evaluate(currentScope);
            cout << "DEBUG: Conditie IF evaluata ca: " << (cond->value.bVal ? "TRUE" : "FALSE") << endl;

            if (cond->value.bVal == true && cond->type == astBOOL) {
                cout << "DEBUG: Intru pe ramura TRUE" << endl;
                if (right->label == "IF_ELSE_LINK") {
                    if (right->left) return right->left->evaluate(currentScope);
                } else {
                    return right->evaluate(currentScope);
                }
            } else {
                cout << "DEBUG: Intru pe ramura FALSE (ELSE)" << endl;
                if (right && right->label == "IF_ELSE_LINK") {
                    if (right->right) return right->right->evaluate(currentScope);
                }
            }
            return nullptr;
        }

        //IN STANGA CONDITIA, IN DREAPTA CORPUL BUCLEI
        else if (label == "WHILE") {
            while (true) {
                ASTNode* cond = left->evaluate(currentScope); 

                if (cond->type == astBOOL && cond->value.bVal == true) {
                    right->evaluate(currentScope);
                } else {
                    break;
                }
            }
            return nullptr;
        }

        //IN STANGA CONDITIA DE INITIALIZARE, IN DREAPTA UN ALT NOD CARE IN STANGA ARE CONDITIA, IAR IN DREAPTA UN ALT NOD CARE IN STANGA ARE PASUL, IAR IN DREAPTA CORPUL LUI FOR
        else if (label == "FOR") {
            if (left) left->evaluate(currentScope);

            ASTNode* forRest = right;
            ASTNode* condNode = forRest->left;
            ASTNode* stepBody = forRest->right;
            ASTNode* stepNode = stepBody->left;
            ASTNode* bodyNode = stepBody->right;

            while (true) {
                ASTNode* condResult = condNode->evaluate(currentScope);
                
                if (condResult->type == astBOOL && condResult->value.bVal) {
                    if (bodyNode) bodyNode->evaluate(currentScope);

                    if (stepNode) stepNode->evaluate(currentScope);
                } else {
                    break;
                }
            }
            return nullptr;
        }


        ASTNode* L = left->evaluate(currentScope);
        ASTNode* R = right->evaluate(currentScope);

        if (L == nullptr) {
            return nullptr; 
        }
        if (R == nullptr) {
            return nullptr; 
        }
        if(L->type == astERROR) return L;
        if(R->type == astERROR) return R;

        // OPERATII NUMERICE
        if(label=="+"){
            if (L->type == astINT && R->type == astINT) return new ASTNode("int", to_string(L->value.iVal + R->value.iVal), "int");
            if (L->type == astFL && R->type == astFL) return new ASTNode("float", to_string(L->value.fVal + R->value.fVal), "float");
            if (L->type == astSTR && R->type == astSTR) return new ASTNode("string", L->value.sVal + R->value.sVal, "string");
            return new ASTNode("error", "Type mismatch", "error");
        }
        else if(label=="-"){
            if (L->type == astINT && R->type == astINT) return new ASTNode("int", to_string(L->value.iVal - R->value.iVal), "int");
            if (L->type == astFL && R->type == astFL) return new ASTNode("float", to_string(L->value.fVal - R->value.fVal), "float");
            return new ASTNode("error", "Type mismatch", "error");
        }
        else if(label=="*"){
            if (L->type == astINT && R->type == astINT) return new ASTNode("int", to_string(L->value.iVal * R->value.iVal), "int");
            if (L->type == astFL && R->type == astFL) return new ASTNode("float", to_string(L->value.fVal * R->value.fVal), "float");
            return new ASTNode("error", "Type mismatch", "error");
        }
        else if(label=="/"){
            if (R->value.fVal == 0 || R->value.iVal == 0) return new ASTNode("error", "Div by zero", "error");
            if (L->type == astINT && R->type == astINT) return new ASTNode("int", to_string(L->value.iVal / R->value.iVal), "int");
            if (L->type ==astFL && R->type==astFL) return new ASTNode("float", to_string(L->value.fVal / R->value.fVal), "float");
            return new ASTNode("error", "Type mismatch", "error");
        }
        else if(label=="%"){
            if (L->type == astINT && R->type == astINT) return new ASTNode("int",to_string(L->value.iVal%R->value.iVal),"int");
            return new ASTNode("error", "Type mismatch", "error");
        }

        // OPERATII BOOL

        else if(label=="&&"){
            if(L->type == astBOOL && R->type == astBOOL) return new ASTNode("bool", (L->value.bVal && R->value.bVal) ? "true" : "false", "bool");
            return new ASTNode("error", "Type mismatch", "error");
        }
        else if(label=="||"){
            if(L->type == astBOOL && R->type == astBOOL) return new ASTNode("bool", (L->value.bVal || R->value.bVal) ? "true" : "false", "bool");
            return new ASTNode("error", "Type mismatch", "error");

        }
        else if(label=="=="){
            if(L->type != R->type){
                return new ASTNode("error", "Type mismatch", "error");
            }
            return new ASTNode("bool", (L->getStringValue() == R->getStringValue()) ? "true" : "false", "bool");
        }
        else if(label=="!="){
            if(L->type != R->type){
                return new ASTNode("error", "Type mismatch", "error");
            }
            return new ASTNode("bool", (L->getStringValue() != R->getStringValue()) ? "true" : "false", "bool");
        }
        else if(label==">"){
            if(L->type != R->type){
                return new ASTNode("error", "Type mismatch", "error");
            }
            return new ASTNode("bool", (L->getStringValue() > R->getStringValue()) ? "true" : "false", "bool");
        }
        else if(label==">="){
             if(L->type != R->type){
                return new ASTNode("error", "Type mismatch", "error");
            }
            return new ASTNode("bool", (L->getStringValue() >= R->getStringValue()) ? "true" : "false", "bool");
        }
        else if(label=="<"){
            if(L->type != R->type){
                return new ASTNode("error", "Type mismatch", "error");
            }
            return new ASTNode("bool", (L->getStringValue() < R->getStringValue()) ? "true" : "false", "bool");
        }
        else if(label=="<="){
             if(L->type != R->type){
                return new ASTNode("error", "Type mismatch", "error");
            }
            return new ASTNode("bool", (L->getStringValue() <= R->getStringValue()) ? "true" : "false", "bool");
        }

        //acces VECTOR
        else if(label=="[]"){
            ASTNode* index = this->right->evaluate(currentScope);
            if(index->type!=astINT){
                return new ASTNode("error", "Type mismatch", "error");
            }
            int idx=index->value.iVal;
            
            string numeRealVector = this->left->label;

            cout<<"FULL VECTOR NAMGE IN ACCESS "<<numeRealVector<<endl;


            auto var=currentScope->searchVector(numeRealVector);
            
            if (!var.has_value()) {
                cerr << "Eroare la Runtime: Vectorul '" << numeRealVector << "' nu a fost gasit!" << endl;
                return new ASTNode("error", "Vector missing", "error");
            }

            auto [tip,marime,vector,clasa] = var.value();
            if(idx<0 || idx>=marime){
                return new ASTNode("error", "Tried accesing a wrong index on vector "+left->label, "error");
            }
            if(!var.has_value()){
                return new ASTNode("error", "Vector "+label+" doesn't exist", "error");
            }

            string valReal;
            if(vector.has_value()){
                valReal=vector.value()[idx];
            } else if(tip=="int" || tip=="float"){
                valReal ="0";
            } else if(tip=="bool"){
                valReal ="true";
            } else if(tip=="char" || tip=="string"){
                valReal =" ";
            }



            ASTNode* nod=new ASTNode(tip,valReal,tip);
            return nod;

        }
        
        //ASSIGN
        else if(label==":="){
            cout<<"am intrat in assign "<<endl;
            cout<<"TIPUL PULII "<<left->type<<endl;
            if(right==nullptr){
                cout<<"ESTI PROST DE PUTI "<<endl;
            }
            ASTNode* rezultat=right->evaluate(currentScope);
            if(rezultat==nullptr){
                cout<<"PROST MAI ESIT E NULL DREAPTA"<<endl;
            }
            //DACA E ID SIMPLU
            if(left->type==astID){
                cout<<"Am intart aici bre"<<endl;
                cout<<"VALOAREA MEA DE UPDATE E "<<rezultat->getStringValue()<<endl;
                if(currentScope->getType(left->label)!=rezultat->exprType){
                    return new ASTNode("error", "Tried assigining values of different types", "error");
                }
                currentScope->updateVarValue(left->label,rezultat->getStringValue());
                return rezultat;
            }

            //DACA E VECTOR
            else if (left->label == "[]") {
            ASTNode* indexNode = left->right->evaluate(currentScope);
            if (indexNode->type != astINT) {
                return new ASTNode("error", "Vector index must be an integer", "error");
            }
            int idx = indexNode->value.iVal;
            if (left->left == nullptr) return new ASTNode("error", "Invalid vector access", "error");
            string fullVecName = left->left->label;
            cout<<"FULL VECTOR NAMGE IN ASIGNARE MORTII MEI "<<fullVecName<<endl;

            auto var = currentScope->searchVector(fullVecName);
            if (!var.has_value()) {
                cout << "EROARE: Vectorul " << fullVecName << " nu a fost gasit in tabel!" << endl;
                return new ASTNode("error", "Vector not found", "error");
            }

            bool succes = currentScope->updateVectorElement(fullVecName, idx, rezultat->getStringValue());
        
                if (!succes) {
                    cerr << "Runtime Error: Could not update vector " << fullVecName << " at index " << idx << endl;
                }
            } 
                return rezultat;
            }

            return new ASTNode("error", "Tried assigining a value to a non lvalue", "error");
        }

        // STRUCTURI DE CONTROL

        
        //in stanga numele functiei, in dreapta ARG care in stanga are argument, dreapta alt ARG
        else if (label == "CALL") {
            string fName = left->label;
            vector<string> names = currentScope->getParamNames(fName);
            
            SymTable* funcScope = new SymTable(fName, currentScope);
            ASTNode* currentArg = right;

            for (int i = 0; i < names.size(); i++) {
                if (currentArg == nullptr) break;

                ASTNode* val = currentArg->left->evaluate(currentScope);

                funcScope->addVariable(names[i], val->exprType);
                funcScope->updateVarValue(names[i], val->getStringValue());

                currentArg = currentArg->right;
            }
            
            ASTNode* body = currentScope->getFunctionBody(fName);
            return body->evaluate(funcScope);
        }
        else if (label == "NEW_CLASS") {

            cout<<"AM INTRAT IN NODULNEW_C;LASS SKIBIDY"<<endl;
            string instanceName = left->label;
            string className = right->label;

            
            SymTable* classTemplate = currentScope->getChildScope(className);
    
            if (classTemplate != nullptr) {
               
                for (auto const& [varName, info] : classTemplate->variables) {
                    string memberName = instanceName + "." + varName;
                    string type = get<0>(info);
                    string defaultValue;
                    if (type == "int") defaultValue = "0";
                    else if (type == "float") defaultValue = "0.0";
                    else if (type == "bool") defaultValue = "false";
                    else if (type == "string") defaultValue = "";
                    else if (type == "char") defaultValue = " ";
                    else defaultValue = "0"; // fallback
                    if (get<1>(info).has_value()) {
                        defaultValue = get<1>(info).value();
                    }
                    
                    currentScope->addVariable(memberName, type);
                    currentScope->updateVarValue(memberName, defaultValue);
                    cout<<"ADDED VARIABLE "<<memberName<<" WITH VALUE "<<defaultValue<<endl;
                }
                for (auto const& [vecName, info] : classTemplate->vectors) {
                    string memberName = instanceName + "." + vecName;
                    string type = get<0>(info);
                    int size = get<1>(info);
                    auto const& initialValuesOpt = get<2>(info);
                    string defaultValue;
                    if (type == "int") defaultValue = "0";
                    else if (type == "float") defaultValue = "0.0";
                    else if (type == "bool") defaultValue = "false";
                    else if (type == "string") defaultValue = "";
                    else if (type == "char") defaultValue = " ";
                    else defaultValue = "0"; // fallback
            
                    
                    currentScope->addVector(memberName, type, size);
                    cout<<"ADDED VARIABLE "<<memberName<<" WITH VALUE "<< "0" <<endl;

                
                    for (int i = 0; i < size; i++) {
                        string valueToSet = defaultValue;

                        if (initialValuesOpt.has_value()) {
                            const vector<string>& vals = initialValuesOpt.value();
                            if (i < vals.size()) {
                                valueToSet = vals[i];
                            }
                        }
                        
                        currentScope->updateVectorElement(memberName, i, valueToSet);
                    }
                    
                }
                cout << "DEBUG: Instantiated object " << instanceName << " of class " << className << endl;
            }
            return nullptr;
        }
        else if (label == "METHOD_CALL") {
            string objName = left->left->label;
            string methodName = left->right->label;
            ASTNode* args = right;

            string classType = currentScope->getType(objName);
            SymTable* classScope = currentScope->getChildScope(classType);

            SymTable* execScope = new SymTable(methodName, classScope);
            
            
            ASTNode* body = classScope->getFunctionBody(methodName);
            return body->evaluate(execScope);
        }
        
        

    
    //IN STANGA BLOCK, IN DREAPTA ALTA INSTR
    else if (label == "BLOCK") {
        if (this->left != nullptr) {
            cout<<"EVALUAM STANGA "<<left->label<<endl;
            this->left->evaluate(currentScope);
        }
        
        if (this->right != nullptr) {
            cout<<"EVALUAM DREAPTA "<<right->label<<endl;

            this->right->evaluate(currentScope);
        }

        return nullptr;
    }
    return new ASTNode("error", "Invalid AST","error");
    

    //CLASELE SI VECTORII VOR FI BINARI (LA VECTORI, STANGA ID, DREAPTA INDEX, IAR LA CLASE STANGA ID CLASA, DREAPTA ID)
}