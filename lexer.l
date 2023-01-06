%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
%}
%option noyywrap
%%

"/*"(.|\n)+"*/" ; /*comentariu C-style*/
[\t ] ; /*aici ignoram spatiu si tab*/
\n                                          {yylineno++; return NEWLINE;}   /**/


"START:"                                    {return START;}  /*token pentru inceputul programului*/
"GLOBAL:"                                   {return GLOBAL;}  /*token care marcheaza inceputul blocului de declaratii globale*/
"FUNCTIONS:"                                {return FUNCTIONS;} /*token care marcheaza inceputul blocului de declaratii de functii*/
"TYPES:"                                    {return TYPES;}  /*token care marcheaza inceputul blocului de declaratii de tipuri custom*/
"members:"                                  {return MEMBERS;}  /*variabile din tipurile custom*/
"methods:"                                  {return METHODS;}  /*metodele din tipurile custom*/
"MAIN:"                                     {return MAIN;}  /*toke care marcheaza inceput main*/
"END_MAIN"                                  {return END_MAIN;}  /*toke care marcheaza final main*/
"END"                                       {return END;}  /*token pentru finalul programului*/



"int"|"float"|"char"|"string"|"bool"        {return DATA_TYPE;}  /*tipurile de date primitive*/
"const"                                     {return CONST;}      /*const*/
"-->"                                       {return ACCES;}      /*operator pentru accesat membri si metode in clasele noastre(TYPES)*/

[a-zA-Z]+                                   {return CUSTOM_TYPE;} /*valorile pe care le poate lua un nume de clasa*/
[a-zA-Z_][a-zA-Z0-9_]*                      {return IDENTIFIER;} /*nume de variabile si functii*/
([+-])?(0|([1-9][0-9]*))                    {return INTEGER_VALUE;} /*valori int*/
(0|([1-9][0-9]*))                           {return ABSOLUTE_VALUE;} /*valori int pozitive*/
"true"|"false"                              {return BOOL_VALUE;} /*valori booleene (true si false)*/
"^[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?$"  {return FLOAT_VALUE;} /*valori float*/
\"([^\\"]|\\.)*\"                           {return STRING_VALUE;}   /*valori pe care le poate lua un sir de caractere*/ 
[\x20-\x7E]                                 {return CHAR_VALUE;}  /*valorile pe care le poate lua un caracter(ASCII)*/     


"EVAL"                                      {return EVAL;}  /*functie care evalueaza expresii aritmetice EX : EVAL(a+2);*/
"Print"                                     {return PRINT;} /*functie care printeaza pe ecran numere sau siruri de caractere Print("hello")*/
"TypeOf"                                    {return TYPEOF;} /*functie care afiseaza pe ecran tipul de date al expresiei din paranteza TypeOf(a+2)*/


"if"                                        {return IF;} /*keyword if*/
"for"                                       {return FOR;} /*keyword for*/
"while"                                     {return WHILE;} /*keyword while*/
"return"                                    {return RETURN;} /*keyword return din functii*/


"="                                         {return ASSIGN;}   /*operator de atribuire*/
"+"|"-"|"*"|"/"|"%"                         {return ARITHMETIC_OPERATOR;} /*operatori aritmetici +,-, etc*/
">"|">="|"<"|"<="|"=="|"!="                 {return RELATIONAL_OPERATOR;} /*operatori relationali(if,while,etc)*/


"{"|"}"|","|"("|")"|"!"|";"					{ return yytext[0]; } /*alte semne de punctuatie si paranteze*/
.                                           {return yytext[0];}  /* pentru '.' inseamna toate caracterele UNICODE*/
%%