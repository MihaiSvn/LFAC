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
#line 9 "limbaj.y"

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
int current_init_index=0;
string current_init_vec_name;



#line 108 "limbaj.tab.c"

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
  YYSYMBOL_UMINUS = 34,                    /* UMINUS  */
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
  YYSYMBOL_class_access = 54,              /* class_access  */
  YYSYMBOL_class_method_call = 55,         /* class_method_call  */
  YYSYMBOL_56_2 = 56,                      /* $@2  */
  YYSYMBOL_method_call_params = 57,        /* method_call_params  */
  YYSYMBOL_58_3 = 58,                      /* @3  */
  YYSYMBOL_class_var_call = 59,            /* class_var_call  */
  YYSYMBOL_global_var_section = 60,        /* global_var_section  */
  YYSYMBOL_variable_declarations = 61,     /* variable_declarations  */
  YYSYMBOL_var_decl = 62,                  /* var_decl  */
  YYSYMBOL_63_4 = 63,                      /* $@4  */
  YYSYMBOL_64_5 = 64,                      /* $@5  */
  YYSYMBOL_vector_elements = 65,           /* vector_elements  */
  YYSYMBOL_vector_element = 66,            /* vector_element  */
  YYSYMBOL_var_list = 67,                  /* var_list  */
  YYSYMBOL_global_fun_section = 68,        /* global_fun_section  */
  YYSYMBOL_function_declarations = 69,     /* function_declarations  */
  YYSYMBOL_fun_decl = 70,                  /* fun_decl  */
  YYSYMBOL_71_6 = 71,                      /* $@6  */
  YYSYMBOL_fun_decl_params = 72,           /* fun_decl_params  */
  YYSYMBOL_fun_param = 73,                 /* fun_param  */
  YYSYMBOL_fun_block = 74,                 /* fun_block  */
  YYSYMBOL_block_element = 75,             /* block_element  */
  YYSYMBOL_fun_call = 76,                  /* fun_call  */
  YYSYMBOL_77_7 = 77,                      /* $@7  */
  YYSYMBOL_fun_call_params = 78,           /* fun_call_params  */
  YYSYMBOL_79_8 = 79,                      /* @8  */
  YYSYMBOL_print_expr = 80,                /* print_expr  */
  YYSYMBOL_print_statement = 81,           /* print_statement  */
  YYSYMBOL_statement = 82,                 /* statement  */
  YYSYMBOL_83_9 = 83,                      /* $@9  */
  YYSYMBOL_exp = 84,                       /* exp  */
  YYSYMBOL_term = 85,                      /* term  */
  YYSYMBOL_factor = 86,                    /* factor  */
  YYSYMBOL_expression_elem = 87,           /* expression_elem  */
  YYSYMBOL_expression = 88,                /* expression  */
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
#define YYLAST   207

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  210

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
       0,    73,    73,    87,    88,    90,    91,    94,    93,   112,
     114,   115,   118,   119,   122,   177,   178,   213,   276,   275,
     341,   342,   357,   356,   380,   407,   443,   476,   518,   570,
     626,   627,   630,   631,   634,   664,   709,   708,   744,   786,
     785,   821,   825,   830,   861,   866,   873,   874,   878,   879,
     883,   882,   914,   915,   916,   919,   928,   929,   942,   944,
     945,   947,   948,   950,   952,   954,   956,   958,   965,   964,
    1000,  1001,  1015,  1014,  1036,  1039,  1050,  1066,  1091,  1117,
    1116,  1147,  1182,  1216,  1219,  1251,  1279,  1282,  1323,  1328,
    1336,  1343,  1344,  1346,  1347,  1348,  1352,  1356,  1360,  1364,
    1368,  1376,  1402,  1417,  1420,  1424,  1429,  1436,  1445,  1454,
    1458,  1463,  1465,  1466,  1468,  1470,  1472,  1474,  1476
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
  "'*'", "'/'", "'%'", "UMINUS", "'{'", "'}'", "'('", "')'", "'.'", "'['",
  "']'", "','", "';'", "$accept", "program", "class_section",
  "class_declarations", "class_declaration", "$@1", "class_block",
  "class_var_section", "class_methods_section", "class_create_instance",
  "class_access", "class_method_call", "$@2", "method_call_params", "@3",
  "class_var_call", "global_var_section", "variable_declarations",
  "var_decl", "$@4", "$@5", "vector_elements", "vector_element",
  "var_list", "global_fun_section", "function_declarations", "fun_decl",
  "$@6", "fun_decl_params", "fun_param", "fun_block", "block_element",
  "fun_call", "$@7", "fun_call_params", "@8", "print_expr",
  "print_statement", "statement", "$@9", "exp", "term", "factor",
  "expression_elem", "expression", "if_statement", "while_statement",
  "main", "main_fun_block", "main_block_element", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-161)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-69)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       8,    32,    19,    22,     9,    32,  -161,  -161,    49,    50,
      30,  -161,    56,    49,    48,    72,    54,  -161,     6,    51,
    -161,    76,    72,  -161,    64,  -161,    90,  -161,    86,    91,
    -161,    74,  -161,    75,    81,    17,    87,    66,    70,  -161,
      82,    83,    84,  -161,  -161,   129,  -161,    49,    92,   123,
      80,    89,    97,  -161,  -161,    80,    80,    80,   120,  -161,
    -161,   116,   117,   103,    80,  -161,  -161,  -161,  -161,  -161,
    -161,  -161,    49,  -161,    72,  -161,    65,  -161,  -161,  -161,
    -161,  -161,    80,    80,    80,  -161,  -161,  -161,    55,   119,
    -161,  -161,  -161,   135,    91,   145,   112,   114,  -161,   144,
      23,   115,    80,   121,  -161,    72,   141,   143,  -161,  -161,
     124,    80,    80,    80,    80,  -161,  -161,   142,    -6,  -161,
     128,   130,   150,    80,  -161,  -161,   151,   132,    27,   133,
     125,  -161,    18,   131,  -161,    53,   119,   119,  -161,   138,
    -161,   139,   145,    64,    64,   140,  -161,   134,    80,  -161,
    -161,  -161,  -161,  -161,   153,  -161,    80,  -161,  -161,    15,
      52,   147,    34,   149,   136,    80,    80,   148,   146,   137,
    -161,     4,   163,  -161,  -161,    80,  -161,  -161,  -161,  -161,
    -161,  -161,  -161,  -161,    80,  -161,   152,   154,   155,  -161,
     156,   157,   158,  -161,  -161,    12,  -161,    80,  -161,  -161,
    -161,  -161,  -161,  -161,  -161,    64,  -161,  -161,    57,  -161
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,    30,     0,     4,     5,     1,     0,    46,
       0,     6,     0,    31,     0,     0,     0,     7,    34,     0,
      32,     0,    47,    48,     0,     2,    10,    36,     0,     0,
      33,     0,    49,     0,     0,    68,     0,     0,     0,    83,
       0,     0,   112,   117,   118,     0,   109,     0,     0,    12,
       0,     0,    44,    35,    50,     0,     0,     0,     0,    77,
      78,     0,     0,     0,     0,   113,   114,   115,   116,   111,
     108,   110,    11,     8,     0,     9,   100,    95,    97,    96,
      99,    98,     0,     0,     0,    93,    15,    94,   103,    86,
      88,    92,    37,    38,     0,    52,     0,     0,    76,     0,
      18,     0,    70,     0,    74,    13,     0,     0,    90,    89,
       0,     0,     0,     0,     0,    39,    45,     0,     0,    53,
       0,     0,     0,     0,    25,    26,     0,     0,     0,     0,
      71,    75,    16,     0,    91,   102,    84,    85,    87,     0,
      55,     0,     0,     0,     0,     0,    24,     0,    20,    79,
      81,    82,    69,    72,     0,   101,     0,    56,    54,     0,
       0,     0,     0,     0,    21,     0,    70,     0,     0,    41,
      43,     0,   104,   107,    14,     0,    28,    29,    19,    22,
      80,    73,    17,    40,     0,    51,     0,     0,    61,    57,
       0,     0,    59,    66,    67,     0,    27,    20,    42,    62,
      63,    60,    64,    65,    58,     0,   106,    23,     0,   105
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -161,  -161,  -161,  -161,   175,  -161,  -161,  -161,  -161,    20,
    -161,   -24,  -161,    -9,  -161,  -161,  -161,   159,   -10,  -161,
    -161,    10,  -161,    96,  -161,   118,   -18,  -161,  -161,    60,
    -161,  -161,   -22,  -161,    37,  -161,  -161,    25,    33,  -161,
      94,   -23,   -73,  -161,   -42,  -160,    36,  -161,  -138,   -44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     5,     6,    26,    48,    49,    75,    37,
      85,    86,   127,   163,   197,    39,     9,    13,    14,    50,
     139,   168,   169,    53,    16,    22,    23,    95,   118,   119,
     171,   189,    87,    63,   129,   166,   103,    41,    42,   165,
      88,    89,    90,    91,   130,    43,    44,    25,    45,    46
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      38,    71,    40,    19,    32,   159,   160,    12,    92,   108,
     109,   193,     1,    96,    97,    98,    33,    27,    34,     7,
      35,    38,   104,    40,    33,    10,    36,    33,    57,    34,
       8,    35,   141,    58,   123,   206,   142,    36,   149,     4,
     185,   138,   110,    59,    60,   175,    28,   205,    29,   124,
     125,   172,    12,   150,   151,   -18,    61,    62,   154,    15,
     176,   177,    19,   126,    33,    17,    34,   208,    35,    33,
     111,    34,    18,    35,    36,    21,    33,    24,    34,    36,
      35,   146,   112,   113,   112,   113,    36,    32,   173,   136,
     137,    20,    31,   209,    30,    47,    76,    77,    78,    79,
      80,    81,   -68,    51,   106,   107,   164,    52,    82,    65,
      83,    54,    55,    66,   170,    71,    71,    84,    56,    38,
      38,    40,    40,   180,    64,    67,    68,    69,    73,    74,
      93,    99,   100,   196,   101,    38,    38,    40,    40,    94,
     102,    33,   170,    34,   114,    35,   115,   187,   117,   190,
     120,    36,   121,    70,   122,   164,   128,   132,   140,   131,
     133,   188,   134,   143,    71,   144,   145,   153,   147,   148,
     167,   152,   155,   156,   157,   162,   195,   161,   179,   184,
      11,    38,   183,    40,    38,   174,    40,   178,   207,   182,
     116,   186,   105,     0,   198,   199,   191,   200,   201,   202,
     203,   204,   158,   181,   192,   135,    72,   194
};

