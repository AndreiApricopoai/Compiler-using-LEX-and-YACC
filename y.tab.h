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
#line 51 "parser.y"

      
int int_value;
char* string_value;
float float_value;

struct variableInformation* varInfo;


#line 167 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
