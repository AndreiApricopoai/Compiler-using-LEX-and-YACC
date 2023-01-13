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
#line 1 "parser.y"


#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <regex.h>
#include "utilitar.h"


#define IS_TYPE 1
#define NOT_TYPE 0
#define IS_ARRAY 1
#define NOT_ARRAY 0
#define IS_CONST 1
#define NOT_CONST 0

#define UNDEFINED "N/A"

#define GLOBAL_SCOPE "GLOBAL"
#define TYPES_SCOPE "TYPES"
#define FUNCTIONS_SCOPE "FUNCTIONS"
#define MAIN_SCOPE "MAIN"


extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern void yyerror();
extern int yylex();


char SYMBOL_SCOPE[100] = "GLOBAL"; // la inceput intram in global(default)
char FUNCTION_SCOPE[100] = "FUNCTIONS"; // la inceput intram in functions(default)

int symbol_scope_position = 0;
int function_scope_position = 0;

int types_position = 0;
int suntem_in_types = 0;



struct symbol_table symbols[100]; // aici vor fi stocate variabilele si array-urile
struct functions_table functions[100]; // aici vor fi stocate functiile si metodele
struct types_table types[100];

int index_symbols_table = 0;
int index_functions_table = 0;
int index_types_table = 0;






char UNDEFINED_ARRAY[200][1000]={"N/A"};
char ARRAY_VALUES[200][1000];
int index_arr = 0;

char FUNCTION_PARAMS[50][1000];
char NO_PARAMS[50][1000] = {"N/A"};

int index_par = 0;



void showError(int error_code){

    switch (error_code)
    {
    case -1:
        yyerror("valoare variabilei are tip difert fata de cel declarat!"); // variable has diffrent datatype value in definition
        break;
    case -2:
        yyerror("valorile din array au tip diferit fata de cel declarat!"); // valorile din array nu sunt de tipul array-ului
        break;
    case -3:
        yyerror("membrul sau variabila este deja definita cu acest nume in acel scope!"); // eroare variabila sau membrul de tip definit este deja definita in acel scope
        break;
    case -4:
        yyerror("functia contine mai multi parametrii cu acelasi identificator!"); // functia contine mai multi parametrii cu acelasi nume
        break;
    case -5:
        yyerror("metoda sau functia este deja definita in acel scope!"); // eroare frunctia sau metoda este deja definita in acel scope
        break;
    case -6:
        yyerror("tipul este deja definit!"); // eroare tipul custom este deja definit
        break;
    case -7:
        yyerror("eroare la creare symbol_table.txt si functions_table.txt!"); // symbol_table.txt si functions_table.txt
        break;  
    
    default:
        break;
    }

}