static const yytype_int16 yycheck[] =
{
      24,    45,    24,    13,    22,   143,   144,     3,    50,    82,
      83,   171,     4,    55,    56,    57,    12,    11,    14,     0,
      16,    45,    64,    45,    12,    16,    22,    12,    11,    14,
       8,    16,    38,    16,    11,   195,    42,    22,    11,     7,
      36,   114,    84,    26,    27,    11,    40,    35,    42,    26,
      27,    36,     3,    26,    27,    37,    39,    40,    40,     9,
      26,    27,    72,    40,    12,    35,    14,   205,    16,    12,
      15,    14,    16,    16,    22,     3,    12,    23,    14,    22,
      16,   123,    29,    30,    29,    30,    22,   105,    36,   112,
     113,    43,    16,    36,    43,     5,    16,    17,    18,    19,
      20,    21,    37,    17,    39,    40,   148,    16,    28,    43,
      30,    37,    37,    43,   156,   159,   160,    37,    37,   143,
     144,   143,   144,   165,    37,    43,    43,    43,    36,     6,
      41,    11,    16,   175,    17,   159,   160,   159,   160,    42,
      37,    12,   184,    14,    25,    16,    11,   171,     3,   171,
      38,    22,    38,    24,    10,   197,    41,    16,    16,    38,
      17,   171,    38,    35,   208,    35,    16,    42,    17,    37,
      17,    38,    41,    35,    35,    41,    13,    37,    42,    42,
       5,   205,    36,   205,   208,    38,   208,    38,   197,    41,
      94,   171,    74,    -1,   184,    43,   171,    43,    43,    43,
      43,    43,   142,   166,   171,   111,    47,   171
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    45,    46,     7,    47,    48,     0,     8,    60,
      16,    48,     3,    61,    62,     9,    68,    35,    16,    62,
      43,     3,    69,    70,    23,    91,    49,    11,    40,    42,
      43,    16,    70,    12,    14,    16,    22,    53,    55,    59,
      76,    81,    82,    89,    90,    92,    93,     5,    50,    51,
      63,    17,    16,    67,    37,    37,    37,    11,    16,    26,
      27,    39,    40,    77,    37,    43,    43,    43,    43,    43,
      24,    93,    61,    36,     6,    52,    16,    17,    18,    19,
      20,    21,    28,    30,    37,    54,    55,    76,    84,    85,
      86,    87,    88,    41,    42,    71,    88,    88,    88,    11,
      16,    17,    37,    80,    88,    69,    39,    40,    86,    86,
      88,    15,    29,    30,    25,    11,    67,     3,    72,    73,
      38,    38,    10,    11,    26,    27,    40,    56,    41,    78,
      88,    38,    16,    17,    38,    84,    85,    85,    86,    64,
      16,    38,    42,    35,    35,    16,    88,    17,    37,    11,
      26,    27,    38,    42,    40,    41,    35,    35,    73,    92,
      92,    37,    41,    57,    88,    83,    79,    17,    65,    66,
      88,    74,    36,    36,    38,    11,    26,    27,    38,    42,
      88,    78,    41,    36,    42,    36,    53,    55,    62,    75,
      76,    81,    82,    89,    90,    13,    88,    58,    65,    43,
      43,    43,    43,    43,    43,    35,    89,    57,    92,    36
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    49,    48,    50,
      51,    51,    52,    52,    53,    54,    54,    54,    56,    55,
      57,    57,    58,    57,    59,    59,    59,    59,    59,    59,
      60,    60,    61,    61,    62,    62,    63,    62,    62,    64,
      62,    65,    65,    66,    67,    67,    68,    68,    69,    69,
      71,    70,    72,    72,    72,    73,    74,    74,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    77,    76,
      78,    78,    79,    78,    80,    81,    82,    82,    82,    83,
      82,    82,    82,    82,    84,    84,    84,    85,    85,    86,
      86,    86,    86,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    88,    88,    89,    89,    89,    90,    91,    92,
      92,    93,    93,    93,    93,    93,    93,    93,    93
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     0,     2,     1,     2,     0,     6,     2,
       0,     2,     0,     2,     7,     1,     3,     6,     0,     7,
       0,     1,     0,     4,     5,     4,     4,     8,     7,     7,
       0,     2,     2,     3,     2,     4,     0,     5,     5,     0,
      10,     1,     3,     1,     1,     3,     0,     2,     1,     2,
       0,     9,     0,     1,     3,     2,     0,     2,     2,     1,
       2,     1,     2,     2,     2,     2,     1,     1,     0,     5,
       0,     1,     0,     4,     1,     4,     3,     2,     2,     0,
       7,     5,     5,     1,     3,     3,     1,     3,     1,     2,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     3,     1,     7,    11,     9,     7,     3,     1,
       2,     2,     1,     2,     2,     2,     2,     1,     1
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
#line 74 "limbaj.y"
{
if(errorCount == 0 && (yyvsp[0].node) != nullptr) {
        cout<<endl;
        (yyvsp[0].node)->printAST(0);
        cout << "--- Start Execution ---" << endl;
        (yyvsp[0].node)->evaluate(globalScope);
        cout << "--- Execution Finished Successfully ---" << endl;

    }

}
#line 1344 "limbaj.tab.c"
    break;

  case 3: /* class_section: %empty  */
#line 87 "limbaj.y"
                {std::cout<<endl<<"No classes"<<endl;}
#line 1350 "limbaj.tab.c"
    break;

  case 7: /* $@1: %empty  */
#line 94 "limbaj.y"
                {
                        if(currentScope->addClass((yyvsp[-1].stringVal))==true){
                                currentScope = currentScope->enterScope((yyvsp[-1].stringVal));  //intram in scope ul clasei
                        } else {
                                string msg="The class "+string((yyvsp[-1].stringVal))+" already exists";
                                yyerror(msg.c_str());
                        }
                        globalScope->childScopes.push_back(currentScope);
                }
#line 1364 "limbaj.tab.c"
    break;

  case 8: /* class_declaration: CLASS ID '{' $@1 class_block '}'  */
#line 106 "limbaj.y"
                {
                        currentScope = currentScope->exitScope(); //iesin din scope ul clasei
                        parentScope = currentScope;
                }
#line 1373 "limbaj.tab.c"
    break;

  case 10: /* class_var_section: %empty  */
#line 114 "limbaj.y"
                    {std::cout<<endl<<"No variables"<<endl;}
#line 1379 "limbaj.tab.c"
    break;

  case 12: /* class_methods_section: %empty  */
#line 118 "limbaj.y"
                        {std::cout<<endl<<"No methods"<<endl;}
#line 1385 "limbaj.tab.c"
    break;

  case 14: /* class_create_instance: ID ID ASSIGN NEW ID '(' ')'  */
#line 123 "limbaj.y"
                        {
                        if(find(globalScope->classes.begin(),globalScope->classes.end(),(yyvsp[-6].stringVal))==globalScope->classes.end()){
                                string msg="The class "+string((yyvsp[-6].stringVal))+" doesn't exists";
                                yyerror(msg.c_str());
                        }
                                if(currentScope->addVariable((yyvsp[-5].stringVal),(yyvsp[-6].stringVal))==false){
                                string msg="The class name"+string((yyvsp[-5].stringVal))+" doesn't exists";
                                        yyerror(msg.c_str());
                                }

                                if(string((yyvsp[-6].stringVal))!=string((yyvsp[-2].stringVal))){
                                        yyerror("Type mismatch: cannot instantiate class with a different constructor type");
                                }
                                
                                SymTable* classTemplate = globalScope->getChildScope(string((yyvsp[-6].stringVal)));
                                
                                if (classTemplate != nullptr) {
                
                                        for (auto const& [varName, info] : classTemplate->variables) {
                                        string memberName = string((yyvsp[-5].stringVal)) + "." + varName;
                                        string type = get<0>(info);
                                        string defaultValue = get<1>(info).value_or("0");
                                        
                                        currentScope->addVariable(memberName, type);
                                        currentScope->updateVarValue(memberName, defaultValue);
                                        }

                                        for (auto const& [vecName, info] : classTemplate->vectors) {
                                                string memberName = string((yyvsp[-5].stringVal)) + "." + vecName;
                                                string type = get<0>(info);
                                                int size = get<1>(info);
                                                
                                                currentScope->addVector(memberName, type, size);
                                                cout<<"ADDED VARIABLE "<<memberName<<" WITH VALUE "<< "0" <<endl;

                                                
                                                for (int i = 0; i < size; i++) {
                                                        currentScope->updateVectorElement(memberName, i, "0");
                                                }
                                                
                                        }
                                        cout << "DEBUG: Instantiated object " << string((yyvsp[-5].stringVal)) << " of class " << string((yyvsp[-6].stringVal)) << endl;

                                }
                                
                                ASTNode* objNode = new ASTNode("id", (yyvsp[-5].stringVal), (yyvsp[-6].stringVal));
                                ASTNode* classTypeNode = new ASTNode("id", (yyvsp[-6].stringVal), "CLASS_TYPE");
                                
                                (yyval.node) = new ASTNode(objNode, "NEW_CLASS", classTypeNode);

                          
                        }
#line 1442 "limbaj.tab.c"
    break;

  case 16: /* class_access: ID '.' ID  */
#line 179 "limbaj.y"
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
                string typeMember;
                if(var.has_value()){
                        auto [tip,valoarea,clasa] = var.value();
                        typeMember=tip;
                        if(clasa.has_value()){  //daca este o variabila de clasa
                                string cls = clasa.value();
                                if(cls!=classType){
                                        string msg="the variable"+string((yyvsp[0].stringVal))+"is in a different class";
                                        yyerror(msg.c_str());
                                } else {
                                }
                        }
                } else {
                        string msg="The class variable "+string((yyvsp[0].stringVal))+" doesn't exist";
                    yyerror(msg.c_str());
                }

                string fullName = string((yyvsp[-2].stringVal)) + "." + string((yyvsp[0].stringVal));

                (yyval.node) = new ASTNode("id", fullName, typeMember);           
                
            }
