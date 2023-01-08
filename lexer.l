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

"int"|"float"|"char"|"string"|"bool"        {return DATA_TYPE;}  /*tipurile de date primitive*/
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

"||"|"&&"                                   {return BOOLEAN_OPERATOR;}
"="                                         {return ASSIGN;}   /*operator de atribuire*/
"+"|"-"|"*"|"/"|"%"                         {return ARITHMETIC_OPERATOR;} /*operatori aritmetici +,-, etc*/
">"|">="|"<"|"<="|"=="|"!="                 {return RELATIONAL_OPERATOR;} /*operatori relationali(if,while,etc)*/
"!"                                         {return NOT;}


"true"|"false"                              {return BOOL_VALUE;} /*valori booleene (true si false)*/


";"                                         {return SEMICOLON;}
","                                         {return COMMA;}
"["                                         {return LSB;}
"]"                                         {return RSB;}
"{"                                         {return LCB;}
"}"                                         {return RCB;}
")"                                         {return RPB;}
"("                                         {return LPB;}

[_a-zA-Z][_a-zA-Z0-9_]*                     {return IDENTIFIER;} /*nume de variabile si functii*/
([+-])?(0|([1-9][0-9]*))                    {return INTEGER_VALUE;} /*valori int*/
[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?      {return FLOAT_VALUE;} /*valori float*/
\"([^\\"]|\\.)*\"                           {return STRING_VALUE;}   /*valori pe care le poate lua un sir de caractere*/ 
[\x21-\x7E]                                 {return CHAR_VALUE;}  /*valorile pe care le poate lua un caracter(ASCII)*/    

"/*"(.|\n)+"*/" ; /*comentariu C-style*/
[\t ] ; /*aici ignoram spatiu si tab*/
\n                                          {yylineno++;}   /**/

.                                           {return yytext[0];}  /* pentru '.' inseamna toate caracterele UNICODE*/
%%