#line 175 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    START = 258,                   /* START  */
    GLOBAL = 259,                  /* GLOBAL  */
    END_GLOBAL = 260,              /* END_GLOBAL  */
    FUNCTIONS = 261,               /* FUNCTIONS  */
    END_FUNCTIONS = 262,           /* END_FUNCTIONS  */
    TYPES = 263,                   /* TYPES  */
    END_TYPES = 264,               /* END_TYPES  */
    MEMBERS = 265,                 /* MEMBERS  */
    METHODS = 266,                 /* METHODS  */
    MAIN = 267,                    /* MAIN  */
    END_MAIN = 268,                /* END_MAIN  */
    END = 269,                     /* END  */
    DATA_TYPE = 270,               /* DATA_TYPE  */
    CONST = 271,                   /* CONST  */
    ACCES = 272,                   /* ACCES  */
    IDENTIFIER = 273,              /* IDENTIFIER  */
    INTEGER_VALUE = 274,           /* INTEGER_VALUE  */
    BOOL_VALUE = 275,              /* BOOL_VALUE  */
    FLOAT_VALUE = 276,             /* FLOAT_VALUE  */
    STRING_VALUE = 277,            /* STRING_VALUE  */
    CHAR_VALUE = 278,              /* CHAR_VALUE  */
    EVAL = 279,                    /* EVAL  */
    TYPEOF = 280,                  /* TYPEOF  */
    IF = 281,                      /* IF  */
    ELSE = 282,                    /* ELSE  */
    FOR = 283,                     /* FOR  */
    WHILE = 284,                   /* WHILE  */
    RETURN = 285,                  /* RETURN  */
    PRINT = 286,                   /* PRINT  */
    ASSIGN = 287,                  /* ASSIGN  */
    ARITHMETIC_OPERATOR = 288,     /* ARITHMETIC_OPERATOR  */
    RELATIONAL_OPERATOR = 289,     /* RELATIONAL_OPERATOR  */
    SEMICOLON = 290,               /* SEMICOLON  */
    NOT = 291,                     /* NOT  */
    COMMA = 292,                   /* COMMA  */
    LSB = 293,                     /* LSB  */
    RSB = 294,                     /* RSB  */
    LCB = 295,                     /* LCB  */
    RCB = 296,                     /* RCB  */
    RPB = 297,                     /* RPB  */
    LPB = 298,                     /* LPB  */
    BOOLEAN_OPERATOR = 299,        /* BOOLEAN_OPERATOR  */
    TYPE = 300                     /* TYPE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define START 258
#define GLOBAL 259
#define END_GLOBAL 260
#define FUNCTIONS 261
#define END_FUNCTIONS 262
#define TYPES 263
#define END_TYPES 264
#define MEMBERS 265
#define METHODS 266
#define MAIN 267
#define END_MAIN 268
#define END 269
#define DATA_TYPE 270
#define CONST 271
#define ACCES 272
#define IDENTIFIER 273
#define INTEGER_VALUE 274
#define BOOL_VALUE 275
#define FLOAT_VALUE 276
#define STRING_VALUE 277
#define CHAR_VALUE 278
#define EVAL 279
#define TYPEOF 280
#define IF 281
#define ELSE 282
#define FOR 283
#define WHILE 284
#define RETURN 285
#define PRINT 286
#define ASSIGN 287
#define ARITHMETIC_OPERATOR 288
#define RELATIONAL_OPERATOR 289
#define SEMICOLON 290
#define NOT 291
#define COMMA 292
#define LSB 293
#define RSB 294
#define LCB 295
#define RCB 296
#define RPB 297
#define LPB 298
#define BOOLEAN_OPERATOR 299
#define TYPE 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 106 "parser.y"

      
int int_value;
char* string_value;
float float_value;



#line 327 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_START = 3,                      /* START  */
  YYSYMBOL_GLOBAL = 4,                     /* GLOBAL  */
  YYSYMBOL_END_GLOBAL = 5,                 /* END_GLOBAL  */
  YYSYMBOL_FUNCTIONS = 6,                  /* FUNCTIONS  */
  YYSYMBOL_END_FUNCTIONS = 7,              /* END_FUNCTIONS  */
  YYSYMBOL_TYPES = 8,                      /* TYPES  */
  YYSYMBOL_END_TYPES = 9,                  /* END_TYPES  */
  YYSYMBOL_MEMBERS = 10,                   /* MEMBERS  */
  YYSYMBOL_METHODS = 11,                   /* METHODS  */
  YYSYMBOL_MAIN = 12,                      /* MAIN  */
  YYSYMBOL_END_MAIN = 13,                  /* END_MAIN  */
  YYSYMBOL_END = 14,                       /* END  */
  YYSYMBOL_DATA_TYPE = 15,                 /* DATA_TYPE  */
  YYSYMBOL_CONST = 16,                     /* CONST  */
  YYSYMBOL_ACCES = 17,                     /* ACCES  */
  YYSYMBOL_IDENTIFIER = 18,                /* IDENTIFIER  */
  YYSYMBOL_INTEGER_VALUE = 19,             /* INTEGER_VALUE  */
  YYSYMBOL_BOOL_VALUE = 20,                /* BOOL_VALUE  */
  YYSYMBOL_FLOAT_VALUE = 21,               /* FLOAT_VALUE  */
  YYSYMBOL_STRING_VALUE = 22,              /* STRING_VALUE  */
  YYSYMBOL_CHAR_VALUE = 23,                /* CHAR_VALUE  */
  YYSYMBOL_EVAL = 24,                      /* EVAL  */
  YYSYMBOL_TYPEOF = 25,                    /* TYPEOF  */
  YYSYMBOL_IF = 26,                        /* IF  */
  YYSYMBOL_ELSE = 27,                      /* ELSE  */
  YYSYMBOL_FOR = 28,                       /* FOR  */
  YYSYMBOL_WHILE = 29,                     /* WHILE  */
  YYSYMBOL_RETURN = 30,                    /* RETURN  */
  YYSYMBOL_PRINT = 31,                     /* PRINT  */
  YYSYMBOL_ASSIGN = 32,                    /* ASSIGN  */
  YYSYMBOL_ARITHMETIC_OPERATOR = 33,       /* ARITHMETIC_OPERATOR  */
  YYSYMBOL_RELATIONAL_OPERATOR = 34,       /* RELATIONAL_OPERATOR  */
  YYSYMBOL_SEMICOLON = 35,                 /* SEMICOLON  */
  YYSYMBOL_NOT = 36,                       /* NOT  */
  YYSYMBOL_COMMA = 37,                     /* COMMA  */
  YYSYMBOL_LSB = 38,                       /* LSB  */
  YYSYMBOL_RSB = 39,                       /* RSB  */
  YYSYMBOL_LCB = 40,                       /* LCB  */
  YYSYMBOL_RCB = 41,                       /* RCB  */
  YYSYMBOL_RPB = 42,                       /* RPB  */
  YYSYMBOL_LPB = 43,                       /* LPB  */
  YYSYMBOL_BOOLEAN_OPERATOR = 44,          /* BOOLEAN_OPERATOR  */
  YYSYMBOL_TYPE = 45,                      /* TYPE  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_program = 47,                   /* program  */
  YYSYMBOL_continut = 48,                  /* continut  */
  YYSYMBOL_block = 49,                     /* block  */
  YYSYMBOL_global_block = 50,              /* global_block  */
  YYSYMBOL_declaratii_variabile = 51,      /* declaratii_variabile  */
  YYSYMBOL_declaratie_variabila = 52,      /* declaratie_variabila  */
  YYSYMBOL_value = 53,                     /* value  */
  YYSYMBOL_array_values = 54,              /* array_values  */
  YYSYMBOL_array_value = 55,               /* array_value  */
  YYSYMBOL_functions_block = 56,           /* functions_block  */
  YYSYMBOL_functions_decl = 57,            /* functions_decl  */
  YYSYMBOL_func_decl = 58,                 /* func_decl  */
  YYSYMBOL_function_params = 59,           /* function_params  */
  YYSYMBOL_func_param = 60,                /* func_param  */
  YYSYMBOL_function_call = 61,             /* function_call  */
  YYSYMBOL_function_arguments = 62,        /* function_arguments  */
  YYSYMBOL_control_statement = 63,         /* control_statement  */
  YYSYMBOL_conditions = 64,                /* conditions  */
  YYSYMBOL_condition = 65,                 /* condition  */
  YYSYMBOL_statements = 66,                /* statements  */
  YYSYMBOL_statement = 67,                 /* statement  */
  YYSYMBOL_assignment = 68,                /* assignment  */
  YYSYMBOL_expression = 69,                /* expression  */
  YYSYMBOL_types_block = 70,               /* types_block  */
  YYSYMBOL_type = 71,                      /* type  */
  YYSYMBOL_inner_content = 72,             /* inner_content  */
  YYSYMBOL_main_block = 73                 /* main_block  */
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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   528

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  243

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   194,   194,   198,   199,   203,   206,   210,   220,   230,
     234,   239,   240,   245,   250,   251,   255,   260,   266,   267,
     273,   279,   282,   290,   299,   309,   310,   311,   312,   313,
     317,   318,   320,   328,   331,   332,   337,   352,   367,   384,
     400,   401,   404,   405,   406,   407,   418,   422,   423,   427,
     428,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   449,   450,   451,   452,   456,   461,   462,
     466,   467,   468,   469,   470,   471,   632,   755,   760,   761,
     762,   766,   767,   768,   769,   770,   771,   772,   773,   776,
     777,   781,   791,   802,   805,   807,   809,   811,   813,   815,
     817,   825,   826
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
  "\"end of file\"", "error", "\"invalid token\"", "START", "GLOBAL",
  "END_GLOBAL", "FUNCTIONS", "END_FUNCTIONS", "TYPES", "END_TYPES",
  "MEMBERS", "METHODS", "MAIN", "END_MAIN", "END", "DATA_TYPE", "CONST",
  "ACCES", "IDENTIFIER", "INTEGER_VALUE", "BOOL_VALUE", "FLOAT_VALUE",
  "STRING_VALUE", "CHAR_VALUE", "EVAL", "TYPEOF", "IF", "ELSE", "FOR",
  "WHILE", "RETURN", "PRINT", "ASSIGN", "ARITHMETIC_OPERATOR",
  "RELATIONAL_OPERATOR", "SEMICOLON", "NOT", "COMMA", "LSB", "RSB", "LCB",
  "RCB", "RPB", "LPB", "BOOLEAN_OPERATOR", "TYPE", "$accept", "program",
  "continut", "block", "global_block", "declaratii_variabile",
  "declaratie_variabila", "value", "array_values", "array_value",
  "functions_block", "functions_decl", "func_decl", "function_params",
  "func_param", "function_call", "function_arguments", "control_statement",
  "conditions", "condition", "statements", "statement", "assignment",
  "expression", "types_block", "type", "inner_content", "main_block", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-127)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      21,   120,    51,    14,    59,    30,    85,   125,  -127,  -127,
    -127,    -4,    57,    64,    88,    10,    61,  -127,    90,   150,
     133,  -127,  -127,    79,    76,  -127,  -127,    33,    84,   131,
     132,   137,   147,   167,   135,   149,  -127,  -127,   179,   127,
    -127,  -127,   112,   202,   203,  -127,   190,  -127,   191,  -127,
    -127,     0,  -127,  -127,   212,   485,   219,   459,   227,   228,
     473,    42,   473,   491,  -127,  -127,  -127,  -127,  -127,   491,
      25,   232,  -127,  -127,    20,     7,   133,  -127,   210,    35,
     226,    -1,  -127,  -127,  -127,  -127,  -127,   485,  -127,  -127,
     233,   230,  -127,    80,   233,   225,   237,   239,   473,   141,
    -127,   166,    11,   235,   249,   162,   243,  -127,   248,   236,
     491,   268,   273,   277,   257,   104,  -127,   133,    16,   133,
    -127,   485,  -127,   282,   284,    73,   485,   270,   485,  -127,
     269,   278,   473,   165,   134,   275,   473,   485,   287,   276,
     473,   280,   286,   290,   291,  -127,   285,   315,  -127,   163,
     180,   296,   133,   133,   233,   295,  -127,   300,  -127,  -127,
     485,   233,  -127,  -127,   175,  -127,   187,  -127,   233,   308,
     311,    77,   211,  -127,   314,   491,    50,  -127,   485,   229,
    -127,  -127,   247,   133,  -127,   233,  -127,   329,   265,   283,
     323,  -127,   301,   491,  -127,   122,  -127,   318,  -127,   136,
     485,  -127,   485,   319,   320,   331,  -127,   337,   317,  -127,
     124,   491,  -127,  -127,   326,   189,   208,   485,   355,   332,
    -127,   334,  -127,  -127,  -127,   328,   335,   213,  -127,   373,
     391,   409,  -127,  -127,   336,  -127,  -127,   427,  -127,   445,
    -127,  -127,  -127
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     3,     1,
       6,     0,     0,     0,     0,    13,     0,     8,     0,     0,
      33,    34,    10,     0,     0,    89,    12,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,   101,     0,     0,
       2,     4,    16,     0,     0,     5,     0,    14,     0,     7,
      35,     0,     9,    90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    71,    72,    70,    11,   102,     0,
       0,    18,    24,    15,     0,    97,    99,    92,     0,     0,
       0,    82,    25,    26,    29,    27,    28,     0,    81,    86,
      78,     0,    48,     0,    49,     0,     0,     0,     0,     0,
      63,     0,     0,     0,     0,     0,     0,    17,     0,    21,
       0,     0,     0,     0,     0,     0,    40,    96,    98,   100,
      91,     0,    73,     0,     0,     0,     0,     0,     0,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    20,     0,    19,    42,     0,    46,     0,
       0,     0,    95,    94,    80,    84,    85,     0,    87,    88,
       0,    50,    76,    75,     0,    65,     0,    66,    67,     0,
       0,     0,     0,    77,     0,     0,     0,    43,     0,     0,
      68,    41,     0,    93,    83,    79,    64,    52,     0,     0,
       0,    58,     0,     0,    32,     0,    30,     0,    44,     0,
       0,    69,     0,     0,     0,    51,    62,     0,     0,    57,
       0,     0,    23,    45,     0,     0,     0,     0,     0,     0,
      61,     0,    22,    31,    39,     0,     0,     0,    56,     0,
       0,     0,    37,    38,     0,    54,    55,     0,    60,     0,
      36,    53,    59
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,  -127,   368,  -127,   310,     5,   -57,   194,   181,
    -127,   -63,   -17,  -127,   240,   -53,  -127,  -127,   -41,  -127,
    -126,    -6,   -56,   -40,  -127,   369,  -127,  -127
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     7,     8,    14,    15,    34,    88,   195,   196,
      19,    20,    21,   115,   116,    35,    93,    36,    99,   100,
     179,   180,    38,   101,    24,    25,    78,    39
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      37,    80,    89,    50,    89,   104,   106,    89,    16,    89,
      75,    76,   107,   119,    42,    90,   123,    94,   117,    10,
      46,   105,    11,    12,     1,    11,    12,   153,   138,    11,
      12,    11,    12,    68,    89,   111,   112,   124,   113,    22,
     188,    77,    57,    55,   108,    89,   192,   125,    23,    56,
      54,     9,    13,   145,   152,    13,   203,   133,   134,    13,
     102,    13,   114,   207,   109,    55,    17,   121,    89,   197,
     156,    56,    43,    89,    18,    89,    57,   103,    57,    89,
      16,   154,    44,    89,    89,    52,   159,    89,   161,   198,
     183,   164,   229,    45,    23,   167,    47,   168,    26,   171,
      11,    12,    50,    27,   237,   239,   126,    89,    48,    28,
      29,    30,   190,    31,    32,   158,    33,   128,   194,    51,
     185,   136,   129,    46,     3,    89,     4,    58,     5,     3,
      13,     4,     6,     5,   208,    50,   194,     6,   199,    40,
      67,   150,    11,    12,    69,    27,   151,    89,    18,    89,
      70,    28,    29,    30,   194,    31,    32,    49,    33,   211,
     215,   211,   216,   212,    89,   222,    50,   126,   137,   126,
      64,   214,    13,   201,    59,    60,   158,   227,    11,    12,
      61,    27,   201,   135,    65,   136,   201,    28,    29,    30,
      62,    31,    32,   178,    33,   111,   112,   201,   113,   126,
     137,   201,    11,    12,   141,    27,   136,   165,    13,   136,
      63,    28,    29,    30,    66,    31,    32,   186,    33,   136,
      71,    72,   126,   201,   225,    73,    11,    12,   187,    27,
      79,   201,    13,   201,    74,    28,    29,    30,    91,    31,
      32,   126,    33,   226,    11,    12,   126,    27,   234,    95,
      96,   120,   191,    28,    29,    30,    13,    31,    32,   200,
      33,   122,    11,    12,   110,    27,   126,   130,   144,   127,
     139,    28,    29,    30,    13,    31,    32,   202,    33,   131,
      11,    12,   132,    27,   140,   142,   146,   143,   147,    28,
      29,    30,    13,    31,    32,   148,    33,   149,    11,    12,
     155,    27,   160,   157,   162,   169,   205,    28,    29,    30,
      13,    31,    32,   163,    33,   166,    11,    12,   170,    27,
     172,   173,   174,   176,   206,    28,    29,    30,    13,    31,
      32,   175,    33,   177,    11,    12,   182,    27,    57,   184,
     121,   102,   209,    28,    29,    30,    13,    31,    32,   217,
      33,   189,    11,    12,   193,    27,   204,   213,   219,   221,
     218,    28,    29,    30,    13,    31,    32,   224,    33,   232,
      11,    12,   230,    27,   231,    41,   233,   240,   220,    28,
      29,    30,    13,    31,    32,   118,    33,   210,    11,    12,
     181,    27,   223,    53,     0,     0,   228,    28,    29,    30,
      13,    31,    32,     0,    33,     0,    11,    12,     0,    27,
       0,     0,     0,     0,   235,    28,    29,    30,    13,    31,
      32,     0,    33,     0,    11,    12,     0,    27,     0,     0,
       0,     0,   236,    28,    29,    30,    13,    31,    32,     0,
      33,     0,    11,    12,     0,    27,     0,     0,     0,     0,
     238,    28,    29,    30,    13,    31,    32,     0,    33,     0,
      11,    12,     0,    27,     0,     0,     0,     0,   241,    28,
      29,    30,    13,    31,    32,     0,    33,    81,    82,    83,
      84,    85,    86,     0,     0,     0,   242,     0,     0,     0,
      13,    81,    82,    83,    84,    85,    86,     0,     0,     0,
       0,    92,    87,    81,    82,    83,    84,    85,    86,    97,
      82,    83,    84,    85,    86,     0,    98,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    87
};