#line 1481 "limbaj.tab.c"
    break;

  case 17: /* class_access: ID '.' ID '[' INT ']'  */
#line 214 "limbaj.y"
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
                string typevec;
                if(var.has_value()){
                        auto [tip,numberElements,valori,clasa] = var.value();
                        typevec=tip;

                        if((yyvsp[-1].intVal) >= numberElements || (yyvsp[-1].intVal) < 0){
                        yyerror("Vector index out of bounds!");
                        }

                        string fullVecName = string((yyvsp[-5].stringVal)) + "." + string((yyvsp[-3].stringVal));
                        
                        if(!currentScope->searchVector(fullVecName)) {
                                currentScope->addVector(fullVecName, typevec, numberElements);
                        }

                       
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
                                }
                        }
                } else {
                        string msg="The class vector "+string((yyvsp[-3].stringVal))+" doesn't exist";
                    yyerror(msg.c_str());
                }

                string fullVecName = string((yyvsp[-5].stringVal)) + "." + string((yyvsp[-3].stringVal));

                ASTNode* vecNode = new ASTNode("id", fullVecName, typevec);
                ASTNode* indexNode = new ASTNode("int", to_string((yyvsp[-1].intVal)), "int");
                (yyval.node) = new ASTNode(vecNode, "[]", indexNode);

        
                
            }
#line 1544 "limbaj.tab.c"
    break;

  case 18: /* $@2: %empty  */
#line 276 "limbaj.y"
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
#line 1585 "limbaj.tab.c"
    break;

  case 19: /* class_method_call: ID '.' ID $@2 '(' method_call_params ')'  */
#line 313 "limbaj.y"
                  {
                        string current_fun = calling_functions.top();
                        int total_params = param_counts.top();

                        if(aux->verifParamNumber(current_fun, total_params) == false){
                                string msg="The method "+current_fun+" doesn't have the correct number of parameters";
                                yyerror(msg.c_str());
                        }

                       auto fun = aux->searchFunction((yyvsp[-4].stringVal));
                        if(fun==nullopt){
                                yyerror("error at finding method");
                        }
                        auto [tip,parametrii,clasa] = fun.value();
                        ASTNode* obj = new ASTNode("id", (yyvsp[-6].stringVal), clasa.value());
                        ASTNode* method = new ASTNode("id", (yyvsp[-4].stringVal), tip);
                        ASTNode* accessNode = new ASTNode(obj, ".", method);
                        ASTNode* tempCall = new ASTNode(accessNode, "METHOD_CALL", (yyvsp[-1].node));
        
                        // $$ = tempCall->evaluate(currentScope);

                        calling_functions.pop();
                        param_counts.pop();

                        
                  }
#line 1616 "limbaj.tab.c"
    break;

  case 20: /* method_call_params: %empty  */
#line 341 "limbaj.y"
                     {(yyval.node)=nullptr;}
#line 1622 "limbaj.tab.c"
    break;

  case 21: /* method_call_params: expression  */
