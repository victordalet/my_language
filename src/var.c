#include <stdio.h>
#include <stdlib.h>

void add_int(char **name, int *values, int *count, char *line) {
    int i = 0;

    int count_new_name = 0;

    int mid = 0;

    int count_number_in_number = 0;
    int multiply = 1;
    int number = 0;

    while (line[i] != '\0' && line[i] != '=') {
        if (line[i] != ' ')
            count_new_name++;

        i++;
    }

    i = 0;

    /*--------------------------------------------------------------*/

    char *var_name = malloc(sizeof(char) * count_new_name + 1);

    count_new_name = 0;

    while (line[i] != '\0' && line[i] != '=') {
        if (line[i] != ' ') {
            var_name[count_new_name] = line[i];
            count_new_name++;
        }

        i++;
    }

    var_name[count_new_name] = '\0';

    name[*count] = var_name;

    /*--------------------------------------------------------------*/

    while (line[i] != '\0') {
        if (line[i] >= 48 && line[i] <= 57) {
            count_number_in_number++;
            multiply *= 10;
        }

        i++;
    }

    multiply /= 10;

    while (line[mid] != '\0') {
        if (line[mid] >= 48 && line[mid] <= 57) {
            number += (line[mid] - 48) * multiply;
            multiply /= 10;
        }

        mid++;
    }

    values[*count] = number;

    *count += 1;
};

void add_float(char **name, float *values, int *count, char *line) {
    int i = 0;

    int count_new_name = 0;
    int new_value = 0;

    int mid = 0;

    int count_number_in_number = 0;
    int multiply = 1;
    float number = 0;

    int decimal = 0;
    int multiply_decimal = 1;

    while (line[i] != '\0' && line[i] != '=') {
        if (line[i] != ' ')
            count_new_name++;

        i++;
    }

    i = 0;

    /*--------------------------------------------------------------*/

    char *var_name = malloc(sizeof(char) * count_new_name + 1);

    count_new_name = 0;

    while (line[i] != '\0' && line[i] != '=') {
        if (line[i] != ' ') {
            var_name[count_new_name] = line[i];
            count_new_name++;
        }

        i++;
    }

    var_name[count_new_name] = '\0';

    name[*count] = var_name;

    /*--------------------------------------------------------------*/

    while (line[i] != '\0' && line[i] != '.') {
        if (line[i] >= 48 && line[i] <= 57) {
            count_number_in_number++;
            multiply *= 10;
        }

        i++;
    }

    multiply /= 10;

    while (line[mid] != '\0' && line[mid] != '.') {
        if (line[mid] >= 48 && line[mid] <= 57) {
            number += (line[mid] - 48) * multiply;
            multiply /= 10;
        }

        mid++;
    }

    /*--------------------------------------------------------------*/
    count_number_in_number = 0;
    multiply = 1;
    i++;
    mid++;

    while (line[i] != '\0') {
        if (line[i] >= 48 && line[i] <= 57) {
            count_number_in_number++;
            multiply *= 10;
        }

        i++;
    }

    multiply /= 10;

    while (line[mid] != '\0' && line[mid] != '.') {
        if (line[mid] >= 48 && line[mid] <= 57) {
            decimal += (line[mid] - 48) * multiply;
            multiply /= 10;
        }

        mid++;
    }

    /*--------------------------------------------------------------*/

    for (i = 0; i < count_number_in_number; i++) {
        multiply_decimal *= 10;
    }

    values[*count] = (number + decimal) / multiply_decimal;

    *count += 1;
};

void add_string(char **name, char **values, int *count, char *line) {
    int i = 0;

    int count_new_name = 0;

    int mid = 0;

    int number_char = 0;

    int nb_quote = 0;

    while (line[i] != '\0' && line[i] != '=') {
        if (line[i] != ' ')
            count_new_name++;

        i++;
    }

    i = 0;

    /*--------------------------------------------------------------*/

    char *var_name = malloc(sizeof(char) * count_new_name + 1);

    count_new_name = 0;

    while (line[i] != '\0' && line[i] != '=') {
        if (line[i] != ' ') {
            var_name[count_new_name] = line[i];
            count_new_name++;
        }

        i++;
    }

    var_name[count_new_name] = '\0';

    name[*count] = var_name;

    mid = i;

    /*--------------------------------------------------------------*/

    while (line[i] != '\0') {
        if (line[i] == '"')
            if (!nb_quote)
                nb_quote++;
            else
                break;

        if (nb_quote) {
            number_char++;
        }
        i++;
    }

    nb_quote = 0;
    char *new_value = malloc(sizeof(char) * number_char + 1);

    for (i = 1; i < number_char; i++) {
        if (line[mid + i] == '"')
            if (!nb_quote)
                nb_quote++;
            else
                break;

        if (!nb_quote) {
            mid++;
            i -= 1;
        } else {
            new_value[i - 1] = line[mid + i + 1];
        }
    }

    new_value[number_char - 1] = '\0';

    values[*count] = new_value;

    *count += 1;
};


void add_int_array(char **name, int **values, int* nb_values,int *count, char *line) {

    int i = 0;

    int count_new_name = 0;

    int mid = 0;

    int count_number_in_number = 0;
    int multiply = 1;
    int number = 0;

    int count_number = 0;

    while (line[i] != '\0' && line[i] != '=') {
        if (line[i] != ' ')
            count_new_name++;

        i++;
    }

    i = 0;

    /*--------------------------------------------------------------*/

    char *var_name = malloc(sizeof(char) * count_new_name + 1);

    count_new_name = 0;

    while (line[i] != '\0' && line[i] != '=') {
        if (line[i] != ' ') {
            var_name[count_new_name] = line[i];
            count_new_name++;
        }

        i++;
    }

    var_name[count_new_name] = '\0';

    name[*count] = var_name;



    /*--------------------------------------------------------------*/
    mid = i;

    while (line[i] != '\0') {
        if (line[i] == ',')
            count_number++;

        i++;
    }


    count_number++;
    int *new_array = malloc(sizeof(int) * count_number);



    /*--------------------------------------------------------------*/


    for (int index = 0 ; index < count_number ; index++) {


        number = 0;
        multiply = 1;
        count_number_in_number = 1;

        while (line[i] != '\0') {
            if (line[i] == ',' || line[i] == ']')
                break;

            if (line[i] >= 48 && line[i] <= 57) {
                count_number_in_number++;
                multiply *= 10;
            }

            i++;
        }



        while (line[mid] != '\0') {


            if (line[mid] == ',' || line[mid] == ']')
                break;

            if (line[mid] >= 48 && line[mid] <= 57) {
                number += (line[mid] - 48) * multiply;
                multiply /= 10;
            }

            mid++;
        }

        i++;
        mid++;
        new_array[index] = number;



    }



    values[*count] = new_array;

    nb_values[*count] = count_number;

    *count += 1;
};
