%code requires {
  #include <string>
  #include <cstring>
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

char* currentVarName;
char* currentVarType;

int nr_param=0;
int vector_size=0;
int numberOfElementsToAdd=0;
%}

%union{
        char* stringVal;
        bool boolVal;
        char charVal;
        int intVal;
        float floatVal;
        class ASTNode* node;
}
%token <stringVal>TYPE CLASS_SECTION CLASS_VAR_SECTION CLASS_METHODS_SECTION CLASS GVAR_SECTION GFUN_SECTION NEW ASSIGN IF ELSE WHILE COMPARE <stringVal>ID <intVal>INT <boolVal>BOOL <floatVal>FLOAT <stringVal>STRING <charVal>CHAR PRINT MAIN_BEGIN MAIN_END <stringVal>OPERATOR INC DEC NOT

%type <stringVal>fun_call <stringVal>class_method_call <stringVal>class_access <stringVal>expression_elem <stringVal>compare_expr <stringVal> expression <stringVal> print_expr
%start program

%left '+' '-' 
%left '*' '/' '%'
%right NOT
%right MINUS
%left INC DEC

%%

program : class_section global_var_section global_fun_section main {if(errorCount==0) cout<<endl<<"The program is correct!\n";};

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

class_create_instance : ID
                        {
                        if(find(globalScope->classes.begin(),globalScope->classes.end(),$1)==globalScope->classes.end()){
                                string msg="The class "+string($1)+" doesn't exists";
                                yyerror(msg.c_str());
                        }

                        }
                         ID 
                         {
                                if(currentScope->addVariable($3,$1)==false){
                                string msg="The class name"+string($3)+" doesn't exists";
                                        yyerror(msg.c_str());
                                }
                         }
                         ASSIGN NEW 
                         ID
                          {
                                if(string($1)!=string($7)){
                                        yyerror("Type mismatch: cannot instantiate class with a different constructor type");
                                }
                          }
                          '(' ')'  //trebuie verificat primul ID=clasa_existenta, al doilea ID=sa nu fei folosit, al treilea ID=aceeasi_clasa_existenta, si apoi parametrii daca e construcotr
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
                if(var.has_value()){
                        auto [tip,valoarea,clasa] = var.value();
                        if(clasa.has_value()){  //daca este o variabila de clasa
                                string cls = clasa.value();
                                if(cls!=classType){
                                        string msg="the variable"+string($3)+"is in a different class";
                                        yyerror(msg.c_str());
                                } else {
                                   $$ = strdup(tip.c_str());
                                }
                        }
                } else {
                        string msg="The class variable "+string($3)+" doesn't exist";
                    yyerror(msg.c_str());
                }
                
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
                if(var.has_value()){
                        auto [tip,numberElements,valori,clasa] = var.value();
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
                                   $$ = strdup(tip.c_str());
                                }
                        }
                } else {
                        string msg="The class vector "+string($3)+" doesn't exist";
                    yyerror(msg.c_str());
                }
                
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
                        calling_functions.push($3);
                        param_counts.push(0);
                  }
                  '(' method_call_params ')'
                  {
                        string current_fun = calling_functions.top();
                        int total_params = param_counts.top();

                        if(aux->verifParamNumber(current_fun, total_params) == false){
                                string msg="The method "+current_fun+" doesn't have the correct number of parameters";
                                yyerror(msg.c_str());
                        }

                       
                        calling_functions.pop();
                        param_counts.pop();

                        auto fun = aux->searchFunction($3);
                        if(fun==nullopt){
                                yyerror("error at finding method");
                        }
                        string tip = std::get<0>(fun.value());
                        $$ = strdup(tip.c_str()); //returnez tipul
                  }
            ;

method_call_params : 
            | method_call_param
            | method_call_params ',' method_call_param
            ;