static const yytype_int16 yycheck[] =
{
       6,    54,    55,    20,    57,    61,    63,    60,     3,    62,
      10,    11,    69,    76,    18,    55,    17,    57,    11,     5,
      15,    62,    15,    16,     3,    15,    16,    11,    17,    15,
      16,    15,    16,    39,    87,    15,    16,    38,    18,     9,
     166,    41,    43,    32,    19,    98,   172,    87,    18,    38,
      17,     0,    45,   110,   117,    45,   182,    98,    98,    45,
      18,    45,    42,   189,    39,    32,     7,    32,   121,    19,
     123,    38,    15,   126,    15,   128,    43,    35,    43,   132,
      75,   121,    18,   136,   137,     9,   126,   140,   128,    39,
     153,   132,   218,     5,    18,   136,    35,   137,    13,   140,
      15,    16,   119,    18,   230,   231,    33,   160,    18,    24,
      25,    26,    35,    28,    29,    42,    31,    37,   175,    40,
     160,    44,    42,   118,     4,   178,     6,    43,     8,     4,
      45,     6,    12,     8,   190,   152,   193,    12,   178,    14,
      13,    37,    15,    16,    32,    18,    42,   200,    15,   202,
      38,    24,    25,    26,   211,    28,    29,     7,    31,    37,
     200,    37,   202,    41,   217,    41,   183,    33,    34,    33,
      35,    35,    45,   179,    43,    43,    42,   217,    15,    16,
      43,    18,   188,    42,    35,    44,   192,    24,    25,    26,
      43,    28,    29,    30,    31,    15,    16,   203,    18,    33,
      34,   207,    15,    16,    42,    18,    44,    42,    45,    44,
      43,    24,    25,    26,    35,    28,    29,    42,    31,    44,
      18,    18,    33,   229,    35,    35,    15,    16,    41,    18,
      18,   237,    45,   239,    43,    24,    25,    26,    19,    28,
      29,    33,    31,    35,    15,    16,    33,    18,    35,    22,
      22,    41,    41,    24,    25,    26,    45,    28,    29,    30,
      31,    35,    15,    16,    32,    18,    33,    42,    32,    39,
      35,    24,    25,    26,    45,    28,    29,    30,    31,    42,
      15,    16,    43,    18,    35,    42,    18,    39,    15,    24,
      25,    26,    45,    28,    29,    18,    31,    40,    15,    16,
      18,    18,    32,    19,    35,    18,    41,    24,    25,    26,
      45,    28,    29,    35,    31,    40,    15,    16,    42,    18,
      40,    35,    32,    38,    41,    24,    25,    26,    45,    28,
      29,    40,    31,    18,    15,    16,    40,    18,    43,    39,
      32,    18,    41,    24,    25,    26,    45,    28,    29,    30,
      31,    40,    15,    16,    40,    18,    27,    39,    27,    42,
      40,    24,    25,    26,    45,    28,    29,    41,    31,    41,
      15,    16,    40,    18,    40,     7,    41,    41,    41,    24,
      25,    26,    45,    28,    29,    75,    31,   193,    15,    16,
     150,    18,   211,    24,    -1,    -1,    41,    24,    25,    26,
      45,    28,    29,    -1,    31,    -1,    15,    16,    -1,    18,
      -1,    -1,    -1,    -1,    41,    24,    25,    26,    45,    28,
      29,    -1,    31,    -1,    15,    16,    -1,    18,    -1,    -1,
      -1,    -1,    41,    24,    25,    26,    45,    28,    29,    -1,
      31,    -1,    15,    16,    -1,    18,    -1,    -1,    -1,    -1,
      41,    24,    25,    26,    45,    28,    29,    -1,    31,    -1,
      15,    16,    -1,    18,    -1,    -1,    -1,    -1,    41,    24,
      25,    26,    45,    28,    29,    -1,    31,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      45,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    42,    43,    18,    19,    20,    21,    22,    23,    36,
      19,    20,    21,    22,    23,    -1,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    47,     4,     6,     8,    12,    48,    49,     0,
       5,    15,    16,    45,    50,    51,    52,     7,    15,    56,
      57,    58,     9,    18,    70,    71,    13,    18,    24,    25,
      26,    28,    29,    31,    52,    61,    63,    67,    68,    73,
      14,    49,    18,    15,    18,     5,    52,    35,    18,     7,
      58,    40,     9,    71,    17,    32,    38,    43,    43,    43,
      43,    43,    43,    43,    35,    35,    35,    13,    67,    32,
      38,    18,    18,    35,    43,    10,    11,    41,    72,    18,
      61,    18,    19,    20,    21,    22,    23,    43,    53,    61,
      69,    19,    42,    62,    69,    22,    22,    36,    43,    64,
      65,    69,    18,    35,    68,    64,    53,    53,    19,    39,
      32,    15,    16,    18,    42,    59,    60,    11,    51,    57,
      41,    32,    35,    17,    38,    69,    33,    39,    37,    42,
      42,    42,    43,    64,    69,    42,    44,    34,    17,    35,
      35,    42,    42,    39,    32,    53,    18,    15,    18,    40,
      37,    42,    57,    11,    69,    18,    61,    19,    42,    69,
      32,    69,    35,    35,    64,    42,    40,    64,    69,    18,
      42,    64,    40,    35,    32,    40,    38,    18,    30,    66,
      67,    60,    40,    57,    39,    69,    42,    41,    66,    40,
      35,    41,    66,    40,    53,    54,    55,    19,    39,    69,
      30,    67,    30,    66,    27,    41,    41,    66,    68,    41,
      54,    37,    41,    39,    35,    69,    69,    30,    40,    27,
      41,    42,    41,    55,    41,    35,    35,    69,    41,    66,
      40,    40,    41,    41,    35,    41,    41,    66,    41,    66,
      41,    41,    41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    49,    49,
      49,    49,    49,    50,    51,    51,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    53,    53,    53,    53,    53,
      54,    54,    55,    56,    57,    57,    58,    58,    58,    58,
      59,    59,    60,    60,    60,    60,    60,    61,    61,    62,
      62,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    64,    64,    64,    64,    65,    66,    66,
      67,    67,    67,    67,    67,    67,    67,    67,    68,    68,
      68,    69,    69,    69,    69,    69,    69,    69,    69,    70,
      70,    71,    71,    72,    72,    72,    72,    72,    72,    72,
      72,    73,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     1,     2,     3,     2,     3,     2,     3,
       2,     3,     2,     1,     2,     3,     2,     4,     3,     5,
       5,     4,     9,     8,     3,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     2,    11,    10,    10,     9,
       1,     3,     2,     3,     4,     5,     2,     4,     3,     1,
       3,     7,     6,    11,    10,    10,     9,     7,     6,    11,
      10,     8,     7,     1,     4,     3,     3,     3,     1,     2,
       2,     2,     2,     4,     1,     5,     5,     5,     3,     6,
       5,     1,     1,     4,     3,     3,     1,     3,     3,     1,
       2,     4,     3,     4,     3,     3,     2,     1,     2,     1,
       2,     1,     2
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
  case 2: /* program: START continut END  */
#line 194 "parser.y"
                              {printf("Programul este corect sintactic!\n");}
#line 1592 "y.tab.c"
    break;

  case 5: /* block: GLOBAL global_block END_GLOBAL  */
#line 203 "parser.y"
                                       {
      setSymbolScope(symbol_scope_position, types_position, SYMBOL_SCOPE, "functions");
}
#line 1600 "y.tab.c"
    break;

  case 6: /* block: GLOBAL END_GLOBAL  */
#line 206 "parser.y"
                          {

      setSymbolScope(symbol_scope_position, types_position, SYMBOL_SCOPE, "functions");
}
#line 1609 "y.tab.c"
    break;

  case 7: /* block: FUNCTIONS functions_block END_FUNCTIONS  */
#line 210 "parser.y"
                                                {

      symbol_scope_position = 0;
      types_position = 0;
      suntem_in_types = 1;
      setSymbolScope(symbol_scope_position, types_position, SYMBOL_SCOPE, "types");
      setFunctionScope(types_position, FUNCTION_SCOPE,"types");


}
#line 1624 "y.tab.c"
    break;

  case 8: /* block: FUNCTIONS END_FUNCTIONS  */
#line 220 "parser.y"
                               {

      symbol_scope_position = 0;
      types_position = 0;
      suntem_in_types = 1;
      setSymbolScope(symbol_scope_position, types_position, SYMBOL_SCOPE, "types");
      setFunctionScope(types_position, FUNCTION_SCOPE,"types");


}
#line 1639 "y.tab.c"
    break;

  case 9: /* block: TYPES types_block END_TYPES  */
#line 230 "parser.y"
                                    {
      strcpy(SYMBOL_SCOPE,MAIN_SCOPE);
      suntem_in_types = 0;
}
#line 1648 "y.tab.c"
    break;

  case 10: /* block: TYPES END_TYPES  */
#line 234 "parser.y"
                        {

      strcpy(SYMBOL_SCOPE,MAIN_SCOPE);
      suntem_in_types = 0;
}
#line 1658 "y.tab.c"
    break;

  case 16: /* declaratie_variabila: DATA_TYPE IDENTIFIER  */
#line 255 "parser.y"
                                           {
      int code = addSymbol(index_symbols_table, SYMBOL_SCOPE, symbols, NOT_TYPE, NOT_ARRAY, NOT_CONST, (yyvsp[-1].string_value), (yyvsp[0].string_value), UNDEFINED,UNDEFINED_ARRAY,0,0);
      index_symbols_table++;
      showError(code);
}
#line 1668 "y.tab.c"
    break;

  case 17: /* declaratie_variabila: DATA_TYPE IDENTIFIER ASSIGN value  */
#line 260 "parser.y"
                                             {
      int code = addSymbol(index_symbols_table, SYMBOL_SCOPE, symbols, NOT_TYPE, NOT_ARRAY, NOT_CONST, (yyvsp[-3].string_value), (yyvsp[-2].string_value), (yyvsp[0].string_value),UNDEFINED_ARRAY,0,0);
      index_symbols_table++;
      showError(code);

}
#line 1679 "y.tab.c"
    break;

  case 18: /* declaratie_variabila: CONST DATA_TYPE IDENTIFIER  */
#line 266 "parser.y"
                                          {/*thows error*/ yyerror("const without value asociated!");}
#line 1685 "y.tab.c"
    break;

  case 19: /* declaratie_variabila: CONST DATA_TYPE IDENTIFIER ASSIGN value  */
#line 267 "parser.y"
                                                   {
      int code = addSymbol(index_symbols_table, SYMBOL_SCOPE, symbols, NOT_TYPE, NOT_ARRAY, IS_CONST, (yyvsp[-3].string_value), (yyvsp[-2].string_value), (yyvsp[0].string_value), UNDEFINED_ARRAY,0,0);
      index_symbols_table++;
      showError(code);

}
#line 1696 "y.tab.c"
    break;

  case 20: /* declaratie_variabila: DATA_TYPE IDENTIFIER LSB INTEGER_VALUE RSB  */
#line 273 "parser.y"
                                                      {      
      int code = addSymbol(index_symbols_table, SYMBOL_SCOPE, symbols, NOT_TYPE, IS_ARRAY, NOT_CONST, (yyvsp[-4].string_value), (yyvsp[-3].string_value), UNDEFINED, UNDEFINED_ARRAY,(yyvsp[-1].int_value),0);
      index_symbols_table++;
      showError(code);

}
#line 1707 "y.tab.c"
    break;

  case 21: /* declaratie_variabila: DATA_TYPE IDENTIFIER LSB RSB  */
#line 279 "parser.y"
                                           {/*throws error array with no space allocated*/ yyerror("error array with no space allocated!");}
#line 1713 "y.tab.c"
    break;

  case 22: /* declaratie_variabila: DATA_TYPE IDENTIFIER LSB INTEGER_VALUE RSB ASSIGN LCB array_values RCB  */
#line 282 "parser.y"
                                                                                  {
      int code = addSymbol(index_symbols_table, SYMBOL_SCOPE, symbols, NOT_TYPE, IS_ARRAY, NOT_CONST, (yyvsp[-8].string_value), (yyvsp[-7].string_value), UNDEFINED, ARRAY_VALUES ,(yyvsp[-5].int_value),index_arr);
      index_symbols_table++;
      index_arr = 0;
      memset(ARRAY_VALUES,0,200*1000*sizeof(char));
      showError(code);

}
#line 1726 "y.tab.c"
    break;

  case 23: /* declaratie_variabila: DATA_TYPE IDENTIFIER LSB RSB ASSIGN LCB array_values RCB  */
#line 290 "parser.y"
                                                                    {
      int code = addSymbol(index_symbols_table, SYMBOL_SCOPE, symbols, NOT_TYPE, IS_ARRAY, NOT_CONST, (yyvsp[-7].string_value), (yyvsp[-6].string_value), UNDEFINED, ARRAY_VALUES ,0,index_arr);
      index_symbols_table++;
      index_arr = 0;
      memset(ARRAY_VALUES,0,200*1000*sizeof(char));
      showError(code);

}
#line 1739 "y.tab.c"
    break;

  case 24: /* declaratie_variabila: TYPE IDENTIFIER IDENTIFIER  */
#line 299 "parser.y"
                                      {
      int code = addSymbol(index_symbols_table, SYMBOL_SCOPE, symbols, IS_TYPE, NOT_ARRAY, NOT_CONST, (yyvsp[-1].string_value), (yyvsp[0].string_value), UNDEFINED, UNDEFINED_ARRAY,0,0);
      index_symbols_table++;
      showError(code);

}
#line 1750 "y.tab.c"
    break;

  case 25: /* value: INTEGER_VALUE  */
#line 309 "parser.y"
                      {(yyval.string_value) = strdup(yytext); }
#line 1756 "y.tab.c"
    break;

  case 26: /* value: BOOL_VALUE  */
#line 310 "parser.y"
                      {(yyval.string_value) = strdup(yytext); }
#line 1762 "y.tab.c"
    break;

  case 27: /* value: STRING_VALUE  */
#line 311 "parser.y"
                      {(yyval.string_value) = strdup(yytext); }
#line 1768 "y.tab.c"
    break;

  case 28: /* value: CHAR_VALUE  */
#line 312 "parser.y"
                      {(yyval.string_value) = strdup(yytext); }
#line 1774 "y.tab.c"
    break;

  case 29: /* value: FLOAT_VALUE  */
#line 313 "parser.y"
                      {(yyval.string_value) = strdup(yytext); }
#line 1780 "y.tab.c"
    break;

  case 32: /* array_value: value  */
#line 320 "parser.y"
                   {
      strcpy(ARRAY_VALUES[index_arr],(yyvsp[0].string_value)); index_arr++;
}
#line 1788 "y.tab.c"
    break;

  case 33: /* functions_block: functions_decl  */
#line 328 "parser.y"
                                {symbol_scope_position = 0;}
#line 1794 "y.tab.c"
    break;

  case 36: /* func_decl: DATA_TYPE IDENTIFIER LPB function_params RPB LCB statements RETURN expression SEMICOLON RCB  */
#line 337 "parser.y"
                                                                                                        {
      symbol_scope_position++;
      if(suntem_in_types == 1)
            setSymbolScope(symbol_scope_position,types_position, SYMBOL_SCOPE, "types");
      else
            setSymbolScope(symbol_scope_position,types_position, SYMBOL_SCOPE, "functions");
           
      int code = addFunction(index_functions_table, FUNCTION_SCOPE, (yyvsp[-10].string_value), (yyvsp[-9].string_value), functions, FUNCTION_PARAMS, index_par);
      memset(FUNCTION_PARAMS,0,50*1000*sizeof(char));

      index_par = 0;
      index_functions_table++;
      showError(code);

}
#line 1814 "y.tab.c"
    break;

  case 37: /* func_decl: DATA_TYPE IDENTIFIER LPB RPB LCB statements RETURN expression SEMICOLON RCB  */
#line 352 "parser.y"
                                                                                         {

      symbol_scope_position++;
      if(suntem_in_types == 1)
            setSymbolScope(symbol_scope_position,types_position, SYMBOL_SCOPE, "types");
      else
            setSymbolScope(symbol_scope_position,types_position, SYMBOL_SCOPE, "functions");

      int code = addFunction(index_functions_table, FUNCTION_SCOPE, (yyvsp[-9].string_value), (yyvsp[-8].string_value), functions, NO_PARAMS, 0);

      index_par = 0;
      index_functions_table++;
      showError(code);
     
}
#line 1834 "y.tab.c"
    break;

  case 38: /* func_decl: DATA_TYPE IDENTIFIER LPB function_params RPB LCB RETURN expression SEMICOLON RCB  */
#line 367 "parser.y"
                                                                                              {

      symbol_scope_position++;
      if(suntem_in_types == 1)
            setSymbolScope(symbol_scope_position,types_position, SYMBOL_SCOPE, "types");
      else
            setSymbolScope(symbol_scope_position,types_position, SYMBOL_SCOPE, "functions");

      int code = addFunction(index_functions_table, FUNCTION_SCOPE, (yyvsp[-9].string_value), (yyvsp[-8].string_value), functions, FUNCTION_PARAMS, index_par);
      memset(FUNCTION_PARAMS,0,50*1000*sizeof(char));

      index_par = 0;
      index_functions_table++;
      showError(code);


}
#line 1856 "y.tab.c"
    break;

  case 39: /* func_decl: DATA_TYPE IDENTIFIER LPB RPB LCB RETURN expression SEMICOLON RCB  */
#line 384 "parser.y"
                                                                               {

      symbol_scope_position++;
      if(suntem_in_types == 1)
            setSymbolScope(symbol_scope_position,types_position, SYMBOL_SCOPE, "types");
      else
            setSymbolScope(symbol_scope_position,types_position, SYMBOL_SCOPE, "functions");
           
      int code = addFunction(index_functions_table, FUNCTION_SCOPE, (yyvsp[-8].string_value), (yyvsp[-7].string_value), functions, NO_PARAMS, 0);

      index_par = 0;
      index_functions_table++;
      showError(code);
}
#line 1875 "y.tab.c"
    break;

  case 42: /* func_param: DATA_TYPE IDENTIFIER  */
#line 404 "parser.y"
                                  {strcpy((yyval.string_value),(yyvsp[-1].string_value)); strcat((yyval.string_value)," "); strcat((yyval.string_value),(yyvsp[0].string_value)); strcpy(FUNCTION_PARAMS[index_par],(yyval.string_value)); index_par++;}
#line 1881 "y.tab.c"
    break;

  case 43: /* func_param: CONST DATA_TYPE IDENTIFIER  */
#line 405 "parser.y"
                                   {strcpy((yyval.string_value),"const"); strcat((yyval.string_value)," "); strcat((yyval.string_value),(yyvsp[-1].string_value)); strcat((yyval.string_value)," "); strcat((yyval.string_value),(yyvsp[0].string_value)); strcpy(FUNCTION_PARAMS[index_par],(yyval.string_value)); index_par++;}
#line 1887 "y.tab.c"
    break;

  case 44: /* func_param: DATA_TYPE IDENTIFIER LSB RSB  */
#line 406 "parser.y"
                                     {strcpy((yyval.string_value),(yyvsp[-3].string_value)); strcat((yyval.string_value)," "); strcat((yyval.string_value),(yyvsp[-2].string_value));strcat((yyval.string_value),"["); strcat((yyval.string_value),"]"); strcpy(FUNCTION_PARAMS[index_par],(yyval.string_value)); index_par++;}
#line 1893 "y.tab.c"
    break;

  case 45: /* func_param: DATA_TYPE IDENTIFIER LSB INTEGER_VALUE RSB  */
#line 407 "parser.y"
                                                   {
      strcpy((yyval.string_value),(yyvsp[-4].string_value)); strcat((yyval.string_value)," "); strcat((yyval.string_value),(yyvsp[-3].string_value));strcat((yyval.string_value),"[");

      char intstring[20]= "\0";
      sprintf(intstring,"%d", (yyvsp[-1].int_value));
      strcat((yyval.string_value),intstring);
      strcat((yyval.string_value),"]");

      strcpy(FUNCTION_PARAMS[index_par],(yyval.string_value));
      index_par++;
}
#line 1909 "y.tab.c"
    break;

  case 46: /* func_param: IDENTIFIER IDENTIFIER  */
#line 418 "parser.y"
                              {strcpy((yyval.string_value),(yyvsp[-1].string_value)); strcat((yyval.string_value)," "); strcat((yyval.string_value),(yyvsp[0].string_value)); strcpy(FUNCTION_PARAMS[index_par],(yyval.string_value)); index_par++;}
#line 1915 "y.tab.c"
    break;

  case 75: /* statement: TYPEOF LPB STRING_VALUE RPB SEMICOLON  */
#line 472 "parser.y"
            {
                  removeQuotes((yyvsp[-2].string_value));
                  char identifier1[100];
                  char identifier2[100];
                  char sign[100];

                  char output[100];
                  bzero(output,sizeof(output));

                  sscanf((yyvsp[-2].string_value),"%s %s %s",identifier1,sign,identifier2);
                  //printf("%s\n",identifier1);

                  if(strchr(identifier1,'[')!=0)
                  {
                        char aux[100];
                        strcpy(aux, identifier1);

                        char *p=strtok(aux,"[");

                        strcpy(identifier1, p);

                  }

                  if(strchr(identifier2,'[')!=0)
                  {
                        char aux[100];
                        strcpy(aux, identifier2);

                        char *p=strtok(aux,"[");

                        strcpy(identifier2, p);
                  }

                  if(existsVariable("MAIN",identifier1,symbols,index_symbols_table)==1)
                  {
                        if(getDataType(symbols,index_symbols_table,identifier1)==1)
                        {
                              strcat(output,"int ");
                              strcat(output,sign);
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier1)==2)
                        {
                              strcat(output,"float ");
                              strcat(output,sign);
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier1)==3)
                        {
                              strcat(output,"char ");
                              strcat(output,sign);
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier1)==4)
                        {
                              strcat(output,"string ");
                              strcat(output,sign);
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier1)==5)
                        {
                              strcat(output,"bool ");
                              strcat(output,sign);
                        }
                  }
                  else if(existsVariable("GLOBAL",identifier1,symbols,index_symbols_table)==1)
                  {
                        if(getDataType(symbols,index_symbols_table,identifier1)==1)
                        {
                              strcat(output,"int ");
                              strcat(output,sign);
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier1)==2)
                        {
                              strcat(output,"float ");
                              strcat(output,sign);
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier1)==3)
                        {
                              strcat(output,"char ");
                              strcat(output,sign);
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier1)==4)
                        {
                              strcat(output,"string ");
                              strcat(output,sign);
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier1)==5)
                        {
                              strcat(output,"bool ");
                              strcat(output,sign);
                        }
                  }
                  else
                  {
                        yyerror("TypeOf: Variabila nu exista!");
                  }

                  if(existsVariable("MAIN",identifier2,symbols,index_symbols_table)==1)
                  {
                        if(getDataType(symbols,index_symbols_table,identifier2)== 1)
                        {
                              strcat(output," int");
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier2)==2)
                        {
                              strcat(output," float");
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier2)==3)
                        {
                              strcat(output," char");
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier2)==4)
                        {
                              strcat(output," string");
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier2)==5)
                        {
                              strcat(output," bool");
                        }
                  }
                  else if(existsVariable("GLOBAL",identifier2,symbols,index_symbols_table)==1)
                  {
                        if(getDataType(symbols,index_symbols_table,identifier2)== 1)
                        {
                              strcat(output," int");
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier2)==2)
                        {
                              strcat(output," float");
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier2)==3)
                        {
                              strcat(output," char");
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier2)==4)
                        {
                              strcat(output," string");
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier2)==5)
                        {
                              strcat(output," bool");
                        }
                  }
                  else
                  {
                        yyerror("TypeOf: Variabila nu exista!");
                  }

                  bzero(identifier1,sizeof(identifier1));
                  bzero(identifier2,sizeof(identifier2));

                  sscanf(output,"%s %s %s",identifier1, sign, identifier2);

                  if(strcmp(identifier1,identifier2)==0)
                  {
                        printf("TypeOf(%s)\n",output);
                  }
                  else
                  {
                        yyerror("TypeOf -> Parametrii diferiti!");
                  }

            }
