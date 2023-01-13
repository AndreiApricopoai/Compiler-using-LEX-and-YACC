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
    case -15:
        yyerror("variabila este utilizata dar nu este definita nicaieri!"); // asignare
        break; 
    case -16:
        yyerror("variabilele au tipuri de date diferite!"); // asignare
        break; 
    case -20:
        yyerror("se incearca atrbuirea unei valori catre variabila const!"); // asignare
        break; 
    
    default:
        break;
    }

}




#line 184 "y.tab.c"

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
    ASSIGN = 286,                  /* ASSIGN  */
    ARITHMETIC_OPERATOR = 287,     /* ARITHMETIC_OPERATOR  */
    RELATIONAL_OPERATOR = 288,     /* RELATIONAL_OPERATOR  */
    SEMICOLON = 289,               /* SEMICOLON  */
    NOT = 290,                     /* NOT  */
    COMMA = 291,                   /* COMMA  */
    LSB = 292,                     /* LSB  */
    RSB = 293,                     /* RSB  */
    LCB = 294,                     /* LCB  */
    RCB = 295,                     /* RCB  */
    RPB = 296,                     /* RPB  */
    LPB = 297,                     /* LPB  */
    BOOLEAN_OPERATOR = 298,        /* BOOLEAN_OPERATOR  */
    TYPE = 299                     /* TYPE  */
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
#define ASSIGN 286
#define ARITHMETIC_OPERATOR 287
#define RELATIONAL_OPERATOR 288
#define SEMICOLON 289
#define NOT 290
#define COMMA 291
#define LSB 292
#define RSB 293
#define LCB 294
#define RCB 295
#define RPB 296
#define LPB 297
#define BOOLEAN_OPERATOR 298
#define TYPE 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 115 "parser.y"

      
int int_value;
char* string_value;
float float_value;