//ORICE SCHIMBARE AICI LA METHOD CALL PARAM AR TREBUI SA SE REFLECTE SI IN FUN CALL PARAM, DOAR CA ACOLO SCOPE UL E CURRENTSCOPE

method_call_param : expression
            {
                string c_fun = calling_functions.top();
                int c_idx = param_counts.top();
                
                if(aux->verifParamType(c_fun, c_idx, $1) == false){
                    string msg = "Parameter " + to_string(c_idx) + " in " + c_fun + " is of type " + $1 + " but should be different.";
                    yyerror(msg.c_str());
                }
                param_counts.top()++;
                free($1);
            }
            ;

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
                string exprType = $5;
                if(memberType != exprType) {
                        string msg = "Cannot assign [" + exprType + "] to member '" + string($1) + "." + string($3) + "' of type [" + memberType + "]";
                        yyerror(msg.c_str());
                }
                }
                free($5);
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
                string exprType = $8;
                if(memberType != exprType) {
                        string msg = "Cannot assign [" + exprType + "] to member '" + string($1) + "." + string($3) + "' of type [" + memberType + "]";
                        yyerror(msg.c_str());
                }
                }
                free($8);
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
        }
            | TYPE ID ',' var_list
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
                string typeExpr=$5;
                if(typeVarToBeAssigned!=typeExpr){
                        string msg="Type mismatch at declaration, trying operation on ["+typeVarToBeAssigned+"] and ["+typeExpr+"]";
                        yyerror(msg.c_str());
                }
                cout<<"TYPE TO ASSIGN: "<<typeVarToBeAssigned<<endl;
                free($5);
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

             }
             | TYPE ID '[' INT ']' ASSIGN
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
                numberOfElementsToAdd=$4;
                if(currentScope->addVector($2,$1,numberOfElementsToAdd,nullopt,className)){
                        currentVarName= $2;
                        currentVarType = $1;
                } else {
                        string msg="Vecotr "+string($2) + " already declared!";
                        yyerror(msg.c_str());
                }

                numberOfElementsToAdd=$4;
                cout<<"NUMBER OF ELEMENTS TO ADD "<<numberOfElementsToAdd<<endl;

             }
              '{' vector_elements '}'
              {
                if(numberOfElementsToAdd>0){
                       string msg="Vector init received too few arguments";
                        yyerror(msg.c_str());  
                }
              }
            ;

vector_elements: vector_element
             | vector_element ',' vector_elements

vector_element: expression
                {
                        if(numberOfElementsToAdd<=0){
                                string msg="Vector init received too many arguments";
                                yyerror(msg.c_str());
                        }
                        if(string($1)!=string(currentVarType)){
                                string msg="Tried adding a variable of type "+ string($1) + " to a vector of type "+string(currentVarType);
                                yyerror(msg.c_str());
                        }
                        numberOfElementsToAdd--;
                        //should add value to vector<string> here
                }

var_list: ID
                {
                        optional<string> className = nullopt;

                        if(currentScope != nullptr && currentScope->parentScope != nullptr) {
                        string parentName = currentScope->name;
                
                        auto& classes = globalScope->classes;
                        if(find(classes.begin(), classes.end(), parentName) != classes.end()) {
                        className = parentName;
                                cout<<"added variable "<<$1<<" to class "<<parentName<<endl;
                        }
                        }
                        if(currentScope->addVariable($1,currentVarType,nullopt,className)){
                                currentVarName=$1;
                        } else {
                                string msg="Variable "+string($1) + " already declared!";
                                yyerror(msg.c_str());
                        }
 
                }
           | ID ',' var_list
                {
                        optional<string> className = nullopt;

                        if(currentScope != nullptr && currentScope->parentScope != nullptr) {
                        string parentName = currentScope->name;
                
                        auto& classes = globalScope->classes;
                        if(find(classes.begin(), classes.end(), parentName) != classes.end()) {
                        className = parentName;
                                cout<<"added variable "<<$1<<" to class "<<parentName<<endl;
                        }
                        }
                        if(currentScope->addVariable($1,currentVarType,nullopt,className)){
                                currentVarName = $1;
                        } else {
                                string msg="Variable "+string($1) + " already declared!";
                                yyerror(msg.c_str());
                        }
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
                parentScope = currentScope;
                currentScope = currentScope->enterScope($2);
        } fun_decl_params ')' '{' fun_block 
         '}'
         {
                currentScope = currentScope->exitScope();
                parentScope = currentScope;
         }
            ;
