/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 7 "limbaj.y"

#include "SymTable.h"
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

#line 103 "limbaj.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "limbaj.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TYPE = 3,                       /* TYPE  */
  YYSYMBOL_CLASS_SECTION = 4,              /* CLASS_SECTION  */
  YYSYMBOL_CLASS_VAR_SECTION = 5,          /* CLASS_VAR_SECTION  */
  YYSYMBOL_CLASS_METHODS_SECTION = 6,      /* CLASS_METHODS_SECTION  */
  YYSYMBOL_CLASS = 7,                      /* CLASS  */
  YYSYMBOL_GVAR_SECTION = 8,               /* GVAR_SECTION  */
  YYSYMBOL_GFUN_SECTION = 9,               /* GFUN_SECTION  */
  YYSYMBOL_NEW = 10,                       /* NEW  */
  YYSYMBOL_ASSIGN = 11,                    /* ASSIGN  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_COMPARE = 15,                   /* COMPARE  */
  YYSYMBOL_ID = 16,                        /* ID  */
  YYSYMBOL_INT = 17,                       /* INT  */
  YYSYMBOL_BOOL = 18,                      /* BOOL  */
  YYSYMBOL_FLOAT = 19,                     /* FLOAT  */
  YYSYMBOL_STRING = 20,                    /* STRING  */
  YYSYMBOL_CHAR = 21,                      /* CHAR  */
  YYSYMBOL_PRINT = 22,                     /* PRINT  */
  YYSYMBOL_MAIN_BEGIN = 23,                /* MAIN_BEGIN  */
  YYSYMBOL_MAIN_END = 24,                  /* MAIN_END  */
  YYSYMBOL_OPERATOR = 25,                  /* OPERATOR  */
  YYSYMBOL_INC = 26,                       /* INC  */
  YYSYMBOL_DEC = 27,                       /* DEC  */
  YYSYMBOL_NOT = 28,                       /* NOT  */
  YYSYMBOL_29_ = 29,                       /* '+'  */
  YYSYMBOL_30_ = 30,                       /* '-'  */
  YYSYMBOL_31_ = 31,                       /* '*'  */
  YYSYMBOL_32_ = 32,                       /* '/'  */
  YYSYMBOL_33_ = 33,                       /* '%'  */
  YYSYMBOL_MINUS = 34,                     /* MINUS  */
  YYSYMBOL_35_ = 35,                       /* '{'  */
  YYSYMBOL_36_ = 36,                       /* '}'  */
  YYSYMBOL_37_ = 37,                       /* '('  */
  YYSYMBOL_38_ = 38,                       /* ')'  */
  YYSYMBOL_39_ = 39,                       /* '.'  */
  YYSYMBOL_40_ = 40,                       /* '['  */
  YYSYMBOL_41_ = 41,                       /* ']'  */
  YYSYMBOL_42_ = 42,                       /* ','  */
  YYSYMBOL_43_ = 43,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_program = 45,                   /* program  */
  YYSYMBOL_class_section = 46,             /* class_section  */
  YYSYMBOL_class_declarations = 47,        /* class_declarations  */
  YYSYMBOL_class_declaration = 48,         /* class_declaration  */
  YYSYMBOL_49_1 = 49,                      /* $@1  */
  YYSYMBOL_class_block = 50,               /* class_block  */
  YYSYMBOL_class_var_section = 51,         /* class_var_section  */
  YYSYMBOL_class_methods_section = 52,     /* class_methods_section  */
  YYSYMBOL_class_create_instance = 53,     /* class_create_instance  */
  YYSYMBOL_54_2 = 54,                      /* $@2  */
  YYSYMBOL_55_3 = 55,                      /* $@3  */
  YYSYMBOL_56_4 = 56,                      /* $@4  */
  YYSYMBOL_class_access = 57,              /* class_access  */
  YYSYMBOL_class_method_call = 58,         /* class_method_call  */
  YYSYMBOL_59_5 = 59,                      /* $@5  */
  YYSYMBOL_method_call_params = 60,        /* method_call_params  */
  YYSYMBOL_method_call_param = 61,         /* method_call_param  */
  YYSYMBOL_class_var_call = 62,            /* class_var_call  */
  YYSYMBOL_global_var_section = 63,        /* global_var_section  */
  YYSYMBOL_variable_declarations = 64,     /* variable_declarations  */
  YYSYMBOL_var_decl = 65,                  /* var_decl  */
  YYSYMBOL_66_6 = 66,                      /* $@6  */
  YYSYMBOL_67_7 = 67,                      /* $@7  */
  YYSYMBOL_vector_elements = 68,           /* vector_elements  */
  YYSYMBOL_vector_element = 69,            /* vector_element  */
  YYSYMBOL_var_list = 70,                  /* var_list  */
  YYSYMBOL_global_fun_section = 71,        /* global_fun_section  */
  YYSYMBOL_function_declarations = 72,     /* function_declarations  */
  YYSYMBOL_fun_decl = 73,                  /* fun_decl  */
  YYSYMBOL_74_8 = 74,                      /* $@8  */
  YYSYMBOL_fun_decl_params = 75,           /* fun_decl_params  */
  YYSYMBOL_fun_param = 76,                 /* fun_param  */
  YYSYMBOL_fun_block = 77,                 /* fun_block  */
  YYSYMBOL_block_element = 78,             /* block_element  */
  YYSYMBOL_fun_call = 79,                  /* fun_call  */
  YYSYMBOL_80_9 = 80,                      /* $@9  */
  YYSYMBOL_fun_call_params = 81,           /* fun_call_params  */
  YYSYMBOL_fun_call_param = 82,            /* fun_call_param  */
  YYSYMBOL_print_expr = 83,                /* print_expr  */
  YYSYMBOL_print_statement = 84,           /* print_statement  */
  YYSYMBOL_statement = 85,                 /* statement  */
  YYSYMBOL_86_10 = 86,                     /* $@10  */
  YYSYMBOL_87_11 = 87,                     /* $@11  */
  YYSYMBOL_expression = 88,                /* expression  */
  YYSYMBOL_expression_elem = 89,           /* expression_elem  */
  YYSYMBOL_compare_expr = 90,              /* compare_expr  */
  YYSYMBOL_if_statement = 91,              /* if_statement  */
  YYSYMBOL_while_statement = 92,           /* while_statement  */
  YYSYMBOL_main = 93,                      /* main  */
  YYSYMBOL_main_fun_block = 94,            /* main_fun_block  */
  YYSYMBOL_main_block_element = 95         /* main_block_element  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   218

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  213

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    33,     2,     2,
      37,    38,    31,    29,    42,    30,    39,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    57,    57,    60,    61,    63,    64,    67,    66,    85,
      87,    88,    91,    92,    96,   104,   112,    95,   120,   121,
     151,   193,   192,   252,   253,   254,   259,   274,   293,   315,
     337,   365,   396,   431,   432,   435,   436,   439,   460,   482,
     481,   513,   536,   535,   570,   571,   573,   587,   608,   630,
     631,   635,   636,   640,   639,   668,   669,   670,   673,   681,
     682,   686,   687,   688,   689,   690,   691,   692,   693,   694,
     695,   701,   700,   734,   735,   736,   740,   757,   760,   772,
     771,   786,   801,   817,   816,   843,   870,   897,   900,   907,
     914,   948,   977,  1020,  1027,  1034,  1038,  1039,  1040,  1044,
    1048,  1053,  1058,  1063,  1071,  1091,  1099,  1116,  1117,  1118,
    1121,  1127,  1133,  1134,  1136,  1137,  1138,  1139,  1140,  1141,
    1142,  1143
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TYPE",
  "CLASS_SECTION", "CLASS_VAR_SECTION", "CLASS_METHODS_SECTION", "CLASS",
  "GVAR_SECTION", "GFUN_SECTION", "NEW", "ASSIGN", "IF", "ELSE", "WHILE",
  "COMPARE", "ID", "INT", "BOOL", "FLOAT", "STRING", "CHAR", "PRINT",
  "MAIN_BEGIN", "MAIN_END", "OPERATOR", "INC", "DEC", "NOT", "'+'", "'-'",
  "'*'", "'/'", "'%'", "MINUS", "'{'", "'}'", "'('", "')'", "'.'", "'['",
  "']'", "','", "';'", "$accept", "program", "class_section",
  "class_declarations", "class_declaration", "$@1", "class_block",
  "class_var_section", "class_methods_section", "class_create_instance",
  "$@2", "$@3", "$@4", "class_access", "class_method_call", "$@5",
  "method_call_params", "method_call_param", "class_var_call",
  "global_var_section", "variable_declarations", "var_decl", "$@6", "$@7",
  "vector_elements", "vector_element", "var_list", "global_fun_section",
  "function_declarations", "fun_decl", "$@8", "fun_decl_params",
  "fun_param", "fun_block", "block_element", "fun_call", "$@9",
  "fun_call_params", "fun_call_param", "print_expr", "print_statement",
  "statement", "$@10", "$@11", "expression", "expression_elem",
  "compare_expr", "if_statement", "while_statement", "main",
  "main_fun_block", "main_block_element", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-159)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-72)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      26,    24,    41,    59,    52,    24,  -159,  -159,    72,    73,
      46,  -159,    76,    72,    51,    95,    81,  -159,    -3,    64,
    -159,    86,    95,  -159,  -159,  -159,   100,  -159,    91,    93,
    -159,    74,  -159,    79,    72,    78,   104,    69,    71,    80,
    -159,  -159,    83,    87,    16,    88,  -159,    75,    85,  -159,
      92,    94,    97,  -159,  -159,  -159,    72,  -159,    95,  -159,
     -18,  -159,  -159,  -159,  -159,  -159,    69,    69,    69,  -159,
    -159,  -159,  -159,   -15,   105,    93,   112,    69,    69,  -159,
    -159,  -159,   107,   109,   113,    99,    69,  -159,  -159,  -159,
    -159,  -159,    95,   114,   121,  -159,  -159,   103,    69,  -159,
    -159,    69,    69,  -159,  -159,   126,    21,  -159,   128,   108,
     110,    69,    -2,   106,  -159,    69,   111,  -159,    40,   115,
    -159,  -159,  -159,  -159,   116,  -159,   118,   112,    69,   119,
     120,  -159,    69,  -159,  -159,   133,   122,     2,   134,    22,
    -159,  -159,  -159,   141,  -159,    69,  -159,  -159,  -159,  -159,
      62,  -159,   123,    69,  -159,  -159,  -159,   150,  -159,    69,
     124,   127,   125,  -159,     4,    35,   130,     6,    23,  -159,
    -159,    69,   146,  -159,  -159,  -159,    69,  -159,   129,   131,
     132,  -159,   135,   137,   138,  -159,  -159,   155,  -159,    69,
    -159,  -159,  -159,    69,  -159,  -159,  -159,  -159,  -159,  -159,
    -159,  -159,  -159,    11,  -159,  -159,   136,  -159,  -159,   144,
      36,  -159,  -159
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,    33,     0,     4,     5,     1,     0,    49,
       0,     6,     0,    34,     0,     0,     0,     7,    37,     0,
      35,     0,    50,    51,   112,     2,    10,    39,     0,     0,
      36,     0,    52,     0,     0,     0,    12,     0,     0,    47,
      38,    53,     0,     0,    14,     0,   111,     0,     0,    87,
       0,     0,   115,   120,   121,   113,    11,     8,     0,     9,
     103,    98,   100,    99,   102,   101,     0,     0,     0,    96,
      18,    97,    40,    95,    41,     0,    55,     0,     0,    79,
      81,    82,     0,     0,     0,     0,     0,   116,   117,   118,
     119,   114,    13,     0,     0,    88,    89,     0,     0,    93,
      94,     0,     0,    42,    48,     0,     0,    56,     0,     0,
       0,     0,    21,     0,    15,    73,     0,    77,    19,     0,
     105,    92,    90,    91,     0,    58,     0,     0,     0,     0,
       0,    80,     0,    28,    29,     0,     0,     0,     0,     0,
      74,    76,    78,     0,   104,     0,    59,    57,   106,   112,
       0,    27,     0,    23,    83,    85,    86,     0,    72,     0,
       0,     0,    44,    46,     0,     0,     0,     0,     0,    24,
      26,     0,     0,    75,    20,    43,     0,    54,     0,     0,
      64,    60,     0,     0,    62,    69,    70,   107,   110,     0,
      31,    32,    22,     0,    84,    16,    45,    65,    66,    63,
      67,    68,    61,     0,    30,    25,     0,   112,   109,     0,
       0,    17,   108
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -159,  -159,  -159,  -159,   164,  -159,  -159,  -159,  -159,     7,
    -159,  -159,  -159,  -159,   -33,  -159,  -159,   -23,  -159,  -159,
     142,   -12,  -159,  -159,     8,  -159,   117,  -159,   139,   -19,
    -159,  -159,    56,  -159,  -159,   -31,  -159,  -159,    27,  -159,
      25,    29,  -159,  -159,   -32,  -159,   140,  -158,    30,  -159,
    -145,    37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     5,     6,    26,    35,    36,    59,    47,
      84,   138,   206,    69,    70,   136,   168,   169,    49,     9,
      13,    14,    37,   124,   161,   162,    40,    16,    22,    23,
      76,   106,   107,   164,   181,    71,    85,   139,   140,   116,
      51,    52,   111,   171,   108,    73,   109,    53,    54,    25,
      33,    55
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,    19,    50,    32,   165,    72,   185,    12,    27,   132,
      98,    99,   100,   154,   101,   102,    42,   189,    43,   -71,
      44,    93,    94,    42,   133,   134,    45,    79,   155,   156,
       1,     4,   190,   191,    95,    96,    97,    28,   135,    29,
     177,     7,    80,    81,    19,   208,   207,    42,    42,    43,
      43,    44,    44,   -71,   117,    82,    83,    45,    45,   126,
     158,   192,   210,   127,   159,   193,   121,     8,    10,   122,
     123,   187,   212,    32,    42,    12,    43,   -21,    44,   131,
     143,    17,    15,   141,    45,    60,    61,    62,    63,    64,
      65,    42,    18,    43,    20,    44,   148,    66,    21,    67,
     151,    45,    31,    46,    24,    34,    68,    30,    38,    39,
      58,    41,    74,   163,    57,   105,   103,    48,    87,    50,
      77,   170,    75,   112,    78,    86,   113,   141,    88,   114,
     118,   179,    48,   182,    50,    89,   115,    90,   119,   194,
      91,   120,   125,   128,   163,   157,   129,   137,   130,   142,
     152,   145,   180,   146,   149,   150,   144,   204,   160,   153,
     172,   170,   195,   175,   167,   174,   188,   176,   203,    11,
     205,   178,   197,   209,   198,   199,    56,    48,   200,    50,
     201,   202,   211,   147,   196,     0,   173,   166,     0,   183,
       0,     0,   104,   184,   186,     0,     0,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   110
};

static const yytype_int16 yycheck[] =
{
      33,    13,    33,    22,   149,    37,   164,     3,    11,    11,
      25,    26,    27,    11,    29,    30,    12,    11,    14,    37,
      16,    39,    40,    12,    26,    27,    22,    11,    26,    27,
       4,     7,    26,    27,    66,    67,    68,    40,    40,    42,
      36,     0,    26,    27,    56,   203,    35,    12,    12,    14,
      14,    16,    16,    37,    86,    39,    40,    22,    22,    38,
      38,    38,   207,    42,    42,    42,    98,     8,    16,   101,
     102,    36,    36,    92,    12,     3,    14,    37,    16,   111,
      40,    35,     9,   115,    22,    16,    17,    18,    19,    20,
      21,    12,    16,    14,    43,    16,   128,    28,     3,    30,
     132,    22,    16,    24,    23,     5,    37,    43,    17,    16,
       6,    37,    41,   145,    36,     3,    11,   150,    43,   150,
      37,   153,    42,    16,    37,    37,    17,   159,    43,    16,
      16,   164,   165,   164,   165,    43,    37,    43,    17,   171,
      43,    38,    16,    15,   176,    11,    38,    41,    38,    38,
      17,    35,   164,    35,    35,    35,    41,   189,    17,    37,
      10,   193,    16,    36,    41,    41,    36,    42,    13,     5,
     193,   164,    43,    37,    43,    43,    34,   210,    43,   210,
      43,    43,    38,   127,   176,    -1,   159,   150,    -1,   164,
      -1,    -1,    75,   164,   164,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    45,    46,     7,    47,    48,     0,     8,    63,
      16,    48,     3,    64,    65,     9,    71,    35,    16,    65,
      43,     3,    72,    73,    23,    93,    49,    11,    40,    42,
      43,    16,    73,    94,     5,    50,    51,    66,    17,    16,
      70,    37,    12,    14,    16,    22,    24,    53,    58,    62,
      79,    84,    85,    91,    92,    95,    64,    36,     6,    52,
      16,    17,    18,    19,    20,    21,    28,    30,    37,    57,
      58,    79,    88,    89,    41,    42,    74,    37,    37,    11,
      26,    27,    39,    40,    54,    80,    37,    43,    43,    43,
      43,    43,    72,    39,    40,    88,    88,    88,    25,    26,
      27,    29,    30,    11,    70,     3,    75,    76,    88,    90,
      90,    86,    16,    17,    16,    37,    83,    88,    16,    17,
      38,    88,    88,    88,    67,    16,    38,    42,    15,    38,
      38,    88,    11,    26,    27,    40,    59,    41,    55,    81,
      82,    88,    38,    40,    41,    35,    35,    76,    88,    35,
      35,    88,    17,    37,    11,    26,    27,    11,    38,    42,
      17,    68,    69,    88,    77,    94,    95,    41,    60,    61,
      88,    87,    10,    82,    41,    36,    42,    36,    53,    58,
      65,    78,    79,    84,    85,    91,    92,    36,    36,    11,
      26,    27,    38,    42,    88,    16,    68,    43,    43,    43,
      43,    43,    43,    13,    88,    61,    56,    35,    91,    37,
      94,    38,    36
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    49,    48,    50,
      51,    51,    52,    52,    54,    55,    56,    53,    57,    57,
      57,    59,    58,    60,    60,    60,    61,    62,    62,    62,
      62,    62,    62,    63,    63,    64,    64,    65,    65,    66,
      65,    65,    67,    65,    68,    68,    69,    70,    70,    71,
      71,    72,    72,    74,    73,    75,    75,    75,    76,    77,
      77,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    80,    79,    81,    81,    81,    82,    83,    84,    86,
      85,    85,    85,    87,    85,    85,    85,    85,    88,    88,
      88,    88,    88,    88,    88,    88,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    90,    91,    91,    91,
      92,    93,    94,    94,    95,    95,    95,    95,    95,    95,
      95,    95
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     0,     2,     1,     2,     0,     6,     2,
       0,     2,     0,     2,     0,     0,     0,    10,     1,     3,
       6,     0,     7,     0,     1,     3,     1,     5,     4,     4,
       8,     7,     7,     0,     2,     2,     3,     2,     4,     0,
       5,     5,     0,    10,     1,     3,     1,     1,     3,     0,
       2,     1,     2,     0,     9,     0,     1,     3,     2,     0,
       2,     2,     1,     2,     1,     2,     2,     2,     2,     1,
       1,     0,     5,     0,     1,     3,     1,     1,     4,     0,
       4,     2,     2,     0,     7,     5,     5,     1,     2,     2,
       3,     3,     3,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     3,     3,     7,    11,     9,
       7,     3,     0,     2,     2,     1,     2,     2,     2,     2,
       1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: class_section global_var_section global_fun_section main  */
