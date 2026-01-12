%code requires {
  #include <string>
  #include <cstring>
#include <vector>

  using namespace std;
}

%{
#include "SymTable.h"
#include "AST.h"
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stack>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yyparse();
extern int yylex();
void yyerror(const char * s);
int errorCount=0;

SymTable* globalScope=nullptr;
SymTable* currentScope=nullptr;
SymTable* parentScope=nullptr;
SymTable* aux=nullptr; //used for method calls

stack<int> param_counts;
stack<string> calling_functions;

char* funName;
char* funType;

char* currentVarName;
char* currentVarType;

int nr_param=0;
int vector_size=0;
int numberOfElementsToAdd=0;
int current_init_index=0;
string current_init_vec_name;


%}

%union{
        char* stringVal;
        bool boolVal;
        char charVal;
        int intVal;
        float floatVal;
        class ASTNode* node;
        vector<string>* idList;
}
%token <stringVal>TYPE CLASS_SECTION CLASS_VAR_SECTION CLASS_METHODS_SECTION CLASS GVAR_SECTION GFUN_SECTION NEW ASSIGN IF ELSE WHILE COMPARE <stringVal>ID <intVal>INT <boolVal>BOOL <floatVal>FLOAT <stringVal>STRING <charVal>CHAR PRINT MAIN_BEGIN MAIN_END <stringVal>OPERATOR INC DEC NOT RETURN


%type <node> expression expression_elem statement if_statement while_statement factor term exp
%type <node> fun_call class_method_call class_access print_statement fun_call_params fun_decl method_call_params class_var_call print_expr class_create_instance
%type <node> main_fun_block main_block_element fun_block block_element main var_decl vector_element vector_elements return_statement
%type <idList> var_list

%start program

%left '+' '-' 
%left '*' '/' '%'
%right NOT
%right UMINUS
%left INC DEC

%%

program : class_section global_var_section global_fun_section main 
{
if(errorCount == 0 && $4 != nullptr) {
        cout<<endl;
        $4->printAST(0);
        cout << "--- Start Execution ---" << endl;
        $4->evaluate(globalScope);
        cout << "--- Execution Finished Successfully ---" << endl;

    }

};

//    ################# CLASE ###########################
class_section : {std::cout<<endl<<"No classes"<<endl;}
            | CLASS_SECTION class_declarations;

class_declarations : class_declaration
            | class_declarations class_declaration

class_declaration : CLASS ID '{'
                {
                        if(currentScope->addClass($2)==true){
                                currentScope = currentScope->enterScope($2);  //intram in scope ul clasei
                        } else {
                                string msg="The class "+string($2)+" already exists";
                                yyerror(msg.c_str());
                        }
                        globalScope->childScopes.push_back(currentScope);
                }


                class_block '}'
                {
                        currentScope = currentScope->exitScope(); //iesin din scope ul clasei
                        parentScope = currentScope;
                }
                ;

class_block : class_var_section class_methods_section;

class_var_section : {std::cout<<endl<<"No variables"<<endl;}
            | CLASS_VAR_SECTION variable_declarations
            ;

class_methods_section : {std::cout<<endl<<"No methods"<<endl;}
            | CLASS_METHODS_SECTION function_declarations
            ;

class_create_instance : ID ID ASSIGN NEW ID '('')'
                        {
                        if(find(globalScope->classes.begin(),globalScope->classes.end(),$1)==globalScope->classes.end()){
                                string msg="The class "+string($1)+" doesn't exists";
                                yyerror(msg.c_str());
                        }
                                if(currentScope->addVariable($2,$1)==false){
                                string msg="The class name"+string($2)+" doesn't exists";
                                        yyerror(msg.c_str());
                                }

                                if(string($1)!=string($5)){
                                        yyerror("Type mismatch: cannot instantiate class with a different constructor type");
                                }
                                
                                SymTable* classTemplate = globalScope->getChildScope(string($1));
                                
                                if (classTemplate != nullptr) {
                
                                        for (auto const& [varName, info] : classTemplate->variables) {
                                        string memberName = string($2) + "." + varName;
                                        string type = get<0>(info);
                                        string defaultValue = get<1>(info).value_or("0");
                                        
                                        currentScope->addVariable(memberName, type);
                                        currentScope->updateVarValue(memberName, defaultValue);
                                        }

                                        for (auto const& [vecName, info] : classTemplate->vectors) {
                                                string memberName = string($2) + "." + vecName;
                                                string type = get<0>(info);
                                                int size = get<1>(info);
                                                
                                                currentScope->addVector(memberName, type, size);
                                                cout<<"ADDED VARIABLE "<<memberName<<" WITH VALUE "<< "0" <<endl;

                                                
                                                for (int i = 0; i < size; i++) {
                                                        currentScope->updateVectorElement(memberName, i, "0");
                                                }
                                                
                                        }
                                        for (auto const& [funName, info] : classTemplate->functions) {
                                                string memberFunName = string($2) + "." + funName;
                                                string returnType = get<0>(info);
                                                optional<vector<string>> params = get<1>(info);
                                                optional<string> className = get<2>(info);
                                                
                                                currentScope->addFunction(memberFunName, returnType, params, className);
                                                
                                                ASTNode* body = classTemplate->getFunctionBody(funName);
                                                currentScope->setFunctionBody(memberFunName, body);
                                                
                                                cout << "DEBUG: Linked method " << memberFunName << " to object " << string($2) << endl;
                                        }
                                        cout << "DEBUG: Instantiated object " << string($2) << " of class " << string($1) << endl;

                                }
                                
                                ASTNode* objNode = new ASTNode("id", $2, $1);
                                ASTNode* classTypeNode = new ASTNode("id", $1, "CLASS_TYPE");
                                
                                $$ = new ASTNode(objNode, "NEW_CLASS", classTypeNode);

                          
                        }  //trebuie verificat primul ID=clasa_existenta, al doilea ID=sa nu fei folosit, al treilea ID=aceeasi_clasa_existenta, si apoi parametrii daca e construcotr
                        ;