fun_decl_params : 
            | fun_param
            | fun_decl_params ',' fun_param
            ;

fun_param : TYPE ID
        {
                parentScope->setFunctionParams(funName,$1);
                cout<<"adding variable "<<$2<<"to scope "<<currentScope->name<<endl;
                currentScope->addVariable($2,$1);
        }
            ;

fun_block : 
        | fun_block block_element
        ;

//ORICE MODIFICARE IN block_element MAI PUTIN var_decl AR TREBUI SCHIMBATA SI IN main_block_element
block_element : statement ';'
            | statement { yyerror("Missing semicolon");}
            | var_decl ';'
            | var_decl { yyerror("Missing semicolon");}
            | class_create_instance ';'
            | class_method_call ';'
            | fun_call ';'
            | print_statement ';'
            | if_statement
            | while_statement
            ;


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
        '(' fun_call_params 
        ')'
        {
                string current_fun = calling_functions.top();
                int total_params = param_counts.top();

                if(currentScope->verifParamNumber(current_fun, total_params) == false){
                        string msg="The function call "+current_fun+" doesn't have the correct number of parameters";
                        yyerror(msg.c_str());
                }

                calling_functions.pop();
                param_counts.pop();

                auto fun = currentScope->searchFunction($1);
                if(fun==nullopt){
                        yyerror("error at finding functiion");
                }
                string tip = std::get<0>(fun.value());
                $$ = strdup(tip.c_str()); //returnez tipul
        }
        ;

fun_call_params : 
            | fun_call_param
            | fun_call_params ',' fun_call_param
            ;

//ORICE SCHIMBARE AICI LA FUN CALL PARAM AR TREBUI SA SE REFLECTE SI IN METHOD CALL PARAM, DOAR CA ACOLO SCOPE UL E AUX
fun_call_param : expression
            {
                string c_fun = calling_functions.top();
                int c_idx = param_counts.top();
                
                if(currentScope->verifParamType(c_fun, c_idx, $1) == false){
                    string msg = "Parameter " + to_string(c_idx) + " in " + c_fun + " is of type " + $1 + " but should be different.";
                    yyerror(msg.c_str());
                }
                param_counts.top()++;
                free($1);
            }
            ;


//    ################# FUNCTII PREDEFINITE ###########################

print_expr: expression
            ;

print_statement : PRINT '(' print_expr ')' {cout<<endl<<$3<<endl;
        free($3);
        }
        ;


//    ################# STATEMENTS ###########################


//    ######## ARITHMETIC ########

statement: ID ASSIGN
        {
                if(currentScope->searchVariable($1)==nullopt){
                        string msg="The variable "+string($1)+" doesn't exist!";
                        yyerror(msg.c_str());
                }
        }
         expression {
                string typeVarToBeAssigned=currentScope->getType($1);
                if(typeVarToBeAssigned!=string($4)){
                        string msg="Type mismatch at assignment, trying operation on ["+typeVarToBeAssigned+"] and ["+string($4)+"]";
                        yyerror(msg.c_str());
                }
                free($4);
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
                        //change value
                } else {
                        string msg="The variable "+string($1)+ " isn't a float or an int, you can't increment it!";
                        yyerror(msg.c_str());
                }
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
                        //change value
                } else {
                        string msg="The variable "+string($1)+ " isn't a float or an int, you can't increment it!";
                        yyerror(msg.c_str());
                }
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
                if(typeVarToBeAssigned!=string($7)){
                        string msg="Type mismatch at assignment, trying operation on ["+typeVarToBeAssigned+"] and ["+string($7)+"]";
                        yyerror(msg.c_str());
                }
                free($7);
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
        }
        | class_var_call 
        ;