#line 334 "y.tab.c"

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
  YYSYMBOL_ASSIGN = 31,                    /* ASSIGN  */
  YYSYMBOL_ARITHMETIC_OPERATOR = 32,       /* ARITHMETIC_OPERATOR  */
  YYSYMBOL_RELATIONAL_OPERATOR = 33,       /* RELATIONAL_OPERATOR  */
  YYSYMBOL_SEMICOLON = 34,                 /* SEMICOLON  */
  YYSYMBOL_NOT = 35,                       /* NOT  */
  YYSYMBOL_COMMA = 36,                     /* COMMA  */
  YYSYMBOL_LSB = 37,                       /* LSB  */
  YYSYMBOL_RSB = 38,                       /* RSB  */
  YYSYMBOL_LCB = 39,                       /* LCB  */
  YYSYMBOL_RCB = 40,                       /* RCB  */
  YYSYMBOL_RPB = 41,                       /* RPB  */
  YYSYMBOL_LPB = 42,                       /* LPB  */
  YYSYMBOL_BOOLEAN_OPERATOR = 43,          /* BOOLEAN_OPERATOR  */
  YYSYMBOL_TYPE = 44,                      /* TYPE  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_program = 46,                   /* program  */
  YYSYMBOL_continut = 47,                  /* continut  */
  YYSYMBOL_block = 48,                     /* block  */
  YYSYMBOL_global_block = 49,              /* global_block  */
  YYSYMBOL_declaratii_variabile = 50,      /* declaratii_variabile  */
  YYSYMBOL_declaratie_variabila = 51,      /* declaratie_variabila  */
  YYSYMBOL_value = 52,                     /* value  */
  YYSYMBOL_array_values = 53,              /* array_values  */
  YYSYMBOL_array_value = 54,               /* array_value  */
  YYSYMBOL_functions_block = 55,           /* functions_block  */
  YYSYMBOL_functions_decl = 56,            /* functions_decl  */
  YYSYMBOL_func_decl = 57,                 /* func_decl  */
  YYSYMBOL_function_params = 58,           /* function_params  */
  YYSYMBOL_func_param = 59,                /* func_param  */
  YYSYMBOL_function_call = 60,             /* function_call  */
  YYSYMBOL_function_arguments = 61,        /* function_arguments  */
  YYSYMBOL_control_statement = 62,         /* control_statement  */
  YYSYMBOL_condition_assignment = 63,      /* condition_assignment  */
  YYSYMBOL_conditions = 64,                /* conditions  */
  YYSYMBOL_condition = 65,                 /* condition  */
  YYSYMBOL_statements = 66,                /* statements  */
  YYSYMBOL_statement = 67,                 /* statement  */
  YYSYMBOL_assignment = 68,                /* assignment  */
  YYSYMBOL_leftexp = 69,                   /* leftexp  */
  YYSYMBOL_expression = 70,                /* expression  */
  YYSYMBOL_types_block = 71,               /* types_block  */
  YYSYMBOL_type = 72,                      /* type  */
  YYSYMBOL_inner_content = 73,             /* inner_content  */
  YYSYMBOL_main_block = 74                 /* main_block  */
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
#define YYLAST   506

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  255

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   203,   203,   207,   208,   212,   215,   219,   229,   239,
     243,   248,   249,   254,   259,   260,   264,   269,   275,   276,
     282,   288,   291,   299,   308,   318,   319,   320,   321,   322,
     326,   327,   329,   337,   340,   341,   346,   361,   376,   393,
     409,   410,   413,   414,   415,   416,   427,   431,   432,   436,
     437,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   457,   458,   459,   462,   463,   464,   465,
     469,   474,   475,   479,   480,   481,   482,   483,   484,   645,
     772,   791,   809,   835,   842,   843,   846,   847,   855,   860,
     861,   862,   863,   864,   865,   866,   867,   873,   874,   878,
     888,   899,   902,   904,   906,   908,   910,   912,   914,   922,
     923
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
  "WHILE", "RETURN", "ASSIGN", "ARITHMETIC_OPERATOR",
  "RELATIONAL_OPERATOR", "SEMICOLON", "NOT", "COMMA", "LSB", "RSB", "LCB",
  "RCB", "RPB", "LPB", "BOOLEAN_OPERATOR", "TYPE", "$accept", "program",
  "continut", "block", "global_block", "declaratii_variabile",
  "declaratie_variabila", "value", "array_values", "array_value",
  "functions_block", "functions_decl", "func_decl", "function_params",
  "func_param", "function_call", "function_arguments", "control_statement",
  "condition_assignment", "conditions", "condition", "statements",
  "statement", "assignment", "leftexp", "expression", "types_block",
  "type", "inner_content", "main_block", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-151)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,   481,    26,     6,    89,    40,    82,   197,  -151,  -151,
    -151,    48,   112,   143,   169,    24,   147,  -151,   159,   190,
     189,  -151,  -151,   174,    46,  -151,  -151,    20,   173,   177,
     188,   191,   198,   200,   210,  -151,  -151,   212,   201,   170,
    -151,  -151,    32,   229,   230,  -151,   217,  -151,   214,  -151,
    -151,    21,  -151,  -151,   236,   242,    94,   233,   243,   130,
      -5,   130,  -151,  -151,  -151,   482,  -151,  -151,   204,   -14,
     237,  -151,  -151,    87,     4,   189,  -151,   224,   228,   238,
     235,    30,  -151,  -151,  -151,  -151,  -151,  -151,   101,  -151,
    -151,    58,   239,   241,   244,   245,   130,    10,  -151,   122,
      28,   254,   255,   119,    -3,   248,  -151,  -151,   253,   271,
     204,   281,   289,   287,   267,    98,  -151,   189,    12,   189,
    -151,  -151,  -151,   290,   288,    39,   101,  -151,   101,   282,
     298,   130,   137,    97,   276,   130,   101,   301,   101,   303,
     280,   130,   284,   306,   314,   316,   305,   300,  -151,   304,
     322,  -151,   192,   152,   310,   189,   189,   228,  -151,   312,
    -151,   239,  -151,  -151,  -151,   141,  -151,   213,  -151,   239,
     324,   239,   315,   317,    75,   234,   228,  -151,   320,   326,
     318,   204,    22,  -151,   101,   251,  -151,  -151,   268,   189,
    -151,  -151,   343,   285,   101,   341,   302,   355,  -151,   319,
    -151,  -151,   204,  -151,   104,  -151,   337,  -151,   113,   101,
    -151,   101,   336,   335,   349,   239,   101,  -151,   353,   342,
    -151,   133,   204,  -151,  -151,   344,   157,   158,   101,   370,
     348,   239,  -151,   350,  -151,  -151,  -151,   351,   352,   168,
    -151,   387,   404,   421,  -151,  -151,   360,  -151,  -151,   438,
    -151,   455,  -151,  -151,  -151
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     3,     1,
       6,     0,     0,     0,     0,    13,     0,     8,     0,     0,
      33,    34,    10,     0,     0,    97,    12,    86,     0,     0,
       0,     0,     0,     0,     0,    77,   109,     0,     0,     0,
       2,     4,    16,     0,     0,     5,     0,    14,     0,     7,
      35,     0,     9,    98,     0,     0,     0,     0,     0,     0,
       0,     0,    74,    75,    73,     0,    11,   110,     0,     0,
      18,    24,    15,     0,   105,   107,   100,     0,    88,     0,
       0,    90,    25,    26,    29,    27,    28,    48,     0,    89,
      94,     0,    49,     0,     0,     0,     0,     0,    66,     0,
       0,     0,     0,     0,    81,     0,    80,    17,     0,    21,
       0,     0,     0,     0,     0,     0,    40,   104,   106,   108,
      99,    76,    87,     0,     0,     0,     0,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    20,     0,    19,    42,
       0,    46,     0,     0,     0,   103,   102,    92,    93,     0,
      95,    50,    96,    79,    78,     0,    68,     0,    69,    70,
       0,    63,     0,     0,     0,     0,    84,    85,     0,     0,
       0,     0,     0,    43,     0,     0,    71,    41,     0,   101,
      91,    67,    52,     0,     0,     0,     0,     0,    58,     0,
      82,    83,     0,    32,     0,    30,     0,    44,     0,     0,
      72,     0,     0,     0,    51,    65,     0,    62,     0,     0,
      57,     0,     0,    23,    45,     0,     0,     0,     0,     0,
       0,    64,    61,     0,    22,    31,    39,     0,     0,     0,
      56,     0,     0,     0,    37,    38,     0,    54,    55,     0,
      60,     0,    36,    53,    59
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -151,  -151,  -151,   383,  -151,   327,    15,   -56,   202,   184,
    -151,   -65,   -18,  -151,   256,   -53,  -151,  -151,   211,   -54,
    -151,  -150,    -6,  -151,  -151,   -52,  -151,   393,  -151,  -151
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     7,     8,    14,    15,    33,    89,   204,   205,
      19,    20,    21,   115,   116,    34,    91,    35,   102,    97,
      98,   185,   186,    37,    38,    99,    24,    25,    77,    39
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      36,    79,    50,    90,    92,   108,    90,   103,    90,   106,
     119,    10,   107,   100,   143,   117,     1,   193,    16,    11,
      12,    11,    12,   156,   109,   199,     9,    11,    12,   101,
      46,    74,    75,    67,   144,    90,   125,    54,   212,    11,
      12,   206,   132,    90,   133,   137,   218,   123,    13,    22,
      13,   134,   155,   135,   148,    52,    13,    55,    23,   138,
     207,    76,    56,    68,    23,   139,    42,   124,    13,    69,
     158,   128,    56,    90,   161,    90,   162,   165,    90,   241,
     160,   168,    90,    90,   169,    90,   171,   174,    90,    16,
     177,   189,   249,   251,   126,    26,    17,    11,    12,   127,
      27,    50,   111,   112,    18,   113,    28,    29,    30,   197,
      31,    32,    81,    82,    83,    84,    85,    86,   135,    81,
      82,    83,    84,    85,    86,   203,    13,    43,   114,   128,
     136,    90,   208,    46,   153,    87,    88,    50,   160,   154,
     222,    90,   215,    88,   223,   128,   203,   225,    81,    82,
      83,    84,    85,    86,   128,   136,    90,   226,    90,   227,
     142,    44,   135,    90,   231,    95,   203,   111,   112,   222,
     113,    50,    96,   234,    45,    90,   239,    48,   166,   210,
     135,    47,   191,    66,   135,    11,    12,   210,    27,   128,
     128,   237,   238,   210,    28,    29,    30,    49,    31,    32,
     128,     3,   246,     4,    18,     5,   210,    11,    12,     6,
      27,    40,   210,    51,    13,    57,    28,    29,    30,    58,
      31,    32,   184,    82,    83,    84,    85,    86,    11,    12,
      59,    27,    65,    60,    62,   210,    13,    28,    29,    30,
      61,    31,    32,   210,    63,   210,    64,    70,    71,    11,
      12,    72,    27,   192,    78,    93,    73,    13,    28,    29,
      30,    80,    31,    32,   120,    94,    11,    12,   110,    27,
      56,   128,   121,   122,   198,    28,    29,    30,    13,    31,
      32,   209,   129,    11,    12,   130,    27,   131,   140,   141,
     145,   146,    28,    29,    30,    13,    31,    32,   211,   149,
      11,    12,   147,    27,   150,   151,   152,   159,   157,    28,
      29,    30,    13,    31,    32,   167,   163,    11,    12,   170,
      27,   173,   172,   175,   176,   214,    28,    29,    30,    13,
      31,    32,   164,   178,    11,    12,   180,    27,   179,   181,
     183,   182,   217,    28,    29,    30,    13,    31,    32,   188,
     190,    11,    12,   195,    27,   194,   196,   202,   200,   220,
      28,    29,    30,    13,    31,    32,   228,   201,    11,    12,
     213,    27,   216,   100,   229,   224,   230,    28,    29,    30,
      13,    31,    32,   233,   236,    11,    12,   242,    27,   243,
      41,   244,   245,   232,    28,    29,    30,    13,    31,    32,
     252,   118,    11,    12,   221,    27,   235,     0,   219,   187,
     240,    28,    29,    30,    13,    31,    32,    53,     0,    11,
      12,     0,    27,     0,     0,     0,     0,   247,    28,    29,
      30,    13,    31,    32,     0,     0,    11,    12,     0,    27,
       0,     0,     0,     0,   248,    28,    29,    30,    13,    31,
      32,     0,     0,    11,    12,     0,    27,     0,     0,     0,
       0,   250,    28,    29,    30,    13,    31,    32,     0,     0,
      11,    12,     0,    27,     0,     0,     0,     0,   253,    28,
      29,    30,    13,    31,    32,     3,     0,     4,     0,     5,
       0,     0,     0,     6,     0,   254,     0,     0,     0,    13,
     104,    82,    83,    84,    85,    86,   105
};

