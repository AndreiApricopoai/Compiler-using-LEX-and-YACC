%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"


%}
%option noyywrap

%%

"START:"                                    {return START;}  /*token pentru inceputul programului*/
"GLOBAL:"                                   {return GLOBAL;}  /*token care marcheaza inceputul blocului de declaratii globale*/
"END_GLOBAL"                                {return END_GLOBAL;} /*token care marcheaza sfarsitul declaratiilor globale*/
"FUNCTIONS:"                                {return FUNCTIONS;} /*token care marcheaza inceputul blocului de declaratii de functii*/
"END_FUNCTIONS"                             {return END_FUNCTIONS;} /*token care marcheaza sfarsitul functiilor*/
"TYPES:"                                    {return TYPES;}  /*token care marcheaza inceputul blocului de declaratii de tipuri custom*/
"END_TYPES"                                 {return END_TYPES;} /*token care marcheaza sfarsitul claselor*/
"members:"                                  {return MEMBERS;}  /*variabile din tipurile custom*/
"methods:"                                  {return METHODS;}  /*metodele din tipurile custom*/
"MAIN:"                                     {return MAIN;}  /*toke care marcheaza inceput main*/
"END_MAIN"                                  {return END_MAIN;}  /*toke care marcheaza final main*/
"END"                                       {return END;}  /*token pentru finalul programului*/

"int"|"float"|"char"|"string"|"bool"        {yylval.string_value = strdup(yytext) ;return DATA_TYPE;}  /*tipurile de date primitive*/
"const"                                     {return CONST;}      /*const*/
"-->"                                       {return ACCES;}      /*operator pentru accesat membri si metode in clasele noastre(TYPES)*/ 


"EVAL"                                      {return EVAL;}  /*functie care evalueaza expresii aritmetice EX : EVAL(a+2);*/
"Print"                                     {return PRINT;} /*functie care printeaza pe ecran numere sau siruri de caractere Print("hello")*/
"TypeOf"                                    {return TYPEOF;} /*functie care afiseaza pe ecran tipul de date al expresiei din paranteza TypeOf(a+2)*/
"TYPE"                                      {return TYPE;}


"if"                                        {return IF;} /*keyword if*/
"else"                                      {return ELSE;}
"for"                                       {return FOR;} /*keyword for*/
"while"                                     {return WHILE;} /*keyword while*/
"return"                                    {return RETURN;} /*keyword return din functii*/

"&&"|"||"                                   {yylval.string_value = strdup(yytext) ;return BOOLEAN_OPERATOR;}
"="                                         {return ASSIGN;}   /*operator de atribuire*/
"+"|"-"|"*"|"/"|"%"                         {yylval.string_value = strdup(yytext) ;return ARITHMETIC_OPERATOR;} /*operatori aritmetici +,-, etc*/
">"|">="|"<"|"<="|"=="|"!="                 {yylval.string_value = strdup(yytext) ;return RELATIONAL_OPERATOR;} /*operatori relationali(if,while,etc)*/
"!"                                         {yylval.string_value = strdup(yytext) ;return NOT;}


"true"|"false"                              {if(strcmp(yytext,"true") == 0){yylval.int_value = 1;} else {yylval.int_value = 0;}  return BOOL_VALUE;} /*valori booleene (true si false)*/


";"                                         {return SEMICOLON;}
","                                         {return COMMA;}
"["                                         {return LSB;}
"]"                                         {return RSB;}
"{"                                         {return LCB;}
"}"                                         {return RCB;}
")"                                         {return RPB;}
"("                                         {return LPB;}



[_a-zA-Z][_a-zA-Z0-9_]* {/*nume de variabile si functii*/
    yylval.string_value = strdup(yytext); 
    return IDENTIFIER;
    }

(0|([1-9][0-9]*))                    {yylval.int_value = atoi(yytext); return INTEGER_VALUE;} /*valori int*/
[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?      {yylval.int_value = atof(yytext);return FLOAT_VALUE;} /*valori float*/


\'[\\n]?[\x21-\x7E ]?\'                     {yylval.string_value = strdup(yytext); return CHAR_VALUE;}  /*valorile pe care le poate lua un caracter(ASCII)*/    
\"[\x21-\x7E ]*\"                           {yylval.string_value = strdup(yytext); return STRING_VALUE;}   /*valori pe care le poate lua un sir de caractere*/ 

[\t ] ; /*aici ignoram spatiu si tab*/
\n                                          {yylineno++;}   /**/

.                                           {return yytext[0];}  /* pentru '.' inseamna toate caracterele UNICODE*/
%%