#line 57 "limbaj.y"
                                                                   {if(errorCount==0) cout<<endl<<"The program is correct!\n";}
#line 1342 "limbaj.tab.c"
    break;

  case 3: /* class_section: %empty  */
#line 60 "limbaj.y"
                {std::cout<<endl<<"No classes"<<endl;}
#line 1348 "limbaj.tab.c"
    break;

  case 7: /* $@1: %empty  */
#line 67 "limbaj.y"
                {
                        if(currentScope->addClass((yyvsp[-1].stringVal))==true){
                                currentScope = currentScope->enterScope((yyvsp[-1].stringVal));  //intram in scope ul clasei
                        } else {
                                string msg="The class "+string((yyvsp[-1].stringVal))+" already exists";
                                yyerror(msg.c_str());
                        }
                        globalScope->childScopes.push_back(currentScope);
                }
#line 1362 "limbaj.tab.c"
    break;

  case 8: /* class_declaration: CLASS ID '{' $@1 class_block '}'  */
#line 79 "limbaj.y"
                {
                        currentScope = currentScope->exitScope(); //iesin din scope ul clasei
                        parentScope = currentScope;
                }
#line 1371 "limbaj.tab.c"
    break;

  case 10: /* class_var_section: %empty  */
#line 87 "limbaj.y"
                    {std::cout<<endl<<"No variables"<<endl;}