#line 2080 "y.tab.c"
    break;

  case 76: /* statement: EVAL LPB STRING_VALUE RPB SEMICOLON  */
#line 633 "parser.y"
            {
            if(strcmp(SYMBOL_SCOPE,"MAIN")==0)
            {          
                  removeQuotes((yyvsp[-2].string_value));
                  char aux[500];
                  char finalString[500];
                  char simbol[100];
                  char varName[100];
                  char arrayName[100];
                  char arrayValue[100];
                  char expression[100];

                  strcpy(aux,(yyvsp[-2].string_value));
                  strcpy(expression,(yyvsp[-2].string_value));

                  
                  replace_function_calls(aux);

                  //printf("%s\n",aux);

                  int isNumber=0;
                  int isVar=0;
                  bzero(finalString,sizeof(finalString));
                  bzero(arrayName,sizeof(arrayName));
                  bzero(arrayValue,sizeof(arrayValue));
                  for(int i=0;i<strlen(aux);i++)
                  {
                        if(aux[i]=='+' || aux[i]=='-' || aux[i]=='*' ||
                           aux[i]=='/' || aux[i]=='(' || aux[i]==')') 
                           {
                              if(existsVariable("MAIN",varName,symbols,index_symbols_table)==1)
                              {
                                    int stringNumber;
                                    stringNumber=getIntValue(symbols,index_symbols_table,varName);

                                    char strNumber[100];
                                    sprintf(strNumber,"%i",stringNumber);

                                    strcat(finalString, strNumber);
                                    bzero(varName, sizeof(varName));
                              }
                              else if(existsVariable("GLOBAL",varName,symbols,index_symbols_table)==1)
                              {
                                    int stringNumber;
                                    stringNumber=getIntValue(symbols,index_symbols_table,varName);

                                    char strNumber[100];
                                    sprintf(strNumber,"%i",stringNumber);
                                    
                                    strcat(finalString, strNumber);
                                    bzero(varName, sizeof(varName));
                              }
                              bzero(varName,sizeof(varName));
                              sprintf(simbol,"%c",aux[i]);
                              strcat(finalString, simbol);
                              isNumber=0;
                              isVar=0;
                           }
                           else if(((aux[i] >= 'a' && aux[i] <= 'z') || (aux[i] >= 'A' && aux[i] <= 'Z')) && isVar == 0)
                           {
                              isVar=0;
                              isNumber=1;
                              sprintf(simbol,"%c",aux[i]);
                              strcat(varName, simbol);
                           }
                           else if(isdigit(aux[i]) && isNumber == 0 )
                           {
                              isVar=1;
                              isNumber=0;
                              sprintf(simbol,"%c",aux[i]);
                              strcat(finalString, simbol);
                           }
                           else if(aux[i]=='[')
                           {
                              isVar=1;
                              isNumber=1;
                              sprintf(simbol,"%c",aux[i]);
                              strcat(arrayValue,simbol);
                           }
                           else if(aux[i]== ']')
                           {
                              sprintf(simbol,"%c",aux[i]);
                              strcat(arrayValue,simbol);

                              if(existsVariable("MAIN",varName,symbols,index_symbols_table)==1)
                              {
                                    strcat(varName,arrayValue);

                                    int stringNumber;
                                    stringNumber=getIntValue(symbols,index_symbols_table,varName);

                                    char strNumber[100];

                                    sprintf(strNumber,"%i",stringNumber);

                                    strcat(finalString, strNumber);
                                    bzero(varName, sizeof(varName));
                              }
                           }
                           else
                           {
                              sprintf(simbol,"%c",aux[i]);
                              strcat(arrayValue,simbol);
                           }

                        //    printf("%s - > %i\n",finalString,i);
                        //    printf("%s - > %i\n",arrayValue,i);
                           
                  }

                  //printf("%s\n",finalString);
                  //printf("VAL:%i\n",atoi(finalString));
                  infixToPostfix(finalString);

                  //printf("%s\n",finalString);
                  struct Node *root = buildTree(finalString);


                  printf("(Eval)Rezultatul expresiei %s este : %i\n",expression, evaluate(root));
                  
            }
            }
