#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <regex.h>
#include <ctype.h>

struct symbol_table
{

    char data_type[100];  //--
    char identifier[100]; //--
    int int_val;
    int bool_val;
    float float_val;
    char char_val;
    char string_val[1000];

    int are_valoare;

    char scope[100]; //--

    int is_const;
    int is_array;
    int is_type;

    int int_array_values[200];
    float float_array_values[200];
    char char_array_values[200];
    char string_array_values[200][1000];
    int bool_array_values[200];

    int array_number_elements;
    int array_allocated_memory;
};

struct param
{
    char data_type[100];
    char identifier[100];

    int is_const;
    int is_array;
    int is_type;

    int array_allocated_memory;
};

struct functions_table
{
    char data_type[100];
    char identifier[100];
    char scope[100];

    int are_params;

    int params_number_elements;
    struct param params[50];
    char params_text[50][1000];
};

struct types_table
{
    char identifier[100];
};

struct Node
{
    char info;
    struct Node *left;
    struct Node *right;
};

struct Stack
{
    int top;
    unsigned capacity;
    int *array;
    struct Node *arrayStack[100];
};

int is_correct_value(char *datatype, char *value)
{

    if (strcmp(datatype, "int") == 0)
    {
        for (int i = 0; i < strlen(value); i++)
        {
            if ((value[i] < 48) || (value[i] > 57))
            {
                if ((value[i] != '+') && (value[i] != '-'))
                    return 0;
            }
        }
        return 1;
    }
    if (strcmp(datatype, "float") == 0)
    {

        float ignore;
        char c;
        int ret = sscanf(value, "%f %c", &ignore, &c);
        if (ret == 1)
            return 1;

        return 0;
    }
    if (strcmp(datatype, "bool") == 0)
    {
        if ((strcmp(value, "true") == 0) || (strcmp(value, "false") == 0))
            return 1;
    }
    if (strcmp(datatype, "char") == 0)
    {
        if ((value[0] == '\'') && (value[2] == '\''))
            return 1;
    }
    if (strcmp(datatype, "string") == 0)
    {
        if ((value[0] == '\"') && (value[strlen(value) - 1] == '\"'))
            return 1;
    }

    return 0;
}

int are_correct_array_values(char *datatype, char array_values[200][1000], int array_number_elements)
{
    for (int i = 0; i < array_number_elements; i++)
    {
        if (is_correct_value(datatype, array_values[i]) == 0)
            return 0;
    }
    return 1;
}

void addValue(char *datatype, char *value, int index, struct symbol_table symbols[100])
{

    if (strcmp(datatype, "int") == 0)
    {
        int ival = atoi(value);
        symbols[index].int_val = ival;
    }

    if (strcmp(datatype, "float") == 0)
    {
        float fval = atof(value);
        symbols[index].float_val = fval;
    }

    if (strcmp(datatype, "char") == 0)
    {
        symbols[index].char_val = value[1];
    }

    if (strcmp(datatype, "string") == 0)
    {
        int len = strlen(value);
        if (len > 0)
            value++;
        if (len > 1)
            value[len - 2] = '\0';
        strcpy(symbols[index].string_val, value);
    }

    if (strcmp(datatype, "bool") == 0)
    {
        if (strcmp(value, "true") == 0)
            symbols[index].bool_val = 1;
        else
            symbols[index].bool_val = 0;
    }
}

void addArrayValues(char *datatype, char array_values[200][1000], int index, int array_number_elements, struct symbol_table symbols[100])
{

    for (int i = 0; i < array_number_elements; i++)
    {

        if (strcmp(datatype, "int") == 0)
        {
            int ival = atoi(array_values[i]);
            symbols[index].int_array_values[i] = ival;
        }

        if (strcmp(datatype, "float") == 0)
        {
            int fval = atof(array_values[i]);
            symbols[index].float_array_values[i] = fval;
        }

        if (strcmp(datatype, "char") == 0)
        {
            symbols[index].char_array_values[i] = array_values[i][1];
        }

        if (strcmp(datatype, "string") == 0)
        {

            char aux[1000];
            char *s = strcpy(aux, array_values[i]);

            int len = strlen(s);
            if (len > 0)
                s++;
            if (len > 1)
                s[len - 2] = '\0';
            strcpy(symbols[index].string_array_values[i], s);
        }

        if (strcmp(datatype, "bool") == 0)
        {

            if (strcmp(array_values[i], "true") == 0)
                symbols[index].bool_array_values[i] = 1;
            else
                symbols[index].bool_array_values[i] = 0;
        }
    }
}

void setSymbolScope(int index, int type_index, char scope[100], char *block)
{
    if (strcmp(block, "functions") == 0)
    {

        char intstring[5] = "\0";
        sprintf(intstring, "%d", index);
        strcpy(scope, "FUNCTIONS ");
        strcat(scope, "function ");
        strcat(scope, intstring);
    }
    if (strcmp(block, "types") == 0)
    {

        strcpy(scope, "TYPES ");

        if (index == 0)
        {

            char intstring[5] = "\0";
            sprintf(intstring, "%d", type_index);
            strcat(scope, "type");
            strcat(scope, intstring);
            strcat(scope, " members");
        }
        else
        {

            char intstring[5] = "\0";
            sprintf(intstring, "%d", type_index);
            strcat(scope, "type");
            strcat(scope, intstring);
            strcat(scope, " methods");

            sprintf(intstring, "%d", index);
            strcat(scope, " method ");
            strcat(scope, intstring);
        }
    }
}

void setFunctionScope(int type_index, char scope[100], char *block)
{

    if (strcmp(block, "types") == 0)
    {

        char intstring[5] = "\0";
        sprintf(intstring, "%d", type_index);
        strcpy(scope, "TYPES ");
        strcat(scope, "type");
        strcat(scope, intstring);
    }
}

