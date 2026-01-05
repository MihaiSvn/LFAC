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

#line 101 "limbaj.tab.c"

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
  YYSYMBOL_38_ = 38,                       /* ','  */
  YYSYMBOL_39_ = 39,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_program = 41,                   /* program  */
  YYSYMBOL_class_section = 42,             /* class_section  */
  YYSYMBOL_class_declarations = 43,        /* class_declarations  */
  YYSYMBOL_class_declaration = 44,         /* class_declaration  */
  YYSYMBOL_45_1 = 45,                      /* $@1  */
  YYSYMBOL_class_block = 46,               /* class_block  */
  YYSYMBOL_class_var_section = 47,         /* class_var_section  */
  YYSYMBOL_class_methods_section = 48,     /* class_methods_section  */
  YYSYMBOL_class_create_instance = 49,     /* class_create_instance  */
  YYSYMBOL_50_2 = 50,                      /* $@2  */
  YYSYMBOL_51_3 = 51,                      /* $@3  */
  YYSYMBOL_52_4 = 52,                      /* $@4  */
  YYSYMBOL_class_access = 53,              /* class_access  */
  YYSYMBOL_class_method_call = 54,         /* class_method_call  */
  YYSYMBOL_55_5 = 55,                      /* $@5  */
  YYSYMBOL_method_call_params = 56,        /* method_call_params  */
  YYSYMBOL_method_call_param = 57,         /* method_call_param  */
  YYSYMBOL_class_var_call = 58,            /* class_var_call  */
  YYSYMBOL_global_var_section = 59,        /* global_var_section  */
  YYSYMBOL_variable_declarations = 60,     /* variable_declarations  */
  YYSYMBOL_var_decl = 61,                  /* var_decl  */
  YYSYMBOL_62_6 = 62,                      /* $@6  */
  YYSYMBOL_global_fun_section = 63,        /* global_fun_section  */
  YYSYMBOL_function_declarations = 64,     /* function_declarations  */
  YYSYMBOL_fun_decl = 65,                  /* fun_decl  */
  YYSYMBOL_66_7 = 66,                      /* $@7  */
  YYSYMBOL_fun_decl_params = 67,           /* fun_decl_params  */
  YYSYMBOL_fun_param = 68,                 /* fun_param  */
  YYSYMBOL_fun_block = 69,                 /* fun_block  */
  YYSYMBOL_block_element = 70,             /* block_element  */
  YYSYMBOL_fun_call = 71,                  /* fun_call  */
  YYSYMBOL_72_8 = 72,                      /* $@8  */
  YYSYMBOL_fun_call_params = 73,           /* fun_call_params  */
  YYSYMBOL_fun_call_param = 74,            /* fun_call_param  */
  YYSYMBOL_print_expr = 75,                /* print_expr  */
  YYSYMBOL_print_statement = 76,           /* print_statement  */
  YYSYMBOL_statement = 77,                 /* statement  */
  YYSYMBOL_78_9 = 78,                      /* $@9  */
  YYSYMBOL_expression = 79,                /* expression  */
  YYSYMBOL_expression_elem = 80,           /* expression_elem  */
  YYSYMBOL_compare_expr = 81,              /* compare_expr  */
  YYSYMBOL_if_statement = 82,              /* if_statement  */
  YYSYMBOL_while_statement = 83,           /* while_statement  */
  YYSYMBOL_main = 84,                      /* main  */
  YYSYMBOL_main_fun_block = 85,            /* main_fun_block  */
  YYSYMBOL_main_block_element = 86         /* main_block_element  */
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
#define YYLAST   154

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

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
      35,    36,    30,    28,    38,    29,    37,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       0,    53,    53,    56,    57,    59,    60,    63,    62,    81,
      83,    84,    87,    88,    92,   100,   108,    91,   116,   117,
     151,   150,   210,   211,   212,   217,   232,   251,   273,   299,
     300,   303,   304,   307,   329,   328,   364,   365,   369,   370,
     374,   373,   402,   403,   404,   407,   415,   416,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   436,
     435,   469,   470,   471,   475,   492,   495,   507,   506,   521,
     536,   553,   562,   563,   564,   567,   568,   569,   573,   577,
     582,   587,   592,   600,   617,   618,   619,   622,   628,   634,
     635,   637,   638,   639,   640,   641,   642,   643,   644,   645
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
  "'/'", "'%'", "'{'", "'}'", "'('", "')'", "'.'", "','", "';'", "$accept",
  "program", "class_section", "class_declarations", "class_declaration",
  "$@1", "class_block", "class_var_section", "class_methods_section",
  "class_create_instance", "$@2", "$@3", "$@4", "class_access",
  "class_method_call", "$@5", "method_call_params", "method_call_param",
  "class_var_call", "global_var_section", "variable_declarations",
  "var_decl", "$@6", "global_fun_section", "function_declarations",
  "fun_decl", "$@7", "fun_decl_params", "fun_param", "fun_block",
  "block_element", "fun_call", "$@8", "fun_call_params", "fun_call_param",
  "print_expr", "print_statement", "statement", "$@9", "expression",
  "expression_elem", "compare_expr", "if_statement", "while_statement",
  "main", "main_fun_block", "main_block_element", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-121)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-60)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       5,    22,    10,     8,    14,    22,  -121,  -121,    33,    46,
      17,  -121,    43,    33,    24,    59,    51,  -121,    70,    44,
    -121,    66,    59,  -121,  -121,  -121,    79,  -121,  -121,    52,
    -121,    32,    33,    54,    80,    50,  -121,    58,    60,    -3,
      65,  -121,    62,    63,    64,    67,    68,    69,  -121,  -121,
    -121,    33,  -121,    59,  -121,    23,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,   -13,    82,    50,    50,  -121,
    -121,  -121,    73,    88,    74,    50,  -121,  -121,  -121,  -121,
    -121,  -121,    59,    89,    50,  -121,  -121,    94,    37,  -121,
      96,    76,    77,    50,     0,  -121,    50,    78,  -121,    81,
    -121,  -121,    85,    82,    50,    86,    87,  -121,    50,  -121,
    -121,    90,   110,    41,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,    35,  -121,    50,   112,  -121,    50,     3,     6,    92,
      42,  -121,  -121,   107,  -121,  -121,    91,    93,    95,    97,
    -121,    98,    99,   100,  -121,  -121,   111,  -121,  -121,    50,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,     9,  -121,
     105,  -121,  -121,   106,    19,  -121,  -121
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,    29,     0,     4,     5,     1,     0,    36,
       0,     6,     0,    30,     0,     0,     0,     7,    33,     0,
      31,     0,    37,    38,    89,     2,    10,    34,    32,     0,
      39,     0,     0,     0,    12,     0,    40,     0,     0,    14,
       0,    88,     0,     0,     0,     0,     0,    92,    98,    99,
      90,    11,     8,     0,     9,    82,    77,    79,    78,    81,
      80,    75,    18,    76,    35,    74,    42,     0,     0,    67,
      69,    70,     0,     0,     0,     0,    93,    94,    95,    96,
      97,    91,    13,     0,     0,    72,    73,     0,     0,    43,
       0,     0,     0,     0,    20,    15,    61,     0,    65,    19,
      71,    45,     0,     0,     0,     0,     0,    68,     0,    27,
      28,     0,     0,     0,    62,    64,    66,    46,    44,    83,
      89,     0,    26,    22,     0,    60,     0,     0,     0,     0,
       0,    23,    25,     0,    63,    41,     0,     0,     0,    51,
      47,     0,     0,    49,    57,    58,    84,    87,    21,     0,
      16,    52,    53,    54,    50,    55,    56,    48,     0,    24,
       0,    89,    86,     0,     0,    17,    85
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -121,  -121,  -121,  -121,   122,  -121,  -121,  -121,  -121,     1,
    -121,  -121,  -121,  -121,   -31,  -121,  -121,   -20,     4,  -121,
     109,   -12,  -121,  -121,   101,   -17,  -121,  -121,    40,  -121,
    -121,   -29,  -121,  -121,    18,  -121,    20,    21,  -121,   -32,
    -121,    83,  -120,    25,  -121,  -116,    28
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     5,     6,    26,    33,    34,    54,    42,
      73,   112,   160,    61,    62,   111,   130,   131,    44,     9,
      13,    14,    35,    16,    22,    23,    66,    88,    89,   127,
     140,    63,    74,   113,   114,    97,    46,    47,    93,    90,
      65,    91,    48,    49,    25,    31,    50
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,    19,    45,    64,   128,    30,    12,   144,    69,     1,
       7,   108,    84,    85,    86,    37,     8,    38,    37,    39,
      38,    37,    39,    70,    71,    40,   109,   110,    40,     4,
      10,    37,   -59,    38,    72,    39,    12,   135,   162,    19,
     146,    40,   161,    98,    37,   164,    38,    37,    39,    38,
      17,    39,   100,   166,    40,    15,    41,    40,   -59,    18,
      83,   107,    21,    20,   115,    30,    55,    56,    57,    58,
      59,    60,   119,   102,    24,   103,   122,   125,   148,   126,
     149,    27,    29,    28,    32,    87,    53,    36,    52,    94,
      43,   132,    45,    67,   115,    68,   137,    43,   141,    45,
      75,    76,    77,    78,    95,    99,    79,    80,    81,    96,
     101,   104,   105,   106,   116,   139,   -20,   132,   117,   120,
     121,   124,   133,   150,   158,   123,   147,    11,   136,   159,
     151,   138,   152,    43,   153,    45,   154,   155,   156,   157,
     163,    51,   165,   118,   134,     0,     0,   142,   143,   129,
       0,    92,   145,     0,    82
};