#line 343 "limbaj.y"
            {
                string c_fun = calling_functions.top();
                int c_idx = param_counts.top();
                
                ASTNode* evaluatedExpr = (yyvsp[0].node)->evaluate(currentScope);

                if(aux->verifParamType(c_fun, c_idx, evaluatedExpr->exprType) == false){
                    string msg = "Parameter " + to_string(c_idx) + " in " + c_fun + " is of type " + (yyvsp[0].node)->exprType + " but should be different.";
                    yyerror(msg.c_str());
                }
                param_counts.top()++;
                (yyval.node) = new ASTNode(evaluatedExpr, "ARG", nullptr);
            }
#line 1640 "limbaj.tab.c"
    break;

  case 22: /* @3: %empty  */
#line 357 "limbaj.y"
            {
                string c_fun = calling_functions.top();
                int c_idx = param_counts.top();
                
                ASTNode* evaluatedExpr = (yyvsp[-1].node)->evaluate(currentScope);
                
                if(aux->verifParamType(c_fun, c_idx, evaluatedExpr->exprType) == false){
                yyerror("Type mismatch in method call parameters");
                }
                
                param_counts.top()++;
                (yyval.node) = evaluatedExpr; 
             }
#line 1658 "limbaj.tab.c"
    break;

  case 23: /* method_call_params: expression ',' @3 method_call_params  */
#line 371 "limbaj.y"
             {
                (yyval.node) = new ASTNode((yyvsp[-1].node), "ARG", (yyvsp[0].node));
             }
#line 1666 "limbaj.tab.c"
    break;

  case 24: /* class_var_call: ID '.' ID ASSIGN expression  */
#line 381 "limbaj.y"
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
                string exprType = (yyvsp[0].node)->exprType;
                        if(memberType != exprType) {
                                string msg = "Cannot assign [" + exprType + "] to member '" + string((yyvsp[-4].stringVal)) + "." + string((yyvsp[-2].stringVal)) + "' of type [" + memberType + "]";
                                yyerror(msg.c_str());
                        }

                        currentScope->updateVarValue(string((yyvsp[-4].stringVal))+'.'+string((yyvsp[-2].stringVal)), (yyvsp[0].node)->getStringValue());

                        string fullName = string((yyvsp[-4].stringVal)) + "." + string((yyvsp[-2].stringVal));

                        ASTNode* nod = new ASTNode("id", fullName, memberType);   

                        (yyval.node) = new ASTNode(nod,":=",(yyvsp[0].node));
                }
                
                }
#line 1697 "limbaj.tab.c"
    break;

  case 25: /* class_var_call: ID '.' ID INC  */
#line 408 "limbaj.y"
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

                auto [tip,val,clasa] = var.value(); 
                string memberType = std::get<0>(var.value());
                // currentScope->updateVarValueInClass($1,$3, memberType, val+1,globalScope);

               
                string fullName = string((yyvsp[-3].stringVal)) + "." + string((yyvsp[-1].stringVal));

                ASTNode* nod = new ASTNode("id", fullName, memberType);   
                ASTNode* nod_c = new ASTNode("id", fullName, memberType);   
                ASTNode* unu = new ASTNode("int","1","int");
                ASTNode* plus=new ASTNode(nod_c,"+",unu);

                (yyval.node) = new ASTNode(nod,":=",plus);
            }
#line 1737 "limbaj.tab.c"
    break;

  case 26: /* class_var_call: ID '.' ID DEC  */
#line 444 "limbaj.y"
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
                string memberType = std::get<0>(var.value());

               
                string fullName = string((yyvsp[-3].stringVal)) + "." + string((yyvsp[-1].stringVal));

                ASTNode* nod = new ASTNode("id", fullName, memberType);   
                ASTNode* nod_c = new ASTNode("id", fullName, memberType);   
                ASTNode* unu = new ASTNode("int","1","int");
                ASTNode* minus=new ASTNode(nod_c,"-",unu);

                (yyval.node) = new ASTNode(nod,":=",minus);
            }
#line 1774 "limbaj.tab.c"
    break;

  case 27: /* class_var_call: ID '.' ID '[' INT ']' ASSIGN expression  */
#line 477 "limbaj.y"
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
                string exprType = (yyvsp[0].node)->exprType;
                if(memberType != exprType) {
                        string msg = "Cannot assign [" + exprType + "] to member '" + string((yyvsp[-7].stringVal)) + "." + string((yyvsp[-5].stringVal)) + "' of type [" + memberType + "]";
                        yyerror(msg.c_str());
                        }
                        currentScope->updateVectorElement(string((yyvsp[-7].stringVal))+'.'+string((yyvsp[-5].stringVal)), (yyvsp[-3].intVal) , (yyvsp[0].node)->getStringValue());

                        string fullVecName = string((yyvsp[-7].stringVal)) + "." + string((yyvsp[-5].stringVal));
        
                        ASTNode* vectorNode = new ASTNode("id_vector", fullVecName, memberType);
                        
                        ASTNode* indexNode = new ASTNode("int", to_string((yyvsp[-3].intVal)), "int");

                        ASTNode* vectorAccess = new ASTNode(vectorNode, "[]", indexNode);
                        vectorAccess->exprType = memberType;

                        (yyval.node) = new ASTNode(vectorAccess, ":=", (yyvsp[0].node));
                }
                
                }
#line 1820 "limbaj.tab.c"
    break;

  case 28: /* class_var_call: ID '.' ID '[' INT ']' INC  */
#line 519 "limbaj.y"
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

                string fullName = string((yyvsp[-6].stringVal)) + "." + string((yyvsp[-4].stringVal));

                ASTNode* destVecName = new ASTNode("id", fullName, memberType);
                ASTNode* destIndex = new ASTNode("int", to_string((yyvsp[-2].intVal)), "int");
                ASTNode* vectorDest = new ASTNode(destVecName, "[]", destIndex);

                
                ASTNode* readVecName = new ASTNode("id", fullName, memberType);
                ASTNode* readIndex = new ASTNode("int", to_string((yyvsp[-2].intVal)), "int");
                ASTNode* vectorRead = new ASTNode(readVecName, "[]", readIndex);

               
                ASTNode* unu = new ASTNode("int", "1", "int");
                ASTNode* plus = new ASTNode(vectorRead, "+", unu);

                
                (yyval.node) = new ASTNode(vectorDest, ":=", plus);

                } else {
                string msg = "Class member '" + string((yyvsp[-4].stringVal)) + "' not found in class '" + className + "'";
                yyerror(msg.c_str());
                }

                
            }
#line 1876 "limbaj.tab.c"
    break;

  case 29: /* class_var_call: ID '.' ID '[' INT ']' DEC  */
#line 571 "limbaj.y"
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

                string fullName = string((yyvsp[-6].stringVal)) + "." + string((yyvsp[-4].stringVal));

                ASTNode* destVecName = new ASTNode("id", fullName, memberType);
                ASTNode* destIndex = new ASTNode("int", to_string((yyvsp[-2].intVal)), "int");
                ASTNode* vectorDest = new ASTNode(destVecName, "[]", destIndex);

                
                ASTNode* readVecName = new ASTNode("id", fullName, memberType);
                ASTNode* readIndex = new ASTNode("int", to_string((yyvsp[-2].intVal)), "int");
                ASTNode* vectorRead = new ASTNode(readVecName, "[]", readIndex);

               
                ASTNode* unu = new ASTNode("int", "1", "int");
                ASTNode* minus = new ASTNode(vectorRead, "-", unu);

                
                (yyval.node) = new ASTNode(vectorDest, ":=", minus);


                } else {
                string msg = "Class member '" + string((yyvsp[-4].stringVal)) + "' not found in class '" + className + "'";
                yyerror(msg.c_str());
                }
                
            }
#line 1932 "limbaj.tab.c"
    break;

  case 30: /* global_var_section: %empty  */
#line 626 "limbaj.y"
                    {std::cout<<endl<<"No global variables"<<endl;}
#line 1938 "limbaj.tab.c"
    break;

  case 34: /* var_decl: TYPE ID  */