#line 1377 "limbaj.tab.c"
    break;

  case 12: /* class_methods_section: %empty  */
#line 91 "limbaj.y"
                        {std::cout<<endl<<"No methods"<<endl;}
#line 1383 "limbaj.tab.c"
    break;

  case 14: /* $@2: %empty  */
#line 96 "limbaj.y"
                        {
                        if(find(globalScope->classes.begin(),globalScope->classes.end(),(yyvsp[0].stringVal))==globalScope->classes.end()){
                                string msg="The class "+string((yyvsp[0].stringVal))+" doesn't exists";
                                yyerror(msg.c_str());
                        }

                        }
#line 1395 "limbaj.tab.c"
    break;

  case 15: /* $@3: %empty  */
#line 104 "limbaj.y"
                         {
                                if(currentScope->addVariable((yyvsp[0].stringVal),(yyvsp[-2].stringVal))==false){
                                string msg="The class name"+string((yyvsp[0].stringVal))+" doesn't exists";
                                        yyerror(msg.c_str());
                                }
                         }
#line 1406 "limbaj.tab.c"
    break;

  case 16: /* $@4: %empty  */
#line 112 "limbaj.y"
                          {
                                if(string((yyvsp[-6].stringVal))!=string((yyvsp[0].stringVal))){
                                        yyerror("Type mismatch: cannot instantiate class with a different constructor type");
                                }
                          }
#line 1416 "limbaj.tab.c"
    break;

  case 19: /* class_access: ID '.' ID  */
#line 122 "limbaj.y"
            {
                if(currentScope->searchVariable((yyvsp[-2].stringVal))==nullopt){
                                string msg="the class instance "+string((yyvsp[-2].stringVal))+" doesn't exist";
                                yyerror(msg.c_str());
                        }
                        if(currentScope->classExists(currentScope->getType((yyvsp[-2].stringVal)))==false){ //daca tipul este o clasa existenta, ca sa nu pot face int.ceva
                                string msg="the variable "+string((yyvsp[-2].stringVal))+"isn't a class instance";
                                yyerror(msg.c_str());
                        }

                string classType = currentScope->getType((yyvsp[-2].stringVal));
                auto var=currentScope->searchVariableInClass(classType,(yyvsp[0].stringVal),globalScope);
                if(var.has_value()){
                        auto [tip,valoarea,clasa] = var.value();
                        if(clasa.has_value()){  //daca este o variabila de clasa
                                string cls = clasa.value();
                                if(cls!=classType){
                                        string msg="the variable"+string((yyvsp[0].stringVal))+"is in a different class";
                                        yyerror(msg.c_str());
                                } else {
                                   (yyval.stringVal) = strdup(tip.c_str());
                                }
                        }
                } else {
                        string msg="The class variable "+string((yyvsp[0].stringVal))+" doesn't exist";
                    yyerror(msg.c_str());
                }
                
            }
#line 1450 "limbaj.tab.c"
    break;

  case 20: /* class_access: ID '.' ID '[' INT ']'  */