static const yytype_int16 yycheck[] =
{
      31,    13,    31,    35,   120,    22,     3,   127,    11,     4,
       0,    11,    25,    26,    27,    12,     8,    14,    12,    16,
      14,    12,    16,    26,    27,    22,    26,    27,    22,     7,
      16,    12,    35,    14,    37,    16,     3,    34,   158,    51,
      34,    22,    33,    75,    12,   161,    14,    12,    16,    14,
      33,    16,    84,    34,    22,     9,    24,    22,    35,    16,
      37,    93,     3,    39,    96,    82,    16,    17,    18,    19,
      20,    21,   104,    36,    23,    38,   108,    36,    36,    38,
      38,    11,    16,    39,     5,     3,     6,    35,    34,    16,
     121,   123,   121,    35,   126,    35,   127,   128,   127,   128,
      35,    39,    39,    39,    16,    16,    39,    39,    39,    35,
      16,    15,    36,    36,    36,   127,    35,   149,    33,    33,
      33,    11,    10,    16,    13,    35,    34,     5,   127,   149,
      39,   127,    39,   164,    39,   164,    39,    39,    39,    39,
      35,    32,    36,   103,   126,    -1,    -1,   127,   127,   121,
      -1,    68,   127,    -1,    53
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    41,    42,     7,    43,    44,     0,     8,    59,
      16,    44,     3,    60,    61,     9,    63,    33,    16,    61,
      39,     3,    64,    65,    23,    84,    45,    11,    39,    16,
      65,    85,     5,    46,    47,    62,    35,    12,    14,    16,
      22,    24,    49,    54,    58,    71,    76,    77,    82,    83,
      86,    60,    34,     6,    48,    16,    17,    18,    19,    20,
      21,    53,    54,    71,    79,    80,    66,    35,    35,    11,
      26,    27,    37,    50,    72,    35,    39,    39,    39,    39,
      39,    39,    64,    37,    25,    26,    27,     3,    67,    68,
      79,    81,    81,    78,    16,    16,    35,    75,    79,    16,
      79,    16,    36,    38,    15,    36,    36,    79,    11,    26,
      27,    55,    51,    73,    74,    79,    36,    33,    68,    79,
      33,    33,    79,    35,    11,    36,    38,    69,    85,    86,
      56,    57,    79,    10,    74,    34,    49,    54,    58,    61,
      70,    71,    76,    77,    82,    83,    34,    34,    36,    38,
      16,    39,    39,    39,    39,    39,    39,    39,    13,    57,
      52,    33,    82,    35,    85,    36,    34
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    45,    44,    46,
      47,    47,    48,    48,    50,    51,    52,    49,    53,    53,
      55,    54,    56,    56,    56,    57,    58,    58,    58,    59,
      59,    60,    60,    61,    62,    61,    63,    63,    64,    64,
      66,    65,    67,    67,    67,    68,    69,    69,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    72,
      71,    73,    73,    73,    74,    75,    76,    78,    77,    77,
      77,    79,    79,    79,    79,    80,    80,    80,    80,    80,
      80,    80,    80,    81,    82,    82,    82,    83,    84,    85,
      85,    86,    86,    86,    86,    86,    86,    86,    86,    86
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     0,     2,     1,     2,     0,     6,     2,
       0,     2,     0,     2,     0,     0,     0,    10,     1,     3,
       0,     7,     0,     1,     3,     1,     5,     4,     4,     0,
       2,     2,     3,     2,     0,     5,     0,     2,     1,     2,
       0,     9,     0,     1,     3,     2,     0,     2,     2,     1,
       2,     1,     2,     2,     2,     2,     2,     1,     1,     0,
       5,     0,     1,     3,     1,     1,     4,     0,     4,     2,
       2,     3,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     7,    11,     9,     7,     3,     0,
       2,     2,     1,     2,     2,     2,     2,     2,     1,     1
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
#line 53 "limbaj.y"
                                                                   {if(errorCount==0) cout<<endl<<"The program is correct!\n";}
#line 1291 "limbaj.tab.c"
    break;

  case 3: /* class_section: %empty  */
#line 56 "limbaj.y"
                {std::cout<<endl<<"No classes"<<endl;}
#line 1297 "limbaj.tab.c"
    break;

  case 7: /* $@1: %empty  */
#line 63 "limbaj.y"
                {
                        if(currentScope->addClass((yyvsp[-1].stringVal))==true){
                                currentScope = currentScope->enterScope((yyvsp[-1].stringVal));  //intram in scope ul clasei
                        } else {
                                string msg="The class "+string((yyvsp[-1].stringVal))+" already exists";
                                yyerror(msg.c_str());
                        }
                        globalScope->childScopes.push_back(currentScope);
                }
#line 1311 "limbaj.tab.c"
    break;

  case 8: /* class_declaration: CLASS ID '{' $@1 class_block '}'  */
#line 75 "limbaj.y"
                {
                        currentScope = currentScope->exitScope(); //iesin din scope ul clasei
                        parentScope = currentScope;
                }
#line 1320 "limbaj.tab.c"
    break;

  case 10: /* class_var_section: %empty  */
#line 83 "limbaj.y"
                    {std::cout<<endl<<"No variables"<<endl;}
#line 1326 "limbaj.tab.c"
    break;

  case 12: /* class_methods_section: %empty  */
#line 87 "limbaj.y"
                        {std::cout<<endl<<"No methods"<<endl;}
#line 1332 "limbaj.tab.c"
    break;

  case 14: /* $@2: %empty  */
#line 92 "limbaj.y"
                        {
                        if(find(currentScope->classes.begin(),currentScope->classes.end(),(yyvsp[0].stringVal))==currentScope->classes.end()){
                                string msg="The class "+string((yyvsp[0].stringVal))+" doesn't exists";
                                yyerror(msg.c_str());
                        }

                        }
#line 1344 "limbaj.tab.c"
    break;

  case 15: /* $@3: %empty  */
#line 100 "limbaj.y"
                         {
                                if(currentScope->addVariable((yyvsp[0].stringVal),(yyvsp[-2].stringVal))==false){
                                string msg="The class name"+string((yyvsp[0].stringVal))+" doesn't exists";
                                        yyerror(msg.c_str());
                                }
                         }
#line 1355 "limbaj.tab.c"
    break;

  case 16: /* $@4: %empty  */
#line 108 "limbaj.y"
                          {
                                if(string((yyvsp[-6].stringVal))!=string((yyvsp[0].stringVal))){
                                        yyerror("Type mismatch: cannot instantiate class with a different constructor type");
                                }
                          }
#line 1365 "limbaj.tab.c"
    break;

  case 19: /* class_access: ID '.' ID  */
#line 118 "limbaj.y"
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
#line 1399 "limbaj.tab.c"
    break;

  case 20: /* $@5: %empty  */
#line 151 "limbaj.y"
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
#line 1440 "limbaj.tab.c"
    break;

  case 21: /* class_method_call: ID '.' ID $@5 '(' method_call_params ')'  */
#line 188 "limbaj.y"
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
#line 1465 "limbaj.tab.c"
    break;

  case 25: /* method_call_param: expression  */
#line 218 "limbaj.y"
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
#line 1481 "limbaj.tab.c"
    break;

  case 26: /* class_var_call: ID '.' ID ASSIGN expression  */
#line 233 "limbaj.y"
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
#line 1504 "limbaj.tab.c"
    break;

  case 27: /* class_var_call: ID '.' ID INC  */
#line 252 "limbaj.y"
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
#line 1530 "limbaj.tab.c"
    break;

  case 28: /* class_var_call: ID '.' ID DEC  */
#line 274 "limbaj.y"
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
#line 1556 "limbaj.tab.c"
    break;

  case 29: /* global_var_section: %empty  */
#line 299 "limbaj.y"
                    {std::cout<<endl<<"No global variables"<<endl;}
#line 1562 "limbaj.tab.c"
    break;

  case 33: /* var_decl: TYPE ID  */
#line 308 "limbaj.y"
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
#line 1587 "limbaj.tab.c"
    break;

  case 34: /* $@6: %empty  */
#line 329 "limbaj.y"
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
#line 1613 "limbaj.tab.c"
    break;

  case 35: /* var_decl: TYPE ID ASSIGN $@6 expression  */
#line 351 "limbaj.y"
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
#line 1628 "limbaj.tab.c"
    break;

  case 36: /* global_fun_section: %empty  */
#line 364 "limbaj.y"
                     {std::cout<<endl<<"No global functions"<<endl;}
#line 1634 "limbaj.tab.c"
    break;

  case 40: /* $@7: %empty  */
#line 374 "limbaj.y"
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
#line 1661 "limbaj.tab.c"
    break;

  case 41: /* fun_decl: TYPE ID '(' $@7 fun_decl_params ')' '{' fun_block '}'  */
#line 397 "limbaj.y"
         {
                currentScope = currentScope->exitScope();
                parentScope = currentScope;
         }
#line 1670 "limbaj.tab.c"
    break;

  case 45: /* fun_param: TYPE ID  */
#line 408 "limbaj.y"
        {
                parentScope->setFunctionParams(funName,(yyvsp[-1].stringVal));
                cout<<"adding variable "<<(yyvsp[0].stringVal)<<"to scope "<<currentScope->name<<endl;
                currentScope->addVariable((yyvsp[0].stringVal),(yyvsp[-1].stringVal));
        }
#line 1680 "limbaj.tab.c"
    break;

  case 49: /* block_element: statement  */
#line 421 "limbaj.y"
                        { yyerror("Missing semicolon");}
#line 1686 "limbaj.tab.c"
    break;

  case 51: /* block_element: var_decl  */
#line 423 "limbaj.y"
                       { yyerror("Missing semicolon");}
#line 1692 "limbaj.tab.c"
    break;

  case 59: /* $@8: %empty  */
#line 436 "limbaj.y"
        {
                if(currentScope->searchFunction((yyvsp[0].stringVal))==nullopt){
                        string msg="The called function "+string((yyvsp[0].stringVal)) +" doesn't exist!";
                        yyerror(msg.c_str());
                } else {
                        calling_functions.push((yyvsp[0].stringVal));
                        param_counts.push(0);
                }

        }
#line 1707 "limbaj.tab.c"
    break;

  case 60: /* fun_call: ID $@8 '(' fun_call_params ')'  */
#line 448 "limbaj.y"
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
#line 1731 "limbaj.tab.c"
    break;

  case 64: /* fun_call_param: expression  */
#line 476 "limbaj.y"
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
#line 1747 "limbaj.tab.c"
    break;

  case 66: /* print_statement: PRINT '(' print_expr ')'  */
#line 495 "limbaj.y"
                                           {cout<<endl<<(yyvsp[-1].stringVal)<<endl;
        free((yyvsp[-1].stringVal));
        }
#line 1755 "limbaj.tab.c"
    break;

  case 67: /* $@9: %empty  */
#line 507 "limbaj.y"
        {
                if(currentScope->searchVariable((yyvsp[-1].stringVal))==nullopt){
                        string msg="The variable "+string((yyvsp[-1].stringVal))+" doesn't exist!";
                        yyerror(msg.c_str());
                }
        }
#line 1766 "limbaj.tab.c"
    break;

  case 68: /* statement: ID ASSIGN $@9 expression  */
#line 513 "limbaj.y"
                    {
                string typeVarToBeAssigned=currentScope->getType((yyvsp[-3].stringVal));
                if(typeVarToBeAssigned!=string((yyvsp[0].stringVal))){
                        string msg="Type mismatch at assignment, trying operation on ["+typeVarToBeAssigned+"] and ["+string((yyvsp[0].stringVal))+"]";
                        yyerror(msg.c_str());
                }
                free((yyvsp[0].stringVal));
         }
#line 1779 "limbaj.tab.c"
    break;

  case 69: /* statement: ID INC  */
#line 522 "limbaj.y"
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
#line 1798 "limbaj.tab.c"
    break;

  case 70: /* statement: ID DEC  */
#line 537 "limbaj.y"
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
#line 1817 "limbaj.tab.c"
    break;

  case 71: /* expression: expression_elem OPERATOR expression  */
#line 554 "limbaj.y"
        { 
            if(string((yyvsp[-2].stringVal))!=string((yyvsp[0].stringVal))){
                string msg="Type mismatch, trying operation on ["+string((yyvsp[-2].stringVal))+"] and ["+string((yyvsp[0].stringVal))+"]";
                yyerror(msg.c_str());
            }
            (yyval.stringVal) = (yyvsp[-2].stringVal); 
            free((yyvsp[0].stringVal)); 
        }
#line 1830 "limbaj.tab.c"
    break;

  case 72: /* expression: expression_elem INC  */
#line 562 "limbaj.y"
                               {(yyval.stringVal)=(yyvsp[-1].stringVal);}
#line 1836 "limbaj.tab.c"
    break;

  case 73: /* expression: expression_elem DEC  */
#line 563 "limbaj.y"
                               {(yyval.stringVal)=(yyvsp[-1].stringVal);}
#line 1842 "limbaj.tab.c"
    break;

  case 74: /* expression: expression_elem  */
#line 564 "limbaj.y"
                          {(yyval.stringVal)=(yyvsp[0].stringVal);}
#line 1848 "limbaj.tab.c"
    break;

  case 77: /* expression_elem: INT  */
#line 570 "limbaj.y"
        {
                (yyval.stringVal)=strdup("int");
        }
#line 1856 "limbaj.tab.c"
    break;

  case 78: /* expression_elem: FLOAT  */
#line 574 "limbaj.y"
        {
                (yyval.stringVal)=strdup("float");
        }
#line 1864 "limbaj.tab.c"
    break;

  case 79: /* expression_elem: BOOL  */
#line 578 "limbaj.y"
        {
                (yyval.stringVal)=strdup("bool");

        }
#line 1873 "limbaj.tab.c"
    break;

  case 80: /* expression_elem: CHAR  */
#line 583 "limbaj.y"
        {

                (yyval.stringVal)=strdup("char");
        }
#line 1882 "limbaj.tab.c"
    break;

  case 81: /* expression_elem: STRING  */
#line 588 "limbaj.y"
        {
                (yyval.stringVal)=strdup("string");

        }
#line 1891 "limbaj.tab.c"
    break;

  case 82: /* expression_elem: ID  */
#line 593 "limbaj.y"
        {
                (yyval.stringVal)=strdup(currentScope->getType((yyvsp[0].stringVal)).c_str());
        }
#line 1899 "limbaj.tab.c"
    break;

  case 83: /* compare_expr: expression COMPARE expression  */
#line 601 "limbaj.y"
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
#line 1918 "limbaj.tab.c"
    break;

  case 92: /* main_block_element: statement  */
#line 638 "limbaj.y"
                        { yyerror("Missing semicolon");}
#line 1924 "limbaj.tab.c"
    break;


#line 1928 "limbaj.tab.c"

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

#line 651 "limbaj.y"

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