#line 635 "limbaj.y"
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
                string defaultValue = "0";
                if (string((yyvsp[-1].stringVal)) == "float") defaultValue = "0.0";
                else if (string((yyvsp[-1].stringVal)) == "bool") defaultValue = "true";
                else if (string((yyvsp[-1].stringVal)) == "string") defaultValue = "";
                else if (string((yyvsp[-1].stringVal)) == "char") defaultValue = "";
                ASTNode* varNode = new ASTNode("id", (yyvsp[0].stringVal), currentVarType);
                ASTNode* defaultValNode = new ASTNode((yyvsp[-1].stringVal), defaultValue, (yyvsp[-1].stringVal));
                
                (yyval.node) = new ASTNode(varNode, ":=", defaultValNode);
        }
#line 1972 "limbaj.tab.c"
    break;

  case 35: /* var_decl: TYPE ID ',' var_list  */
#line 665 "limbaj.y"
            {
                

                string type = (yyvsp[-3].stringVal);
                vector<string>* ids = (yyvsp[0].idList);
                ids->push_back((yyvsp[-2].stringVal));

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
                                if(currentScope->addVariable(idName,(yyvsp[-3].stringVal),nullopt,className)){
                                        currentVarType = (yyvsp[-3].stringVal);
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
#line 2020 "limbaj.tab.c"
    break;

  case 36: /* $@4: %empty  */
#line 709 "limbaj.y"
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
#line 2045 "limbaj.tab.c"
    break;

  case 37: /* var_decl: TYPE ID ASSIGN $@4 expression  */
#line 730 "limbaj.y"
             {
                string typeVarToBeAssigned=(yyvsp[-4].stringVal);
                string typeExpr=(yyvsp[0].node)->exprType;
                if(typeVarToBeAssigned!=typeExpr){
                        string msg="Type mismatch at declaration, trying operation on ["+typeVarToBeAssigned+"] and ["+typeExpr+"]";
                        yyerror(msg.c_str());
                }
                if((yyvsp[0].node)->type != astERROR){
                        currentScope->updateVarValue((yyvsp[-3].stringVal), (yyvsp[0].node)->getStringValue());
                }
                cout<<"TIPUL MEU E ASTA UAII "<<(yyvsp[-4].stringVal)<<endl;
                ASTNode* varNode = new ASTNode("id", (yyvsp[-3].stringVal), (yyvsp[-4].stringVal));
                (yyval.node) = new ASTNode(varNode, ":=", (yyvsp[0].node));
             }
#line 2064 "limbaj.tab.c"
    break;

  case 38: /* var_decl: TYPE ID '[' INT ']'  */
#line 745 "limbaj.y"
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
                ASTNode* rootBlock = nullptr;
                string defaultValue = "0";

                for (int i = 0; i < (yyvsp[-1].intVal); i++) {
                        ASTNode* indexNode = new ASTNode("int", to_string(i), "int");
                        ASTNode* vecNode = new ASTNode("id_vector", (yyvsp[-3].stringVal), (yyvsp[-4].stringVal));
                        ASTNode* access = new ASTNode(vecNode, "[]", indexNode);
                        
                        ASTNode* zero = new ASTNode((yyvsp[-4].stringVal), defaultValue, (yyvsp[-4].stringVal));
                        
                        ASTNode* assign = new ASTNode(access, ":=", zero);

                        if (rootBlock == nullptr) {
                        rootBlock = assign;
                        } else {
                        rootBlock = new ASTNode(assign, "BLOCK", rootBlock);
                        }
                }
                (yyval.node) = rootBlock;

             }
#line 2109 "limbaj.tab.c"
    break;

  case 39: /* $@5: %empty  */
#line 786 "limbaj.y"
             {
                current_init_index=0;
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
                current_init_vec_name=string((yyvsp[-4].stringVal));
                numberOfElementsToAdd=(yyvsp[-2].intVal);
                cout<<"NUMBER OF ELEMENTS TO ADD "<<numberOfElementsToAdd<<endl;
             }
#line 2139 "limbaj.tab.c"
    break;

  case 40: /* var_decl: TYPE ID '[' INT ']' ASSIGN $@5 '{' vector_elements '}'  */
#line 812 "limbaj.y"
              {
                if(numberOfElementsToAdd>0){
                       string msg="Vector init received too few arguments";
                        yyerror(msg.c_str());  
                }
                (yyval.node)=nullptr;
              }
#line 2151 "limbaj.tab.c"
    break;

  case 41: /* vector_elements: vector_element  */
#line 822 "limbaj.y"
                {
                        (yyval.node)=(yyvsp[0].node);
                }
#line 2159 "limbaj.tab.c"
    break;

  case 42: /* vector_elements: vector_element ',' vector_elements  */
#line 826 "limbaj.y"
             {
                (yyval.node) = new ASTNode((yyvsp[-2].node),"BLOCK",(yyvsp[0].node));
             }
#line 2167 "limbaj.tab.c"
    break;

  case 43: /* vector_element: expression  */
#line 831 "limbaj.y"
                {
                        if(numberOfElementsToAdd<=0){
                                string msg="Vector init received too many arguments";
                                yyerror(msg.c_str());
                        }
                        if((yyvsp[0].node)->exprType!=string(currentVarType)){
                                string msg="Tried adding a variable of type "+ (yyvsp[0].node)->exprType + " to a vector of type "+string(currentVarType);
                                yyerror(msg.c_str());
                        }
                        

                        if((yyvsp[0].node)->exprType != currentVarType) {
                        string msg = "Type mismatch in vector init: expected " + string(currentVarType) + " but got "+(yyvsp[0].node)->exprType;
                        yyerror(msg.c_str());
                        }

                        if(!currentScope->updateVectorElement(current_init_vec_name, current_init_index, (yyvsp[0].node)->getStringValue())) {
                                yyerror("Index out of bounds during initialization!");
                        }

                        ASTNode* indexNode = new ASTNode("int", to_string(current_init_index), "int");
                        ASTNode* vecNode = new ASTNode("id_vector", current_init_vec_name, currentVarType);
                        ASTNode* access = new ASTNode(vecNode, "[]", indexNode);

                    
                        (yyval.node) = new ASTNode(access, ":=", (yyvsp[0].node));
                        current_init_index++;
                        numberOfElementsToAdd--;
                }
#line 2201 "limbaj.tab.c"
    break;

  case 44: /* var_list: ID  */
#line 862 "limbaj.y"
    { 
        (yyval.idList) = new vector<string>(); 
        (yyval.idList)->push_back((yyvsp[0].stringVal)); 
    }
#line 2210 "limbaj.tab.c"
    break;

  case 45: /* var_list: ID ',' var_list  */
#line 867 "limbaj.y"
    { 
        (yyvsp[0].idList)->push_back((yyvsp[-2].stringVal)); 
        (yyval.idList) = (yyvsp[0].idList); 
    }
#line 2219 "limbaj.tab.c"
    break;

  case 46: /* global_fun_section: %empty  */
#line 873 "limbaj.y"
                     {std::cout<<endl<<"No global functions"<<endl;}
#line 2225 "limbaj.tab.c"
    break;

  case 50: /* $@6: %empty  */
#line 883 "limbaj.y"
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
#line 2252 "limbaj.tab.c"
    break;

  case 51: /* fun_decl: TYPE ID '(' $@6 fun_decl_params ')' '{' fun_block '}'  */
#line 906 "limbaj.y"
         {
                ASTNode* bodyContent = (yyvsp[-1].node);
                currentScope = currentScope->exitScope();
                currentScope->setFunctionBody((yyvsp[-7].stringVal), bodyContent);
                parentScope = currentScope;
                (yyval.node)=nullptr;
         }
#line 2264 "limbaj.tab.c"
    break;

  case 55: /* fun_param: TYPE ID  */
#line 920 "limbaj.y"
        {
                parentScope->addParamName(funName, (yyvsp[0].stringVal));
                parentScope->setFunctionParams(funName,(yyvsp[-1].stringVal));
                cout<<"adding variable "<<(yyvsp[0].stringVal)<<"to scope "<<currentScope->name<<endl;
                currentScope->addVariable((yyvsp[0].stringVal),(yyvsp[-1].stringVal));
        }
#line 2275 "limbaj.tab.c"
    break;

  case 56: /* fun_block: %empty  */
#line 928 "limbaj.y"
            {(yyval.node)=nullptr;}
#line 2281 "limbaj.tab.c"
    break;

  case 57: /* fun_block: fun_block block_element  */
#line 930 "limbaj.y"
        {
                if ((yyvsp[-1].node) == nullptr) {
                    (yyval.node) = (yyvsp[0].node);
                } else if ((yyvsp[0].node) == nullptr) {
                    (yyval.node) = (yyvsp[-1].node);
                } else {
                    (yyval.node) = new ASTNode((yyvsp[-1].node), "BLOCK", (yyvsp[0].node));
                }
        }
#line 2295 "limbaj.tab.c"
    break;

  case 58: /* block_element: statement ';'  */
#line 943 "limbaj.y"
                { (yyval.node) = (yyvsp[-1].node); }
#line 2301 "limbaj.tab.c"
    break;

  case 59: /* block_element: statement  */
#line 944 "limbaj.y"
                        { yyerror("Missing semicolon"); (yyval.node) = (yyvsp[0].node); }
#line 2307 "limbaj.tab.c"
    break;

  case 60: /* block_element: var_decl ';'  */
#line 946 "limbaj.y"
                { (yyval.node) = nullptr; }
#line 2313 "limbaj.tab.c"
    break;

  case 61: /* block_element: var_decl  */
#line 947 "limbaj.y"
                       { yyerror("Missing semicolon"); (yyval.node) = nullptr; }
#line 2319 "limbaj.tab.c"
    break;

  case 62: /* block_element: class_create_instance ';'  */
#line 949 "limbaj.y"
                { (yyval.node) = nullptr; }
#line 2325 "limbaj.tab.c"
    break;

  case 63: /* block_element: class_method_call ';'  */
#line 951 "limbaj.y"
                { (yyval.node) = (yyvsp[-1].node); }
#line 2331 "limbaj.tab.c"
    break;

  case 64: /* block_element: fun_call ';'  */
#line 953 "limbaj.y"
                { (yyval.node) = (yyvsp[-1].node); }
#line 2337 "limbaj.tab.c"
    break;

  case 65: /* block_element: print_statement ';'  */
#line 955 "limbaj.y"
                { (yyval.node) = (yyvsp[-1].node); }
#line 2343 "limbaj.tab.c"
    break;

  case 66: /* block_element: if_statement  */
#line 957 "limbaj.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 2349 "limbaj.tab.c"
    break;

  case 67: /* block_element: while_statement  */
#line 959 "limbaj.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 2355 "limbaj.tab.c"
    break;

  case 68: /* $@7: %empty  */
#line 965 "limbaj.y"
        {
                if(currentScope->searchFunction((yyvsp[0].stringVal))==nullopt){
                        string msg="The called function "+string((yyvsp[0].stringVal)) +" doesn't exist!";
                        yyerror(msg.c_str());
                } else {
                        calling_functions.push((yyvsp[0].stringVal));
                        param_counts.push(0);
                }

        }
#line 2370 "limbaj.tab.c"
    break;

  case 69: /* fun_call: ID $@7 '(' fun_call_params ')'  */
#line 977 "limbaj.y"
        {
                string current_fun = calling_functions.top();
                int total_params = param_counts.top();

                if(currentScope->verifParamNumber(current_fun, total_params) == false){
                        string msg="The function call "+current_fun+" doesn't have the correct number of parameters";
                        yyerror(msg.c_str());
                }

                auto fun=currentScope->searchFunction(current_fun);
                auto [tip,params,clasa]=fun.value();

                ASTNode* nameNode = new ASTNode("id", (char*)current_fun.c_str(), tip);
                ASTNode* tempCall = new ASTNode(nameNode, "CALL", (yyvsp[-1].node));
                ASTNode* result = tempCall->evaluate(globalScope);
                
                (yyval.node) = result;

                calling_functions.pop();
                param_counts.pop();
        }
#line 2396 "limbaj.tab.c"
    break;

  case 70: /* fun_call_params: %empty  */
#line 1000 "limbaj.y"
                  {(yyval.node)=nullptr;}
#line 2402 "limbaj.tab.c"
    break;

  case 71: /* fun_call_params: expression  */
#line 1002 "limbaj.y"
            {
                string c_fun = calling_functions.top();
                int c_idx = param_counts.top();
                

                if(currentScope->verifParamType(c_fun, c_idx, (yyvsp[0].node)->exprType) == false){
                    string msg = "Parameter " + to_string(c_idx) + " in " + c_fun + " is of type " + (yyvsp[0].node)->exprType + " but should be different.";
                    yyerror(msg.c_str());
                }
                param_counts.top()++;
                (yyval.node) = new ASTNode((yyvsp[0].node), "ARG", nullptr);
            }
#line 2419 "limbaj.tab.c"
    break;

  case 72: /* @8: %empty  */
#line 1015 "limbaj.y"
            {
                string c_fun = calling_functions.top();
                int c_idx = param_counts.top();
                if(currentScope->verifParamType(c_fun, c_idx, (yyvsp[-1].node)->exprType) == false){
                     yyerror("Type mismatch");
                }
                param_counts.top()++;
                (yyval.node) = (yyvsp[-1].node);
            }
#line 2433 "limbaj.tab.c"
    break;

  case 73: /* fun_call_params: expression ',' @8 fun_call_params  */
#line 1025 "limbaj.y"
            {
                (yyval.node) = new ASTNode((yyvsp[-1].node), "ARG", (yyvsp[0].node));
            }
#line 2441 "limbaj.tab.c"
    break;

  case 74: /* print_expr: expression  */
#line 1036 "limbaj.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 2447 "limbaj.tab.c"
    break;

  case 75: /* print_statement: PRINT '(' print_expr ')'  */
#line 1039 "limbaj.y"
                                           {
        (yyval.node)= new ASTNode((yyvsp[-1].node),"PRINT",nullptr);
        }
#line 2455 "limbaj.tab.c"
    break;

  case 76: /* statement: ID ASSIGN expression  */
#line 1051 "limbaj.y"
        {
                if(currentScope->searchVariable((yyvsp[-2].stringVal))==nullopt){
                        string msg="The variable "+string((yyvsp[-2].stringVal))+" doesn't exist!";
                        yyerror(msg.c_str());
                }

                 string typeVarToBeAssigned=currentScope->getType((yyvsp[-2].stringVal));
                string type=(yyvsp[0].node)->exprType;
                if(typeVarToBeAssigned!=type){
                        string msg="Type mismatch at assignment, trying operation on ["+typeVarToBeAssigned+"] and ["+type+"]";
                        yyerror(msg.c_str());
                }
                ASTNode* idNode = new ASTNode("id", (yyvsp[-2].stringVal), type);
                (yyval.node) = new ASTNode(idNode, ":=", (yyvsp[0].node));
        }
#line 2475 "limbaj.tab.c"
    break;

  case 77: /* statement: ID INC  */
#line 1067 "limbaj.y"
        {
                if(currentScope->searchVariable((yyvsp[-1].stringVal))==nullopt){
                        string msg="The variable "+string((yyvsp[-1].stringVal))+" doesn't exist!";
                        yyerror(msg.c_str());
                }
                string typeVarToBeAssigned=currentScope->getType((yyvsp[-1].stringVal));
                cout<<"TYPE TO ASSIGN: "<<typeVarToBeAssigned<<endl;
                if(typeVarToBeAssigned=="int" || typeVarToBeAssigned=="float"){
                        ASTNode* idNode = new ASTNode("id", (yyvsp[-1].stringVal), typeVarToBeAssigned);
                        ASTNode* unu = new ASTNode("int", "1", "int");
                        ASTNode* plus = new ASTNode(idNode, "+", unu);
                        (yyval.node) = new ASTNode(idNode, ":=", plus);
                } else {
                        string msg="The variable "+string((yyvsp[-1].stringVal))+ " isn't a float or an int, you can't increment it!";
                        yyerror(msg.c_str());
                }
                ASTNode* dest = new ASTNode("id", (yyvsp[-1].stringVal), typeVarToBeAssigned);
            
                ASTNode* source = new ASTNode("id", (yyvsp[-1].stringVal), typeVarToBeAssigned);
                ASTNode* unu = new ASTNode("int", "1", "int");
                ASTNode* plus = new ASTNode(source, "+", unu);
                
                (yyval.node) = new ASTNode(dest, ":=", plus);
        }
#line 2504 "limbaj.tab.c"
    break;

  case 78: /* statement: ID DEC  */
#line 1092 "limbaj.y"
        {
                if(currentScope->searchVariable((yyvsp[-1].stringVal))==nullopt){
                        string msg="The variable "+string((yyvsp[-1].stringVal))+" doesn't exist!";
                        yyerror(msg.c_str());
                }
                string typeVarToBeAssigned=currentScope->getType((yyvsp[-1].stringVal));
                cout<<"TYPE TO ASSIGN: "<<typeVarToBeAssigned<<endl;
                if(typeVarToBeAssigned=="int" || typeVarToBeAssigned=="float"){
                        ASTNode* idNode = new ASTNode("id", (yyvsp[-1].stringVal), typeVarToBeAssigned);
                        ASTNode* unu = new ASTNode("int", "1", "int");
                        ASTNode* minus = new ASTNode(idNode, "-", unu);
                        (yyval.node) = new ASTNode(idNode, ":=", minus);
                } else {
                        string msg="The variable "+string((yyvsp[-1].stringVal))+ " isn't a float or an int, you can't increment it!";
                        yyerror(msg.c_str());
                }
                ASTNode* dest = new ASTNode("id", (yyvsp[-1].stringVal), typeVarToBeAssigned);
            
                ASTNode* source = new ASTNode("id", (yyvsp[-1].stringVal), typeVarToBeAssigned);
                ASTNode* unu = new ASTNode("int", "1", "int");
                ASTNode* minus = new ASTNode(source, "-", unu);
                
                (yyval.node) = new ASTNode(dest, ":=", minus);
        }
#line 2533 "limbaj.tab.c"
    break;

  case 79: /* $@9: %empty  */
#line 1117 "limbaj.y"
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
#line 2556 "limbaj.tab.c"
    break;

  case 80: /* statement: ID '[' INT ']' ASSIGN $@9 expression  */
#line 1135 "limbaj.y"
                    {
                string typeVarToBeAssigned=currentScope->getType((yyvsp[-6].stringVal));
                string type = (yyvsp[0].node)->exprType;
                if(typeVarToBeAssigned!=type){
                        string msg="Type mismatch at assignment, trying operation on ["+typeVarToBeAssigned+"] and ["+type+"]";
                        yyerror(msg.c_str());
                }
                ASTNode* vecName = new ASTNode("id_vector", (yyvsp[-6].stringVal), typeVarToBeAssigned);
                ASTNode* indexNode = new ASTNode("int", to_string((yyvsp[-4].intVal)), "int");
                ASTNode* access = new ASTNode(vecName, "[]", indexNode);
                (yyval.node) = new ASTNode(access, ":=", (yyvsp[0].node));
         }
#line 2573 "limbaj.tab.c"
    break;

  case 81: /* statement: ID '[' INT ']' INC  */
#line 1148 "limbaj.y"
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

                ASTNode* vecName = new ASTNode("id_vector", (yyvsp[-4].stringVal), typeVarToBeAssigned);
                ASTNode* indexNode = new ASTNode("int", to_string((yyvsp[-2].intVal)), "int");
                ASTNode* access = new ASTNode(vecName, "[]", indexNode);
                ASTNode* unu = new ASTNode("int", "1", "int");
                ASTNode* plus = new ASTNode(access, "+", unu);
                
                (yyval.node) = new ASTNode(access, ":=", plus);
        }
