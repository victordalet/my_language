#include <stdio.h>
#include <stdlib.h>
#include "src/parser.h"
#include "src/finder.h"
#include "src/spliter.h"

int main(int argc, char *argv[])
{

	if (argc != 2) {
		printf("Usage: %s <file_name>\n", argv[0]);
		return 1;
	}

	int number_line = get_number_line_in_file(argv[1]);

	int number_numbers = 0;
	int number_strings = 0;
	int number_floats = 0;

	char **numbers_name = malloc(number_numbers * sizeof(char *));
	int *number_value = malloc(number_numbers * sizeof(int));

	char **floats_name = malloc(number_numbers * sizeof(char *));
	float *float_value = malloc(number_numbers * sizeof(float));

	char **strings_name = malloc(number_strings * sizeof(char *));
	char **strings_value = malloc(number_strings * sizeof(char *));

	for (int i = 0; i < number_line; i++) {

		char *line = read_file(argv[1], i);

		if (!is_comment(line)) {

			char **function = get_function(line);
			if (function[0][0] != '0') {

				int is_default =
				    is_default_function(function[1],
							numbers_name,
							number_value,
							number_numbers,
							floats_name,
							float_value,
							number_floats);

			}

		}

		free(line);

	}

	free(numbers_name);
	free(number_value);
	free(floats_name);
	free(float_value);
	free(strings_name);
	free(strings_value);

	return 0;

}
