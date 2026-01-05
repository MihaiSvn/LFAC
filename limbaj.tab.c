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
  YYSYMBOL_28_ = 28,                       /* '+'  */
  YYSYMBOL_29_ = 29,                       /* '-'  */
  YYSYMBOL_30_ = 30,                       /* '*'  */
  YYSYMBOL_31_ = 31,                       /* '/'  */
  YYSYMBOL_32_ = 32,                       /* '%'  */
  YYSYMBOL_33_ = 33,                       /* '{'  */
  YYSYMBOL_34_ = 34,                       /* '}'  */
  YYSYMBOL_35_ = 35,                       /* '('  */
  YYSYMBOL_36_ = 36,                       /* ')'  */
  YYSYMBOL_37_ = 37,                       /* '.'  */
  YYSYMBOL_38_ = 38,                       /* '['  */
  YYSYMBOL_39_ = 39,                       /* ']'  */
  YYSYMBOL_40_ = 40,                       /* ','  */
  YYSYMBOL_41_ = 41,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_program = 43,                   /* program  */
  YYSYMBOL_class_section = 44,             /* class_section  */
  YYSYMBOL_class_declarations = 45,        /* class_declarations  */
  YYSYMBOL_class_declaration = 46,         /* class_declaration  */
  YYSYMBOL_47_1 = 47,                      /* $@1  */
  YYSYMBOL_class_block = 48,               /* class_block  */
  YYSYMBOL_class_var_section = 49,         /* class_var_section  */
  YYSYMBOL_class_methods_section = 50,     /* class_methods_section  */
  YYSYMBOL_class_create_instance = 51,     /* class_create_instance  */
  YYSYMBOL_52_2 = 52,                      /* $@2  */
  YYSYMBOL_53_3 = 53,                      /* $@3  */
  YYSYMBOL_54_4 = 54,                      /* $@4  */
  YYSYMBOL_class_access = 55,              /* class_access  */
  YYSYMBOL_class_method_call = 56,         /* class_method_call  */
  YYSYMBOL_57_5 = 57,                      /* $@5  */
  YYSYMBOL_method_call_params = 58,        /* method_call_params  */
  YYSYMBOL_method_call_param = 59,         /* method_call_param  */
  YYSYMBOL_class_var_call = 60,            /* class_var_call  */
  YYSYMBOL_global_var_section = 61,        /* global_var_section  */
  YYSYMBOL_variable_declarations = 62,     /* variable_declarations  */
  YYSYMBOL_var_decl = 63,                  /* var_decl  */
  YYSYMBOL_64_6 = 64,                      /* $@6  */
  YYSYMBOL_65_7 = 65,                      /* $@7  */
  YYSYMBOL_vector_elements = 66,           /* vector_elements  */
  YYSYMBOL_vector_element = 67,            /* vector_element  */
  YYSYMBOL_var_list = 68,                  /* var_list  */
  YYSYMBOL_global_fun_section = 69,        /* global_fun_section  */
  YYSYMBOL_function_declarations = 70,     /* function_declarations  */
  YYSYMBOL_fun_decl = 71,                  /* fun_decl  */
  YYSYMBOL_72_8 = 72,                      /* $@8  */
  YYSYMBOL_fun_decl_params = 73,           /* fun_decl_params  */
  YYSYMBOL_fun_param = 74,                 /* fun_param  */
  YYSYMBOL_fun_block = 75,                 /* fun_block  */
  YYSYMBOL_block_element = 76,             /* block_element  */
  YYSYMBOL_fun_call = 77,                  /* fun_call  */
  YYSYMBOL_78_9 = 78,                      /* $@9  */
  YYSYMBOL_fun_call_params = 79,           /* fun_call_params  */
  YYSYMBOL_fun_call_param = 80,            /* fun_call_param  */
  YYSYMBOL_print_expr = 81,                /* print_expr  */
  YYSYMBOL_print_statement = 82,           /* print_statement  */
  YYSYMBOL_statement = 83,                 /* statement  */
  YYSYMBOL_84_10 = 84,                     /* $@10  */
  YYSYMBOL_85_11 = 85,                     /* $@11  */
  YYSYMBOL_expression = 86,                /* expression  */
  YYSYMBOL_expression_elem = 87,           /* expression_elem  */
  YYSYMBOL_compare_expr = 88,              /* compare_expr  */
  YYSYMBOL_if_statement = 89,              /* if_statement  */
  YYSYMBOL_while_statement = 90,           /* while_statement  */
  YYSYMBOL_main = 91,                      /* main  */
  YYSYMBOL_main_fun_block = 92,            /* main_fun_block  */
  YYSYMBOL_main_block_element = 93         /* main_block_element  */
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
#define YYLAST   192

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  202

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


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
       2,     2,     2,     2,     2,     2,     2,    32,     2,     2,
      35,    36,    30,    28,    40,    29,    37,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
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
      25,    26,    27
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    55,    55,    58,    59,    61,    62,    65,    64,    83,
      85,    86,    89,    90,    94,   102,   110,    93,   118,   119,
     149,   191,   190,   250,   251,   252,   257,   272,   291,   313,
     335,   363,   394,   429,   430,   433,   434,   437,   458,   480,
     479,   512,   535,   534,   569,   570,   572,   586,   607,   629,
     630,   634,   635,   639,   638,   667,   668,   669,   672,   680,
     681,   685,   686,   687,   688,   689,   690,   691,   692,   693,
     694,   700,   699,   733,   734,   735,   739,   756,   759,   771,
     770,   785,   800,   816,   815,   842,   869,   896,   899,   940,
     947,   954,   957,   958,   959,   963,   967,   972,   977,   982,
     990,  1014,  1031,  1032,  1033,  1036,  1042,  1048,  1049,  1051,
    1052,  1053,  1054,  1055,  1056,  1057,  1058
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
  "MAIN_BEGIN", "MAIN_END", "OPERATOR", "INC", "DEC", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'{'", "'}'", "'('", "')'", "'.'", "'['", "']'", "','",
  "';'", "$accept", "program", "class_section", "class_declarations",
  "class_declaration", "$@1", "class_block", "class_var_section",
  "class_methods_section", "class_create_instance", "$@2", "$@3", "$@4",
  "class_access", "class_method_call", "$@5", "method_call_params",
  "method_call_param", "class_var_call", "global_var_section",
  "variable_declarations", "var_decl", "$@6", "$@7", "vector_elements",
  "vector_element", "var_list", "global_fun_section",
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