#line 152 "limbaj.y"
            {
                if(currentScope->searchVariable((yyvsp[-5].stringVal))==nullopt){
                                string msg="the class instance "+string((yyvsp[-5].stringVal))+" doesn't exist";
                                yyerror(msg.c_str());
                        }
                        if(currentScope->classExists(currentScope->getType((yyvsp[-5].stringVal)))==false){ //daca tipul este o clasa existenta, ca sa nu pot face int.ceva
                                string msg="the variable "+string((yyvsp[-5].stringVal))+"isn't a class instance";
                                yyerror(msg.c_str());
                        }

                string classType = currentScope->getType((yyvsp[-5].stringVal));
                auto var=currentScope->searchVectorInClass(classType,(yyvsp[-3].stringVal),globalScope);
                if(var.has_value()){
                        auto [tip,numberElements,valori,clasa] = var.value();
                        if(clasa.has_value()){  //daca este o variabila de clasa
                                string cls = clasa.value();
                                 if((yyvsp[-1].intVal)>=numberElements){
                                        string msg = "Tried accesing vector index "+ to_string((yyvsp[-1].intVal)) +" that doens't exist (the maximum elements for the vector is "+to_string(numberElements-1)+")";
                                        yyerror(msg.c_str());
                                }
                                if((yyvsp[-1].intVal)<0){
                                        string msg = "Tried accesing vector index "+ to_string((yyvsp[-1].intVal)) +" that doens't exist (the index can't be negative!)";
                                        yyerror(msg.c_str());
                                }
                                if(cls!=classType){
                                        string msg="the vector"+string((yyvsp[-3].stringVal))+"is in a different class";
                                        yyerror(msg.c_str());
                                } else {
                                   (yyval.stringVal) = strdup(tip.c_str());
                                }
                        }
                } else {
                        string msg="The class vector "+string((yyvsp[-3].stringVal))+" doesn't exist";
                    yyerror(msg.c_str());
                }
                
            }
#line 1492 "limbaj.tab.c"
    break;

  case 21: /* $@5: %empty  */
#line 193 "limbaj.y"
                  {
                        if(currentScope->searchVariable((yyvsp[-2].stringVal))==nullopt){
                                string msg="The class variable "+string((yyvsp[-2].stringVal))+" doesn't exist!";
                                yyerror(msg.c_str());
                        }
                        if(currentScope->classExists(currentScope->getType((yyvsp[-2].stringVal)))==false){ //daca tipul este o clasa existenta, ca sa nu pot face int.ceva
                                yyerror("Tried calling a method on a non-class variable");
                        }

                        cout<<"Searching for method "<<(yyvsp[0].stringVal)<<endl;
                        
                        string classType = currentScope->getType((yyvsp[-2].stringVal));
                        auto fun=currentScope->searchMethodInClass(classType,(yyvsp[0].stringVal),globalScope);
                        if(fun.has_value()){
                                auto [tip,params,clasa] = fun.value();
                                if(clasa.has_value()){  //daca este o metoda
                                        string cls = clasa.value();
                                        if(cls!=classType){
                                                string msg="The method "+string((yyvsp[0].stringVal))+" is in a different class!";
                                                yyerror(msg.c_str());
                                        }
                                } else {
                                        string msg="Tried calling method "+string((yyvsp[0].stringVal))+" , but it's a function!";
                                        yyerror(msg.c_str());
                                }
                        } else {
                                string msg="The method "+string((yyvsp[0].stringVal))+" doesn't exist!";
                                yyerror(msg.c_str());
                        }
                        aux=globalScope->getChildScope(classType);
                        if(aux==nullptr){
                                yyerror("didn't find child scope succesfuly");
                        }
                        calling_functions.push((yyvsp[0].stringVal));
                        param_counts.push(0);
                  }
#line 1533 "limbaj.tab.c"
    break;

  case 22: /* class_method_call: ID '.' ID $@5 '(' method_call_params ')'  */
#line 230 "limbaj.y"
                  {
                        string current_fun = calling_functions.top();
                        int total_params = param_counts.top();

                        if(aux->verifParamNumber(current_fun, total_params) == false){
                                string msg="The method "+current_fun+" doesn't have the correct number of parameters";
                                yyerror(msg.c_str());
                        }

                       
                        calling_functions.pop();
                        param_counts.pop();

                        auto fun = aux->searchFunction((yyvsp[-4].stringVal));
                        if(fun==nullopt){
                                yyerror("error at finding method");
                        }
                        string tip = std::get<0>(fun.value());
                        (yyval.stringVal) = strdup(tip.c_str()); //returnez tipul
                  }
#line 1558 "limbaj.tab.c"
    break;

  case 26: /* method_call_param: expression  */
#line 260 "limbaj.y"
            {
                string c_fun = calling_functions.top();
                int c_idx = param_counts.top();
                
                if(aux->verifParamType(c_fun, c_idx, (yyvsp[0].stringVal)) == false){
                    string msg = "Parameter " + to_string(c_idx) + " in " + c_fun + " is of type " + (yyvsp[0].stringVal) + " but should be different.";
                    yyerror(msg.c_str());
                }
                param_counts.top()++;
                free((yyvsp[0].stringVal));
            }
#line 1574 "limbaj.tab.c"
    break;

  case 27: /* class_var_call: ID '.' ID ASSIGN expression  */
#line 275 "limbaj.y"
                {
                auto varObj = currentScope->searchVariable((yyvsp[-4].stringVal));
                if (!varObj.has_value()) {
                        string msg = "Object '" + string((yyvsp[-4].stringVal)) + "' is not declared.";
                        yyerror(msg.c_str());
                }
                string className = currentScope->getType((yyvsp[-4].stringVal));
                auto var = currentScope->searchVariableInClass(className, (yyvsp[-2].stringVal), globalScope);
                if(var.has_value()) {
                string memberType = get<0>(var.value());
                string exprType = (yyvsp[0].stringVal);
                if(memberType != exprType) {
                        string msg = "Cannot assign [" + exprType + "] to member '" + string((yyvsp[-4].stringVal)) + "." + string((yyvsp[-2].stringVal)) + "' of type [" + memberType + "]";
                        yyerror(msg.c_str());
                }
                }
                free((yyvsp[0].stringVal));
                }
#line 1597 "limbaj.tab.c"
    break;

  case 28: /* class_var_call: ID '.' ID INC  */
#line 294 "limbaj.y"
            {
                auto varObj = currentScope->searchVariable((yyvsp[-3].stringVal));
                if (!varObj.has_value()) {
                        string msg = "Object '" + string((yyvsp[-3].stringVal)) + "' is not declared.";
                        yyerror(msg.c_str());
                }
                string className = currentScope->getType((yyvsp[-3].stringVal));
                auto var = currentScope->searchVariableInClass(className, (yyvsp[-1].stringVal), globalScope);
                
                if(var.has_value()) {
                string memberType = std::get<0>(var.value());
                if(memberType != "int" && memberType != "float") {
                        string msg = "Cannot increment member '" + string((yyvsp[-3].stringVal)) + "." + string((yyvsp[-1].stringVal)) + 
                                "' because it is of type [" + memberType + "] (not numeric)";
                        yyerror(msg.c_str());
                }
                } else {
                string msg = "Class member '" + string((yyvsp[-1].stringVal)) + "' not found in class '" + className + "'";
                yyerror(msg.c_str());
                }
            }
#line 1623 "limbaj.tab.c"
    break;

  case 29: /* class_var_call: ID '.' ID DEC  */
#line 316 "limbaj.y"
            {
                auto varObj = currentScope->searchVariable((yyvsp[-3].stringVal));
                if (!varObj.has_value()) {
                        string msg = "Object '" + string((yyvsp[-3].stringVal)) + "' is not declared.";
                        yyerror(msg.c_str());
                }
                string className = currentScope->getType((yyvsp[-3].stringVal));
                auto var = currentScope->searchVariableInClass(className, (yyvsp[-1].stringVal), globalScope);
                
                if(var.has_value()) {
                string memberType = std::get<0>(var.value());
                if(memberType != "int" && memberType != "float") {
                        string msg = "Cannot decrement member '" + string((yyvsp[-3].stringVal)) + "." + string((yyvsp[-1].stringVal)) + 
                                "' because it is of type [" + memberType + "] (not numeric)";
                        yyerror(msg.c_str());
                }
                } else {
                string msg = "Class member '" + string((yyvsp[-1].stringVal)) + "' not found in class '" + className + "'";
                yyerror(msg.c_str());
                }
            }