#line 2612 "limbaj.tab.c"
    break;

  case 82: /* statement: ID '[' INT ']' DEC  */
#line 1183 "limbaj.y"
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
                ASTNode* vecName = new ASTNode("id_vector", (yyvsp[-4].stringVal), typeVarToBeAssigned);
                ASTNode* indexNode = new ASTNode("int", to_string((yyvsp[-2].intVal)), "int");
                ASTNode* access = new ASTNode(vecName, "[]", indexNode);
                ASTNode* unu = new ASTNode("int", "1", "int");
                ASTNode* minus = new ASTNode(access, "-", unu);
                
                (yyval.node) = new ASTNode(access, ":=", minus);
        }
#line 2650 "limbaj.tab.c"
    break;

  case 84: /* exp: exp '+' term  */
#line 1220 "limbaj.y"
        {
                string type1=(yyvsp[-2].node)->exprType;
                string type2=(yyvsp[0].node)->exprType;
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
            (yyval.node) = new ASTNode((yyvsp[-2].node), "+", (yyvsp[0].node));
        }
#line 2686 "limbaj.tab.c"
    break;

  case 85: /* exp: exp '-' term  */
#line 1252 "limbaj.y"
        {
                string type1=(yyvsp[-2].node)->exprType;
                string type2=(yyvsp[0].node)->exprType;
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
            (yyval.node) = new ASTNode((yyvsp[-2].node), "-", (yyvsp[0].node));

        }