#line 2207 "y.tab.c"
    break;

  case 91: /* type: IDENTIFIER LCB inner_content RCB  */
#line 781 "parser.y"
                                        {
      symbol_scope_position = 0; types_position++;  
      setSymbolScope(symbol_scope_position,types_position, SYMBOL_SCOPE, "types");
      setFunctionScope(types_position, FUNCTION_SCOPE,"types");

      int code = addType(index_types_table, (yyvsp[-3].string_value), types);
      index_types_table++;
      showError(code);

}
#line 2222 "y.tab.c"
    break;

  case 92: /* type: IDENTIFIER LCB RCB  */
#line 791 "parser.y"
                          {
      symbol_scope_position = 0; types_position++;
      setSymbolScope(symbol_scope_position,types_position, SYMBOL_SCOPE, "types");
      setFunctionScope(types_position,FUNCTION_SCOPE,"types");

      int code = addType(index_types_table, (yyvsp[-2].string_value), types);
      index_types_table++;
      showError(code);
      }
#line 2236 "y.tab.c"
    break;

  case 93: /* inner_content: MEMBERS declaratii_variabile METHODS functions_decl  */
#line 802 "parser.y"
                                                                   {

}
#line 2244 "y.tab.c"
    break;

  case 94: /* inner_content: MEMBERS declaratii_variabile METHODS  */