static const yytype_int16 yycheck[] =
{
       6,    54,    20,    56,    56,    19,    59,    61,    61,    65,
      75,     5,    68,    18,    17,    11,     3,   167,     3,    15,
      16,    15,    16,    11,    38,   175,     0,    15,    16,    34,
      15,    10,    11,    39,    37,    88,    88,    17,   188,    15,
      16,    19,    96,    96,    96,    17,   196,    17,    44,     9,
      44,    41,   117,    43,   110,     9,    44,    37,    18,    31,
      38,    40,    42,    31,    18,    37,    18,    37,    44,    37,
     123,    32,    42,   126,   126,   128,   128,   131,   131,   229,
      41,   135,   135,   136,   136,   138,   138,   141,   141,    74,
     143,   156,   242,   243,    36,    13,     7,    15,    16,    41,
      18,   119,    15,    16,    15,    18,    24,    25,    26,    34,
      28,    29,    18,    19,    20,    21,    22,    23,    43,    18,
      19,    20,    21,    22,    23,   181,    44,    15,    41,    32,
      33,   184,   184,   118,    36,    41,    42,   155,    41,    41,
      36,   194,   194,    42,    40,    32,   202,    34,    18,    19,
      20,    21,    22,    23,    32,    33,   209,   209,   211,   211,
      41,    18,    43,   216,   216,    35,   222,    15,    16,    36,
      18,   189,    42,    40,     5,   228,   228,    18,    41,   185,
      43,    34,    41,    13,    43,    15,    16,   193,    18,    32,
      32,    34,    34,   199,    24,    25,    26,     7,    28,    29,
      32,     4,    34,     6,    15,     8,   212,    15,    16,    12,
      18,    14,   218,    39,    44,    42,    24,    25,    26,    42,
      28,    29,    30,    19,    20,    21,    22,    23,    15,    16,
      42,    18,    31,    42,    34,   241,    44,    24,    25,    26,
      42,    28,    29,   249,    34,   251,    34,    18,    18,    15,
      16,    34,    18,    40,    18,    22,    42,    44,    24,    25,
      26,    19,    28,    29,    40,    22,    15,    16,    31,    18,
      42,    32,    34,    38,    40,    24,    25,    26,    44,    28,
      29,    30,    41,    15,    16,    41,    18,    42,    34,    34,
      42,    38,    24,    25,    26,    44,    28,    29,    30,    18,
      15,    16,    31,    18,    15,    18,    39,    19,    18,    24,
      25,    26,    44,    28,    29,    39,    34,    15,    16,    18,
      18,    41,    19,    39,    18,    40,    24,    25,    26,    44,
      28,    29,    34,    19,    15,    16,    31,    18,    22,    39,
      18,    37,    40,    24,    25,    26,    44,    28,    29,    39,
      38,    15,    16,    38,    18,    31,    39,    39,    38,    40,
      24,    25,    26,    44,    28,    29,    30,    41,    15,    16,
      27,    18,    31,    18,    39,    38,    27,    24,    25,    26,
      44,    28,    29,    41,    40,    15,    16,    39,    18,    39,
       7,    40,    40,    40,    24,    25,    26,    44,    28,    29,
      40,    74,    15,    16,   202,    18,   222,    -1,   197,   153,
      40,    24,    25,    26,    44,    28,    29,    24,    -1,    15,
      16,    -1,    18,    -1,    -1,    -1,    -1,    40,    24,    25,
      26,    44,    28,    29,    -1,    -1,    15,    16,    -1,    18,
      -1,    -1,    -1,    -1,    40,    24,    25,    26,    44,    28,
      29,    -1,    -1,    15,    16,    -1,    18,    -1,    -1,    -1,
      -1,    40,    24,    25,    26,    44,    28,    29,    -1,    -1,
      15,    16,    -1,    18,    -1,    -1,    -1,    -1,    40,    24,
      25,    26,    44,    28,    29,     4,    -1,     6,    -1,     8,
      -1,    -1,    -1,    12,    -1,    40,    -1,    -1,    -1,    44,
      18,    19,    20,    21,    22,    23,    24
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    46,     4,     6,     8,    12,    47,    48,     0,
       5,    15,    16,    44,    49,    50,    51,     7,    15,    55,
      56,    57,     9,    18,    71,    72,    13,    18,    24,    25,
      26,    28,    29,    51,    60,    62,    67,    68,    69,    74,
      14,    48,    18,    15,    18,     5,    51,    34,    18,     7,
      57,    39,     9,    72,    17,    37,    42,    42,    42,    42,
      42,    42,    34,    34,    34,    31,    13,    67,    31,    37,
      18,    18,    34,    42,    10,    11,    40,    73,    18,    60,
      19,    18,    19,    20,    21,    22,    23,    41,    42,    52,
      60,    61,    70,    22,    22,    35,    42,    64,    65,    70,
      18,    34,    63,    64,    18,    24,    52,    52,    19,    38,
      31,    15,    16,    18,    41,    58,    59,    11,    50,    56,
      40,    34,    38,    17,    37,    70,    36,    41,    32,    41,
      41,    42,    64,    70,    41,    43,    33,    17,    31,    37,
      34,    34,    41,    17,    37,    42,    38,    31,    52,    18,
      15,    18,    39,    36,    41,    56,    11,    18,    60,    19,
      41,    70,    70,    34,    34,    64,    41,    39,    64,    70,
      18,    70,    19,    41,    64,    39,    18,    60,    19,    22,
      31,    39,    37,    18,    30,    66,    67,    59,    39,    56,
      38,    41,    40,    66,    31,    38,    39,    34,    40,    66,
      38,    41,    39,    52,    53,    54,    19,    38,    70,    30,
      67,    30,    66,    27,    40,    70,    31,    40,    66,    63,
      40,    53,    36,    40,    38,    34,    70,    70,    30,    39,
      27,    70,    40,    41,    40,    54,    40,    34,    34,    70,
      40,    66,    39,    39,    40,    40,    34,    40,    40,    66,
      40,    66,    40,    40,    40
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    48,    48,    48,
      48,    48,    48,    49,    50,    50,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    52,    52,    52,    52,    52,
      53,    53,    54,    55,    56,    56,    57,    57,    57,    57,
      58,    58,    59,    59,    59,    59,    59,    60,    60,    61,
      61,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    63,    63,    63,    64,    64,    64,    64,
      65,    66,    66,    67,    67,    67,    67,    67,    67,    67,
      68,    68,    68,    68,    68,    68,    69,    69,    69,    70,
      70,    70,    70,    70,    70,    70,    70,    71,    71,    72,
      72,    73,    73,    73,    73,    73,    73,    73,    73,    74,
      74
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
      10,     8,     7,     3,     6,     5,     1,     4,     3,     3,
       3,     1,     2,     2,     2,     2,     4,     1,     5,     5,
       3,     3,     6,     6,     5,     5,     1,     4,     3,     1,
       1,     4,     3,     3,     1,     3,     3,     1,     2,     4,
       3,     4,     3,     3,     2,     1,     2,     1,     2,     1,
       2
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
#line 203 "parser.y"
                              {printf("Programul este corect sintactic!\n");}
#line 1602 "y.tab.c"
    break;

  case 5: /* block: GLOBAL global_block END_GLOBAL  */
#line 212 "parser.y"
                                       {
      setSymbolScope(symbol_scope_position, types_position, SYMBOL_SCOPE, "functions");
}
#line 1610 "y.tab.c"
    break;

  case 6: /* block: GLOBAL END_GLOBAL  */
#line 215 "parser.y"
                          {

      setSymbolScope(symbol_scope_position, types_position, SYMBOL_SCOPE, "functions");
}
#line 1619 "y.tab.c"
    break;

  case 7: /* block: FUNCTIONS functions_block END_FUNCTIONS  */
#line 219 "parser.y"
                                                {

      symbol_scope_position = 0;
      types_position = 0;
      suntem_in_types = 1;
      setSymbolScope(symbol_scope_position, types_position, SYMBOL_SCOPE, "types");
      setFunctionScope(types_position, FUNCTION_SCOPE,"types");


}
#line 1634 "y.tab.c"
    break;

  case 8: /* block: FUNCTIONS END_FUNCTIONS  */
#line 229 "parser.y"
                               {

      symbol_scope_position = 0;
      types_position = 0;
      suntem_in_types = 1;
      setSymbolScope(symbol_scope_position, types_position, SYMBOL_SCOPE, "types");
      setFunctionScope(types_position, FUNCTION_SCOPE,"types");


}
#line 1649 "y.tab.c"
    break;

  case 9: /* block: TYPES types_block END_TYPES  */
#line 239 "parser.y"
                                    {
      strcpy(SYMBOL_SCOPE,MAIN_SCOPE);
      suntem_in_types = 0;
}
#line 1658 "y.tab.c"
    break;

  case 10: /* block: TYPES END_TYPES  */
#line 243 "parser.y"
                        {

      strcpy(SYMBOL_SCOPE,MAIN_SCOPE);
      suntem_in_types = 0;
}
#line 1668 "y.tab.c"
    break;

  case 16: /* declaratie_variabila: DATA_TYPE IDENTIFIER  */
#line 264 "parser.y"
                                           {
      int code = addSymbol(index_symbols_table, SYMBOL_SCOPE, symbols, NOT_TYPE, NOT_ARRAY, NOT_CONST, (yyvsp[-1].string_value), (yyvsp[0].string_value), UNDEFINED,UNDEFINED_ARRAY,0,0);
      index_symbols_table++;
      showError(code);
}
#line 1678 "y.tab.c"
    break;

  case 17: /* declaratie_variabila: DATA_TYPE IDENTIFIER ASSIGN value  */
#line 269 "parser.y"
                                             {
      int code = addSymbol(index_symbols_table, SYMBOL_SCOPE, symbols, NOT_TYPE, NOT_ARRAY, NOT_CONST, (yyvsp[-3].string_value), (yyvsp[-2].string_value), (yyvsp[0].string_value),UNDEFINED_ARRAY,0,0);
      index_symbols_table++;
      showError(code);

}
#line 1689 "y.tab.c"
    break;

  case 18: /* declaratie_variabila: CONST DATA_TYPE IDENTIFIER  */
#line 275 "parser.y"
                                          {/*thows error*/ yyerror("const without value asociated!");}
#line 1695 "y.tab.c"
    break;

  case 19: /* declaratie_variabila: CONST DATA_TYPE IDENTIFIER ASSIGN value  */
#line 276 "parser.y"
                                                   {
      int code = addSymbol(index_symbols_table, SYMBOL_SCOPE, symbols, NOT_TYPE, NOT_ARRAY, IS_CONST, (yyvsp[-3].string_value), (yyvsp[-2].string_value), (yyvsp[0].string_value), UNDEFINED_ARRAY,0,0);
      index_symbols_table++;
      showError(code);

}
#line 1706 "y.tab.c"
    break;

  case 20: /* declaratie_variabila: DATA_TYPE IDENTIFIER LSB INTEGER_VALUE RSB  */
#line 282 "parser.y"
                                                      {      
      int code = addSymbol(index_symbols_table, SYMBOL_SCOPE, symbols, NOT_TYPE, IS_ARRAY, NOT_CONST, (yyvsp[-4].string_value), (yyvsp[-3].string_value), UNDEFINED, UNDEFINED_ARRAY,(yyvsp[-1].int_value),0);
      index_symbols_table++;
      showError(code);

}
#line 1717 "y.tab.c"
    break;

  case 21: /* declaratie_variabila: DATA_TYPE IDENTIFIER LSB RSB  */
#line 288 "parser.y"
                                           {/*throws error array with no space allocated*/ yyerror("error array with no space allocated!");}
#line 1723 "y.tab.c"
    break;

  case 22: /* declaratie_variabila: DATA_TYPE IDENTIFIER LSB INTEGER_VALUE RSB ASSIGN LCB array_values RCB  */
#line 291 "parser.y"
                                                                                  {
      int code = addSymbol(index_symbols_table, SYMBOL_SCOPE, symbols, NOT_TYPE, IS_ARRAY, NOT_CONST, (yyvsp[-8].string_value), (yyvsp[-7].string_value), UNDEFINED, ARRAY_VALUES ,(yyvsp[-5].int_value),index_arr);
      index_symbols_table++;
      index_arr = 0;
      memset(ARRAY_VALUES,0,200*1000*sizeof(char));
      showError(code);

}
#line 1736 "y.tab.c"
    break;

  case 23: /* declaratie_variabila: DATA_TYPE IDENTIFIER LSB RSB ASSIGN LCB array_values RCB  */
#line 299 "parser.y"
                                                                    {
      int code = addSymbol(index_symbols_table, SYMBOL_SCOPE, symbols, NOT_TYPE, IS_ARRAY, NOT_CONST, (yyvsp[-7].string_value), (yyvsp[-6].string_value), UNDEFINED, ARRAY_VALUES ,0,index_arr);
      index_symbols_table++;
      index_arr = 0;
      memset(ARRAY_VALUES,0,200*1000*sizeof(char));
      showError(code);

}
#line 1749 "y.tab.c"
    break;

  case 24: /* declaratie_variabila: TYPE IDENTIFIER IDENTIFIER  */
#line 308 "parser.y"
                                      {
      int code = addSymbol(index_symbols_table, SYMBOL_SCOPE, symbols, IS_TYPE, NOT_ARRAY, NOT_CONST, (yyvsp[-1].string_value), (yyvsp[0].string_value), UNDEFINED, UNDEFINED_ARRAY,0,0);
      index_symbols_table++;
      showError(code);

}
#line 1760 "y.tab.c"
    break;

  case 25: /* value: INTEGER_VALUE  */
#line 318 "parser.y"
                      {(yyval.string_value) = strdup(yytext); }
#line 1766 "y.tab.c"
    break;

  case 26: /* value: BOOL_VALUE  */
#line 319 "parser.y"
                      {(yyval.string_value) = strdup(yytext); }
#line 1772 "y.tab.c"
    break;

  case 27: /* value: STRING_VALUE  */
#line 320 "parser.y"
                      {(yyval.string_value) = strdup(yytext); }
#line 1778 "y.tab.c"
    break;

  case 28: /* value: CHAR_VALUE  */
#line 321 "parser.y"
                      {(yyval.string_value) = strdup(yytext); }
#line 1784 "y.tab.c"
    break;

  case 29: /* value: FLOAT_VALUE  */
#line 322 "parser.y"
                      {(yyval.string_value) = strdup(yytext); }
#line 1790 "y.tab.c"
    break;

  case 32: /* array_value: value  */
#line 329 "parser.y"
                   {
      strcpy(ARRAY_VALUES[index_arr],(yyvsp[0].string_value)); index_arr++;
}
#line 1798 "y.tab.c"
    break;

  case 33: /* functions_block: functions_decl  */
#line 337 "parser.y"
                                {symbol_scope_position = 0;}
#line 1804 "y.tab.c"
    break;

  case 36: /* func_decl: DATA_TYPE IDENTIFIER LPB function_params RPB LCB statements RETURN expression SEMICOLON RCB  */
#line 346 "parser.y"
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
#line 1824 "y.tab.c"
    break;

  case 37: /* func_decl: DATA_TYPE IDENTIFIER LPB RPB LCB statements RETURN expression SEMICOLON RCB  */
#line 361 "parser.y"
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
#line 1844 "y.tab.c"
    break;

  case 38: /* func_decl: DATA_TYPE IDENTIFIER LPB function_params RPB LCB RETURN expression SEMICOLON RCB  */
#line 376 "parser.y"
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
#line 1866 "y.tab.c"
    break;

  case 39: /* func_decl: DATA_TYPE IDENTIFIER LPB RPB LCB RETURN expression SEMICOLON RCB  */
#line 393 "parser.y"
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
#line 1885 "y.tab.c"
    break;

  case 42: /* func_param: DATA_TYPE IDENTIFIER  */
#line 413 "parser.y"
                                  {strcpy((yyval.string_value),(yyvsp[-1].string_value)); strcat((yyval.string_value)," "); strcat((yyval.string_value),(yyvsp[0].string_value)); strcpy(FUNCTION_PARAMS[index_par],(yyval.string_value)); index_par++;}
#line 1891 "y.tab.c"
    break;

  case 43: /* func_param: CONST DATA_TYPE IDENTIFIER  */
#line 414 "parser.y"
                                   {strcpy((yyval.string_value),"const"); strcat((yyval.string_value)," "); strcat((yyval.string_value),(yyvsp[-1].string_value)); strcat((yyval.string_value)," "); strcat((yyval.string_value),(yyvsp[0].string_value)); strcpy(FUNCTION_PARAMS[index_par],(yyval.string_value)); index_par++;}
#line 1897 "y.tab.c"
    break;

  case 44: /* func_param: DATA_TYPE IDENTIFIER LSB RSB  */
#line 415 "parser.y"
                                     {strcpy((yyval.string_value),(yyvsp[-3].string_value)); strcat((yyval.string_value)," "); strcat((yyval.string_value),(yyvsp[-2].string_value));strcat((yyval.string_value),"["); strcat((yyval.string_value),"]"); strcpy(FUNCTION_PARAMS[index_par],(yyval.string_value)); index_par++;}
#line 1903 "y.tab.c"
    break;

  case 45: /* func_param: DATA_TYPE IDENTIFIER LSB INTEGER_VALUE RSB  */
#line 416 "parser.y"
                                                   {
      strcpy((yyval.string_value),(yyvsp[-4].string_value)); strcat((yyval.string_value)," "); strcat((yyval.string_value),(yyvsp[-3].string_value));strcat((yyval.string_value),"[");

      char intstring[20]= "\0";
      sprintf(intstring,"%d", (yyvsp[-1].int_value));
      strcat((yyval.string_value),intstring);
      strcat((yyval.string_value),"]");

      strcpy(FUNCTION_PARAMS[index_par],(yyval.string_value));
      index_par++;
}
#line 1919 "y.tab.c"
    break;

  case 46: /* func_param: IDENTIFIER IDENTIFIER  */
#line 427 "parser.y"
                              {strcpy((yyval.string_value),(yyvsp[-1].string_value)); strcat((yyval.string_value)," "); strcat((yyval.string_value),(yyvsp[0].string_value)); strcpy(FUNCTION_PARAMS[index_par],(yyval.string_value)); index_par++;}
#line 1925 "y.tab.c"
    break;

  case 78: /* statement: TYPEOF LPB STRING_VALUE RPB SEMICOLON  */
#line 485 "parser.y"
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
#line 2090 "y.tab.c"
    break;

  case 79: /* statement: EVAL LPB STRING_VALUE RPB SEMICOLON  */
#line 646 "parser.y"
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
#line 2217 "y.tab.c"
    break;

  case 80: /* assignment: leftexp ASSIGN value  */
#line 772 "parser.y"
                                 {

      if(strcmp((yyvsp[-2].string_value),"N/A") != 0){

            if((yyvsp[-2].string_value)[strlen((yyvsp[-2].string_value))-1] == 'V'){
                  (yyvsp[-2].string_value)[strlen((yyvsp[-2].string_value))-1] = '\0';
                  int res = assign((yyvsp[-2].string_value),(yyvsp[0].string_value), 1 , 1,symbols,index_symbols_table);
                  showError(res);



            }
            else if((yyvsp[-2].string_value)[strlen((yyvsp[-2].string_value))-1] == 'A'){
                  (yyvsp[-2].string_value)[strlen((yyvsp[-2].string_value))-1] = '\0';
                  int res = assign((yyvsp[-2].string_value),(yyvsp[0].string_value), 2 , 1,symbols,index_symbols_table) ;
                  showError(res);
            }
      }
}
#line 2241 "y.tab.c"
    break;

  case 81: /* assignment: leftexp ASSIGN IDENTIFIER  */
#line 791 "parser.y"
                                      {

      if(strcmp((yyvsp[-2].string_value),"N/A") !=0){

            if((yyvsp[-2].string_value)[strlen((yyvsp[-2].string_value))-1] == 'V'){
                  (yyvsp[-2].string_value)[strlen((yyvsp[-2].string_value))-1] = '\0';
                  int res = assign((yyvsp[-2].string_value),(yyvsp[0].string_value), 1 , 2,symbols,index_symbols_table);
                  showError(res);
                  

            }
            else if((yyvsp[-2].string_value)[strlen((yyvsp[-2].string_value))-1] == 'A'){
                  (yyvsp[-2].string_value)[strlen((yyvsp[-2].string_value))-1] = '\0';
                  int res = assign((yyvsp[-2].string_value),(yyvsp[0].string_value), 2 , 2,symbols,index_symbols_table);
                  showError(res);
            }
      }
}
#line 2264 "y.tab.c"
    break;

  case 82: /* assignment: leftexp ASSIGN IDENTIFIER LSB INTEGER_VALUE RSB  */
#line 809 "parser.y"
                                                            {

      if(strcmp((yyvsp[-5].string_value),"N/A") !=0){

            char aux[100];
            char intToString[50];

            strcpy(aux,(yyvsp[-3].string_value)); strcat(aux,"["); 
            sprintf(intToString,"%d",(yyvsp[-1].int_value));
            strcat(aux,intToString); 
            strcat(aux,"]");
            

            if((yyvsp[-5].string_value)[strlen((yyvsp[-5].string_value))-1] == 'V'){
                  (yyvsp[-5].string_value)[strlen((yyvsp[-5].string_value))-1] = '\0';
                  int res = assign((yyvsp[-5].string_value),aux, 1 , 3,symbols,index_symbols_table);
                  showError(res);

            }
            else if((yyvsp[-5].string_value)[strlen((yyvsp[-5].string_value))-1] == 'A'){
                  (yyvsp[-5].string_value)[strlen((yyvsp[-5].string_value))-1] = '\0';
                  int res = assign((yyvsp[-5].string_value),aux, 2 , 3,symbols,index_symbols_table);
                  showError(res);
            }
      }
}
#line 2295 "y.tab.c"
    break;

  case 83: /* assignment: leftexp ASSIGN EVAL LPB STRING_VALUE RPB  */
#line 835 "parser.y"
                                                     {

      if(strcmp((yyvsp[-5].string_value),"N/A") !=0){
            //asteptam functia EVAL();

      }
}
#line 2307 "y.tab.c"
    break;

  case 86: /* leftexp: IDENTIFIER  */
#line 846 "parser.y"
                     {strcpy((yyval.string_value),(yyvsp[0].string_value)); strcat((yyval.string_value),"V");}
#line 2313 "y.tab.c"
    break;

  case 87: /* leftexp: IDENTIFIER LSB INTEGER_VALUE RSB  */
#line 847 "parser.y"
                                           {
            strcpy((yyval.string_value),(yyvsp[-3].string_value)); strcat((yyval.string_value),"["); 
            char aux[100];
            sprintf(aux,"%d",(yyvsp[-1].int_value));
            strcat((yyval.string_value),aux); 
            strcat((yyval.string_value),"]");
            strcat((yyval.string_value),"A");
            }
#line 2326 "y.tab.c"
    break;

  case 88: /* leftexp: IDENTIFIER ACCES IDENTIFIER  */
#line 855 "parser.y"
                                      {strcat((yyval.string_value),"N/A");}
#line 2332 "y.tab.c"
    break;

  case 99: /* type: IDENTIFIER LCB inner_content RCB  */
#line 878 "parser.y"
                                        {
      symbol_scope_position = 0; types_position++;  
      setSymbolScope(symbol_scope_position,types_position, SYMBOL_SCOPE, "types");
      setFunctionScope(types_position, FUNCTION_SCOPE,"types");

      int code = addType(index_types_table, (yyvsp[-3].string_value), types);
      index_types_table++;
      showError(code);

}
#line 2347 "y.tab.c"
    break;

  case 100: /* type: IDENTIFIER LCB RCB  */
#line 888 "parser.y"
                          {
      symbol_scope_position = 0; types_position++;
      setSymbolScope(symbol_scope_position,types_position, SYMBOL_SCOPE, "types");
      setFunctionScope(types_position,FUNCTION_SCOPE,"types");

      int code = addType(index_types_table, (yyvsp[-2].string_value), types);
      index_types_table++;
      showError(code);
      }
#line 2361 "y.tab.c"
    break;

  case 101: /* inner_content: MEMBERS declaratii_variabile METHODS functions_decl  */
#line 899 "parser.y"
                                                                   {

}
#line 2369 "y.tab.c"
    break;

  case 102: /* inner_content: MEMBERS declaratii_variabile METHODS  */
#line 902 "parser.y"
                                                {
}
#line 2376 "y.tab.c"
    break;

  case 103: /* inner_content: MEMBERS METHODS functions_decl  */
#line 904 "parser.y"
                                          {
}
#line 2383 "y.tab.c"
    break;

  case 104: /* inner_content: MEMBERS METHODS  */
#line 906 "parser.y"
                           {
}
#line 2390 "y.tab.c"
    break;

  case 105: /* inner_content: MEMBERS  */
#line 908 "parser.y"
                   {
}
#line 2397 "y.tab.c"
    break;

  case 106: /* inner_content: MEMBERS declaratii_variabile  */
#line 910 "parser.y"
                                        {
}
#line 2404 "y.tab.c"
    break;

  case 107: /* inner_content: METHODS  */
#line 912 "parser.y"
                   {
}
#line 2411 "y.tab.c"
    break;

  case 108: /* inner_content: METHODS functions_decl  */
#line 914 "parser.y"
                                  {
}
#line 2418 "y.tab.c"
    break;


#line 2422 "y.tab.c"

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

#line 927 "parser.y"






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