class_access : class_method_call
            | ID '.' ID
            {
                if(currentScope->searchVariable($1)==nullopt){
                                string msg="the class instance "+string($1)+" doesn't exist";
                                yyerror(msg.c_str());
                        }
                        if(currentScope->classExists(currentScope->getType($1))==false){ //daca tipul este o clasa existenta, ca sa nu pot face int.ceva
                                string msg="the variable "+string($1)+"isn't a class instance";
                                yyerror(msg.c_str());
                        }

                string classType = currentScope->getType($1);
                auto var=currentScope->searchVariableInClass(classType,$3,globalScope);
                string typeMember;
                if(var.has_value()){
                        auto [tip,valoarea,clasa] = var.value();
                        typeMember=tip;
                        if(clasa.has_value()){  //daca este o variabila de clasa
                                string cls = clasa.value();
                                if(cls!=classType){
                                        string msg="the variable"+string($3)+"is in a different class";
                                        yyerror(msg.c_str());
                                } else {
                                }
                        }
                } else {
                        string msg="The class variable "+string($3)+" doesn't exist";
                    yyerror(msg.c_str());
                }

                string fullName = string($1) + "." + string($3);

                $$ = new ASTNode("id", fullName, typeMember);           
                
            }
            | ID '.' ID '[' INT ']'
            {
                if(currentScope->searchVariable($1)==nullopt){
                                string msg="the class instance "+string($1)+" doesn't exist";
                                yyerror(msg.c_str());
                        }
                        if(currentScope->classExists(currentScope->getType($1))==false){ //daca tipul este o clasa existenta, ca sa nu pot face int.ceva
                                string msg="the variable "+string($1)+"isn't a class instance";
                                yyerror(msg.c_str());
                        }

                string classType = currentScope->getType($1);
                auto var=currentScope->searchVectorInClass(classType,$3,globalScope);
                string typevec;
                if(var.has_value()){
                        auto [tip,numberElements,valori,clasa] = var.value();
                        typevec=tip;

                        if($5 >= numberElements || $5 < 0){
                        yyerror("Vector index out of bounds!");
                        }

                        string fullVecName = string($1) + "." + string($3);
                        
                        if(!currentScope->searchVector(fullVecName)) {
                                currentScope->addVector(fullVecName, typevec, numberElements);
                        }

                       
                        if(clasa.has_value()){  //daca este o variabila de clasa
                                string cls = clasa.value();
                                 if($5>=numberElements){
                                        string msg = "Tried accesing vector index "+ to_string($5) +" that doens't exist (the maximum elements for the vector is "+to_string(numberElements-1)+")";
                                        yyerror(msg.c_str());
                                }
                                if($5<0){
                                        string msg = "Tried accesing vector index "+ to_string($5) +" that doens't exist (the index can't be negative!)";
                                        yyerror(msg.c_str());
                                }
                                if(cls!=classType){
                                        string msg="the vector"+string($3)+"is in a different class";
                                        yyerror(msg.c_str());
                                } else {
                                }
                        }
                } else {
                        string msg="The class vector "+string($3)+" doesn't exist";
                    yyerror(msg.c_str());
                }

                string fullVecName = string($1) + "." + string($3);

                ASTNode* vecNode = new ASTNode("id", fullVecName, typevec);
                ASTNode* indexNode = new ASTNode("int", to_string($5), "int");
                $$ = new ASTNode(vecNode, "[]", indexNode);

        
                
            }
        //primul id e o varaibla clasa existenta, al doilea e o varaibila din acea clasa existenta
            ;

class_method_call : ID '.' ID  //vezi sa pui ID.fun_call si intri intr-un scope aux=currentScope si schimbi la funCall
                  {
                        if(currentScope->searchVariable($1)==nullopt){
                                string msg="The class variable "+string($1)+" doesn't exist!";
                                yyerror(msg.c_str());
                        }
                        if(currentScope->classExists(currentScope->getType($1))==false){ //daca tipul este o clasa existenta, ca sa nu pot face int.ceva
                                yyerror("Tried calling a method on a non-class variable");
                        }

                        cout<<"Searching for method "<<$3<<endl;
                        
                        string classType = currentScope->getType($1);
                        auto fun=currentScope->searchMethodInClass(classType,$3,globalScope);
                        if(fun.has_value()){
                                auto [tip,params,clasa] = fun.value();
                                if(clasa.has_value()){  //daca este o metoda
                                        string cls = clasa.value();
                                        if(cls!=classType){
                                                string msg="The method "+string($3)+" is in a different class!";
                                                yyerror(msg.c_str());
                                        }
                                } else {
                                        string msg="Tried calling method "+string($3)+" , but it's a function!";
                                        yyerror(msg.c_str());
                                }
                        } else {
                                string msg="The method "+string($3)+" doesn't exist!";
                                yyerror(msg.c_str());
                        }
                        aux=globalScope->getChildScope(classType);
                        if(aux==nullptr){
                                yyerror("didn't find child scope succesfuly");
                        }

                        //string fun_name=string($1)+"."+string($3);
                        //calling_functions.push(fun_name.c_str());
                        calling_functions.push($3);
                        param_counts.push(0);
                  }
                  '(' method_call_params ')'
                  {
                        string current_fun = calling_functions.top();
                        string fullName = string($1) + "." + string($3);
                        int total_params = param_counts.top();
                        cout<<"NR PARAMETRII CURENTI "<<total_params<<endl;
                        if(aux->verifParamNumber(current_fun, total_params) == false){
                                string msg="The method "+current_fun+" doesn't have the correct number of parameters";
                                yyerror(msg.c_str());
                        }

                       auto fun = aux->searchFunction(current_fun);
                        if(fun==nullopt){
                                yyerror("error at finding method");
                        }
                        auto [tip,parametrii,clasa] = fun.value();
        
                        ASTNode* nameNode = new ASTNode("id", (char*)fullName.c_str(), tip);
                        $$ = new ASTNode(nameNode, "CALL", $6);

                        calling_functions.pop();
                        param_counts.pop();

                        
                  }
            ;

method_call_params : {$$=nullptr;}
            | expression
            {
                string c_fun = calling_functions.top();
                int c_idx = param_counts.top();
                
                if(aux->verifParamType(c_fun, c_idx, $1->exprType) == false){
                    string msg = "Parameter " + to_string(c_idx) + " in " + c_fun + " is of type " + $1->exprType + " but should be different.";
                    yyerror(msg.c_str());
                }
                param_counts.top()++;
                $$ = new ASTNode($1, "ARG", nullptr);
            }
            | expression ',' 
            {
                string c_fun = calling_functions.top();
                int c_idx = param_counts.top();
                
                
                if(aux->verifParamType(c_fun, c_idx, $1->exprType) == false){
                yyerror("Type mismatch in method call parameters");
                }
                
                param_counts.top()++;
                $<node>$ = $1; 
             }
             method_call_params
             {
                $$ = new ASTNode($<node>3, "ARG", $4);
             }
            ;

//ORICE SCHIMBARE AICI LA METHOD CALL PARAM AR TREBUI SA SE REFLECTE SI IN FUN CALL PARAM, DOAR CA ACOLO SCOPE UL E CURRENTSCOPE