#define YYPACT_NINF (-148)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-72)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      25,    32,    17,    33,    26,    32,  -148,  -148,    47,    45,
      28,  -148,    50,    47,    39,    66,    55,  -148,    -3,    42,
    -148,    57,    66,  -148,  -148,  -148,    81,  -148,    82,    72,
    -148,    68,  -148,    60,    47,    67,    94,    74,    70,    64,
    -148,  -148,    76,    77,    20,    78,  -148,    73,    83,  -148,
      84,    85,    86,  -148,  -148,  -148,    47,  -148,    66,  -148,
      30,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
      71,    96,    72,   102,    74,    74,  -148,  -148,  -148,    99,
     100,   103,    95,    74,  -148,  -148,  -148,  -148,  -148,    66,
     113,   101,    74,  -148,  -148,  -148,  -148,   115,   -26,  -148,
     117,    98,   104,    74,    -2,    97,  -148,    74,   106,  -148,
      21,   105,  -148,   110,  -148,   112,   102,    74,   114,   116,
    -148,    74,  -148,  -148,   118,   119,     1,   126,   -17,  -148,
    -148,  -148,   121,  -148,    74,  -148,  -148,  -148,  -148,    65,
    -148,   109,    74,  -148,  -148,  -148,   129,  -148,    74,   120,
     122,   111,  -148,     4,    -1,   123,    37,    13,  -148,  -148,
      74,   136,  -148,  -148,  -148,    74,  -148,   124,   128,   130,
    -148,   131,   132,   133,  -148,  -148,   140,  -148,    74,  -148,
    -148,  -148,    74,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,    10,  -148,  -148,   125,  -148,  -148,   127,    18,
    -148,  -148
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,    33,     0,     4,     5,     1,     0,    49,
       0,     6,     0,    34,     0,     0,     0,     7,    37,     0,
      35,     0,    50,    51,   107,     2,    10,    39,     0,     0,
      36,     0,    52,     0,     0,     0,    12,     0,     0,    47,
      38,    53,     0,     0,    14,     0,   106,     0,     0,    87,
       0,     0,   110,   115,   116,   108,    11,     8,     0,     9,
      99,    94,    96,    95,    98,    97,    92,    18,    93,    40,
      91,    41,     0,    55,     0,     0,    79,    81,    82,     0,
       0,     0,     0,     0,   111,   112,   113,   114,   109,    13,
       0,     0,     0,    89,    90,    42,    48,     0,     0,    56,
       0,     0,     0,     0,    21,     0,    15,    73,     0,    77,
      19,     0,    88,     0,    58,     0,     0,     0,     0,     0,
      80,     0,    28,    29,     0,     0,     0,     0,     0,    74,
      76,    78,     0,   100,     0,    59,    57,   101,   107,     0,
      27,     0,    23,    83,    85,    86,     0,    72,     0,     0,
       0,    44,    46,     0,     0,     0,     0,     0,    24,    26,
       0,     0,    75,    20,    43,     0,    54,     0,     0,    64,
      60,     0,     0,    62,    69,    70,   102,   105,     0,    31,
      32,    22,     0,    84,    16,    45,    65,    66,    63,    67,
      68,    61,     0,    30,    25,     0,   107,   104,     0,     0,
      17,   103
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -148,  -148,  -148,  -148,   150,  -148,  -148,  -148,  -148,     5,
    -148,  -148,  -148,  -148,   -33,  -148,  -148,   -21,  -148,  -148,
     141,   -12,  -148,  -148,     2,  -148,    90,  -148,   134,   -19,
    -148,  -148,    48,  -148,  -148,   -31,  -148,  -148,    22,  -148,
      23,    24,  -148,  -148,   -32,  -148,   107,  -147,    27,  -148,
    -134,    40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     5,     6,    26,    35,    36,    59,    47,
      81,   127,   195,    66,    67,   125,   157,   158,    49,     9,
      13,    14,    37,   113,   150,   151,    40,    16,    22,    23,
      73,    98,    99,   153,   170,    68,    82,   128,   129,   108,
      51,    52,   103,   160,   100,    70,   101,    53,    54,    25,
      33,    55
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,    19,    50,    32,   154,    69,   174,    12,    27,   121,
     115,    42,   143,    43,   116,    44,    42,     7,    43,   147,
      44,    45,    42,   148,   122,   123,    45,   144,   145,     1,
      42,    76,    43,   176,    44,    28,   124,    29,   166,     4,
      45,     8,    10,   196,    19,   197,    77,    78,   178,   181,
      12,   109,   201,   182,    15,   -71,   -21,    79,    80,   132,
     112,    17,   199,   179,   180,   -71,    18,    90,    91,    21,
      32,   120,    42,    31,    43,   130,    44,    42,    24,    43,
      20,    44,    45,    30,    46,   137,    34,    45,    39,   140,
      60,    61,    62,    63,    64,    65,    92,    93,    94,    38,
      58,    57,   152,    41,    72,    97,    48,    95,    50,    71,
     159,    74,    75,    83,    84,   104,   130,   105,   111,   106,
     168,    48,   171,    50,    85,    86,    87,    88,   183,   110,
     107,   114,   117,   152,   118,   141,   126,   146,   149,   161,
     119,   169,   131,   134,   133,   135,   193,   138,   156,   139,
     159,   165,   184,   192,   142,    11,   164,   177,   167,   163,
     198,   194,    96,   200,   136,   186,    48,   185,    50,   187,
     162,   188,   189,   190,   191,    56,   172,   173,     0,   155,
     175,     0,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    89
};

