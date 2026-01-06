#include "AST.h"
ASTNode::ASTNode(string type, string value, string exprType){
    left=nullptr;
    right=nullptr;
    exprType=type;
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
    }
    else if(type=="id"){
        this->type=astID;
        this->label=value;
    }
    else if(type=="id_vector"){
        this->type=astVECTOR;
        this->label=value;
    }
    else if(type=="id_varclass"){
        this->type=astVARCLASS;
        this->label=value;
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
}

string ASTNode::getStringValue() {
    if (this->type == astINT) return to_string(this->value.iVal);
    if (this->type == astFL)  return to_string(this->value.fVal);
    if (this->type == astBOOL) return this->value.bVal ? "true" : "false";
    if (this->type == astSTR)  return this->value.sVal;
    if (this->type == astCH)  return string(1,this->value.cVal);
    return "";
}

ASTNode* ASTNode::evaluate(SymTable* currentScope){
    if(left==nullptr && right==nullptr){  //frunza, avem fie id, fie o valoarea
        if(this->type==astINT || this->type==astFL || this->type == astBOOL || this->type == astCH || this->type== astSTR){
            return this;
        }
        else if(this->type==astID){
            auto var=currentScope->searchVariable(label);
            auto [tip,valoare,clasa] = var.value();
            if(!var.has_value()){
                return new ASTNode("int","0","int");
            }
            string valReal;
            if(tip=="int" || tip=="float"){
                valReal = valoare.value_or("0");
            } else if(tip=="bool"){
                valReal = valoare.value_or("true");
            } else if(tip=="char" || tip=="string"){
                valReal = valoare.value_or("");
            }
            ASTNode* nod=new ASTNode(tip,valReal,tip);
            return nod;
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
        else if (label == "Print") {
            ASTNode* rezultat = left->evaluate(currentScope);

            if (rezultat->type == astERROR) {
                return rezultat;
            }

            cout << "[Output]: " << rezultat->getStringValue() << endl;
            return rezultat;
        }
        
    }

    // OPERATII BINARE
    else if(left!=nullptr && right!=nullptr){

        ASTNode* L = left->evaluate(currentScope);
        ASTNode* R = right->evaluate(currentScope);

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
            std::optional<std::tuple<std::string, int, std::optional<std::vector<std::string>>, std::optional<std::string>>> var;
            if(left->label=="."){
                string numeObiect = this->left->left->label; 
                string numeVector = this->left->right->label; 
                string tipClasa = currentScope->getType(numeObiect);
                var=currentScope->searchVectorInClass(numeObiect,numeVector,currentScope);
            } else{
                var=currentScope->searchVector(left->label);
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
                valReal ="";
            }
            ASTNode* nod=new ASTNode(tip,valReal,tip);
            return nod;

        }

        //acces CLASA
        else if(label=="."){
        if (right->type == astVARCLASS) {
            auto objectVar = currentScope->searchVariable(left->label);
            if (!objectVar.has_value()) {
                return new ASTNode("error", "Object " + left->label + " not declared", "error");
            }

            auto [objType, objVal, objClass] = objectVar.value();
            string memberName = right->label;

            auto member = currentScope->searchVariableInClass(objType, memberName, currentScope);

            if (!member.has_value()) {
                return new ASTNode("error", "Member " + memberName + " not found in class " + objType, "error");
            }

            auto [mTip, mValoare, mClasa] = member.value();
            
            string valReal;
            if (mValoare.has_value()) {
                valReal = mValoare.value();
            } else {
                if (mTip == "int" || mTip == "float") valReal = "0";
                else if (mTip == "bool") valReal = "true";
                else valReal = "";
            }

            return new ASTNode(mTip, valReal, mTip);
            }
        }
        
        //ASSIGN
        else if(label==":="){
            ASTNode* rezultat=right->evaluate(currentScope);
            //DACA E ID SIMPLU
            if(left->type==astID){
                if(currentScope->getType(left->label)!=rezultat->exprType){
                    return new ASTNode("error", "Tried assigining values of different types", "error");
                }
                currentScope->updateVarValue(left->label,rezultat->getStringValue());
                return rezultat;
            }

            //DACA E CLASA
            else if(left->label=="."){
                string objName = left->left->label;  // "idk"
                string varName = left->right->label; // "a"
                    
                string className = currentScope->getType(objName);
                ASTNode* valNode = right->evaluate(currentScope); // Calculăm noua valoare
                
                bool succes = currentScope->updateVarValueInClass(className, varName, valNode->exprType, valNode->getStringValue(), currentScope);
                
                if (!succes) {
                    return new ASTNode("error", "Failed to update class member", "error");
                }
                return valNode;
            }

            //DACA E VECTOR
            else if (left->label == "[]") {
            ASTNode* indexNode = left->right->evaluate(currentScope);
            if (indexNode->type != astINT) {
                return new ASTNode("error", "Vector index must be an integer", "error");
            }
            int idx = indexNode->value.iVal;

            //DACA E VECTOR IN CLASA
            if (left->left->label == ".") {
                string objName = left->left->left->label;
                string vecName = left->left->right->label;
                string className = currentScope->getType(objName);

                bool succes = currentScope->updateVectorElementInClass(className, vecName, idx, rezultat->getStringValue(), currentScope);
                if (!succes) {
                    return new ASTNode("error", "Failed to update vector element in class", "error");
                }
            } 
            else {
                string vecName = left->left->label;
                bool succes = currentScope->updateVectorElement(vecName, idx, rezultat->getStringValue());
                if (!succes) {
                    return new ASTNode("error", "Vector index out of bounds or vector not found", "error");
                }
            }
            return rezultat;
            }

            return new ASTNode("error", "Tried assigining a value to a non lvalue", "error");
        }

        // STRUCTURI DE CONTROL

        //IN STANGA CONDITIA, IN DREAPTA UN NOD BODY CARE IN STANGA ARE THEN, IAR IN DREAPTA RAMURILE ELSE
        else if (label == "IF") {
            ASTNode* cond = left->evaluate(currentScope);
            if (cond->type == astBOOL && cond->value.bVal == true) {
                if (right->left) right->left->evaluate(currentScope);
            } else {
                if (right->right) right->right->evaluate(currentScope);
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
        
        return new ASTNode("error", "Invalid AST","error");

    }


    //CLASELE SI VECTORII VOR FI BINARI (LA VECTORI, STANGA ID, DREAPTA INDEX, IAR LA CLASE STANGA ID CLASA, DREAPTA ID)
}