int existsVariable(char *scope, char *identifier, struct symbol_table symbols[100], int nr_elements)
{

    for (int i = 0; i < nr_elements; i++)
    {
        if ((strcmp(symbols[i].identifier, identifier) == 0) && (strcmp(symbols[i].scope, scope) == 0))
        {
            return 1;
        }
    }

    return 0;
}

int existsFunction(char *scope, char *identifier, struct functions_table functions[100], int nr_elements)
{

    for (int i = 0; i < nr_elements; i++)
    {
        if ((strcmp(functions[i].identifier, identifier) == 0) && (strcmp(functions[i].scope, scope) == 0))
        {
            return 1;
        }
    }
    return 0;
}

int existsType(char *identifier, struct types_table types[100], int nr_elements)
{

    for (int i = 0; i < nr_elements; i++)
    {
        if (strcmp(types[i].identifier, identifier) == 0)
            return 1;
    }

    return 0;
}

int addSymbol(int table_index, char *scope, struct symbol_table symbols[100],
              int is_type, int is_array, int is_const, char *data_type, char *identifier,
              char *value, char array_values[200][1000], int array_allocated_memory, int array_number_elements)
{

    // printf("identifier : %s\nscope : %s\ndata_type : %s\nvalue : %s\narray_values : %s , %s\n\n\n",identifier,scope,data_type,value,array_values[0],array_values[1]);
    if (existsVariable(scope, identifier, symbols, table_index) == 0)
    {
        struct symbol_table s;

        strcpy(s.data_type, data_type);
        strcpy(s.identifier, identifier);
        strcpy(s.scope, scope);

        if (is_type == 1)
        {
            s.is_array = 0;
            s.is_type = 1;
            s.is_const = 0;
            s.are_valoare = 0;
            symbols[table_index] = s;
        }
        else if (is_const == 1)
        {
            s.is_array = 0;
            s.is_type = 0;
            s.is_const = 1;
            s.are_valoare = 1;
            symbols[table_index] = s;

            if (is_correct_value(data_type, value) == 1)
            {
                addValue(data_type, value, table_index, symbols);
            }
            else
            {
                return -1; // variable has diffrent datatype value in definition
            }
        }
        else if (is_array == 1)
        {
            s.is_array = 1;
            s.is_type = 0;
            s.is_const = 0;

            if (strcmp(array_values[0], "N/A") == 0)
            {
                s.are_valoare = 0;
                s.array_number_elements = 0;
                s.array_allocated_memory = array_allocated_memory;

                symbols[table_index] = s;
            }
            else
            {

                s.are_valoare = 1;
                s.array_number_elements = array_number_elements;
                s.array_allocated_memory = array_allocated_memory;
                symbols[table_index] = s;

                if (are_correct_array_values(data_type, array_values, array_number_elements) == 1)
                    addArrayValues(data_type, array_values, table_index, array_number_elements, symbols);
                else
                    return -2; // valorile din array nu sunt de tipul array-ului
            }
        }
        else
        {
            s.is_array = 0;
            s.is_type = 0;
            s.is_const = 0;

            if (strcmp(value, "N/A") == 0)
            {
                s.are_valoare = 0;
                symbols[table_index] = s;
            }
            else
            {
                s.are_valoare = 1;
                symbols[table_index] = s;
                if (is_correct_value(data_type, value) == 1)
                    addValue(data_type, value, table_index, symbols);
                else
                    return -1; // variable has diffrent datatype value in definition
            }
        }
    }
    else
    {
        return -3; // eroare variabila sau membrul de tip definit este deja definita in acel scope
    }

    return 0;
}

int addParams(char params_text[50][1000], struct functions_table functions[100], int index, int params_number)
{

    for (int i = 0; i < params_number; i++)
    {
        struct param p;

        char aux[1000];
        strcpy(aux, params_text[i]);

        if (strstr(aux, "const") != NULL)
        { // aici avem constante  || const int a;

            p.is_const = 1;
            p.is_array = 0;
            p.is_type = 0;
            p.array_allocated_memory = 0;

            char *pointer = strtok(aux, " ");

            pointer = strtok(NULL, " ");
            strcpy(p.data_type, pointer);

            pointer = strtok(NULL, " ");
            strcpy(p.identifier, pointer);
        }
        else if ((strchr(aux, '[') == NULL) && (strchr(aux, ']') == NULL))
        { // aici avem variabile normale ||| int a || Student student

            char *pointer = strtok(aux, " ");
            strcpy(p.data_type, pointer);

            if ((strcmp(pointer, "int") == 0) || (strcmp(pointer, "bool") == 0) || (strcmp(pointer, "char") == 0) || (strcmp(pointer, "string") == 0) || (strcmp(pointer, "float") == 0))
            {
                p.is_const = 0;
                p.is_array = 0;
                p.is_type = 0;
                p.array_allocated_memory = 0;
            }
            else
            {
                p.is_const = 0;
                p.is_array = 0;
                p.is_type = 1;
                p.array_allocated_memory = 0;
            }

            pointer = strtok(NULL, " ");
            strcpy(p.identifier, pointer);
        }
        else if ((strchr(aux, '[') != NULL) && (strchr(aux, ']') != NULL))
        { // aici avem array    || int a[] , int a[100]

            p.is_const = 0;
            p.is_array = 1;
            p.is_type = 0;

            char *pointer = strtok(aux, " []");
            strcpy(p.data_type, pointer);

            pointer = strtok(NULL, " []");
            strcpy(p.identifier, pointer);

            pointer = strtok(NULL, " []");
            if (pointer == NULL)
            {
                p.array_allocated_memory = 0;
            }
            else
            {
                int ival = atoi(pointer);
                p.array_allocated_memory = ival;
            }
        }

        // const int param4 || int param1 || int a[] || int b[100]

        functions[index].params[i] = p;
    }

    for (int n = 0; n < params_number - 1; n++)
    {
        for (int m = n + 1; m < params_number; m++)
        {
            if (strcmp(functions[index].params[n].identifier, functions[index].params[m].identifier) == 0)
                return 0;
        }
    }

    return 1;
}