//primul ID trebuie sa fie o varaibila de clasa existenta deja, al doilea id trebuie sa fie o metoda in acea clasa
class_var_call : ID '.' ID ASSIGN expression
                {
                auto varObj = currentScope->searchVariable($1);
                if (!varObj.has_value()) {
                        string msg = "Object '" + string($1) + "' is not declared.";
                        yyerror(msg.c_str());
                }
                string className = currentScope->getType($1);
                auto var = currentScope->searchVariableInClass(className, $3, globalScope);
                if(var.has_value()) {
                string memberType = get<0>(var.value());
                string exprType = $5->exprType;
                        if(memberType != exprType) {
                                string msg = "Cannot assign [" + exprType + "] to member '" + string($1) + "." + string($3) + "' of type [" + memberType + "]";
                                yyerror(msg.c_str());
                        }

                        currentScope->updateVarValue(string($1)+'.'+string($3), $5->getStringValue());

                        string fullName = string($1) + "." + string($3);

                        ASTNode* nod = new ASTNode("id", fullName, memberType);   

                        $$ = new ASTNode(nod,":=",$5);
                }
                
                }
            | ID '.' ID INC
            {
                auto varObj = currentScope->searchVariable($1);
                if (!varObj.has_value()) {
                        string msg = "Object '" + string($1) + "' is not declared.";
                        yyerror(msg.c_str());
                }
                string className = currentScope->getType($1);
                auto var = currentScope->searchVariableInClass(className, $3, globalScope);
                
                if(var.has_value()) {
                string memberType = std::get<0>(var.value());
                if(memberType != "int" && memberType != "float") {
                        string msg = "Cannot increment member '" + string($1) + "." + string($3) + 
                                "' because it is of type [" + memberType + "] (not numeric)";
                        yyerror(msg.c_str());
                }
                } else {
                string msg = "Class member '" + string($3) + "' not found in class '" + className + "'";
                yyerror(msg.c_str());
                }

                auto [tip,val,clasa] = var.value(); 
                string memberType = std::get<0>(var.value());
                // currentScope->updateVarValueInClass($1,$3, memberType, val+1,globalScope);

               
                string fullName = string($1) + "." + string($3);

                ASTNode* nod = new ASTNode("id", fullName, memberType);   
                ASTNode* nod_c = new ASTNode("id", fullName, memberType);   
                ASTNode* unu = new ASTNode("int","1","int");
                ASTNode* plus=new ASTNode(nod_c,"+",unu);

                $$ = new ASTNode(nod,":=",plus);
            }
            | ID '.' ID DEC
            {
                auto varObj = currentScope->searchVariable($1);
                if (!varObj.has_value()) {
                        string msg = "Object '" + string($1) + "' is not declared.";
                        yyerror(msg.c_str());
                }
                string className = currentScope->getType($1);
                auto var = currentScope->searchVariableInClass(className, $3, globalScope);
                
                if(var.has_value()) {
                string memberType = std::get<0>(var.value());
                if(memberType != "int" && memberType != "float") {
                        string msg = "Cannot decrement member '" + string($1) + "." + string($3) + 
                                "' because it is of type [" + memberType + "] (not numeric)";
                        yyerror(msg.c_str());
                }
                } else {
                string msg = "Class member '" + string($3) + "' not found in class '" + className + "'";
                yyerror(msg.c_str());
                }
                string memberType = std::get<0>(var.value());

               
                string fullName = string($1) + "." + string($3);

                ASTNode* nod = new ASTNode("id", fullName, memberType);   
                ASTNode* nod_c = new ASTNode("id", fullName, memberType);   
                ASTNode* unu = new ASTNode("int","1","int");
                ASTNode* minus=new ASTNode(nod_c,"-",unu);

                $$ = new ASTNode(nod,":=",minus);
            }
            | ID '.' ID '[' INT ']' ASSIGN expression
                {
                auto varObj = currentScope->searchVariable($1);
                if (!varObj.has_value()) {
                        string msg = "Object '" + string($1) + "' is not declared.";
                        yyerror(msg.c_str());
                }
                string className = currentScope->getType($1);
                auto var = currentScope->searchVectorInClass(className, $3, globalScope);
                if(var.has_value()) {
                int numberElements = get<1>(var.value());
                if($5>=numberElements){
                        string msg = "Tried accesing vector index "+ to_string($5) +" that doens't exist (the maximum elements for the vector is "+to_string(numberElements-1)+")";
                        yyerror(msg.c_str());
                }
                if($5<0){
                        string msg = "Tried accesing vector index "+ to_string($5) +" that doens't exist (the index can't be negative!)";
                        yyerror(msg.c_str());
                }

               
                string memberType = get<0>(var.value());
                string exprType = $8->exprType;
                if(memberType != exprType) {
                        string msg = "Cannot assign [" + exprType + "] to member '" + string($1) + "." + string($3) + "' of type [" + memberType + "]";
                        yyerror(msg.c_str());
                        }
                        currentScope->updateVectorElement(string($1)+'.'+string($3), $5 , $8->getStringValue());

                        string fullVecName = string($1) + "." + string($3);
        
                        ASTNode* vectorNode = new ASTNode("id_vector", fullVecName, memberType);
                        
                        ASTNode* indexNode = new ASTNode("int", to_string($5), "int");

                        ASTNode* vectorAccess = new ASTNode(vectorNode, "[]", indexNode);
                        vectorAccess->exprType = memberType;

                        $$ = new ASTNode(vectorAccess, ":=", $8);
                }
                
                }
            | ID '.' ID '[' INT ']' INC
            {
                auto varObj = currentScope->searchVariable($1);
                if (!varObj.has_value()) {
                        string msg = "Object '" + string($1) + "' is not declared.";
                        yyerror(msg.c_str());
                }
                string className = currentScope->getType($1);
                auto var = currentScope->searchVectorInClass(className, $3, globalScope);
                
                if(var.has_value()) {
                 int numberElements = get<1>(var.value());
                if($5>=numberElements){
                        string msg = "Tried accesing vector index "+ to_string($5) +" that doens't exist (the maximum elements for the vector is "+to_string(numberElements-1)+")";
                        yyerror(msg.c_str());
                }
                if($5<0){
                        string msg = "Tried accesing vector index "+ to_string($5) +" that doens't exist (the index can't be negative!)";
                        yyerror(msg.c_str());
                }
                string memberType = std::get<0>(var.value());
                if(memberType != "int" && memberType != "float") {
                        string msg = "Cannot increment member '" + string($1) + "." + string($3) + 
                                "' because it is of type [" + memberType + "] (not numeric)";
                        yyerror(msg.c_str());
                }

                string fullName = string($1) + "." + string($3);

                ASTNode* destVecName = new ASTNode("id", fullName, memberType);
                ASTNode* destIndex = new ASTNode("int", to_string($5), "int");
                ASTNode* vectorDest = new ASTNode(destVecName, "[]", destIndex);

                
                ASTNode* readVecName = new ASTNode("id", fullName, memberType);
                ASTNode* readIndex = new ASTNode("int", to_string($5), "int");
                ASTNode* vectorRead = new ASTNode(readVecName, "[]", readIndex);

               
                ASTNode* unu = new ASTNode("int", "1", "int");
                ASTNode* plus = new ASTNode(vectorRead, "+", unu);

                
                $$ = new ASTNode(vectorDest, ":=", plus);

                } else {
                string msg = "Class member '" + string($3) + "' not found in class '" + className + "'";
                yyerror(msg.c_str());
                }

                
            }
            | ID '.' ID '[' INT ']' DEC
            {
                auto varObj = currentScope->searchVariable($1);
                if (!varObj.has_value()) {
                        string msg = "Object '" + string($1) + "' is not declared.";
                        yyerror(msg.c_str());
                }
                string className = currentScope->getType($1);
                auto var = currentScope->searchVectorInClass(className, $3, globalScope);
                
                if(var.has_value()) {
                 int numberElements = get<1>(var.value());
                if($5>=numberElements){
                        string msg = "Tried accesing vector index "+ to_string($5) +" that doens't exist (the maximum elements for the vector is "+to_string(numberElements-1)+")";
                        yyerror(msg.c_str());
                }
                if($5<0){
                        string msg = "Tried accesing vector index "+ to_string($5) +" that doens't exist (the index can't be negative!)";
                        yyerror(msg.c_str());
                }
                string memberType = std::get<0>(var.value());
                if(memberType != "int" && memberType != "float") {
                        string msg = "Cannot decrement member '" + string($1) + "." + string($3) + 
                                "' because it is of type [" + memberType + "] (not numeric)";
                        yyerror(msg.c_str());
                }

                string fullName = string($1) + "." + string($3);

                ASTNode* destVecName = new ASTNode("id", fullName, memberType);
                ASTNode* destIndex = new ASTNode("int", to_string($5), "int");
                ASTNode* vectorDest = new ASTNode(destVecName, "[]", destIndex);

                
                ASTNode* readVecName = new ASTNode("id", fullName, memberType);
                ASTNode* readIndex = new ASTNode("int", to_string($5), "int");
                ASTNode* vectorRead = new ASTNode(readVecName, "[]", readIndex);

               
                ASTNode* unu = new ASTNode("int", "1", "int");
                ASTNode* minus = new ASTNode(vectorRead, "-", unu);

                
                $$ = new ASTNode(vectorDest, ":=", minus);


                } else {
                string msg = "Class member '" + string($3) + "' not found in class '" + className + "'";
                yyerror(msg.c_str());
                }
                
            }
            ;