#line 805 "parser.y"
                                                {
}
#line 2251 "y.tab.c"
    break;

  case 95: /* inner_content: MEMBERS METHODS functions_decl  */
#line 807 "parser.y"
                                          {
}
#line 2258 "y.tab.c"
    break;

  case 96: /* inner_content: MEMBERS METHODS  */
#line 809 "parser.y"
                           {
}
#line 2265 "y.tab.c"
    break;

  case 97: /* inner_content: MEMBERS  */
#line 811 "parser.y"
                   {
}
#line 2272 "y.tab.c"
    break;

  case 98: /* inner_content: MEMBERS declaratii_variabile  */
#line 813 "parser.y"
                                        {
}
#line 2279 "y.tab.c"
    break;

  case 99: /* inner_content: METHODS  */
#line 815 "parser.y"
                   {
}
#line 2286 "y.tab.c"
    break;

  case 100: /* inner_content: METHODS functions_decl  */
#line 817 "parser.y"
                                  {
}
#line 2293 "y.tab.c"
    break;


#line 2297 "y.tab.c"

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

#line 830 "parser.y"






void yyerror(char * s){

printf("EROARE: %s LA LINIA : %d\n",s,yylineno);

}

int main(int argc, char** argv){

/*
extern int yydebug;
yydebug = 1;
*/


yyin=fopen(argv[1],"r");
yyparse();

int res = symbol_table_file(symbols, index_symbols_table); // aici printam tabela de simboluri in symbol_table.txt
showError(res);
res = functions_table_file(functions, index_functions_table); // aici printam tabela de functii in functions_table.txt
showError(res);


return 0;

} 