int addFunction(int table_index, char *scope, char *data_type, char *identifier, struct functions_table functions[100], char params[50][1000], int params_number)
{

    if (existsFunction(scope, identifier, functions, table_index) == 0)
    {
        struct functions_table f;
        strcpy(f.data_type, data_type);
        strcpy(f.identifier, identifier);
        strcpy(f.scope, scope);

        if (strcmp(params[0], "N/A") == 0)
        {
            f.are_params = 0;
            f.params_number_elements = 0;
            functions[table_index] = f;
        }
        else
        {
            f.are_params = 1;
            f.params_number_elements = params_number;

            for (int i = 0; i < params_number; i++)
            {
                strcpy(f.params_text[i], params[i]);
            }

            functions[table_index] = f;

            if (addParams(params, functions, table_index, params_number) == 0)
                return -4; // functia contine mai multi parametrii cu acelasi nume
        }
    }
    else
    {
        return -5; // eroare frunctia sau metoda este deja definita in acel scope
    }

    return 0;
}

int addType(int table_index, char *identifier, struct types_table types[100])
{

    if (existsType(identifier, types, table_index) == 0)
    {
        strcpy(types[table_index].identifier, identifier);
    }
    else
    {
        return -6; // eroare tipul custom este deja definit
    }
}

int symbol_table_file(struct symbol_table symbols[100], int table_index)
{
    FILE *file;
    file = fopen("symbol_table.txt", "w");

    if (file == NULL)
    {
        return -7;
    }

    for (int i = 0; i < table_index; i++)
    {

        if (symbols[i].is_type == 1)
        {
            fprintf(file, "[%d] TIP : %s | ID : %s | SCOPE : %s\n\n", i, symbols[i].data_type, symbols[i].identifier, symbols[i].scope);
        }
        else
        {

            if (strcmp(symbols[i].data_type, "int") == 0)
            {
                if (symbols[i].is_array == 1)
                {
                    if (symbols[i].are_valoare == 0)
                    {

                        fprintf(file, "[%d] TIP : array %s | ID : %s | VALUE : {N/A} | SCOPE : %s\n\n", i, symbols[i].data_type, symbols[i].identifier, symbols[i].scope);
                    }
                    else
                    {

                        fprintf(file, "[%d] TIP : array %s | ID : %s | VALUE : {", i, symbols[i].data_type, symbols[i].identifier);

                        for (int j = 0; j < symbols[i].array_number_elements; j++)
                            fprintf(file, "%d,", symbols[i].int_array_values[j]);
                        fprintf(file, "} | SCOPE %s\n\n", symbols[i].scope);
                    }
                }
                else if (symbols[i].is_const == 1)
                {
                    fprintf(file, "[%d] TIP : const %s | ID : %s | VALUE : %d | SCOPE : %s\n\n", i, symbols[i].data_type, symbols[i].identifier, symbols[i].int_val, symbols[i].scope);
                }
                else
                {
                    if (symbols[i].are_valoare == 0)
                    {

                        fprintf(file, "[%d] TIP : %s | ID : %s | VALUE : {N/A} | SCOPE : %s\n\n", i, symbols[i].data_type, symbols[i].identifier, symbols[i].scope);
                    }
                    else
                    {
                        fprintf(file, "[%d] TIP : %s | ID : %s | VALUE : %d | SCOPE : %s\n\n", i, symbols[i].data_type, symbols[i].identifier, symbols[i].int_val, symbols[i].scope);
                    }
                }
            }

            else if (strcmp(symbols[i].data_type, "bool") == 0)
            {

                if (symbols[i].is_array == 1)
                {
                    if (symbols[i].are_valoare == 0)
                    {

                        fprintf(file, "[%d] TIP : array %s | ID : %s | VALUE : {N/A} | SCOPE : %s\n\n", i, symbols[i].data_type, symbols[i].identifier, symbols[i].scope);
                    }
                    else
                    {

                        fprintf(file, "[%d] TIP : array %s | ID : %s | VALUE : {", i, symbols[i].data_type, symbols[i].identifier);

                        for (int j = 0; j < symbols[i].array_number_elements; j++)
                            fprintf(file, "%d,", symbols[i].bool_array_values[j]);
                        fprintf(file, "} | SCOPE %s\n\n", symbols[i].scope);
                    }
                }
                else if (symbols[i].is_const == 1)
                {
                    fprintf(file, "[%d] TIP : const %s | ID : %s | VALUE : %d | SCOPE : %s\n\n", i, symbols[i].data_type, symbols[i].identifier, symbols[i].bool_val, symbols[i].scope);
                }
                else
                {
                    if (symbols[i].are_valoare == 0)
                    {

                        fprintf(file, "[%d] TIP : %s | ID : %s | VALUE : {N/A} | SCOPE : %s\n\n", i, symbols[i].data_type, symbols[i].identifier, symbols[i].scope);
                    }
                    else
                    {
                        fprintf(file, "[%d] TIP : %s | ID : %s | VALUE : %d | SCOPE : %s\n\n", i, symbols[i].data_type, symbols[i].identifier, symbols[i].bool_val, symbols[i].scope);
                    }
                }
            }
            else if (strcmp(symbols[i].data_type, "float") == 0)
            {
                if (symbols[i].is_array == 1)
                {
                    if (symbols[i].are_valoare == 0)
                    {

                        fprintf(file, "[%d] TIP : array %s | ID : %s | VALUE : {N/A} | SCOPE : %s\n\n", i, symbols[i].data_type, symbols[i].identifier, symbols[i].scope);
                    }
                    else
                    {

                        fprintf(file, "[%d] TIP : array %s | ID : %s | VALUE : {", i, symbols[i].data_type, symbols[i].identifier);

                        for (int j = 0; j < symbols[i].array_number_elements; j++)
                            fprintf(file, "%.2f,", symbols[i].float_array_values[j]);
                        fprintf(file, "} | SCOPE %s\n\n", symbols[i].scope);
                    }
                }
                else if (symbols[i].is_const == 1)
                {
                    fprintf(file, "[%d] TIP : const %s | ID : %s | VALUE : %.2f | SCOPE : %s\n\n", i, symbols[i].data_type, symbols[i].identifier, symbols[i].float_val, symbols[i].scope);
                }
                else
                {
                    if (symbols[i].are_valoare == 0)
                    {

                        fprintf(file, "[%d] TIP : %s | ID : %s | VALUE : {N/A} | SCOPE : %s\n\n", i, symbols[i].data_type, symbols[i].identifier, symbols[i].scope);
                    }
                    else
                    {
                        fprintf(file, "[%d] TIP : %s | ID : %s | VALUE : %.2f | SCOPE : %s\n\n", i, symbols[i].data_type, symbols[i].identifier, symbols[i].float_val, symbols[i].scope);
                    }
                }
            }
            else if (strcmp(symbols[i].data_type, "char") == 0)
            {
                if (symbols[i].is_array == 1)
                {
                    if (symbols[i].are_valoare == 0)
                    {

                        fprintf(file, "[%d] TIP : array %s | ID : %s | VALUE : {N/A} | SCOPE : %s\n\n", i, symbols[i].data_type, symbols[i].identifier, symbols[i].scope);
                    }
                    else
                    {

                        fprintf(file, "[%d] TIP : array %s | ID : %s | VALUE : {", i, symbols[i].data_type, symbols[i].identifier);

                        for (int j = 0; j < symbols[i].array_number_elements; j++)
                            fprintf(file, "\'%c\',", symbols[i].char_array_values[j]);
                        fprintf(file, "} | SCOPE %s\n\n", symbols[i].scope);
                    }
                }
                else if (symbols[i].is_const == 1)
                {
                    fprintf(file, "[%d] TIP : const %s | ID : %s | VALUE : \'%c\' | SCOPE : %s\n\n", i, symbols[i].data_type, symbols[i].identifier, symbols[i].char_val, symbols[i].scope);
                }
                else
                {
                    if (symbols[i].are_valoare == 0)
                    {

                        fprintf(file, "[%d] TIP : %s | ID : %s | VALUE : {N/A} | SCOPE : %s\n\n", i, symbols[i].data_type, symbols[i].identifier, symbols[i].scope);
                    }
                    else
                    {
                        fprintf(file, "[%d] TIP : %s | ID : %s | VALUE : \'%c\' | SCOPE : %s\n\n", i, symbols[i].data_type, symbols[i].identifier, symbols[i].char_val, symbols[i].scope);
                    }
                }
            }
            else if (strcmp(symbols[i].data_type, "string") == 0)
            {
                if (symbols[i].is_array == 1)
                {
                    if (symbols[i].are_valoare == 0)
                    {

                        fprintf(file, "[%d] TIP : array %s | ID : %s | VALUE : {N/A} | SCOPE : %s\n\n", i, symbols[i].data_type, symbols[i].identifier, symbols[i].scope);
                    }
                    else
                    {

                        fprintf(file, "[%d] TIP : array %s | ID : %s | VALUE : {", i, symbols[i].data_type, symbols[i].identifier);

                        for (int j = 0; j < symbols[i].array_number_elements; j++)
                            fprintf(file, "\"%s\",", symbols[i].string_array_values[j]);
                        fprintf(file, "} | SCOPE %s\n\n", symbols[i].scope);
                    }
                }
                else if (symbols[i].is_const == 1)
                {
                    fprintf(file, "[%d] TIP : const %s | ID : %s | VALUE : \"%s\" | SCOPE : %s\n\n", i, symbols[i].data_type, symbols[i].identifier, symbols[i].string_val, symbols[i].scope);
                }
                else
                {
                    if (symbols[i].are_valoare == 0)
                    {

                        fprintf(file, "[%d] TIP : %s | ID : %s | VALUE : {N/A} | SCOPE : %s\n\n", i, symbols[i].data_type, symbols[i].identifier, symbols[i].scope);
                    }
                    else
                    {
                        fprintf(file, "[%d] TIP : %s | ID : %s | VALUE : \"%s\" | SCOPE : %s\n\n", i, symbols[i].data_type, symbols[i].identifier, symbols[i].string_val, symbols[i].scope);
                    }
                }
            }
        }
    }

    return 0;
}