//    ################# VARIABILE ###########################

global_var_section: {std::cout<<endl<<"No global variables"<<endl;}
            | GVAR_SECTION variable_declarations
            ;

variable_declarations : var_decl ';'
            | variable_declarations var_decl ';'
            ;

var_decl : TYPE ID 
        {
               optional<string> className = nullopt;

               if(currentScope != nullptr && currentScope->parentScope != nullptr) {
                  string parentName = currentScope->name;
            
                  auto& classes = globalScope->classes;
                  if(find(classes.begin(), classes.end(), parentName) != classes.end()) {
                     className = parentName;
                        cout<<"added function "<<$2<<" to class "<<parentName<<endl;
                  }
                }
                if(currentScope->addVariable($2,$1,nullopt,className)){
                        currentVarName= $2;
                        currentVarType = $1;
                } else {
                        string msg="Variable "+string($2) + " already declared!";
                        yyerror(msg.c_str());
                }
                string defaultValue = "0";
                if (string($1) == "float") defaultValue = "0.0";
                else if (string($1) == "bool") defaultValue = "true";
                else if (string($1) == "string") defaultValue = "";
                else if (string($1) == "char") defaultValue = "";
                ASTNode* varNode = new ASTNode("id", $2, currentVarType);
                ASTNode* defaultValNode = new ASTNode($1, defaultValue, $1);
                
                $$ = new ASTNode(varNode, ":=", defaultValNode);
        }
            | TYPE ID ',' var_list
            {
                

                string type = $1;
                vector<string>* ids = $4;
                ids->push_back($2);

                ASTNode* rootBlock = nullptr;

                string defVal;
                if (type == "int") defVal = "0";
                else if (type == "float") defVal = "0.0";
                else if (type == "bool") defVal = "true";
                else if (type == "char") defVal = " "; 
                else if (type == "string") defVal = "";
                else defVal = "0";
                for(string idName : *ids) {
                        optional<string> className = nullopt;

                        if(currentScope != nullptr && currentScope->parentScope != nullptr) {
                                string parentName = currentScope->name;
                        
                                auto& classes = globalScope->classes;
                                if(find(classes.begin(), classes.end(), parentName) != classes.end()) {
                                className = parentName;
                                        cout<<"added function "<<idName<<" to class "<<parentName<<endl;
                                }
                                }
                                if(currentScope->addVariable(idName,$1,nullopt,className)){
                                        currentVarType = $1;
                                } else {
                                        string msg="Variable "+idName + " already declared!";
                                        yyerror(msg.c_str());
                                }

                        ASTNode* varNode = new ASTNode("id", idName, type);
                        ASTNode* defValNode = new ASTNode(type, defVal, type);
                        ASTNode* assign = new ASTNode(varNode, ":=", defValNode);

                        if (rootBlock == nullptr) rootBlock = assign;
                        else rootBlock = new ASTNode(assign, "BLOCK", rootBlock);
                }
            }
            | TYPE ID ASSIGN
            {
                optional<string> className = nullopt;

               if(currentScope != nullptr && currentScope->parentScope != nullptr) {
                  string parentName = currentScope->name;
            
                  auto& classes = globalScope->classes;
                  if(find(classes.begin(), classes.end(), parentName) != classes.end()) {
                     className = parentName;
                        cout<<"added function "<<$2<<" to class "<<parentName<<endl;
                  }
                }
                if(currentScope->addVariable($2,$1,nullopt,className)){
                        currentVarName= $2;
                        currentVarType = $1;
                } else {
                        string msg="Variable "+string($2) + " already declared!";
                        yyerror(msg.c_str());
                }                
            }
             expression
             {
                string typeVarToBeAssigned=$1;
                string typeExpr=$5->exprType;
                if(typeVarToBeAssigned!=typeExpr){
                        string msg="Type mismatch at declaration, trying operation on ["+typeVarToBeAssigned+"] and ["+typeExpr+"]";
                        yyerror(msg.c_str());
                }
                if($5->type != astERROR){
                        currentScope->updateVarValue($2, $5->getStringValue());
                }
                cout<<"TIPUL MEU E ASTA UAII "<<$1<<endl;
                ASTNode* varNode = new ASTNode("id", $2, $1);
                $$ = new ASTNode(varNode, ":=", $5);
             }
             | TYPE ID '[' INT ']'
             {
                 optional<string> className = nullopt;

               if(currentScope != nullptr && currentScope->parentScope != nullptr) {
                  string parentName = currentScope->name;
            
                  auto& classes = globalScope->classes;
                  if(find(classes.begin(), classes.end(), parentName) != classes.end()) {
                     className = parentName;
                        cout<<"added Vector "<<$2<<" to class "<<parentName<<endl;
                  }
                }
                if(currentScope->addVector($2,$1,$4,nullopt,className)){
                        currentVarName= $2;
                        currentVarType = $1;
                } else {
                        string msg="Vecotr "+string($2) + " already declared!";
                        yyerror(msg.c_str());
                }
                ASTNode* rootBlock = nullptr;
                string defaultValue = "0";

                for (int i = 0; i < $4; i++) {
                        ASTNode* indexNode = new ASTNode("int", to_string(i), "int");
                        ASTNode* vecNode = new ASTNode("id_vector", $2, $1);
                        ASTNode* access = new ASTNode(vecNode, "[]", indexNode);
                        
                        ASTNode* zero = new ASTNode($1, defaultValue, $1);
                        
                        ASTNode* assign = new ASTNode(access, ":=", zero);

                        if (rootBlock == nullptr) {
                        rootBlock = assign;
                        } else {
                        rootBlock = new ASTNode(assign, "BLOCK", rootBlock);
                        }
                }
                $$ = rootBlock;

             }
             | TYPE ID '[' INT ']' ASSIGN
             {
                current_init_index=0;
                 optional<string> className = nullopt;

               if(currentScope != nullptr && currentScope->parentScope != nullptr) {
                  string parentName = currentScope->name;
            
                  auto& classes = globalScope->classes;
                  if(find(classes.begin(), classes.end(), parentName) != classes.end()) {
                     className = parentName;
                        cout<<"added Vector "<<$2<<" to class "<<parentName<<endl;
                  }
                }
                numberOfElementsToAdd=$4;
                if(currentScope->addVector($2,$1,numberOfElementsToAdd,nullopt,className)){
                        currentVarName= $2;
                        currentVarType = $1;
                } else {
                        string msg="Vecotr "+string($2) + " already declared!";
                        yyerror(msg.c_str());
                }
                current_init_vec_name=string($2);
                numberOfElementsToAdd=$4;
                cout<<"NUMBER OF ELEMENTS TO ADD "<<numberOfElementsToAdd<<endl;
             }
              '{' vector_elements '}'
              {
                if(numberOfElementsToAdd>0){
                       string msg="Vector init received too few arguments";
                        yyerror(msg.c_str());  
                }
                $$=nullptr;
              }
            ;

