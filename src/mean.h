#ifndef MEAN_H
#define MEAN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void print_array(int *array, int size);
float calculate_mean(int *array, int size);
float process_mean_direct(char *line);
float process_mean_variable(char *line, char **int_array_name, int **int_array_value, int count_number_int_array, int *int_array_size_value);
float process_mean_method(char *line, char **int_array_name, int **int_array_value, int count_number_int_array, int *int_array_size_value);

#endif
