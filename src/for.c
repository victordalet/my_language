#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_for_loop(char *line, char **var, int *start, int *end, int *step) {

    *var = NULL;
    *start = 0;
    *end = 0;
    *step = 1;  

    int parsed = sscanf(line, "for %ms in range(%d, %d)", var, start, end);

    if (parsed == 3 && *var != NULL) {
        printf("Parsed for loop: var = %s, start = %d, end = %d\n", *var, *start, *end);
    } else {
        printf("Error: Failed to parse the for loop.\n");
        *var = NULL;
        *start = *end = *step = 0;
    }
}


void handle_for_loop(char *line, char **numbers_name, int *number_value,
                     int *count_number, char **floats_name, float *float_value,
                     int *count_floats, char **strings_name, char **strings_value,
                     int *count_strings, char **int_array_name, int **int_array_value,
                     int *count_number_int_array, int *int_array_size_value,
                     int *image_number, char **image_url, int *image_x_position,
                     int *image_y_position, int *last_condition, int *touche_number,
                     char *touche_name, int *touche_image_index_postion,
                     int *touche_image_x_action, int *touche_image_y_action,
                     int *count_function, char **function_name, char **line_function,
                     int number_line, char *file_name) {

    char *var = NULL; 
    int start = 0, end = 0, step = 0;

    parse_for_loop(line, &var, &start, &end, &step);

    if (var == NULL) {
        printf("Error: No valid variable found in the for loop.\n");
        return;
    }


    printf("For loop: var = %s, start = %d, end = %d, step = %d\n", var, start, end, step);


    for (int i = start; i < end; i += step) {

        for (int j = 0; j < *count_number; j++) {
            if (strcmp(numbers_name[j], var) == 0) {
                number_value[j] = i;  
                break;
            }
        }

        printf("Loop iteration %d: %s = %d\n", i, var, i);
    }


    free(var);
}