int functions_table_file(struct functions_table functions[100], int table_index)
{
    FILE *file;
    file = fopen("functions_table.txt", "w");

    if (file == NULL)
    {
        return -7;
    }

    for (int i = 0; i < table_index; i++)
    {
        fprintf(file, "[%d] RETURN TYPE : %s | ID : %s | SCOPE : %s | ", i, functions[i].data_type, functions[i].identifier, functions[i].scope);

        if (functions[i].are_params == 0)
        {

            fprintf(file, "PARAMS : {N/A}\n\n");
        }
        else
        {
            fprintf(file, "PARAMS : (");
            for (int j = 0; j < functions[i].params_number_elements; j++)
                fprintf(file, "%s ,", functions[i].params_text[j]);
            fprintf(file, ")\n\n");
        }
    }

    return 0;
    // TODO functia care creeaza functions_table.txt
}

int getDataType(struct symbol_table symbols[100], int table_index, char *identifier_eval)
{ // a, b[10]

    char scope[100];

    char aux[100];
    strcpy(aux, identifier_eval);

    char identifier[100];
    char *p = strtok(aux, "[");

    strcpy(identifier, p);

    if (existsVariable("MAIN", identifier, symbols, table_index) == 1)
    {
        strcpy(scope, "MAIN");
    }
    else if (existsVariable("GLOBAL", identifier, symbols, table_index) == 1)
    {
        strcpy(scope, "GLOBAL");
    }
    else
        return -11; // var nu a fost definita

    for (int i = 0; i < table_index; i++)
    {
        if ((strcmp(identifier, symbols[i].identifier) == 0) && (strcmp(scope, symbols[i].scope) == 0))
        {
            if (strcmp(symbols[i].data_type, "int") == 0)
                return 1; // tipul e int
            else if (strcmp(symbols[i].data_type, "float") == 0)
                return 2; // tipul e float
            else
                return -10; // datatype nu e int sau float
        }
    }
}