vector_elements: vector_element
                {
                        $$=$1;
                }
             | vector_element ',' vector_elements
             {
                $$ = new ASTNode($1,"BLOCK",$3);
             }

vector_element: expression
                {
                        if(numberOfElementsToAdd<=0){
                                string msg="Vector init received too many arguments";
                                yyerror(msg.c_str());
                        }
                        if($1->exprType!=string(currentVarType)){
                                string msg="Tried adding a variable of type "+ $1->exprType + " to a vector of type "+string(currentVarType);
                                yyerror(msg.c_str());
                        }
                        

                        if($1->exprType != currentVarType) {
                        string msg = "Type mismatch in vector init: expected " + string(currentVarType) + " but got "+$1->exprType;
                        yyerror(msg.c_str());
                        }

                        if(!currentScope->updateVectorElement(current_init_vec_name, current_init_index, $1->getStringValue())) {
                                yyerror("Index out of bounds during initialization!");
                        }

                        ASTNode* indexNode = new ASTNode("int", to_string(current_init_index), "int");
                        ASTNode* vecNode = new ASTNode("id_vector", current_init_vec_name, currentVarType);
                        ASTNode* access = new ASTNode(vecNode, "[]", indexNode);

                    
                        $$ = new ASTNode(access, ":=", $1);
                        current_init_index++;
                        numberOfElementsToAdd--;
                }

var_list: ID 
    { 
        $$ = new vector<string>(); 
        $$->push_back($1); 
    }
    | ID ',' var_list 
    { 
        $3->push_back($1); 
        $$ = $3; 
    }
//    ################# FUNCTII ###########################

global_fun_section : {std::cout<<endl<<"No global functions"<<endl;}
            | GFUN_SECTION function_declarations
            ;

//declararer functie
function_declarations : fun_decl
            | function_declarations fun_decl
            ;
        
fun_decl : TYPE ID '('
        {
               optional<string> className = nullopt;

               if(currentScope != nullptr && currentScope->parentScope != nullptr) {
                  string parentName = currentScope->name;
            
                  auto& classes = globalScope->classes;
                  if(find(classes.begin(), classes.end(), parentName) != classes.end()) {
                     className = parentName;
                        cout<<"added function "<<$2<<" to class "<<parentName<<endl;
                  }
                }

                if(currentScope->addFunction($2, $1, nullopt, className)==false){
                        string msg="Function or method "+string($2)+" already declared!";
                        yyerror(msg.c_str());
                }

                funName = $2;
                funType = $1;
                parentScope = currentScope;
                currentScope = currentScope->enterScope($2);
        } fun_decl_params ')' '{' fun_block 
         '}'
         {
                ASTNode* bodyContent = $8;
                currentScope = currentScope->exitScope();
                currentScope->setFunctionBody($2, bodyContent);
                parentScope = currentScope;
                $$=nullptr;
         }
            ;
fun_decl_params : 
            | fun_param
            | fun_decl_params ',' fun_param
            ;

fun_param : TYPE ID
        {
                parentScope->addParamName(funName, $2);
                parentScope->setFunctionParams(funName,$1);
                cout<<"adding variable "<<$2<<"to scope "<<currentScope->name<<endl;
                currentScope->addVariable($2,$1);
        }
            ;

fun_block : {$$=nullptr;} 
        | fun_block block_element
        {
                if ($1 == nullptr) {
                    $$ = $2;
                } else if ($2 == nullptr) {
                    $$ = $1;
                } else {
                    $$ = new ASTNode($1, "BLOCK", $2);
                }
        }
        ;

