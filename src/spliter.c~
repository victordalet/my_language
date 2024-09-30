#include <stdlib.h>
#include <string.h>

char *get_attribution(char *line)
{

	int i = 0;
	int count = 0;

	while (line[i] != '\0') {
		if (line[i] == '=') {
			count = i;
		}
		i++;
	}

	char *result = (char *)malloc(i - count + 1 * sizeof(char));

	i = 0;

	while (line[count] != '\0' && line[count] != '\n' && line[count] != ';') {
		result[i] = line[count];
		count++;
	}

	result[i] = '\0';

	return result;

}

char *get_name(char *line)
{

	int i = 0;
	int count = 0;

	while (line[i] != '\0') {
		if (line[i] == '=') {
			count = i;
			break;
		}
		i++;
	}

	char *result = (char *)malloc(count + 1 * sizeof(char));

	i = 0;

	while (line[i] != '\0' && line[i] != '\n' && line[i] != ';'
	       && i < count) {
		result[i] = line[i];
		i++;
	}

	result[i] = '\0';

	return result;

}

char **get_function(char *line)
{
	/*
	   0 -> false
	   else -> function name
	 */

	int i = 0;
	int j = 0;

	while (line[i] != '\0') {
		if (line[i] == '(') {
			j = i;
		}
		i++;
	}

	char *function_name = (char *)malloc(j + 1 * sizeof(char));

	char *function_args = (char *)malloc(i - j + 1 * sizeof(char));

	i = 0;

	while (line[i] != '(') {
		function_name[i] = line[i];
		i++;
	}

	j++;
	while (line[j] != '\0' && line[j] != ')') {
		function_args[j] = line[j];
		j++;
	}

	char **result = malloc(2 * sizeof(char *));
	result[0] = function_name;
	result[1] = function_args;
	return result;

}
