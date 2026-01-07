%{
#include <stdio.h>
#include <iostream>
#include "limbaj.tab.h"
%}
%x comment
%x comment_linie
%option noyywrap


%%
"Print" {std::cout<<"("<<yytext<<",PRINT)";  return PRINT;}

"class_section" {return CLASS_SECTION;}
"class_var_section" {return CLASS_VAR_SECTION;}
"class_methods_section" {return CLASS_METHODS_SECTION;}
"global_var_section" {return GVAR_SECTION;}
"global_fun_section" {return GFUN_SECTION;}
"int"|"float"|"string"|"bool"|"char" {std::cout<<"("<<yytext<<",TYPE)";
yylval.stringVal = strdup(yytext);
 return TYPE;}
"class" {std::cout<<"("<<yytext<<",CLASS)";  return CLASS;}
"new" {std::cout<<"("<<yytext<<",NEW)";  return NEW;}

"=" {std::cout<<"("<<yytext<<",ASSIGN)";  return ASSIGN;}
"if" {std::cout<<"("<<yytext<<",IF)";  return IF;}
"else" {std::cout<<"("<<yytext<<",ELSE)";  return ELSE;}
"while" {std::cout<<"("<<yytext<<",WHILE)";  return WHILE;}

"<="|">="|"=="|"!="|"<"|">" {
    yylval.stringVal = strdup(yytext);
    std::cout<<"("<<yytext<<",COMPARE)";  return COMPARE;
    
    }

"!" {std::cout<<"("<<yytext<<",NOT)";
yylval.stringVal=strdup(yytext);
return NOT;}
"++" {std::cout<<"("<<yytext<<",INC)"; return INC;}
"--" {std::cout<<"("<<yytext<<",DEC)"; return DEC;}
"+"|"-" { 
    yylval.stringVal = strdup(yytext); 
    return yytext[0];
}

"*"|"/"|"%"|"&&"|"||" { 
    yylval.stringVal = strdup(yytext); 
    return OPERATOR; 
}

"true"|"false" {
    if(strcmp(yytext,"true") == 0) { yylval.boolVal = true; }
    else { yylval.boolVal = false; }
    return BOOL;
}

"main" {return MAIN_BEGIN;}
"end_main" {return MAIN_END;}
[a-zA-Z][a-zA-Z0-9_]* {std::cout<<"("<<yytext<<",ID)"; 
yylval.stringVal = strdup(yytext);
return ID;}



0|-?([1-9][0-9]*) { 
    yylval.intVal = atoi(yytext); 
    return INT; 
}

-?([1-9][0-9]*|[0])"."[0-9]* { 
    yylval.floatVal = atof(yytext); 
    return FLOAT; 
}

'[a-zA-Z0-9 -=+()\/?;:'!@#$%^&]' {
    yylval.charVal = yytext[1]; 
    return CHAR;
}

\"[^\"]*\" {
    yylval.stringVal = strdup(yytext); 
    return STRING;
}


"{" {return '{';}
"}" {return '}';}
"(" {return '(';}
")" {return ')';}
";" {return ';';}
"," {return ',';}
"." {return '.';}
"[" {return '[';}
"]" {return ']';}

[ \t] ; // ignora spatii
\n {yylineno++;}

"/*" {BEGIN comment; std::cout<<"("<<yytext<<",BCOMM)";}
<comment>. ;
<comment>\n {yylineno++;} // ignora chestii din comment-uri
<comment>"*/" {BEGIN 0; std::cout<<"("<<yytext<<",ENDCOMM)";}

"//" {BEGIN comment_linie; std::cout<<"("<<yytext<<",BCOMM)";}
<comment_linie>. ;
<comment_linie>\n {yylineno++; BEGIN 0; std::cout<<"("<<"newline,ENDCOMM)";}

. {std::cout<<"("<<yytext<<",NECUNOSCUT)";}


