#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>




struct symbol_table{

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
    int is_type;

    int int_array_values[200];
    char char_array_values[200];
    char* string_array_values[200];
    int bool_array_values[200];

    int array_index;
};





struct param{
    char* data_type;
    char* identifier;
};


struct functionInformation
{
    char* data_type;
    char* identifier;
    char* scope;
    struct param params[100];

};


struct typeInformation
{
    /* data */
};


int addVariable(char* scope, struct symbol_table symbols[100], int is_type, int is_array, int is_const,char* data_type, char* identifier, char* value, char array_values[200][1000], int array_allocated_memory,  int array_number_elements){

    if(strcmp(array_values[0],"N/A")==0){
        printf("pull");
    }
    printf("%s | %s |%s |%s \n " , scope, value, array_values[0],identifier );
    return 0;
}


