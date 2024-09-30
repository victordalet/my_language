#include <stdlib.h>
#include <string.h>
#include "print.h"

int is_attribution(char *line)
{
	/*
	   0 -> false
	   1 -> int
	   2 -> string
	   3 -> bool
	   4 -> list[int]
	   5 -> list[string]
	   6 -> list[bool]
	 */
	int i = 0;
	int result = 0;
	while (line[i] != '\0') {
		if (line[i] == '=' && line[i + 1] != '=') {
			result = 1;
			break;
		}
		i++;
	}
	while (i != 0) {
		if (line[i] == 't' && line[i - 1] == 'n' && line[i - 2] == 'i') {
			result = 1;
			break;
		} else if (line[i] == 'g' && line[i - 1] == 'n'
			   && line[i - 2] == 'i' && line[i - 3] == 'r'
			   && line[i - 4] == 't' && line[i - 5] == 's') {
			result = 2;
			break;
		} else if (line[i] == 'l' && line[i - 1] == 'o'
			   && line[i - 2] == 'o' && line[i - 2] == 'l') {
			result = 3;
			break;
		} else if (line[i] == ']') {
			i--;
			if (line[i] == 't' && line[i - 1] == 'n'
			    && line[i - 2] == 'i') {
				result = 4;
				break;
			} else if (line[i] == 'g' && line[i - 1] == 'n'
				   && line[i - 2] == 'i' && line[i - 3] == 'r'
				   && line[i - 4] == 't'
				   && line[i - 5] == 's') {
				result = 5;
				break;
			} else if (line[i] == 'l' && line[i - 1] == 'o'
				   && line[i - 2] == 'o'
				   && line[i - 2] == 'l') {
				result = 6;
				break;
			}
		}

		i--;
	}
	return result;
}

int is_default_function(char *line, char **int_name, int *int_values,
			int int_count, char **float_name, float *float_values,
			int float_count)
{
	/*
	   0 -> false
	   1 -> true
	 */

	if (strcmp(line, "print") == 0) {
		print(line, int_name, int_values, int_count, float_name,
		      float_values, float_count);
		return 1;
	}

	return 0;
}

int is_comment(char *line)
{

	if (line[0] == '#') {
		return 1;
	}

	return 0;

}