int getIntValue(struct symbol_table symbols[100], int table_index, char *identifier_eval)
{
    char scope[100];
    char aux[100];
    strcpy(aux, identifier_eval);

    char identifier[100];
    int int_arr_index;

    if (strchr(identifier_eval, '[') != 0)
    {
        char *p = strtok(aux, "[]");
        bzero(identifier, sizeof(identifier));
        strcpy(identifier, p);

        for (int i = 0; i < strlen(identifier_eval); i++)
        {
            if (isdigit(identifier_eval[i]))
            {
                int_arr_index = identifier_eval[i] - '0';
            }
        }

        strtok(NULL, "[]");
        // printf("INDEX: %s\n", p);

        // printf("%i\n",int_arr_index);

        if (existsVariable("MAIN", identifier, symbols, table_index) == 1)
        {
            strcpy(scope, "MAIN");
        }
        else if (existsVariable("GLOBAL", identifier, symbols, table_index) == 1)
        {
            strcpy(scope, "GLOBAL");
        }

        for (int i = 0; i < table_index; i++)
        {
            if ((strcmp(identifier, symbols[i].identifier) == 0) && (strcmp(scope, symbols[i].scope) == 0))
            {
                if (symbols[i].are_valoare == 1)
                {
                    // printf("VAL: %i\n",symbols[i].int_array_values[int_arr_index]);
                    return symbols[i].int_array_values[int_arr_index];
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    else
    {
        strcpy(identifier, identifier_eval);

        if (existsVariable("MAIN", identifier, symbols, table_index) == 1)
        {
            strcpy(scope, "MAIN");
        }
        else if (existsVariable("GLOBAL", identifier, symbols, table_index) == 1)
        {
            strcpy(scope, "GLOBAL");
        }

        for (int i = 0; i < table_index; i++)
        {
            if ((strcmp(identifier, symbols[i].identifier) == 0) && (strcmp(scope, symbols[i].scope) == 0))
            {
                if (symbols[i].are_valoare == 1)
                    return symbols[i].int_val;
                else
                    return 0;
            }
        }
    }
}

float getFloatValue(struct symbol_table symbols[100], int table_index, char *identifier_eval)
{
    char scope[100];
    char aux[100];
    strcpy(aux, identifier_eval);

    char identifier[100];
    if (strchr(identifier, '[') != NULL)
    {
        char *p = strtok(aux, "[]");
        strcpy(identifier, p);

        strtok(NULL, "[]");

        int int_arr_index = atoi(p);

        if (existsVariable("MAIN", identifier, symbols, table_index) == 1)
        {
            strcpy(scope, "MAIN");
        }
        else if (existsVariable("GLOBAL", identifier, symbols, table_index) == 1)
        {
            strcpy(scope, "GLOBAL");
        }

        for (int i = 0; i < table_index; i++)
        {
            if ((strcmp(identifier, symbols[i].identifier) == 0) && (strcmp(scope, symbols[i].scope) == 0))
            {
                if (symbols[i].are_valoare == 1)
                {
                    return symbols[i].float_array_values[int_arr_index];
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    else
    {
        strcpy(identifier, identifier_eval);

        if (existsVariable("MAIN", identifier, symbols, table_index) == 1)
        {
            strcpy(scope, "MAIN");
        }
        else if (existsVariable("GLOBAL", identifier, symbols, table_index) == 1)
        {
            strcpy(scope, "GLOBAL");
        }
        for (int i = 0; i < table_index; i++)
        {
            if ((strcmp(identifier, symbols[i].identifier) == 0) && (strcmp(scope, symbols[i].scope) == 0))
            {
                if (symbols[i].are_valoare == 1)
                    return symbols[i].float_val;
                else
                    return 0;
            }
        }
    }
}

int CheckEvalSameDataType(struct symbol_table symbols[100], int table_index, char identifiers[100][100], int number_operands)
{

    char tip_referinta[100] = "N/A";
    char operand_curent[100];

    for (int i = 0; i < number_operands; i++)
    {
        strcpy(operand_curent, identifiers[i]);
        int aux = getDataType(symbols, table_index, operand_curent);

        if (aux == 1)
        {
            if (strcmp(tip_referinta, "N/A") == 0)
            {
                strcpy(tip_referinta, "int");
            }

            else if (strcmp(tip_referinta, "int") != 0)
            {
                return 0;
            }
        }
        else if (aux == 2)
        {

            if (strcmp(tip_referinta, "N/A") == 0)
            {
                strcpy(tip_referinta, "float");
            }

            else if (strcmp(tip_referinta, "float") != 0)
            {
                return 0;
            }
        }
        else
            return aux;
    }

    return 1;
}

struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));

    if (!stack)
        return NULL;

    stack->top = -1;
    stack->capacity = capacity;

    stack->array = (int *)malloc(stack->capacity * sizeof(int));

    return stack;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

char peek(struct Stack *stack)
{
    return stack->array[stack->top];
}

char pop(struct Stack *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

struct Node *popNode(struct Stack *stack)
{
    if (stack->top == -1)
    {
        return NULL;
    }

    return stack->arrayStack[stack->top--];
}

void push(struct Stack *stack, char op)
{
    stack->array[++stack->top] = op;
}

void pushStS(struct Stack *stack, struct Node *node)
{
    stack->arrayStack[++stack->top] = node;
}

int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z') ||
           (ch >= '0' && ch <= '9') ||
           (ch >= '[' && ch <= ']');
}

int isNumber(char ch)
{
    return (ch >= '0' && ch <= '9');
}

int isSign(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int toDigit(char ch)
{
    return ch - '0';
}

int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;
    }
    return -1;
}

char *infixToPostfix(char *exp)
{
    int i, k;

    struct Stack *stack = createStack(strlen(exp));
    if (!stack)
        return "Error";

    for (i = 0, k = -1; exp[i]; ++i)
    {

        if (isOperand(exp[i]))
            exp[++k] = exp[i];
        else if (exp[i] == '(')
            push(stack, exp[i]);

        else if (exp[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return "Error";
            else
                pop(stack);
        }

        else
        {
            while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }
    }

    while (!isEmpty(stack))
    {
        exp[++k] = pop(stack);
    }

    exp[++k] = '\0';

    return exp;
}

struct Node *newNode(char data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->info = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

struct Node *buildTree(char postfix[])
{
    struct Stack *stack = createStack(strlen(postfix));

    struct Node *t, *t1, *t2;

    for (int i = 0; i < strlen(postfix); i++)
    {
        if (isOperand(postfix[i]))
        {
            t = newNode(postfix[i]);
            pushStS(stack, t);
        }
        else if (isSign(postfix[i]))
        {
            t = newNode(postfix[i]);
            t1 = popNode(stack);
            t2 = popNode(stack);

            t->right = t1;
            t->left = t2;
            pushStS(stack, t);
        }
        else
        {
            printf("Invalid character: %c\n", postfix[i]);
        }
    }

    t = popNode(stack);

    return t;
}

int evaluate(struct Node *root)
{
    if (root == NULL)
        return 0;
    if (!isSign(root->info))
        return toDigit(root->info);

    int left = evaluate(root->left);
    int right = evaluate(root->right);

    // printf("LEFT: %i\n", left);
    // printf("RIGHT: %i\n", right);

    switch (root->info)
    {
    case '+':
        return left + right;
    case '-':
        return left - right;
    case '*':
        return left * right;
    case '/':
        if (right == 0)
        {
            printf("Divide by zero error.");
            exit(0);
        }
        return left / right;
    }

    return -1;
}

void removeQuotes(char *str)
{
    int i, j;
    int len = strlen(str);
    for (i = 0; i < len; i++)
    {
        if (str[i] == '"')
        {
            for (j = i; j < len; j++)
            {
                str[j] = str[j + 1];
            }
            len--;
            i--;
        }
    }
}

void removeBracket(char *str)
{
    int i, j;
    int len = strlen(str);
    for (i = 0; i < len; i++)
    {
        if (str[i] == '[' || str[i] == ']')
        {
            for (j = i; j < len; j++)
            {
                str[j] = str[j + 1];
            }
            len--;
            i--;
        }
    }
}

void replace_function_calls(char *input)
{
    regex_t function_regex;
    regmatch_t match[1];
    regcomp(&function_regex, "[_a-zA-Z][_a-zA-Z0-9_]*+\\(", REG_EXTENDED);

    char *output = (char *)malloc(strlen(input) + 1);
    int output_index = 0;
    char *start = input;
    while (*start != '\0')
    {
        if (regexec(&function_regex, start, 1, match, 0) == 0)
        {
            int match_start = match[0].rm_so + (start - input);
            int match_end = match[0].rm_eo + (start - input);
            int copy_length = match_start - (start - input);
            memcpy(output + output_index, start, copy_length);
            output_index += copy_length;
            output[output_index++] = '0';
            int i = match_end;
            int open_parenthesis = 1;
            while (open_parenthesis != 0 && input[i] != '\0')
            {
                if (input[i] == '(')
                    open_parenthesis++;
                if (input[i] == ')')
                    open_parenthesis--;
                i++;
            }
            start = input + i;
        }
        else
        {
            output[output_index++] = *start;
            start++;
        }
    }
    output[output_index] = '\0';
    regfree(&function_regex);
    strcpy(input, output);
    free(output);
}

char *getDataTypeFromValue(char *value)
{
    char *datatype = (char *)malloc(100 * sizeof(char));

    if (is_correct_value("int", value) == 1)
    {
        strcpy(datatype, "int");
        return datatype;
    }
    if (is_correct_value("float", value) == 1)
    {
        strcpy(datatype, "float");
        return datatype;
    }
    if (is_correct_value("string", value) == 1)
    {
        strcpy(datatype, "string");
        return datatype;
    }
    if (is_correct_value("char", value) == 1)
    {
        strcpy(datatype, "char");
        return datatype;
    }
    if (is_correct_value("bool", value) == 1)
    {
        strcpy(datatype, "bool");
        return datatype;
    }
}

int assign(char *left, char *right, int left_forma, int right_forma, struct symbol_table symbols[100], int table_index)
{

    if (left_forma == 1 && right_forma == 1)
    {
        // a = 10;
        char left_scope[100];
        if (existsVariable("MAIN", left, symbols, table_index) == 1)
        {
            strcpy(left_scope, "MAIN");
        }
        else if (existsVariable("GLOBAL", left, symbols, table_index) == 1)
        {
            strcpy(left_scope, "GLOBAL");
        }
        else
        {
            return -15; // nu exista variabila a definita
        }

        for (int i = 0; i < table_index; i++)
        {
            if (strcmp(left, symbols[i].identifier) == 0 && strcmp(left_scope, symbols[i].scope))
            {
                if (strcmp(symbols[i].data_type, getDataTypeFromValue(right)) == 0)
                {
                    if (symbols[i].is_const == 1)
                        return -20;

                    symbols[i].are_valoare = 1;
                    addValue(symbols[i].data_type, right, i, symbols);
                    printf("%s : %d\n", symbols[i].identifier, symbols[i].int_val);
                    return 0;
                }
                else
                {
                    return -16; // au tipuri de date diferite
                }
            }
        }
    }
    else if (left_forma == 2 && right_forma == 1)
    {
        // a[10] = 10;
        char left_scope[100];

        char aux[100];
        strcpy(aux, left);

        if (strstr(aux, "[") != 0)
        {
            char auxLeft[100];
            char stringIndex[50];
            char *p = strtok(aux, "[]");
            strcpy(auxLeft, p);
            p = strtok(NULL, "[]");
            strcpy(stringIndex, p);

            int arrIndex = atoi(stringIndex);

            if (existsVariable("MAIN", auxLeft, symbols, table_index) == 1)
            {
                strcpy(left_scope, "MAIN");
            }
            else if (existsVariable("GLOBAL", auxLeft, symbols, table_index) == 1)
            {
                strcpy(left_scope, "GLOBAL");
            }
            else
            {
                return -15; // nu exista variabila a definita
            }

            for (int i = 0; i < table_index; i++)
            {
                if (strcmp(auxLeft, symbols[i].identifier) == 0 && strcmp(left_scope, symbols[i].scope))
                {
                    if (strcmp(symbols[i].data_type, getDataTypeFromValue(right)) == 0)
                    {

                        symbols[i].are_valoare = 1;
                        symbols[i].int_array_values[arrIndex] = atoi(right);
                        symbols[i].float_array_values[arrIndex] = atof(right);
                        if (strcmp(right, "true") == 0)
                        {
                            symbols[i].bool_array_values[arrIndex] = 1;
                        }
                        else
                        {
                            symbols[i].bool_array_values[arrIndex] = 0;
                        }
                        symbols[i].char_array_values[arrIndex] = right[1];

                        int len = strlen(right);
                        if (len > 0)
                            right++;
                        if (len > 1)
                            right[len - 2] = '\0';

                        strcpy(symbols[i].string_array_values[arrIndex],right);

                        printf("%s : %d\n", symbols[i].identifier, symbols[i].int_array_values[arrIndex]);
                        return 0;
                    }
                    else
                    {
                        return -16; // au tipuri de date diferite
                    }
                }
            }
        }
    }
    else if (left_forma == 1 && right_forma == 2)
    {

        // a = b
        char left_scope[100];
        char right_scope[100];

        if (existsVariable("MAIN", left, symbols, table_index) == 1)
        {
            strcpy(left_scope, "MAIN");
        }
        else if (existsVariable("GLOBAL", left, symbols, table_index) == 1)
        {
            strcpy(left_scope, "GLOBAL");
        }
        else
        {
            return -15; // nu exista variabila a definita
        }

        if (existsVariable("MAIN", right, symbols, table_index) == 1)
        {
            strcpy(left_scope, "MAIN");
        }
        else if (existsVariable("GLOBAL", right, symbols, table_index) == 1)
        {
            strcpy(left_scope, "GLOBAL");
        }
        else
        {
            return -15; // nu exista variabila a definita
        }

        int index1, index2;

        for (int i = 0; i < table_index; i++)
        {
            if (strcmp(left, symbols[i].identifier) == 0)
            {
                index1 = i;
            }
        }
        for (int i = 0; i < table_index; i++)
        {
            if (strcmp(right, symbols[i].identifier) == 0)
            {
                index2 = i;
            }
        }

        if (strcmp(symbols[index1].data_type, symbols[index2].data_type) == 0)
        {

            if (symbols[index1].is_const == 1)
            {
                return -20;
            } // atribuire catre const
            else
            {

                symbols[index1].are_valoare = 1;
                symbols[index1].int_val = symbols[index2].int_val;
                symbols[index1].float_val = symbols[index2].float_val;
                symbols[index1].bool_val = symbols[index2].bool_val;
                symbols[index1].char_val = symbols[index2].char_val;
                strcpy(symbols[index1].string_val, symbols[index2].string_val);

                printf("%s : %d\n", symbols[index1].identifier, symbols[index1].int_val);
            }
        }
        else
            return -16; // au tipuri de date diferite
    }
    else if (left_forma == 2 && right_forma == 2)
    {
        // a[10] = b

        char left_scope[100];
        char right_scope[100];

        char aux[100];
        strcpy(aux, left);

        char auxLeft[100];
        char stringIndex[50];

        char *p = strtok(aux, "[]");
        strcpy(auxLeft, p);
        p = strtok(NULL, "[]");
        strcpy(stringIndex, p);

        int arrayIndex = atoi(stringIndex);

        if (existsVariable("MAIN", auxLeft, symbols, table_index) == 1)
        {
            strcpy(left_scope, "MAIN");
        }
        else if (existsVariable("GLOBAL", auxLeft, symbols, table_index) == 1)
        {
            strcpy(left_scope, "GLOBAL");
        }
        else
        {
            return -15; // nu exista variabila a definita
        }

        if (existsVariable("MAIN", right, symbols, table_index) == 1)
        {
            strcpy(right_scope, "MAIN");
        }
        else if (existsVariable("GLOBAL", right, symbols, table_index) == 1)
        {
            strcpy(right_scope, "GLOBAL");
        }
        else
        {
            return -15; // nu exista variabila a definita
        }

        int index1, index2;

        for (int i = 0; i < table_index; i++)
        {
            if (strcmp(auxLeft, symbols[i].identifier) == 0 && strcmp(left_scope, symbols[i].scope) == 0)
            {
                index1 = i;
            }
        }
        for (int i = 0; i < table_index; i++)
        {
            if (strcmp(right, symbols[i].identifier) == 0 && strcmp(right_scope, symbols[i].scope) == 0)
            {
                index2 = i;
            }
        }
        if (strcmp(symbols[index1].data_type, symbols[index2].data_type) == 0)
        {

            if (symbols[index1].is_const == 1)
            {
                return -20;
            } // atribuire catre const
            else
            {

                symbols[index1].are_valoare = 1;

                symbols[index1].int_array_values[arrayIndex] = symbols[index2].int_val;
                symbols[index1].float_array_values[arrayIndex] = symbols[index2].float_val;
                symbols[index1].bool_array_values[arrayIndex] = symbols[index2].bool_val;
                symbols[index1].char_array_values[arrayIndex] = symbols[index2].char_val;
                strcpy(symbols[index1].string_array_values[arrayIndex], symbols[index2].string_val);

                printf("%s : %d\n", symbols[index1].identifier, symbols[index1].int_array_values[arrayIndex]);
            }
        }
        else
            return -16; // au tipuri de date diferite
    }
    else if (left_forma == 1 && right_forma == 3)
    {
        // a = b[10]
        char left_scope[100];
        char right_scope[100];

        char aux[100];
        strcpy(aux, right);

        char auxRight[100];
        char stringIndex[50];

        char *p = strtok(aux, "[]");
        strcpy(auxRight, p);
        p = strtok(NULL, "[]");
        strcpy(stringIndex, p);

        int arrayIndex = atoi(stringIndex);

        if (existsVariable("MAIN", left, symbols, table_index) == 1)
        {
            strcpy(left_scope, "MAIN");
        }
        else if (existsVariable("GLOBAL", left, symbols, table_index) == 1)
        {
            strcpy(left_scope, "GLOBAL");
        }
        else
        {
            return -15; // nu exista variabila a definita
        }

        if (existsVariable("MAIN", auxRight, symbols, table_index) == 1)
        {
            strcpy(right_scope, "MAIN");
        }
        else if (existsVariable("GLOBAL", auxRight, symbols, table_index) == 1)
        {
            strcpy(right_scope, "GLOBAL");
        }
        else
        {
            return -15; // nu exista variabila a definita
        }

        int index1, index2;

        for (int i = 0; i < table_index; i++)
        {
            if (strcmp(left, symbols[i].identifier) == 0 && strcmp(symbols[i].scope, left_scope) == 0)
            {
                index1 = i;
            }
        }
        for (int i = 0; i < table_index; i++)
        {
            if (strcmp(auxRight, symbols[i].identifier) == 0 && strcmp(symbols[i].scope, right_scope) == 0)
            {
                index2 = i;
            }
        }

        if (strcmp(symbols[index1].data_type, symbols[index2].data_type) == 0)
        {

            if (symbols[index1].is_const == 1)
            {
                return -20;
            } // atribuire catre const
            else
            {

                symbols[index1].are_valoare = 1;

                symbols[index1].int_val = symbols[index2].int_array_values[arrayIndex];
                symbols[index1].float_val = symbols[index2].float_array_values[arrayIndex];
                symbols[index1].bool_val = symbols[index2].bool_array_values[arrayIndex];
                symbols[index1].char_val = symbols[index2].char_array_values[arrayIndex];
                strcpy(symbols[index1].string_val, symbols[index2].string_array_values[arrayIndex]);

                printf("%s : %d\n", symbols[index1].identifier, symbols[index1].int_val);
            }
        }
        else
            return -16; // au tipuri de date diferite
    }
    else if (left_forma == 2 && right_forma == 3)
    {
        // a[10] = b[10]

        char left_scope[100];
        char right_scope[100];

        char aux2[100];
        strcpy(aux2, right);

        char auxRight[100];
        char stringIndexRight[50];

        char *p = strtok(aux2, "[]");
        strcpy(auxRight, p);
        p = strtok(NULL, "[]");
        strcpy(stringIndexRight, p);

        int arrayIndexRight = atoi(stringIndexRight);

        // printf("RIGHT:%i\n", arrayIndexRight);
        char aux1[100];
        strcpy(aux1, left);

        char auxLeft[100];
        char stringIndexLeft[50];

        p = strtok(aux1, "[]");
        // printf("P:%s\n",p);
        strcpy(auxLeft, p);
        p = strtok(NULL, "[]");
        strcpy(stringIndexLeft, p);

        int arrayIndexLeft = atoi(stringIndexLeft);

        // printf("LEFT:%i\n", arrayIndexLeft);

        if (existsVariable("MAIN", auxLeft, symbols, table_index) == 1)
        {
            strcpy(left_scope, "MAIN");
        }
        else if (existsVariable("GLOBAL", auxLeft, symbols, table_index) == 1)
        {
            strcpy(left_scope, "GLOBAL");
        }
        else
        {
            return -15; // nu exista variabila a definita
        }

        if (existsVariable("MAIN", auxRight, symbols, table_index) == 1)
        {
            strcpy(right_scope, "MAIN");
        }
        else if (existsVariable("GLOBAL", auxRight, symbols, table_index) == 1)
        {
            strcpy(right_scope, "GLOBAL");
        }
        else
        {
            return -15; // nu exista variabila a definita
        }

        int index1, index2;

        for (int i = 0; i < table_index; i++)
        {
            if (strcmp(auxLeft, symbols[i].identifier) == 0 && strcmp(symbols[i].scope, left_scope) == 0)
            {
                index1 = i;
            }
        }
        for (int i = 0; i < table_index; i++)
        {
            if (strcmp(auxRight, symbols[i].identifier) == 0 && strcmp(symbols[i].scope, right_scope) == 0)
            {
                index2 = i;
            }
        }

        if (strcmp(symbols[index1].data_type, symbols[index2].data_type) == 0)
        {

            symbols[index1].are_valoare = 1;

            symbols[index1].int_array_values[arrayIndexLeft] = symbols[index2].int_array_values[arrayIndexRight];
            symbols[index1].float_array_values[arrayIndexLeft] = symbols[index2].float_array_values[arrayIndexRight];
            symbols[index1].bool_array_values[arrayIndexLeft] = symbols[index2].bool_array_values[arrayIndexRight];
            symbols[index1].char_array_values[arrayIndexLeft] = symbols[index2].char_array_values[arrayIndexRight];
            strcpy(symbols[index1].string_array_values[arrayIndexLeft], symbols[index2].string_array_values[arrayIndexRight]);

            printf("%s : %d\n", symbols[index1].identifier, symbols[index1].int_array_values[arrayIndexLeft]);
        }
        else
            return -16; // au tipuri de date diferite
    }

    return 0;
}

//final