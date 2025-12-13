%code requires {
  #include <string>
 
  using namespace std;
}

%{
#include <iostream>
#include <stdio.h>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yyparse();
extern int yylex();
void yyerror(const char * s);
int errorCount=0;
%}
%token TYPE CLASS_SECTION CLASS_VAR_SECTION CLASS_METHODS_SECTION CLASS GVAR_SECTION GFUN_SECTION NEW ASSIGN IF ELSE WHILE COMPARE ID NR PRINT MAIN_BEGIN MAIN_END OPERATOR INC DEC

%start program

%left '+' '-' 
%left '*' '/' '%'
%%

program : class_section global_var_section global_fun_section main {if(errorCount==0) cout<<endl<<"The program is correct!\n";};

//    ################# CLASE ###########################
class_section : {std::cout<<endl<<"No classes"<<endl;}
            | CLASS_SECTION class_declarations;

class_declarations : class_declaration
            | class_declarations class_declaration

class_declaration : CLASS ID '{' class_block '}';

class_block : class_var_section class_methods_section;

class_var_section : {std::cout<<endl<<"No variables"<<endl;}
            | CLASS_VAR_SECTION variable_declarations
            ;

class_methods_section : {std::cout<<endl<<"No methods"<<endl;}
            | CLASS_METHODS_SECTION function_declarations
            ;

class_create_instance : ID ID ASSIGN NEW ID '(' ')'  //trebuie verificat primul ID=clasa_existenta, al doilea ID=sa nu fei folosit, al treilea ID=aceeasi_clasa_existenta, si apoi parametrii daca e construcotr
        ;

class_access : class_method_call
            | ID '.' ID
            ;

class_method_call : ID '.' ID '(' fun_call_params ')'
            ;

class_var_call : ID '.' ID ASSIGN expression
            | ID '.' ID INC
            | ID '.' ID DEC
            ;

//    ################# VARIABILE ###########################

global_var_section: {std::cout<<endl<<"No global variables"<<endl;}
            | GVAR_SECTION variable_declarations
            ;

variable_declarations : var_decl ';'
            | variable_declarations var_decl ';'
            ;

var_decl : TYPE ID
            | TYPE ID ASSIGN expression
            ;

//    ################# FUNCTII ###########################

global_fun_section : {std::cout<<endl<<"No global functions"<<endl;}
            | GFUN_SECTION function_declarations
            ;

//declararer functie
function_declarations : fun_decl
            | function_declarations fun_decl
            ;
        
fun_decl : TYPE ID '(' fun_decl_params ')' '{' fun_block '}'
            ;
fun_decl_params : 
            | fun_param
            | fun_decl_params ',' fun_param
            ;

fun_param : TYPE ID
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
            | class_var_call ';'
            | fun_call ';'
            | print_statement ';'
            | if_statement
            | while_statement
            ;


//apelare functie
fun_call : ID '(' fun_call_params ')'
        ;

fun_call_params : 
            | fun_call_param
            | fun_call_params ',' fun_call_param
            ;

fun_call_param : ID
            | NR
            | class_method_call
            | fun_call
            ;


//    ################# FUNCTII PREDEFINITE ###########################

print_expr: ID
            |NR 
            ;

print_statement : PRINT '(' print_expr ')' {cout<<endl<<"PRINT"<<endl;}
        ;


//    ################# STATEMENTS ###########################


//    ######## ARITHMETIC ########

statement: ID ASSIGN expression
        | ID INC
        | ID DEC
        ;

expression : expression_elem OPERATOR expression
        | expression_elem INC
        | expression_elem DEC
        | expression_elem
        ;

expression_elem : class_access
        | fun_call
        | NR
        | ID
        ;

//    ######## BOOLEAN ########

compare_expr : ID COMPARE expression
            | class_method_call COMPARE expression
            | class_var_call COMPARE expression
            | fun_call COMPARE expression
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
            | class_var_call ';'
            | fun_call ';'
            | print_statement ';'
            | if_statement
            | while_statement
            ;




%%
void yyerror(const char * s){
    errorCount++;
    cout << endl<< "error:" << s << " at line: " << yylineno << endl;
}


int main(int argc, char** argv){
    FILE *g;
    if(argc>1)
        yyin = fopen(argv[1],"r");
    yyparse();
}