//ORICE MODIFICARE IN block_element MAI PUTIN var_decl AR TREBUI SCHIMBATA SI IN main_block_element
block_element : statement ';'
                { $$ = $1; }
            | statement { yyerror("Missing semicolon"); $$ = $1; }
            | var_decl ';'
                { $$ = $1; }
            | var_decl { yyerror("Missing semicolon"); $$ = nullptr; }
            | class_create_instance ';'
                { $$ = nullptr; }
            | class_method_call ';'
                { $$ = $1; }
            | fun_call ';'
                { $$ = $1; }
            | print_statement ';'
                { $$ = $1; }
            | if_statement
                { $$ = $1; }
            | while_statement
                { $$ = $1; }
            | return_statement
                { $$=$1; }
            ;

return_statement: RETURN expression ';'
                {
                        cout<<string(funType)<<' '<<$2->exprType<<endl;
                        if(string(funType)!=$2->exprType){
                                string msg="Return type of function "+string(funName)+" must be of type ["+string(funType)+"], received type ["+$2->exprType+"] instead.";
                                yyerror(msg.c_str());
                        }
                        $$ = new ASTNode($2, "RETURN", nullptr);
                        $$->exprType = $2->exprType;

                }
//apelare functie
fun_call : ID 
        {
                if(currentScope->searchFunction($1)==nullopt){
                        string msg="The called function "+string($1) +" doesn't exist!";
                        yyerror(msg.c_str());
                } else {
                        calling_functions.push($1);
                        param_counts.push(0);
                }

        }
        '(' fun_call_params ')'
        {
                string current_fun = calling_functions.top();
                int total_params = param_counts.top();

                if(currentScope->verifParamNumber(current_fun, total_params) == false){
                        string msg="The function call "+current_fun+" doesn't have the correct number of parameters";
                        yyerror(msg.c_str());
                }

                auto fun=currentScope->searchFunction(current_fun);
                auto [tip,params,clasa]=fun.value();
                // CE FAC CAND VAD CALL IN AST
                ASTNode* nameNode = new ASTNode("id", (char*)current_fun.c_str(), tip);
                $$ = new ASTNode(nameNode, "CALL", $4);
        
                calling_functions.pop();
                param_counts.pop();
        }
        ;

fun_call_params : {$$=nullptr;}
            | expression
            {
                string c_fun = calling_functions.top();
                int c_idx = param_counts.top();
                

                if(currentScope->verifParamType(c_fun, c_idx, $1->exprType) == false){
                    string msg = "Parameter " + to_string(c_idx) + " in " + c_fun + " is of type " + $1->exprType + " but should be different.";
                    yyerror(msg.c_str());
                }
                param_counts.top()++;
                $$ = new ASTNode($1, "ARG", nullptr);
            }
            | expression ','
            {
                string c_fun = calling_functions.top();
                int c_idx = param_counts.top();
                if(currentScope->verifParamType(c_fun, c_idx, $1->exprType) == false){
                     yyerror("Type mismatch");
                }
                param_counts.top()++;
                $<node>$ = $1;
            }
            fun_call_params
            {
                $$ = new ASTNode($<node>3, "ARG", $4);
            }
            ;

//ORICE SCHIMBARE AICI LA FUN CALL PARAM AR TREBUI SA SE REFLECTE SI IN METHOD CALL PARAM, DOAR CA ACOLO SCOPE UL E AUX



//    ################# FUNCTII PREDEFINITE ###########################

print_expr: expression {$$=$1;}
            ;

print_statement : PRINT '(' print_expr ')' {
        $$= new ASTNode($3,"PRINT",nullptr);
        }
        ;


//    ################# STATEMENTS ###########################


//    ######## ARITHMETIC ########