#line 1649 "limbaj.tab.c"
    break;

  case 30: /* class_var_call: ID '.' ID '[' INT ']' ASSIGN expression  */
#line 338 "limbaj.y"
                {
                auto varObj = currentScope->searchVariable((yyvsp[-7].stringVal));
                if (!varObj.has_value()) {
                        string msg = "Object '" + string((yyvsp[-7].stringVal)) + "' is not declared.";
                        yyerror(msg.c_str());
                }
                string className = currentScope->getType((yyvsp[-7].stringVal));
                auto var = currentScope->searchVectorInClass(className, (yyvsp[-5].stringVal), globalScope);
                if(var.has_value()) {
                int numberElements = get<1>(var.value());
                if((yyvsp[-3].intVal)>=numberElements){
                        string msg = "Tried accesing vector index "+ to_string((yyvsp[-3].intVal)) +" that doens't exist (the maximum elements for the vector is "+to_string(numberElements-1)+")";
                        yyerror(msg.c_str());
                }
                if((yyvsp[-3].intVal)<0){
                        string msg = "Tried accesing vector index "+ to_string((yyvsp[-3].intVal)) +" that doens't exist (the index can't be negative!)";
                        yyerror(msg.c_str());
                }
                string memberType = get<0>(var.value());
                string exprType = (yyvsp[0].stringVal);
                if(memberType != exprType) {
                        string msg = "Cannot assign [" + exprType + "] to member '" + string((yyvsp[-7].stringVal)) + "." + string((yyvsp[-5].stringVal)) + "' of type [" + memberType + "]";
                        yyerror(msg.c_str());
                }
                }
                free((yyvsp[0].stringVal));
                }
#line 1681 "limbaj.tab.c"
    break;

  case 31: /* class_var_call: ID '.' ID '[' INT ']' INC  */
#line 366 "limbaj.y"
            {
                auto varObj = currentScope->searchVariable((yyvsp[-6].stringVal));
                if (!varObj.has_value()) {
                        string msg = "Object '" + string((yyvsp[-6].stringVal)) + "' is not declared.";
                        yyerror(msg.c_str());
                }
                string className = currentScope->getType((yyvsp[-6].stringVal));
                auto var = currentScope->searchVectorInClass(className, (yyvsp[-4].stringVal), globalScope);
                
                if(var.has_value()) {
                 int numberElements = get<1>(var.value());
                if((yyvsp[-2].intVal)>=numberElements){
                        string msg = "Tried accesing vector index "+ to_string((yyvsp[-2].intVal)) +" that doens't exist (the maximum elements for the vector is "+to_string(numberElements-1)+")";
                        yyerror(msg.c_str());
                }
                if((yyvsp[-2].intVal)<0){
                        string msg = "Tried accesing vector index "+ to_string((yyvsp[-2].intVal)) +" that doens't exist (the index can't be negative!)";
                        yyerror(msg.c_str());
                }
                string memberType = std::get<0>(var.value());
                if(memberType != "int" && memberType != "float") {
                        string msg = "Cannot increment member '" + string((yyvsp[-6].stringVal)) + "." + string((yyvsp[-4].stringVal)) + 
                                "' because it is of type [" + memberType + "] (not numeric)";
                        yyerror(msg.c_str());
                }
                } else {
                string msg = "Class member '" + string((yyvsp[-4].stringVal)) + "' not found in class '" + className + "'";
                yyerror(msg.c_str());
                }
            }
#line 1716 "limbaj.tab.c"
    break;

  case 32: /* class_var_call: ID '.' ID '[' INT ']' DEC  */
#line 397 "limbaj.y"
            {
                auto varObj = currentScope->searchVariable((yyvsp[-6].stringVal));
                if (!varObj.has_value()) {
                        string msg = "Object '" + string((yyvsp[-6].stringVal)) + "' is not declared.";
                        yyerror(msg.c_str());
                }
                string className = currentScope->getType((yyvsp[-6].stringVal));
                auto var = currentScope->searchVectorInClass(className, (yyvsp[-4].stringVal), globalScope);
                
                if(var.has_value()) {
                 int numberElements = get<1>(var.value());
                if((yyvsp[-2].intVal)>=numberElements){
                        string msg = "Tried accesing vector index "+ to_string((yyvsp[-2].intVal)) +" that doens't exist (the maximum elements for the vector is "+to_string(numberElements-1)+")";
                        yyerror(msg.c_str());
                }
                if((yyvsp[-2].intVal)<0){
                        string msg = "Tried accesing vector index "+ to_string((yyvsp[-2].intVal)) +" that doens't exist (the index can't be negative!)";
                        yyerror(msg.c_str());
                }
                string memberType = std::get<0>(var.value());
                if(memberType != "int" && memberType != "float") {
                        string msg = "Cannot decrement member '" + string((yyvsp[-6].stringVal)) + "." + string((yyvsp[-4].stringVal)) + 
                                "' because it is of type [" + memberType + "] (not numeric)";
                        yyerror(msg.c_str());
                }
                } else {
                string msg = "Class member '" + string((yyvsp[-4].stringVal)) + "' not found in class '" + className + "'";
                yyerror(msg.c_str());
                }
            }
#line 1751 "limbaj.tab.c"
    break;

  case 33: /* global_var_section: %empty  */
#line 431 "limbaj.y"
                    {std::cout<<endl<<"No global variables"<<endl;}
#line 1757 "limbaj.tab.c"
    break;

  case 37: /* var_decl: TYPE ID  */
#line 440 "limbaj.y"
        {
               optional<string> className = nullopt;

               if(currentScope != nullptr && currentScope->parentScope != nullptr) {
                  string parentName = currentScope->name;
            
                  auto& classes = globalScope->classes;
                  if(find(classes.begin(), classes.end(), parentName) != classes.end()) {
                     className = parentName;
                        cout<<"added function "<<(yyvsp[0].stringVal)<<" to class "<<parentName<<endl;
                  }
                }
                if(currentScope->addVariable((yyvsp[0].stringVal),(yyvsp[-1].stringVal),nullopt,className)){
                        currentVarName= (yyvsp[0].stringVal);
                        currentVarType = (yyvsp[-1].stringVal);
                } else {
                        string msg="Variable "+string((yyvsp[0].stringVal)) + " already declared!";
                        yyerror(msg.c_str());
                }
        }
#line 1782 "limbaj.tab.c"
    break;

  case 38: /* var_decl: TYPE ID ',' var_list  */
#line 461 "limbaj.y"
            {
                optional<string> className = nullopt;

               if(currentScope != nullptr && currentScope->parentScope != nullptr) {
                  string parentName = currentScope->name;
            
                  auto& classes = globalScope->classes;
                  if(find(classes.begin(), classes.end(), parentName) != classes.end()) {
                     className = parentName;
                        cout<<"added function "<<(yyvsp[-2].stringVal)<<" to class "<<parentName<<endl;
                  }
                }
                if(currentScope->addVariable((yyvsp[-2].stringVal),(yyvsp[-3].stringVal),nullopt,className)){
                        currentVarName= (yyvsp[-2].stringVal);
                        currentVarType = (yyvsp[-3].stringVal);
                } else {
                        string msg="Variable "+string((yyvsp[-2].stringVal)) + " already declared!";
                        yyerror(msg.c_str());
                }
            }
#line 1807 "limbaj.tab.c"
    break;

  case 39: /* $@6: %empty  */
#line 482 "limbaj.y"
            {
                optional<string> className = nullopt;

               if(currentScope != nullptr && currentScope->parentScope != nullptr) {
                  string parentName = currentScope->name;
            
                  auto& classes = globalScope->classes;
                  if(find(classes.begin(), classes.end(), parentName) != classes.end()) {
                     className = parentName;
                        cout<<"added function "<<(yyvsp[-1].stringVal)<<" to class "<<parentName<<endl;
                  }
                }
                if(currentScope->addVariable((yyvsp[-1].stringVal),(yyvsp[-2].stringVal),nullopt,className)){
                        currentVarName= (yyvsp[-1].stringVal);
                        currentVarType = (yyvsp[-2].stringVal);
                } else {
                        string msg="Variable "+string((yyvsp[-1].stringVal)) + " already declared!";
                        yyerror(msg.c_str());
                }                
            }
