#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void max_array_int(char **int_array_name, int **int_array_values,
              int int_array_count, int *int_array_size,
              char *line)
{
    char *var_name = strtok(line, ".");

    for (int i = 0; i < int_array_count; i++) {
        if (!strcmp(var_name, int_array_name[i])) {
            int max = int_array_values[i][0];
            for (int j = 1; j < int_array_size[i]; j++) {
                if(int_array_values[i][j] >= max) {
                    max = int_array_values[i][j];
                }
            }
            printf("%d\n", max);
            break;

        }

    }

}

int is_max_method (char *line) {
    int count = 0;
    int number_char_in_method = 0;
    int have_point = 0;
    int have_par = 0;

    while (line[count] != '\0') {

        if (line[count] == '.')
            have_point = 1;

        if (line[count] == '(')
            have_par = 1;

        if (have_point && !have_par)
            number_char_in_method++;

        count++;

    }

    /*---------------------------------------------*/

    char *name_of_method = malloc(sizeof(char) * number_char_in_method + 1);

    count = 0;
    number_char_in_method = 0;
    have_point = 0;
    have_par = 0;

    while (line[count] != '\0') {

        if (line[count] == '.')
            have_point = 1;

        else if (line[count] == '(')
            have_par = 1;

        else if (have_point && !have_par) {
            name_of_method[number_char_in_method] = line[count];
            number_char_in_method++;
        }

        count++;

    }

    name_of_method[number_char_in_method] = '\0';

    /*---------------------------------------------*/
    if (!strcmp(name_of_method, "max")) {
        return 1;
    }

    return 0;
}