statement: ID ASSIGN expression
        {
                if(currentScope->searchVariable($1)==nullopt){
                        string msg="The variable "+string($1)+" doesn't exist!";
                        yyerror(msg.c_str());
                }

                 string typeVarToBeAssigned=currentScope->getType($1);
                string type=$3->exprType;
                if(typeVarToBeAssigned!=type){
                        string msg="Type mismatch at assignment, trying operation on ["+typeVarToBeAssigned+"] and ["+type+"]";
                        yyerror(msg.c_str());
                }
                ASTNode* idNode = new ASTNode("id", $1, type);
                $$ = new ASTNode(idNode, ":=", $3);
        }
        | ID INC
        {
                if(currentScope->searchVariable($1)==nullopt){
                        string msg="The variable "+string($1)+" doesn't exist!";
                        yyerror(msg.c_str());
                }
                string typeVarToBeAssigned=currentScope->getType($1);
                cout<<"TYPE TO ASSIGN: "<<typeVarToBeAssigned<<endl;
                if(typeVarToBeAssigned=="int" || typeVarToBeAssigned=="float"){
                        ASTNode* idNode = new ASTNode("id", $1, typeVarToBeAssigned);
                        ASTNode* unu = new ASTNode("int", "1", "int");
                        ASTNode* plus = new ASTNode(idNode, "+", unu);
                        $$ = new ASTNode(idNode, ":=", plus);
                } else {
                        string msg="The variable "+string($1)+ " isn't a float or an int, you can't increment it!";
                        yyerror(msg.c_str());
                }
                ASTNode* dest = new ASTNode("id", $1, typeVarToBeAssigned);
            
                ASTNode* source = new ASTNode("id", $1, typeVarToBeAssigned);
                ASTNode* unu = new ASTNode("int", "1", "int");
                ASTNode* plus = new ASTNode(source, "+", unu);
                
                $$ = new ASTNode(dest, ":=", plus);
        }
        | ID DEC
        {
                if(currentScope->searchVariable($1)==nullopt){
                        string msg="The variable "+string($1)+" doesn't exist!";
                        yyerror(msg.c_str());
                }
                string typeVarToBeAssigned=currentScope->getType($1);
                cout<<"TYPE TO ASSIGN: "<<typeVarToBeAssigned<<endl;
                if(typeVarToBeAssigned=="int" || typeVarToBeAssigned=="float"){
                        ASTNode* idNode = new ASTNode("id", $1, typeVarToBeAssigned);
                        ASTNode* unu = new ASTNode("int", "1", "int");
                        ASTNode* minus = new ASTNode(idNode, "-", unu);
                        $$ = new ASTNode(idNode, ":=", minus);
                } else {
                        string msg="The variable "+string($1)+ " isn't a float or an int, you can't increment it!";
                        yyerror(msg.c_str());
                }
                ASTNode* dest = new ASTNode("id", $1, typeVarToBeAssigned);
            
                ASTNode* source = new ASTNode("id", $1, typeVarToBeAssigned);
                ASTNode* unu = new ASTNode("int", "1", "int");
                ASTNode* minus = new ASTNode(source, "-", unu);
                
                $$ = new ASTNode(dest, ":=", minus);
        }
        | ID '[' INT ']' ASSIGN
        {
                auto var=currentScope->searchVector($1);
                if(var.has_value()){
                        int numberElements= get<1>(var.value());
                        if($3>=numberElements){
                        string msg = "Tried accesing vector index "+ to_string($3) +" that doens't exist (the maximum elements for the vector is "+to_string(numberElements-1)+")";
                        yyerror(msg.c_str());
                        }
                          if($3<0){
                        string msg = "Tried accesing vector index "+ to_string($3) +" that doens't exist (the index can't be negative!)";
                        yyerror(msg.c_str());
                        }
                }
                if(var==nullopt){
                        string msg="The vector "+string($1)+" doesn't exist!";
                        yyerror(msg.c_str());
                }
        }
         expression {
                string typeVarToBeAssigned=currentScope->getType($1);
                string type = $7->exprType;
                if(typeVarToBeAssigned!=type){
                        string msg="Type mismatch at assignment, trying operation on ["+typeVarToBeAssigned+"] and ["+type+"]";
                        yyerror(msg.c_str());
                }
                ASTNode* vecName = new ASTNode("id_vector", $1, typeVarToBeAssigned);
                ASTNode* indexNode = new ASTNode("int", to_string($3), "int");
                ASTNode* access = new ASTNode(vecName, "[]", indexNode);
                $$ = new ASTNode(access, ":=", $7);
         }
        | ID '[' INT ']' INC
        {
                auto var=currentScope->searchVector($1);
                if(var.has_value()){
                        int numberElements= get<1>(var.value());
                        if($3>=numberElements){
                        string msg = "Tried accesing vector index "+ to_string($3) +" that doens't exist (the maximum elements for the vector is "+to_string(numberElements-1)+")";
                        yyerror(msg.c_str());
                        }
                          if($3<0){
                        string msg = "Tried accesing vector index "+ to_string($3) +" that doens't exist (the index can't be negative!)";
                        yyerror(msg.c_str());
                        }
                }
                if(var==nullopt){
                        string msg="The vector "+string($1)+" doesn't exist!";
                        yyerror(msg.c_str());
                }
                string typeVarToBeAssigned=currentScope->getType($1);
                cout<<"TYPE TO ASSIGN: "<<typeVarToBeAssigned<<endl;
                if(typeVarToBeAssigned=="int" || typeVarToBeAssigned=="float"){
                        //change value
                } else {
                        string msg="The variable "+string($1)+ " isn't a float or an int, you can't increment it!";
                        yyerror(msg.c_str());
                }

                ASTNode* vecName = new ASTNode("id_vector", $1, typeVarToBeAssigned);
                ASTNode* indexNode = new ASTNode("int", to_string($3), "int");
                ASTNode* access = new ASTNode(vecName, "[]", indexNode);
                ASTNode* unu = new ASTNode("int", "1", "int");
                ASTNode* plus = new ASTNode(access, "+", unu);
                
                $$ = new ASTNode(access, ":=", plus);
        }
        | ID '[' INT ']' DEC
        {
                auto var=currentScope->searchVector($1);
                if(var.has_value()){
                        int numberElements= get<1>(var.value());
                        if($3>=numberElements){
                        string msg = "Tried accesing vector index "+ to_string($3) +" that doens't exist (the maximum elements for the vector is "+to_string(numberElements-1)+")";
                        yyerror(msg.c_str());
                        }
                          if($3<0){
                        string msg = "Tried accesing vector index "+ to_string($3) +" that doens't exist (the index can't be negative!)";
                        yyerror(msg.c_str());
                        }
                }
                if(var==nullopt){
                        string msg="The vector "+string($1)+" doesn't exist!";
                        yyerror(msg.c_str());
                }
                string typeVarToBeAssigned=currentScope->getType($1);
                cout<<"TYPE TO ASSIGN: "<<typeVarToBeAssigned<<endl;
                if(typeVarToBeAssigned=="int" || typeVarToBeAssigned=="float"){
                        //change value
                } else {
                        string msg="The variable "+string($1)+ " isn't a float or an int, you can't increment it!";
                        yyerror(msg.c_str());
                }
                ASTNode* vecName = new ASTNode("id_vector", $1, typeVarToBeAssigned);
                ASTNode* indexNode = new ASTNode("int", to_string($3), "int");
                ASTNode* access = new ASTNode(vecName, "[]", indexNode);
                ASTNode* unu = new ASTNode("int", "1", "int");
                ASTNode* minus = new ASTNode(access, "-", unu);
                
                $$ = new ASTNode(access, ":=", minus);
        }
        | class_var_call 
        ;

exp : exp '+' term
        {
                string type1=$1->exprType;
                string type2=$3->exprType;
                string resultType="int";
                string op = "+";
                cout<<"OPERATOR "<<op<<endl;
                bool ok=true;

                if (op == "+") {
                if (type1 == "string" && type2 == "string") {
                        resultType = "string";
                } 
                else if ((type1 == "int" || type1 == "float") && (type2 == "int" || type2 == "float")) {
                        if (type1 == "float" || type2 == "float") resultType = "float";
                        else resultType = "int";
                        } 
                        else {
                                ok = false;
                        }
                } 

                if(ok==false){
                string msg="Type mismatch, trying operation "+op+ " on ["+type1+"] and ["+type2+"]";
                yyerror(msg.c_str());
            }
            if(type1!=type2){
                string msg="Type mismatch, trying operation on ["+type1+"] and ["+type2+"]";
                yyerror(msg.c_str());
            }
            $$ = new ASTNode($1, "+", $3);
        }
        |exp '-' term
        {
                string type1=$1->exprType;
                string type2=$3->exprType;
                string resultType="int";
                string op = "-";
                cout<<"OPERATOR "<<op<<endl;
                bool ok=true;

                if (op == "-") {
                if ((type1 != "int" && type1 != "float") || (type2 != "int" && type2 != "float")) {
                        ok = false;
                }
                if (type1 == "float" || type2 == "float") resultType = "float";
                else resultType = "int";
                }

                if(ok==false){
                string msg="Type mismatch, trying operation "+op+ " on ["+type1+"] and ["+type2+"]";
                yyerror(msg.c_str());
            }
            if(type1!=type2){
                string msg="Type mismatch, trying operation on ["+type1+"] and ["+type2+"]";
                yyerror(msg.c_str());
            }
            $$ = new ASTNode($1, "-", $3);

        }
        | term {$$=$1;}
        ;