static const yytype_int16 yycheck[] =
{
      33,    13,    33,    22,   138,    37,   153,     3,    11,    11,
      36,    12,    11,    14,    40,    16,    12,     0,    14,    36,
      16,    22,    12,    40,    26,    27,    22,    26,    27,     4,
      12,    11,    14,    34,    16,    38,    38,    40,    34,     7,
      22,     8,    16,    33,    56,   192,    26,    27,    11,    36,
       3,    83,    34,    40,     9,    35,    35,    37,    38,    38,
      92,    33,   196,    26,    27,    35,    16,    37,    38,     3,
      89,   103,    12,    16,    14,   107,    16,    12,    23,    14,
      41,    16,    22,    41,    24,   117,     5,    22,    16,   121,
      16,    17,    18,    19,    20,    21,    25,    26,    27,    17,
       6,    34,   134,    35,    40,     3,   139,    11,   139,    39,
     142,    35,    35,    35,    41,    16,   148,    17,    17,    16,
     153,   154,   153,   154,    41,    41,    41,    41,   160,    16,
      35,    16,    15,   165,    36,    17,    39,    11,    17,    10,
      36,   153,    36,    33,    39,    33,   178,    33,    39,    33,
     182,    40,    16,    13,    35,     5,    34,    34,   153,    39,
      35,   182,    72,    36,   116,    41,   199,   165,   199,    41,
     148,    41,    41,    41,    41,    34,   153,   153,    -1,   139,
     153,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    43,    44,     7,    45,    46,     0,     8,    61,
      16,    46,     3,    62,    63,     9,    69,    33,    16,    63,
      41,     3,    70,    71,    23,    91,    47,    11,    38,    40,
      41,    16,    71,    92,     5,    48,    49,    64,    17,    16,
      68,    35,    12,    14,    16,    22,    24,    51,    56,    60,
      77,    82,    83,    89,    90,    93,    62,    34,     6,    50,
      16,    17,    18,    19,    20,    21,    55,    56,    77,    86,
      87,    39,    40,    72,    35,    35,    11,    26,    27,    37,
      38,    52,    78,    35,    41,    41,    41,    41,    41,    70,
      37,    38,    25,    26,    27,    11,    68,     3,    73,    74,
      86,    88,    88,    84,    16,    17,    16,    35,    81,    86,
      16,    17,    86,    65,    16,    36,    40,    15,    36,    36,
      86,    11,    26,    27,    38,    57,    39,    53,    79,    80,
      86,    36,    38,    39,    33,    33,    74,    86,    33,    33,
      86,    17,    35,    11,    26,    27,    11,    36,    40,    17,
      66,    67,    86,    75,    92,    93,    39,    58,    59,    86,
      85,    10,    80,    39,    34,    40,    34,    51,    56,    63,
      76,    77,    82,    83,    89,    90,    34,    34,    11,    26,
      27,    36,    40,    86,    16,    66,    41,    41,    41,    41,
      41,    41,    13,    86,    59,    54,    33,    89,    35,    92,
      36,    34
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    47,    46,    48,
      49,    49,    50,    50,    52,    53,    54,    51,    55,    55,
      55,    57,    56,    58,    58,    58,    59,    60,    60,    60,
      60,    60,    60,    61,    61,    62,    62,    63,    63,    64,
      63,    63,    65,    63,    66,    66,    67,    68,    68,    69,
      69,    70,    70,    72,    71,    73,    73,    73,    74,    75,
      75,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    78,    77,    79,    79,    79,    80,    81,    82,    84,
      83,    83,    83,    85,    83,    83,    83,    83,    86,    86,
      86,    86,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    88,    89,    89,    89,    90,    91,    92,    92,    93,
      93,    93,    93,    93,    93,    93,    93
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
       4,     2,     2,     0,     7,     5,     5,     1,     3,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     3,     7,    11,     9,     7,     3,     0,     2,     2,
       1,     2,     2,     2,     2,     1,     1
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
#line 55 "limbaj.y"
                                                                   {if(errorCount==0) cout<<endl<<"The program is correct!\n";}
#line 1330 "limbaj.tab.c"
    break;

  case 3: /* class_section: %empty  */
#line 58 "limbaj.y"
                {std::cout<<endl<<"No classes"<<endl;}
#line 1336 "limbaj.tab.c"
    break;

  case 7: /* $@1: %empty  */
#line 65 "limbaj.y"
                {
                        if(currentScope->addClass((yyvsp[-1].stringVal))==true){
                                currentScope = currentScope->enterScope((yyvsp[-1].stringVal));  //intram in scope ul clasei
                        } else {
                                string msg="The class "+string((yyvsp[-1].stringVal))+" already exists";
                                yyerror(msg.c_str());
                        }
                        globalScope->childScopes.push_back(currentScope);
                }
#line 1350 "limbaj.tab.c"
    break;

  case 8: /* class_declaration: CLASS ID '{' $@1 class_block '}'  */
#line 77 "limbaj.y"
                {
                        currentScope = currentScope->exitScope(); //iesin din scope ul clasei
                        parentScope = currentScope;
                }
#line 1359 "limbaj.tab.c"
    break;

  case 10: /* class_var_section: %empty  */
#line 85 "limbaj.y"
                    {std::cout<<endl<<"No variables"<<endl;}
#line 1365 "limbaj.tab.c"
    break;

  case 12: /* class_methods_section: %empty  */
#line 89 "limbaj.y"
                        {std::cout<<endl<<"No methods"<<endl;}
#line 1371 "limbaj.tab.c"
    break;

  case 14: /* $@2: %empty  */
#line 94 "limbaj.y"
                        {
                        if(find(currentScope->classes.begin(),currentScope->classes.end(),(yyvsp[0].stringVal))==currentScope->classes.end()){
                                string msg="The class "+string((yyvsp[0].stringVal))+" doesn't exists";
                                yyerror(msg.c_str());
                        }

                        }
#line 1383 "limbaj.tab.c"
    break;

  case 15: /* $@3: %empty  */
#line 102 "limbaj.y"
                         {
                                if(currentScope->addVariable((yyvsp[0].stringVal),(yyvsp[-2].stringVal))==false){
                                string msg="The class name"+string((yyvsp[0].stringVal))+" doesn't exists";
                                        yyerror(msg.c_str());
                                }
                         }
#line 1394 "limbaj.tab.c"
    break;

  case 16: /* $@4: %empty  */
#line 110 "limbaj.y"
                          {
                                if(string((yyvsp[-6].stringVal))!=string((yyvsp[0].stringVal))){
                                        yyerror("Type mismatch: cannot instantiate class with a different constructor type");
                                }
                          }
#line 1404 "limbaj.tab.c"
    break;

  case 19: /* class_access: ID '.' ID  */
#line 120 "limbaj.y"
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
#line 1438 "limbaj.tab.c"
    break;

  case 20: /* class_access: ID '.' ID '[' INT ']'  */
#line 150 "limbaj.y"
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
#line 1480 "limbaj.tab.c"
    break;

  case 21: /* $@5: %empty  */
#line 191 "limbaj.y"
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
#line 1521 "limbaj.tab.c"
    break;

  case 22: /* class_method_call: ID '.' ID $@5 '(' method_call_params ')'  */
#line 228 "limbaj.y"
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
#line 1546 "limbaj.tab.c"
    break;

  case 26: /* method_call_param: expression  */
#line 258 "limbaj.y"
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
#line 1562 "limbaj.tab.c"
    break;

  case 27: /* class_var_call: ID '.' ID ASSIGN expression  */
#line 273 "limbaj.y"
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
#line 1585 "limbaj.tab.c"
    break;

  case 28: /* class_var_call: ID '.' ID INC  */
#line 292 "limbaj.y"
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
#line 1611 "limbaj.tab.c"
    break;

  case 29: /* class_var_call: ID '.' ID DEC  */
#line 314 "limbaj.y"
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
#line 1637 "limbaj.tab.c"
    break;

  case 30: /* class_var_call: ID '.' ID '[' INT ']' ASSIGN expression  */
#line 336 "limbaj.y"
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
#line 1669 "limbaj.tab.c"
    break;

  case 31: /* class_var_call: ID '.' ID '[' INT ']' INC  */
#line 364 "limbaj.y"
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
#line 1704 "limbaj.tab.c"
    break;

  case 32: /* class_var_call: ID '.' ID '[' INT ']' DEC  */
#line 395 "limbaj.y"
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
#line 1739 "limbaj.tab.c"
    break;

  case 33: /* global_var_section: %empty  */
#line 429 "limbaj.y"
                    {std::cout<<endl<<"No global variables"<<endl;}
#line 1745 "limbaj.tab.c"
    break;

  case 37: /* var_decl: TYPE ID  */
#line 438 "limbaj.y"
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
#line 1770 "limbaj.tab.c"
    break;

  case 38: /* var_decl: TYPE ID ',' var_list  */
#line 459 "limbaj.y"
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
#line 1795 "limbaj.tab.c"
    break;

  case 39: /* $@6: %empty  */
#line 480 "limbaj.y"
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
#line 1821 "limbaj.tab.c"
    break;

  case 40: /* var_decl: TYPE ID ASSIGN $@6 expression  */
#line 502 "limbaj.y"
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
#line 1836 "limbaj.tab.c"
    break;

  case 41: /* var_decl: TYPE ID '[' INT ']'  */
#line 513 "limbaj.y"
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
#line 1862 "limbaj.tab.c"
    break;

  case 42: /* $@7: %empty  */
#line 535 "limbaj.y"
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
#line 1892 "limbaj.tab.c"
    break;

  case 43: /* var_decl: TYPE ID '[' INT ']' ASSIGN $@7 '{' vector_elements '}'  */
#line 561 "limbaj.y"
              {
                if(numberOfElementsToAdd>0){
                       string msg="Vector init received too few arguments";
                        yyerror(msg.c_str());  
                }
              }
#line 1903 "limbaj.tab.c"
    break;

  case 46: /* vector_element: expression  */
#line 573 "limbaj.y"
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
#line 1920 "limbaj.tab.c"
    break;

  case 47: /* var_list: ID  */
#line 587 "limbaj.y"
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
#line 1945 "limbaj.tab.c"
    break;

  case 48: /* var_list: ID ',' var_list  */
#line 608 "limbaj.y"
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
#line 1969 "limbaj.tab.c"
    break;

  case 49: /* global_fun_section: %empty  */
#line 629 "limbaj.y"
                     {std::cout<<endl<<"No global functions"<<endl;}
#line 1975 "limbaj.tab.c"
    break;

  case 53: /* $@8: %empty  */
#line 639 "limbaj.y"
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
#line 2002 "limbaj.tab.c"
    break;

  case 54: /* fun_decl: TYPE ID '(' $@8 fun_decl_params ')' '{' fun_block '}'  */
#line 662 "limbaj.y"
         {
                currentScope = currentScope->exitScope();
                parentScope = currentScope;
         }
#line 2011 "limbaj.tab.c"
    break;

  case 58: /* fun_param: TYPE ID  */
#line 673 "limbaj.y"
        {
                parentScope->setFunctionParams(funName,(yyvsp[-1].stringVal));
                cout<<"adding variable "<<(yyvsp[0].stringVal)<<"to scope "<<currentScope->name<<endl;
                currentScope->addVariable((yyvsp[0].stringVal),(yyvsp[-1].stringVal));
        }
#line 2021 "limbaj.tab.c"
    break;

  case 62: /* block_element: statement  */
#line 686 "limbaj.y"
                        { yyerror("Missing semicolon");}
#line 2027 "limbaj.tab.c"
    break;

  case 64: /* block_element: var_decl  */
#line 688 "limbaj.y"
                       { yyerror("Missing semicolon");}
#line 2033 "limbaj.tab.c"
    break;

  case 71: /* $@9: %empty  */
#line 700 "limbaj.y"
        {
                if(currentScope->searchFunction((yyvsp[0].stringVal))==nullopt){
                        string msg="The called function "+string((yyvsp[0].stringVal)) +" doesn't exist!";
                        yyerror(msg.c_str());
                } else {
                        calling_functions.push((yyvsp[0].stringVal));
                        param_counts.push(0);
                }

        }
#line 2048 "limbaj.tab.c"
    break;

  case 72: /* fun_call: ID $@9 '(' fun_call_params ')'  */
#line 712 "limbaj.y"
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
#line 2072 "limbaj.tab.c"
    break;

  case 76: /* fun_call_param: expression  */
#line 740 "limbaj.y"
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
#line 2088 "limbaj.tab.c"
    break;

  case 78: /* print_statement: PRINT '(' print_expr ')'  */
#line 759 "limbaj.y"
                                           {cout<<endl<<(yyvsp[-1].stringVal)<<endl;
        free((yyvsp[-1].stringVal));
        }
#line 2096 "limbaj.tab.c"
    break;

  case 79: /* $@10: %empty  */
#line 771 "limbaj.y"
        {
                if(currentScope->searchVariable((yyvsp[-1].stringVal))==nullopt){
                        string msg="The variable "+string((yyvsp[-1].stringVal))+" doesn't exist!";
                        yyerror(msg.c_str());
                }
        }
#line 2107 "limbaj.tab.c"
    break;

  case 80: /* statement: ID ASSIGN $@10 expression  */
#line 777 "limbaj.y"
                    {
                string typeVarToBeAssigned=currentScope->getType((yyvsp[-3].stringVal));
                if(typeVarToBeAssigned!=string((yyvsp[0].stringVal))){
                        string msg="Type mismatch at assignment, trying operation on ["+typeVarToBeAssigned+"] and ["+string((yyvsp[0].stringVal))+"]";
                        yyerror(msg.c_str());
                }
                free((yyvsp[0].stringVal));
         }
#line 2120 "limbaj.tab.c"
    break;

  case 81: /* statement: ID INC  */
#line 786 "limbaj.y"
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
#line 2139 "limbaj.tab.c"
    break;

  case 82: /* statement: ID DEC  */
#line 801 "limbaj.y"
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
#line 2158 "limbaj.tab.c"
    break;

  case 83: /* $@11: %empty  */
#line 816 "limbaj.y"
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
#line 2181 "limbaj.tab.c"
    break;

  case 84: /* statement: ID '[' INT ']' ASSIGN $@11 expression  */
#line 834 "limbaj.y"
                    {
                string typeVarToBeAssigned=currentScope->getType((yyvsp[-6].stringVal));
                if(typeVarToBeAssigned!=string((yyvsp[0].stringVal))){
                        string msg="Type mismatch at assignment, trying operation on ["+typeVarToBeAssigned+"] and ["+string((yyvsp[0].stringVal))+"]";
                        yyerror(msg.c_str());
                }
                free((yyvsp[0].stringVal));
         }
#line 2194 "limbaj.tab.c"
    break;

  case 85: /* statement: ID '[' INT ']' INC  */
#line 843 "limbaj.y"
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
#line 2225 "limbaj.tab.c"
    break;

  case 86: /* statement: ID '[' INT ']' DEC  */
#line 870 "limbaj.y"
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
#line 2256 "limbaj.tab.c"
    break;

  case 88: /* expression: expression_elem OPERATOR expression  */
#line 900 "limbaj.y"
        { 
                string type1=string((yyvsp[-2].stringVal));
                string type2=string((yyvsp[0].stringVal));
                string resultType="int";
                string op = string((yyvsp[-1].stringVal));
                cout<<"OPERATOR "<<op<<endl;
                bool ok=true;
                if (op == "+" || op == "-" || op == "*" || op == "/") {
                    if ((type1 != "int" && type1 != "float") || (type2 != "int" && type2 != "float")) {
                        ok = false;
                    }
                    if (type1 == "float" || type2 == "float") resultType = "float";
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
                string msg="Type mismatch, trying operation "+op+ "on ["+type1+"] and ["+type2+"]";
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
#line 2301 "limbaj.tab.c"
    break;

  case 89: /* expression: expression_elem INC  */
#line 941 "limbaj.y"
        {
            if(string((yyvsp[-1].stringVal))!="int" && string((yyvsp[-1].stringVal))!="float"){
                yyerror("Cannot increment a non-numeric value!");
            }    
            (yyval.stringVal)=(yyvsp[-1].stringVal); 
        }
#line 2312 "limbaj.tab.c"
    break;

  case 90: /* expression: expression_elem DEC  */
#line 948 "limbaj.y"
        {
            if(string((yyvsp[-1].stringVal))!="int" && string((yyvsp[-1].stringVal))!="float"){
                yyerror("Cannot increment a non-numeric value!");
            }
           (yyval.stringVal)=(yyvsp[-1].stringVal);
        }
#line 2323 "limbaj.tab.c"
    break;

  case 91: /* expression: expression_elem  */
#line 954 "limbaj.y"
                          {(yyval.stringVal)=(yyvsp[0].stringVal);}
#line 2329 "limbaj.tab.c"
    break;

  case 94: /* expression_elem: INT  */
#line 960 "limbaj.y"
        {
                (yyval.stringVal)=strdup("int");
        }
#line 2337 "limbaj.tab.c"
    break;

  case 95: /* expression_elem: FLOAT  */
#line 964 "limbaj.y"
        {
                (yyval.stringVal)=strdup("float");
        }
#line 2345 "limbaj.tab.c"
    break;

  case 96: /* expression_elem: BOOL  */
#line 968 "limbaj.y"
        {
                (yyval.stringVal)=strdup("bool");

        }
#line 2354 "limbaj.tab.c"
    break;

  case 97: /* expression_elem: CHAR  */
#line 973 "limbaj.y"
        {

                (yyval.stringVal)=strdup("char");
        }
#line 2363 "limbaj.tab.c"
    break;

  case 98: /* expression_elem: STRING  */
#line 978 "limbaj.y"
        {
                (yyval.stringVal)=strdup("string");

        }
#line 2372 "limbaj.tab.c"
    break;

  case 99: /* expression_elem: ID  */
#line 983 "limbaj.y"
        {
                if(currentScope->searchVariable((yyvsp[0].stringVal))==nullopt){
                        string msg="Variable "+string((yyvsp[0].stringVal))+" doesn't exist";
                        yyerror(msg.c_str());
                }
                (yyval.stringVal)=strdup(currentScope->getType((yyvsp[0].stringVal)).c_str());
        }
#line 2384 "limbaj.tab.c"
    break;

  case 100: /* expression_elem: ID '[' INT ']'  */
#line 991 "limbaj.y"
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
#line 2408 "limbaj.tab.c"
    break;

  case 101: /* compare_expr: expression COMPARE expression  */
#line 1015 "limbaj.y"
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
#line 2427 "limbaj.tab.c"
    break;

  case 110: /* main_block_element: statement  */
#line 1052 "limbaj.y"
                        { yyerror("Missing semicolon");}
#line 2433 "limbaj.tab.c"
    break;


#line 2437 "limbaj.tab.c"

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

#line 1064 "limbaj.y"

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