expression : NOT expression
        {
                if (string($2) != "bool") {
                   yyerror("NOT operator ca only be applied to bool type!");
               }
               $$ = strdup("bool");
        }
        | '-' expression %prec MINUS
        {
                if (string($2) != "int" && string($2) != "float") {
                   yyerror("Minus operator ca only be appleid to numeric values!");
               }
               $$ = strdup($2);
        }
        |expression_elem '+' expression
        {
                string type1=string($1);
                string type2=string($3);
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
            $$ = strdup(resultType.c_str());
            free($1);
            free($3);
        }
        |expression_elem '-' expression
        {
                string type1=string($1);
                string type2=string($3);
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
            $$ = strdup(resultType.c_str());
            free($1);
            free($3);
        }
        |expression_elem OPERATOR expression 
        { 
                string type1=string($1);
                string type2=string($3);
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
            $$ = strdup(resultType.c_str());
            free($1);
            free($3); 
        }
        | expression_elem INC  
        {
            if(string($1)!="int" && string($1)!="float"){
                yyerror("Cannot increment a non-numeric value!");
            }    
            $$=$1; 
        }
        | expression_elem DEC  
        {
            if(string($1)!="int" && string($1)!="float"){
                yyerror("Cannot increment a non-numeric value!");
            }
           $$=$1;
        }
        | expression_elem {$$=$1;}
        
        ;

expression_elem : class_access
        | fun_call
        | INT
        {
                $$=strdup("int");
        }
        | FLOAT
        {
                $$=strdup("float");
        }
        | BOOL
        {
                $$=strdup("bool");

        }
        | CHAR
        {

                $$=strdup("char");
        }
        | STRING
        {
                $$=strdup("string");

        }
        | ID
        {
                if(currentScope->searchVariable($1)==nullopt){
                        string msg="Variable "+string($1)+" doesn't exist";
                        yyerror(msg.c_str());
                }
                $$=strdup(currentScope->getType($1).c_str());
        }
        | ID '[' INT ']'
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
                $$=strdup(currentScope->getType($1).c_str());
        }
        | '(' expression ')'
        {
                $$=$2;
        }
        ;

//    ######## BOOLEAN ########

compare_expr : expression COMPARE expression
            {
                cout << "DEBUG: Comparing [" << $1 << "] with [" << $3 << "]" << endl;
   
                if(string($1)!=string($3)){
                         string msg="Type mismatch at compare, trying operation on ["+string($1)+"] and ["+string($3)+"]";
                yyerror(msg.c_str());
                }
                //ar trebui adaucat si verific compare ul
                $$=strdup("bool");

                free($1);
                free($3);

            }
            ;

if_statement : IF '(' compare_expr ')' '{' main_fun_block '}'
            | IF '(' compare_expr ')' '{' main_fun_block '}' ELSE '{' main_fun_block '}'
            | IF '(' compare_expr ')' '{' main_fun_block '}' ELSE if_statement
            ;

while_statement : WHILE '(' compare_expr ')' '{' main_block_element '}'
            ;

//    ################# MAIN ###########################


main : MAIN_BEGIN main_fun_block MAIN_END;

//main fun block nu permite declararea variabilelelor, diferit de fun_block care permite

//ORICE MODIFICARE IN main_block_element AR TREBUI SCHIMBATA SI IN block_element

main_fun_block : 
                | main_fun_block main_block_element
                ;
main_block_element : statement ';'
            | statement { yyerror("Missing semicolon");}
            | class_create_instance ';'
            | class_method_call ';'
            | fun_call ';'
            | print_statement ';'
            | if_statement
            | while_statement
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