#line 2718 "limbaj.tab.c"
    break;

  case 86: /* exp: term  */
#line 1279 "limbaj.y"
               {(yyval.node)=(yyvsp[0].node);}
#line 2724 "limbaj.tab.c"
    break;

  case 87: /* term: term OPERATOR factor  */
#line 1283 "limbaj.y"
        {
                string type1=(yyvsp[-2].node)->exprType;
                string type2=(yyvsp[0].node)->exprType;
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
            (yyval.node) = new ASTNode((yyvsp[-2].node), op, (yyvsp[0].node));
        }
#line 2769 "limbaj.tab.c"
    break;

  case 88: /* term: factor  */
#line 1324 "limbaj.y"
        {
                (yyval.node)=(yyvsp[0].node);
        }
#line 2777 "limbaj.tab.c"
    break;

  case 89: /* factor: '-' factor  */
#line 1329 "limbaj.y"
        { 
                cout<<(yyvsp[0].node)->exprType<<" TIPUL ASTA NU E NUMERIC CICA!"<<endl;
                if ((yyvsp[0].node)->exprType != "int" && (yyvsp[0].node)->exprType != "float") {
                   yyerror("Minus operator ca only be appleid to numeric values!");
               }
               (yyval.node) = new ASTNode((yyvsp[0].node), "NEG", nullptr);
        }
#line 2789 "limbaj.tab.c"
    break;

  case 90: /* factor: NOT factor  */
#line 1337 "limbaj.y"
       { 
                if ((yyvsp[0].node)->exprType != "bool") {
                   yyerror("NOT operator ca only be applied to bool type!");
               }
               (yyval.node) = new ASTNode((yyvsp[0].node), "NOT", nullptr);
        }
#line 2800 "limbaj.tab.c"
    break;

  case 91: /* factor: '(' expression ')'  */
#line 1343 "limbaj.y"
                               { (yyval.node) = (yyvsp[-1].node); }
#line 2806 "limbaj.tab.c"
    break;

  case 92: /* factor: expression_elem  */
#line 1344 "limbaj.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 2812 "limbaj.tab.c"
    break;

  case 93: /* expression_elem: class_access  */
#line 1346 "limbaj.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 2818 "limbaj.tab.c"
    break;

  case 94: /* expression_elem: fun_call  */
#line 1347 "limbaj.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 2824 "limbaj.tab.c"
    break;

  case 95: /* expression_elem: INT  */
#line 1349 "limbaj.y"
        {
            (yyval.node) = new ASTNode("int", to_string((yyvsp[0].intVal)), "int");
        }
