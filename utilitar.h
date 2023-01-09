#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>





struct variableInformation
{
    char* data_type ;
    char* identifier;
    int int_val;
    int bool_val;
    float float_val;
    char char_val;
    char* string_val;
    char* scope;
    int is_const;

    int is_array;
    struct arrayValues arr_value[100];
    

};

struct arrayValues
{
    char* data_type;
    int int_val;
    int bool_val;
    float float_val;
    char char_val;
    char* string_val;

};



struct functionInformation
{
    char* data_type;
    char* identifier;
    char* scope;




};


struct typeInformation
{
    /* data */
};
