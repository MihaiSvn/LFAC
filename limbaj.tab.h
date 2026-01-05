/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_LIMBAJ_TAB_H_INCLUDED
# define YY_YY_LIMBAJ_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "limbaj.y"

  #include <string>
  #include <cstring>
  using namespace std;

#line 55 "limbaj.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TYPE = 258,                    /* TYPE  */
    CLASS_SECTION = 259,           /* CLASS_SECTION  */
    CLASS_VAR_SECTION = 260,       /* CLASS_VAR_SECTION  */
    CLASS_METHODS_SECTION = 261,   /* CLASS_METHODS_SECTION  */
    CLASS = 262,                   /* CLASS  */
    GVAR_SECTION = 263,            /* GVAR_SECTION  */
    GFUN_SECTION = 264,            /* GFUN_SECTION  */
    NEW = 265,                     /* NEW  */
    ASSIGN = 266,                  /* ASSIGN  */
    IF = 267,                      /* IF  */
    ELSE = 268,                    /* ELSE  */
    WHILE = 269,                   /* WHILE  */
    COMPARE = 270,                 /* COMPARE  */
    ID = 271,                      /* ID  */
    INT = 272,                     /* INT  */
    BOOL = 273,                    /* BOOL  */
    FLOAT = 274,                   /* FLOAT  */
    STRING = 275,                  /* STRING  */
    CHAR = 276,                    /* CHAR  */
    PRINT = 277,                   /* PRINT  */
    MAIN_BEGIN = 278,              /* MAIN_BEGIN  */
    MAIN_END = 279,                /* MAIN_END  */
    OPERATOR = 280,                /* OPERATOR  */
    INC = 281,                     /* INC  */
    DEC = 282                      /* DEC  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 37 "limbaj.y"

        char* stringVal;
        bool boolVal;
        char charVal;
        int intVal;
        float floatVal;

#line 107 "limbaj.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_LIMBAJ_TAB_H_INCLUDED  */