#line 1832 "limbaj.tab.c"
    break;

  case 40: /* var_decl: TYPE ID ASSIGN $@6 expression  */
#line 503 "limbaj.y"
             {
                string typeVarToBeAssigned=(yyvsp[-4].stringVal);
                string typeExpr=(yyvsp[0].stringVal);
                if(typeVarToBeAssigned!=typeExpr){
                        string msg="Type mismatch at declaration, trying operation on ["+typeVarToBeAssigned+"] and ["+typeExpr+"]";
                        yyerror(msg.c_str());
                }
                cout<<"TYPE TO ASSIGN: "<<typeVarToBeAssigned<<endl;
                free((yyvsp[0].stringVal));
             }
#line 1847 "limbaj.tab.c"
    break;

  case 41: /* var_decl: TYPE ID '[' INT ']'  */
#line 514 "limbaj.y"
             {
                 optional<string> className = nullopt;

               if(currentScope != nullptr && currentScope->parentScope != nullptr) {
                  string parentName = currentScope->name;
            
                  auto& classes = globalScope->classes;
                  if(find(classes.begin(), classes.end(), parentName) != classes.end()) {
                     className = parentName;
                        cout<<"added Vector "<<(yyvsp[-3].stringVal)<<" to class "<<parentName<<endl;
                  }
                }
                if(currentScope->addVector((yyvsp[-3].stringVal),(yyvsp[-4].stringVal),(yyvsp[-1].intVal),nullopt,className)){
                        currentVarName= (yyvsp[-3].stringVal);
                        currentVarType = (yyvsp[-4].stringVal);
                } else {
                        string msg="Vecotr "+string((yyvsp[-3].stringVal)) + " already declared!";
                        yyerror(msg.c_str());
                }

             }
#line 1873 "limbaj.tab.c"
    break;

  case 42: /* $@7: %empty  */
#line 536 "limbaj.y"
             {
                 optional<string> className = nullopt;

               if(currentScope != nullptr && currentScope->parentScope != nullptr) {
                  string parentName = currentScope->name;
            
                  auto& classes = globalScope->classes;
                  if(find(classes.begin(), classes.end(), parentName) != classes.end()) {
                     className = parentName;
                        cout<<"added Vector "<<(yyvsp[-4].stringVal)<<" to class "<<parentName<<endl;
                  }
                }
                numberOfElementsToAdd=(yyvsp[-2].intVal);
                if(currentScope->addVector((yyvsp[-4].stringVal),(yyvsp[-5].stringVal),numberOfElementsToAdd,nullopt,className)){
                        currentVarName= (yyvsp[-4].stringVal);
                        currentVarType = (yyvsp[-5].stringVal);
                } else {
                        string msg="Vecotr "+string((yyvsp[-4].stringVal)) + " already declared!";
                        yyerror(msg.c_str());
                }

                numberOfElementsToAdd=(yyvsp[-2].intVal);
                cout<<"NUMBER OF ELEMENTS TO ADD "<<numberOfElementsToAdd<<endl;

             }
#line 1903 "limbaj.tab.c"
    break;

  case 43: /* var_decl: TYPE ID '[' INT ']' ASSIGN $@7 '{' vector_elements '}'  */
#line 562 "limbaj.y"
              {
                if(numberOfElementsToAdd>0){
                       string msg="Vector init received too few arguments";
                        yyerror(msg.c_str());  
                }
              }
#line 1914 "limbaj.tab.c"
    break;

  case 46: /* vector_element: expression  */
#line 574 "limbaj.y"
                {
                        if(numberOfElementsToAdd<=0){
                                string msg="Vector init received too many arguments";
                                yyerror(msg.c_str());
                        }
                        if(string((yyvsp[0].stringVal))!=string(currentVarType)){
                                string msg="Tried adding a variable of type "+ string((yyvsp[0].stringVal)) + " to a vector of type "+string(currentVarType);
                                yyerror(msg.c_str());
                        }
                        numberOfElementsToAdd--;
                        //should add value to vector<string> here
                }
#line 1931 "limbaj.tab.c"
    break;

  case 47: /* var_list: ID  */
#line 588 "limbaj.y"
                {
                        optional<string> className = nullopt;

                        if(currentScope != nullptr && currentScope->parentScope != nullptr) {
                        string parentName = currentScope->name;
                
                        auto& classes = globalScope->classes;
                        if(find(classes.begin(), classes.end(), parentName) != classes.end()) {
                        className = parentName;
                                cout<<"added variable "<<(yyvsp[0].stringVal)<<" to class "<<parentName<<endl;
                        }
                        }
                        if(currentScope->addVariable((yyvsp[0].stringVal),currentVarType,nullopt,className)){
                                currentVarName=(yyvsp[0].stringVal);
                        } else {
                                string msg="Variable "+string((yyvsp[0].stringVal)) + " already declared!";
                                yyerror(msg.c_str());
                        }
 
                }
#line 1956 "limbaj.tab.c"
    break;

  case 48: /* var_list: ID ',' var_list  */
#line 609 "limbaj.y"
                {
                        optional<string> className = nullopt;

                        if(currentScope != nullptr && currentScope->parentScope != nullptr) {
                        string parentName = currentScope->name;
                
                        auto& classes = globalScope->classes;
                        if(find(classes.begin(), classes.end(), parentName) != classes.end()) {
                        className = parentName;
                                cout<<"added variable "<<(yyvsp[-2].stringVal)<<" to class "<<parentName<<endl;
                        }
                        }
                        if(currentScope->addVariable((yyvsp[-2].stringVal),currentVarType,nullopt,className)){
                                currentVarName = (yyvsp[-2].stringVal);
                        } else {
                                string msg="Variable "+string((yyvsp[-2].stringVal)) + " already declared!";
                                yyerror(msg.c_str());
                        }
                }
#line 1980 "limbaj.tab.c"
    break;

  case 49: /* global_fun_section: %empty  */
#line 630 "limbaj.y"
                     {std::cout<<endl<<"No global functions"<<endl;}
#line 1986 "limbaj.tab.c"
    break;

  case 53: /* $@8: %empty  */
#line 640 "limbaj.y"
        {
               optional<string> className = nullopt;

               if(currentScope != nullptr && currentScope->parentScope != nullptr) {
                  string parentName = currentScope->name;
            
                  auto& classes = globalScope->classes;
                  if(find(classes.begin(), classes.end(), parentName) != classes.end()) {
                     className = parentName;
                        cout<<"added function "<<(yyvsp[-1].stringVal)<<" to class "<<parentName<<endl;
                  }
                }

                if(currentScope->addFunction((yyvsp[-1].stringVal), (yyvsp[-2].stringVal), nullopt, className)==false){
                        string msg="Function or method "+string((yyvsp[-1].stringVal))+" already declared!";
                        yyerror(msg.c_str());
                }

                funName = (yyvsp[-1].stringVal);
                parentScope = currentScope;
                currentScope = currentScope->enterScope((yyvsp[-1].stringVal));
        }
#line 2013 "limbaj.tab.c"
    break;

  case 54: /* fun_decl: TYPE ID '(' $@8 fun_decl_params ')' '{' fun_block '}'  */
#line 663 "limbaj.y"
         {
                currentScope = currentScope->exitScope();
                parentScope = currentScope;
         }
#line 2022 "limbaj.tab.c"
    break;

  case 58: /* fun_param: TYPE ID  */
#line 674 "limbaj.y"
        {
                parentScope->setFunctionParams(funName,(yyvsp[-1].stringVal));
                cout<<"adding variable "<<(yyvsp[0].stringVal)<<"to scope "<<currentScope->name<<endl;
                currentScope->addVariable((yyvsp[0].stringVal),(yyvsp[-1].stringVal));
        }
#line 2032 "limbaj.tab.c"
    break;

  case 62: /* block_element: statement  */
#line 687 "limbaj.y"
                        { yyerror("Missing semicolon");}
#line 2038 "limbaj.tab.c"
    break;

  case 64: /* block_element: var_decl  */
#line 689 "limbaj.y"
                       { yyerror("Missing semicolon");}
#line 2044 "limbaj.tab.c"
    break;

  case 71: /* $@9: %empty  */