#line 2832 "limbaj.tab.c"
    break;

  case 96: /* expression_elem: FLOAT  */
#line 1353 "limbaj.y"
        {
            (yyval.node) = new ASTNode("float", to_string((yyvsp[0].floatVal)), "float");
        }
#line 2840 "limbaj.tab.c"
    break;

  case 97: /* expression_elem: BOOL  */
#line 1357 "limbaj.y"
        {
            (yyval.node) = new ASTNode("bool", (yyvsp[0].boolVal) ? "true" : "false", "bool");
        }
#line 2848 "limbaj.tab.c"
    break;

  case 98: /* expression_elem: CHAR  */
#line 1361 "limbaj.y"
        {
            (yyval.node) = new ASTNode("char", string(1, (yyvsp[0].charVal)), "char");
        }
#line 2856 "limbaj.tab.c"
    break;

  case 99: /* expression_elem: STRING  */
#line 1365 "limbaj.y"
        {
            (yyval.node) = new ASTNode("string", (yyvsp[0].stringVal), "string");
        }
#line 2864 "limbaj.tab.c"
    break;

  case 100: /* expression_elem: ID  */
#line 1369 "limbaj.y"
        {
            if(currentScope->searchVariable((yyvsp[0].stringVal)) == nullopt){
                string msg = "Variable " + string((yyvsp[0].stringVal)) + " doesn't exist";
                yyerror(msg.c_str());
            }
            (yyval.node) = new ASTNode("id", (yyvsp[0].stringVal), currentScope->getType((yyvsp[0].stringVal)));
        }
#line 2876 "limbaj.tab.c"
    break;

  case 101: /* expression_elem: ID '[' INT ']'  */
#line 1377 "limbaj.y"
        {
            auto var = currentScope->searchVector((yyvsp[-3].stringVal));
            if(var.has_value()){
                int numberElements = get<1>(var.value());
                if((yyvsp[-1].intVal) >= numberElements){
                    string msg = "Tried accessing vector index " + to_string((yyvsp[-1].intVal)) + " that doesn't exist (max is " + to_string(numberElements-1) + ")";
                    yyerror(msg.c_str());
                }
                if((yyvsp[-1].intVal) < 0){
                    yyerror("Vector index can't be negative!");
                }
            } else {
                string msg = "The vector " + string((yyvsp[-3].stringVal)) + " doesn't exist!";
                yyerror(msg.c_str());
            }
            
            ASTNode* vecName = new ASTNode("id_vector", (yyvsp[-3].stringVal), currentScope->getType((yyvsp[-3].stringVal)));
            ASTNode* indexNode = new ASTNode("int", to_string((yyvsp[-1].intVal)), "int");
            (yyval.node) = new ASTNode(vecName, "[]", indexNode);
        }
#line 2901 "limbaj.tab.c"
    break;

  case 102: /* expression: exp COMPARE exp  */
#line 1403 "limbaj.y"
            {   
                if ((yyvsp[-2].node)->exprType != (yyvsp[0].node)->exprType) {
                    string msg = "Type mismatch at compare: trying to compare [" + 
                                 (yyvsp[-2].node)->exprType + "] with [" + (yyvsp[0].node)->exprType + "]";
                    yyerror(msg.c_str());
                }

                cout<<"WHAT THE SIGMA COMPARE "<<string((yyvsp[-1].stringVal))<<endl;
                (yyval.node) = new ASTNode((yyvsp[-2].node), string((yyvsp[-1].stringVal)), (yyvsp[0].node));
                
                (yyval.node)->exprType = "bool";

                cout << "Nod de comparare creat cu tipul: " << (yyval.node)->exprType << endl;
            }
#line 2920 "limbaj.tab.c"
    break;

  case 103: /* expression: exp  */
#line 1417 "limbaj.y"
                  {(yyval.node)=(yyvsp[0].node);}
#line 2926 "limbaj.tab.c"
    break;

  case 104: /* if_statement: IF '(' expression ')' '{' main_fun_block '}'  */
#line 1421 "limbaj.y"
            {
                (yyval.node) = new ASTNode((yyvsp[-4].node), "IF", (yyvsp[-1].node));
            }
#line 2934 "limbaj.tab.c"
    break;

  case 105: /* if_statement: IF '(' expression ')' '{' main_fun_block '}' ELSE '{' main_fun_block '}'  */
#line 1425 "limbaj.y"
            {
                ASTNode* bodyNode = new ASTNode((yyvsp[-5].node), "IF_ELSE_LINK", (yyvsp[-1].node));
                (yyval.node) = new ASTNode((yyvsp[-8].node), "IF", bodyNode);
            }
#line 2943 "limbaj.tab.c"
    break;

  case 106: /* if_statement: IF '(' expression ')' '{' main_fun_block '}' ELSE if_statement  */
#line 1430 "limbaj.y"
            {
                ASTNode* bodyNode = new ASTNode((yyvsp[-3].node), "IF_ELSE_LINK", (yyvsp[0].node));
                (yyval.node) = new ASTNode((yyvsp[-6].node), "IF", bodyNode);
            }
#line 2952 "limbaj.tab.c"
    break;

  case 107: /* while_statement: WHILE '(' expression ')' '{' main_fun_block '}'  */
#line 1437 "limbaj.y"
             {
                (yyval.node) = new ASTNode((yyvsp[-4].node), "WHILE", (yyvsp[-1].node));
             }
#line 2960 "limbaj.tab.c"
    break;

  case 108: /* main: MAIN_BEGIN main_fun_block MAIN_END  */
#line 1445 "limbaj.y"
                                          {
        if ((yyvsp[-1].node) == nullptr) cout << "DEBUG: main_fun_block e NULL!" << endl;
    (yyval.node) = (yyvsp[-1].node);
    }
#line 2969 "limbaj.tab.c"
    break;

  case 109: /* main_fun_block: main_block_element  */
#line 1455 "limbaj.y"
                {
                        (yyval.node)=(yyvsp[0].node);
                }
#line 2977 "limbaj.tab.c"
    break;

  case 110: /* main_fun_block: main_fun_block main_block_element  */
#line 1459 "limbaj.y"
                {
                        (yyval.node) = new ASTNode((yyvsp[-1].node), "BLOCK", (yyvsp[0].node));
                }
#line 2985 "limbaj.tab.c"
    break;

  case 111: /* main_block_element: statement ';'  */
#line 1464 "limbaj.y"
                { (yyval.node) = (yyvsp[-1].node); }
#line 2991 "limbaj.tab.c"
    break;

  case 112: /* main_block_element: statement  */
#line 1465 "limbaj.y"
                        { yyerror("Missing semicolon"); (yyval.node) = (yyvsp[0].node); }
#line 2997 "limbaj.tab.c"
    break;

  case 113: /* main_block_element: class_create_instance ';'  */
#line 1467 "limbaj.y"
                { (yyval.node) = nullptr; }
#line 3003 "limbaj.tab.c"
    break;

  case 114: /* main_block_element: class_method_call ';'  */
#line 1469 "limbaj.y"
                { (yyval.node) = (yyvsp[-1].node); }
#line 3009 "limbaj.tab.c"
    break;

  case 115: /* main_block_element: fun_call ';'  */
#line 1471 "limbaj.y"
                { (yyval.node) = (yyvsp[-1].node); }
#line 3015 "limbaj.tab.c"
    break;

  case 116: /* main_block_element: print_statement ';'  */
#line 1473 "limbaj.y"
                { (yyval.node) = (yyvsp[-1].node); }
#line 3021 "limbaj.tab.c"
    break;

  case 117: /* main_block_element: if_statement  */
#line 1475 "limbaj.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 3027 "limbaj.tab.c"
    break;

  case 118: /* main_block_element: while_statement  */
#line 1477 "limbaj.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 3033 "limbaj.tab.c"
    break;


#line 3037 "limbaj.tab.c"

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

#line 1483 "limbaj.y"

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