term: term OPERATOR factor
        {
                string type1=$1->exprType;
                string type2=$3->exprType;
                string resultType="int";
                string op = string($2);
                cout<<"OPERATOR "<<op<<endl;
                bool ok=true;
                
                if (op == "*" || op == "/") {
                if ((type1 != "int" && type1 != "float") || (type2 != "int" && type2 != "float")) {
                        ok = false;
                }
                if (type1 == "float" || type2 == "float") resultType = "float";
                else resultType = "int";
                }
                else if (op == "%") {
                        if (type1 != "int" || type2 != "int") {
                                ok = false;
                        }
                        resultType = "int";
                } 
                else if (op == "&&" || op == "||") {
                        if (type1 != "bool" || type2 != "bool") {
                                ok = false;
                        }
                        resultType = "bool";
                } 
                else {
                        ok = false;
                }
            if(ok==false){
                string msg="Type mismatch, trying operation "+op+ " on ["+type1+"] and ["+type2+"]";
                yyerror(msg.c_str());
            }
            if(type1!=type2){
                string msg="Type mismatch, trying operation on ["+type1+"] and ["+type2+"]";
                yyerror(msg.c_str());
            }
            $$ = new ASTNode($1, op, $3);
        }
        | factor
        {
                $$=$1;
        }
        ;
factor: '-' factor %prec UMINUS 
        { 
                cout<<$2->exprType<<" TIPUL ASTA NU E NUMERIC CICA!"<<endl;
                if ($2->exprType != "int" && $2->exprType != "float") {
                   yyerror("Minus operator ca only be appleid to numeric values!");
               }
               $$ = new ASTNode($2, "NEG", nullptr);
        }
       | NOT factor             
       { 
                if ($2->exprType != "bool") {
                   yyerror("NOT operator ca only be applied to bool type!");
               }
               $$ = new ASTNode($2, "NOT", nullptr);
        }
       | '(' expression ')'    { $$ = $2; }
       | expression_elem       { $$ = $1; }
       ;
expression_elem : class_access { $$ = $1; }
        | fun_call { $$ = $1; }
        | INT
        {
            $$ = new ASTNode("int", to_string($1), "int");
        }
        | FLOAT
        {
            $$ = new ASTNode("float", to_string($1), "float");
        }
        | BOOL
        {
            $$ = new ASTNode("bool", $1 ? "true" : "false", "bool");
        }
        | CHAR
        {
            $$ = new ASTNode("char", string(1, $1), "char");
        }
        | STRING
        {
            $$ = new ASTNode("string", $1, "string");
        }
        | ID
        {
            if(currentScope->searchVariable($1) == nullopt){
                string msg = "Variable " + string($1) + " doesn't exist";
                yyerror(msg.c_str());
            }
            $$ = new ASTNode("id", $1, currentScope->getType($1));
        }
        | ID '[' INT ']'
        {
            auto var = currentScope->searchVector($1);
            if(var.has_value()){
                int numberElements = get<1>(var.value());
                if($3 >= numberElements){
                    string msg = "Tried accessing vector index " + to_string($3) + " that doesn't exist (max is " + to_string(numberElements-1) + ")";
                    yyerror(msg.c_str());
                }
                if($3 < 0){
                    yyerror("Vector index can't be negative!");
                }
            } else {
                string msg = "The vector " + string($1) + " doesn't exist!";
                yyerror(msg.c_str());
            }
            
            ASTNode* vecName = new ASTNode("id_vector", $1, currentScope->getType($1));
            ASTNode* indexNode = new ASTNode("int", to_string($3), "int");
            $$ = new ASTNode(vecName, "[]", indexNode);
        }
       
        ;

//    ######## BOOLEAN ########

expression : exp COMPARE exp
            {   
                if ($1->exprType != $3->exprType) {
                    string msg = "Type mismatch at compare: trying to compare [" + 
                                 $1->exprType + "] with [" + $3->exprType + "]";
                    yyerror(msg.c_str());
                }

                cout<<"WHAT THE SIGMA COMPARE "<<string($2)<<endl;
                $$ = new ASTNode($1, string($2), $3);
                
                $$->exprType = "bool";

                cout << "Nod de comparare creat cu tipul: " << $$->exprType << endl;
            }
            | exp {$$=$1;}
            ;

if_statement : IF '(' expression ')' '{' main_fun_block '}'
            {
                $$ = new ASTNode($3, "IF", $6);
            }
            | IF '(' expression ')' '{' main_fun_block '}' ELSE '{' main_fun_block '}'
            {
                ASTNode* bodyNode = new ASTNode($6, "IF_ELSE_LINK", $10);
                $$ = new ASTNode($3, "IF", bodyNode);
            }
            | IF '(' expression ')' '{' main_fun_block '}' ELSE if_statement
            {
                ASTNode* bodyNode = new ASTNode($6, "IF_ELSE_LINK", $9);
                $$ = new ASTNode($3, "IF", bodyNode);
            }
            ;

while_statement : WHILE '(' expression ')' '{' main_fun_block '}'
             {
                $$ = new ASTNode($3, "WHILE", $6);
             }
            ;

//    ################# MAIN ###########################


main : MAIN_BEGIN main_fun_block MAIN_END {
        if ($2 == nullptr) cout << "DEBUG: main_fun_block e NULL!" << endl;
    $$ = $2;
    };

//main fun block nu permite declararea variabilelelor, diferit de fun_block care permite

//ORICE MODIFICARE IN main_block_element AR TREBUI SCHIMBATA SI IN block_element

main_fun_block : main_block_element
                {
                        $$=$1;
                }
                | main_fun_block main_block_element
                {
                        $$ = new ASTNode($1, "BLOCK", $2);
                }
                ;
main_block_element : statement ';'
                { $$ = $1; }
            | statement { yyerror("Missing semicolon"); $$ = $1; }
            | class_create_instance ';'
                { $$ = nullptr; }
            | class_method_call ';'
                { $$ = $1; }
            | fun_call ';'
                { $$ = $1; }
            | print_statement ';'
                { $$ = $1; }
            | if_statement
                { $$ = $1; }
            | while_statement
                { $$ = $1; }
            | return_statement
                { $$ = $1; }
            ;




%%
void yyerror(const char * s){
    errorCount++;
    cout << endl<< "error:" << s << " at line: " << yylineno << endl;
    exit(1);
}


int main(int argc, char** argv){
    FILE *g;
    if(argc>1)
        yyin = fopen(argv[1],"r");

    globalScope = new SymTable("global");
    currentScope = globalScope;
    yyparse();
}