#line 701 "limbaj.y"
        {
                if(currentScope->searchFunction((yyvsp[0].stringVal))==nullopt){
                        string msg="The called function "+string((yyvsp[0].stringVal)) +" doesn't exist!";
                        yyerror(msg.c_str());
                } else {
                        calling_functions.push((yyvsp[0].stringVal));
                        param_counts.push(0);
                }

        }
#line 2059 "limbaj.tab.c"
    break;

  case 72: /* fun_call: ID $@9 '(' fun_call_params ')'  */
#line 713 "limbaj.y"
        {
                string current_fun = calling_functions.top();
                int total_params = param_counts.top();

                if(currentScope->verifParamNumber(current_fun, total_params) == false){
                        string msg="The function call "+current_fun+" doesn't have the correct number of parameters";
                        yyerror(msg.c_str());
                }

                calling_functions.pop();
                param_counts.pop();

                auto fun = currentScope->searchFunction((yyvsp[-4].stringVal));
                if(fun==nullopt){
                        yyerror("error at finding functiion");
                }
                string tip = std::get<0>(fun.value());
                (yyval.stringVal) = strdup(tip.c_str()); //returnez tipul
        }
#line 2083 "limbaj.tab.c"
    break;

  case 76: /* fun_call_param: expression  */
#line 741 "limbaj.y"
            {
                string c_fun = calling_functions.top();
                int c_idx = param_counts.top();
                
                if(currentScope->verifParamType(c_fun, c_idx, (yyvsp[0].stringVal)) == false){
                    string msg = "Parameter " + to_string(c_idx) + " in " + c_fun + " is of type " + (yyvsp[0].stringVal) + " but should be different.";
                    yyerror(msg.c_str());
                }
                param_counts.top()++;
                free((yyvsp[0].stringVal));
            }
#line 2099 "limbaj.tab.c"
    break;

  case 78: /* print_statement: PRINT '(' print_expr ')'  */
#line 760 "limbaj.y"
                                           {cout<<endl<<(yyvsp[-1].stringVal)<<endl;
        free((yyvsp[-1].stringVal));
        }
#line 2107 "limbaj.tab.c"
    break;

  case 79: /* $@10: %empty  */
#line 772 "limbaj.y"
        {
                if(currentScope->searchVariable((yyvsp[-1].stringVal))==nullopt){
                        string msg="The variable "+string((yyvsp[-1].stringVal))+" doesn't exist!";
                        yyerror(msg.c_str());
                }
        }
#line 2118 "limbaj.tab.c"
    break;

  case 80: /* statement: ID ASSIGN $@10 expression  */
#line 778 "limbaj.y"
                    {
                string typeVarToBeAssigned=currentScope->getType((yyvsp[-3].stringVal));
                if(typeVarToBeAssigned!=string((yyvsp[0].stringVal))){
                        string msg="Type mismatch at assignment, trying operation on ["+typeVarToBeAssigned+"] and ["+string((yyvsp[0].stringVal))+"]";
                        yyerror(msg.c_str());
                }
                free((yyvsp[0].stringVal));
         }
#line 2131 "limbaj.tab.c"
    break;

  case 81: /* statement: ID INC  */
#line 787 "limbaj.y"
        {
                if(currentScope->searchVariable((yyvsp[-1].stringVal))==nullopt){
                        string msg="The variable "+string((yyvsp[-1].stringVal))+" doesn't exist!";
                        yyerror(msg.c_str());
                }
                string typeVarToBeAssigned=currentScope->getType((yyvsp[-1].stringVal));
                cout<<"TYPE TO ASSIGN: "<<typeVarToBeAssigned<<endl;
                if(typeVarToBeAssigned=="int" || typeVarToBeAssigned=="float"){
                        //change value
                } else {
                        string msg="The variable "+string((yyvsp[-1].stringVal))+ " isn't a float or an int, you can't increment it!";
                        yyerror(msg.c_str());
                }
        }
#line 2150 "limbaj.tab.c"
    break;

  case 82: /* statement: ID DEC  */
#line 802 "limbaj.y"
        {
                if(currentScope->searchVariable((yyvsp[-1].stringVal))==nullopt){
                        string msg="The variable "+string((yyvsp[-1].stringVal))+" doesn't exist!";
                        yyerror(msg.c_str());
                }
                string typeVarToBeAssigned=currentScope->getType((yyvsp[-1].stringVal));
                cout<<"TYPE TO ASSIGN: "<<typeVarToBeAssigned<<endl;
                if(typeVarToBeAssigned=="int" || typeVarToBeAssigned=="float"){
                        //change value
                } else {
                        string msg="The variable "+string((yyvsp[-1].stringVal))+ " isn't a float or an int, you can't increment it!";
                        yyerror(msg.c_str());
                }
        }
#line 2169 "limbaj.tab.c"
    break;

  case 83: /* $@11: %empty  */
#line 817 "limbaj.y"
        {
                auto var=currentScope->searchVector((yyvsp[-4].stringVal));
                if(var.has_value()){
                        int numberElements= get<1>(var.value());
                        if((yyvsp[-2].intVal)>=numberElements){
                        string msg = "Tried accesing vector index "+ to_string((yyvsp[-2].intVal)) +" that doens't exist (the maximum elements for the vector is "+to_string(numberElements-1)+")";
                        yyerror(msg.c_str());
                        }
                          if((yyvsp[-2].intVal)<0){
                        string msg = "Tried accesing vector index "+ to_string((yyvsp[-2].intVal)) +" that doens't exist (the index can't be negative!)";
                        yyerror(msg.c_str());
                        }
                }
                if(var==nullopt){
                        string msg="The vector "+string((yyvsp[-4].stringVal))+" doesn't exist!";
                        yyerror(msg.c_str());
                }
        }
#line 2192 "limbaj.tab.c"
    break;

  case 84: /* statement: ID '[' INT ']' ASSIGN $@11 expression  */
#line 835 "limbaj.y"
                    {
                string typeVarToBeAssigned=currentScope->getType((yyvsp[-6].stringVal));
                if(typeVarToBeAssigned!=string((yyvsp[0].stringVal))){
                        string msg="Type mismatch at assignment, trying operation on ["+typeVarToBeAssigned+"] and ["+string((yyvsp[0].stringVal))+"]";
                        yyerror(msg.c_str());
                }
                free((yyvsp[0].stringVal));
         }
#line 2205 "limbaj.tab.c"
    break;

  case 85: /* statement: ID '[' INT ']' INC  */
#line 844 "limbaj.y"
        {
                auto var=currentScope->searchVector((yyvsp[-4].stringVal));
                if(var.has_value()){
                        int numberElements= get<1>(var.value());
                        if((yyvsp[-2].intVal)>=numberElements){
                        string msg = "Tried accesing vector index "+ to_string((yyvsp[-2].intVal)) +" that doens't exist (the maximum elements for the vector is "+to_string(numberElements-1)+")";
                        yyerror(msg.c_str());
                        }
                          if((yyvsp[-2].intVal)<0){
                        string msg = "Tried accesing vector index "+ to_string((yyvsp[-2].intVal)) +" that doens't exist (the index can't be negative!)";
                        yyerror(msg.c_str());
                        }
                }
                if(var==nullopt){
                        string msg="The vector "+string((yyvsp[-4].stringVal))+" doesn't exist!";
                        yyerror(msg.c_str());
                }
                string typeVarToBeAssigned=currentScope->getType((yyvsp[-4].stringVal));
                cout<<"TYPE TO ASSIGN: "<<typeVarToBeAssigned<<endl;
                if(typeVarToBeAssigned=="int" || typeVarToBeAssigned=="float"){
                        //change value
                } else {
                        string msg="The variable "+string((yyvsp[-4].stringVal))+ " isn't a float or an int, you can't increment it!";
                        yyerror(msg.c_str());
                }
        }
#line 2236 "limbaj.tab.c"
    break;

  case 86: /* statement: ID '[' INT ']' DEC  */
