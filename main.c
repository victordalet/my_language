#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/parser.h"
#include "src/finder.h"
#include "src/spliter.h"
#include "src/var.h"
#include "src/append.h"
#include "src/pop.h"
#include "src/condition.h"
#include "src/pipeline.h"

int main(int argc, char *argv[])
{

	int number_line = 1;
	int last_condition = 0;

	if (argc >= 2)
		number_line = get_number_line_in_file(argv[1]);

	int count_number = 0;
	int count_strings = 0;
	int count_floats = 0;
	int count_number_int_array = 0;

	char **numbers_name = malloc(count_number * sizeof(char *));
	int *number_value = malloc(count_number * sizeof(int));

	char **floats_name = malloc(count_floats * sizeof(char *));
	float *float_value = malloc(count_floats * sizeof(float));

	char **strings_name = malloc(count_strings * sizeof(char *));
	char **strings_value = malloc(count_strings * sizeof(char *));

	char **int_array_name = malloc(count_number_int_array * sizeof(char *));
	int **int_array_value = malloc(count_number_int_array * sizeof(int *));
	int *int_array_size_value =
	    malloc(count_number_int_array * sizeof(int));

	for (int i = 0; i < number_line; i++) {
		char *line = malloc(sizeof(char) * 100);
		if (argc >= 2)
			line = read_file(argv[1], i);
		else {
			scanf("%s", line);
			if (strcmp(line, "exit")) {
				number_line++;
			} else {
				break;
			}
		}

		pipeline(line, numbers_name, number_value, &count_number,
			 floats_name, float_value, &count_floats,
			 strings_name, strings_value, &count_strings,
			 int_array_name, int_array_value,
			 &count_number_int_array, int_array_size_value,
			 &last_condition);

		free(line);
	}

	for (int i = 0; i < count_number; i++) {
		free(numbers_name[i]);
	}
	for (int i = 0; i < count_strings; i++) {
		free(strings_name[i]);
		free(strings_value[i]);
	}
	for (int i = 0; i < count_floats; i++) {
		free(floats_name[i]);
	}
	for (int i = 0; i < count_number_int_array; i++) {
		free(int_array_name[i]);
		free(int_array_value[i]);
	}
	free(numbers_name);
	free(number_value);
	free(floats_name);
	free(float_value);
	free(strings_name);
	free(strings_value);
	free(int_array_name);
	free(int_array_value);
	free(int_array_size_value);

	printf("\n");

	return 0;
}
