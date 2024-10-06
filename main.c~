#include <stdio.h>
#include <stdlib.h>
#include "src/parser.h"
#include "src/finder.h"
#include "src/spliter.h"
#include "src/var.h"
#include "src/append.h"

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Usage: %s <file_name>\n", argv[0]);
		return 1;
	}

	int type_line = 0;

	int number_line = get_number_line_in_file(argv[1]);

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
		char *line = read_file(argv[1], i);

		if (!is_comment(line)) {
			if (is_var(line)) {
				if (is_string(line)) {
					strings_name =
					    realloc(strings_name,
						    sizeof(char *) *
						    count_strings + 1);
					strings_value =
					    realloc(strings_value,
						    sizeof(char *) *
						    count_strings + 1);
					add_string(strings_name, strings_value,
						   &count_strings, line);
				} else if (is_tab_of_int(line)) {

					int_array_name =
					    realloc(int_array_name,
						    sizeof(char *) *
						    count_number_int_array + 1);
					int_array_value =
					    realloc(int_array_value,
						    sizeof(int *) *
						    count_number_int_array + 1);
					int_array_size_value =
					    realloc(int_array_size_value,
						    sizeof(int) *
						    count_number_int_array + 1);
					add_int_array(int_array_name,
						      int_array_value,
						      int_array_size_value,
						      &count_number_int_array,
						      line);

				} else if (is_float(line)) {
					floats_name =
					    realloc(floats_name,
						    sizeof(char *) *
						    count_floats + 1);
					float_value =
					    realloc(float_value,
						    sizeof(float) *
						    count_floats + 1);
					add_float(floats_name, float_value,
						  &count_floats, line);
				} else if (is_int(line)) {
					numbers_name =
					    realloc(numbers_name,
						    sizeof(char *) *
						    count_number + 1);
					number_value =
					    realloc(number_value,
						    sizeof(int) * count_number +
						    1);
					add_int(numbers_name, number_value,
						&count_number, line);
				}
			}

			else if (is_method(line)) {
				if (is_append_method(line)) {
					append_array_int(int_array_name,
							 int_array_value,
							 count_number_int_array,
							 int_array_size_value,
							 is_method(line), line);

				}

			}

			else {
				char *function = get_function(line, &type_line);

				if (type_line == 1) {
					char *param = get_param_function(line);

					is_default_function(function,
							    param,
							    numbers_name,
							    number_value,
							    count_number,
							    floats_name,
							    float_value,
							    count_floats,
							    strings_name,
							    strings_value,
							    count_strings,
							    int_array_name,
							    int_array_value,
							    count_number_int_array,
							    int_array_size_value);

					free(param);
				}
				free(function);
			}
		}
		//free(line);
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