#line 871 "limbaj.y"
        {
                auto var=currentScope->searchVector((yyvsp[-4].stringVal));
                if(var.has_value()){
                        int numberElements= get<1>(var.value());
                        if((yyvsp[-2].intVal)>=numberElements){
                        string msg = "Tried accesing vector index "+ to_string((yyvsp[-2].intVal)) +" that doens't exist (the maximum elements for the vector is "+to_string(numberElements-1)+")";
                        yyerror(msg.c_str());
                        }
                          if((yyvsp[-2].intVal)<0){
                        string msg = "Tried accesing vector index "+ to_string((yyvsp[-2].intVal)) +" that doens't exist (the index can't be negative!)";
                        yyerror(msg.c_str());
                        }
                }
                if(var==nullopt){
                        string msg="The vector "+string((yyvsp[-4].stringVal))+" doesn't exist!";
                        yyerror(msg.c_str());
                }
                string typeVarToBeAssigned=currentScope->getType((yyvsp[-4].stringVal));
                cout<<"TYPE TO ASSIGN: "<<typeVarToBeAssigned<<endl;
                if(typeVarToBeAssigned=="int" || typeVarToBeAssigned=="float"){
                        //change value
                } else {
                        string msg="The variable "+string((yyvsp[-4].stringVal))+ " isn't a float or an int, you can't increment it!";
                        yyerror(msg.c_str());
                }
        }
#line 2267 "limbaj.tab.c"
    break;

  case 88: /* expression: NOT expression  */
#line 901 "limbaj.y"
        {
                if (string((yyvsp[0].stringVal)) != "bool") {
                   yyerror("NOT operator ca only be applied to bool type!");
               }
               (yyval.stringVal) = strdup("bool");
        }
#line 2278 "limbaj.tab.c"
    break;

  case 89: /* expression: '-' expression  */
#line 908 "limbaj.y"
        {
                if (string((yyvsp[0].stringVal)) != "int" && string((yyvsp[0].stringVal)) != "float") {
                   yyerror("Minus operator ca only be appleid to numeric values!");
               }
               (yyval.stringVal) = strdup((yyvsp[0].stringVal));
        }
#line 2289 "limbaj.tab.c"
    break;

  case 90: /* expression: expression_elem '+' expression  */
#line 915 "limbaj.y"
        {
                string type1=string((yyvsp[-2].stringVal));
                string type2=string((yyvsp[0].stringVal));
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
            (yyval.stringVal) = strdup(resultType.c_str());
            free((yyvsp[-2].stringVal));
            free((yyvsp[0].stringVal));
        }
#line 2327 "limbaj.tab.c"
    break;

  case 91: /* expression: expression_elem '-' expression  */
#line 949 "limbaj.y"
        {
                string type1=string((yyvsp[-2].stringVal));
                string type2=string((yyvsp[0].stringVal));
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
            (yyval.stringVal) = strdup(resultType.c_str());
            free((yyvsp[-2].stringVal));
            free((yyvsp[0].stringVal));
        }
#line 2360 "limbaj.tab.c"
    break;

  case 92: /* expression: expression_elem OPERATOR expression  */
#line 978 "limbaj.y"
        { 
                string type1=string((yyvsp[-2].stringVal));
                string type2=string((yyvsp[0].stringVal));
                string resultType="int";
                string op = string((yyvsp[-1].stringVal));
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
            (yyval.stringVal) = strdup(resultType.c_str());
            free((yyvsp[-2].stringVal));
            free((yyvsp[0].stringVal)); 
        }
#line 2407 "limbaj.tab.c"
    break;

  case 93: /* expression: expression_elem INC  */
#line 1021 "limbaj.y"
        {
            if(string((yyvsp[-1].stringVal))!="int" && string((yyvsp[-1].stringVal))!="float"){
                yyerror("Cannot increment a non-numeric value!");
            }    
            (yyval.stringVal)=(yyvsp[-1].stringVal); 
        }
#line 2418 "limbaj.tab.c"
    break;

  case 94: /* expression: expression_elem DEC  */
#line 1028 "limbaj.y"
        {
            if(string((yyvsp[-1].stringVal))!="int" && string((yyvsp[-1].stringVal))!="float"){
                yyerror("Cannot increment a non-numeric value!");
            }
           (yyval.stringVal)=(yyvsp[-1].stringVal);
        }
#line 2429 "limbaj.tab.c"
    break;

  case 95: /* expression: expression_elem  */
#line 1034 "limbaj.y"
                          {(yyval.stringVal)=(yyvsp[0].stringVal);}
#line 2435 "limbaj.tab.c"
    break;

  case 98: /* expression_elem: INT  */
#line 1041 "limbaj.y"
        {
                (yyval.stringVal)=strdup("int");
        }
#line 2443 "limbaj.tab.c"
    break;

  case 99: /* expression_elem: FLOAT  */
#line 1045 "limbaj.y"
        {
                (yyval.stringVal)=strdup("float");
        }
#line 2451 "limbaj.tab.c"
    break;

  case 100: /* expression_elem: BOOL  */
#line 1049 "limbaj.y"
        {
                (yyval.stringVal)=strdup("bool");

        }
#line 2460 "limbaj.tab.c"
    break;

  case 101: /* expression_elem: CHAR  */
#line 1054 "limbaj.y"
        {

                (yyval.stringVal)=strdup("char");
        }
#line 2469 "limbaj.tab.c"
    break;

  case 102: /* expression_elem: STRING  */
#line 1059 "limbaj.y"
        {
                (yyval.stringVal)=strdup("string");

        }
#line 2478 "limbaj.tab.c"
    break;

  case 103: /* expression_elem: ID  */
#line 1064 "limbaj.y"
        {
                if(currentScope->searchVariable((yyvsp[0].stringVal))==nullopt){
                        string msg="Variable "+string((yyvsp[0].stringVal))+" doesn't exist";
                        yyerror(msg.c_str());
                }
                (yyval.stringVal)=strdup(currentScope->getType((yyvsp[0].stringVal)).c_str());
        }
#line 2490 "limbaj.tab.c"
    break;

  case 104: /* expression_elem: ID '[' INT ']'  */
#line 1072 "limbaj.y"
        {
                 auto var=currentScope->searchVector((yyvsp[-3].stringVal));
                if(var.has_value()){
                        int numberElements= get<1>(var.value());
                        if((yyvsp[-1].intVal)>=numberElements){
                        string msg = "Tried accesing vector index "+ to_string((yyvsp[-1].intVal)) +" that doens't exist (the maximum elements for the vector is "+to_string(numberElements-1)+")";
                        yyerror(msg.c_str());
                        }
                          if((yyvsp[-1].intVal)<0){
                        string msg = "Tried accesing vector index "+ to_string((yyvsp[-1].intVal)) +" that doens't exist (the index can't be negative!)";
                        yyerror(msg.c_str());
                        }
                }
                if(var==nullopt){
                        string msg="The vector "+string((yyvsp[-3].stringVal))+" doesn't exist!";
                        yyerror(msg.c_str());
                }
                (yyval.stringVal)=strdup(currentScope->getType((yyvsp[-3].stringVal)).c_str());
        }
#line 2514 "limbaj.tab.c"
    break;

  case 105: /* expression_elem: '(' expression ')'  */
#line 1092 "limbaj.y"
        {
                (yyval.stringVal)=(yyvsp[-1].stringVal);
        }
#line 2522 "limbaj.tab.c"
    break;

  case 106: /* compare_expr: expression COMPARE expression  */
#line 1100 "limbaj.y"
            {
                cout << "DEBUG: Comparing [" << (yyvsp[-2].stringVal) << "] with [" << (yyvsp[0].stringVal) << "]" << endl;
   
                if(string((yyvsp[-2].stringVal))!=string((yyvsp[0].stringVal))){
                         string msg="Type mismatch at compare, trying operation on ["+string((yyvsp[-2].stringVal))+"] and ["+string((yyvsp[0].stringVal))+"]";
                yyerror(msg.c_str());
                }
                //ar trebui adaucat si verific compare ul
                (yyval.stringVal)=strdup("bool");

                free((yyvsp[-2].stringVal));
                free((yyvsp[0].stringVal));

            }
#line 2541 "limbaj.tab.c"
    break;

  case 115: /* main_block_element: statement  */
#line 1137 "limbaj.y"
                        { yyerror("Missing semicolon");}
#line 2547 "limbaj.tab.c"
    break;


#line 2551 "limbaj.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1149 "limbaj.y"

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
