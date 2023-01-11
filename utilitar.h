#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
    // char scope[100];
    int is_const;
    int is_array;
    int is_type;

    int array_number_elements;
    int array_allocated_memory;
};

struct functions_table
{
    char data_type[100];
    char identifier[100];
    char scope[100];

    int param_index;
    struct param params[50];
};

struct types_table
{
    char identifier[100];
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
                return -4; // variable has diffrent datatype value in definition
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
                    return -5;
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
                    return -4; // variable has diffrent datatype value in definition
            }
        }
    }
    else
    {
        return -3; // eroare variabila sau membrul de tip definit este deja definita in acel scope
    }

    return 0;
}

int addFunction(int table_index, char *scope, char *data_type, char *identifier, struct functions_table functions[100], char params[50][1000], int params_number)
{

    if (existsFunction(scope, identifier, functions, table_index) == 0)
    {
    }
    else
    {
        return -2; // eroare frunctia sau metoda este deja definita in acel scope
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
        return -1; // eroare tipul custom este deja definit
    }
}

int symbol_table_file(struct symbol_table symbols[100], int table_index)
{
    FILE *file;
    file = fopen("symbol_table.txt", "w");

    if (file == NULL)
    {
        return -6;
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

                        for(int j = 0 ; j < symbols[i].array_number_elements ; j++)
                            fprintf(file,"%.2f,",symbols[i].float_array_values[j]);
                        fprintf(file,"} | SCOPE %s\n\n",symbols[i].scope);
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

    return 0;
    // TODO functia care creeaza functions_table.txt
}