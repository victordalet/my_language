#include <stdlib.h>

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

	char *result = malloc(i - count + 1 * sizeof(char));

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

	char *result = malloc(count + 1 * sizeof(char));

	i = 0;

	while (line[i] != '\0' && line[i] != '\n' && line[i] != ';'
	       && i < count) {
		result[i] = line[i];
		i++;
	}

	result[i] = '\0';

	return result;
}

char *get_function(char *line, int *type_line)
{
	int i = 0;
	int j = 0;

	while (line[i] != '\0') {
		if (line[i] == '(') {
			j = i;
		}
		i++;
	}

	if (j == 0) {
		*type_line = 0;
	} else {
		*type_line = 1;
	}

	char *function_name = malloc(j + 1 * sizeof(char));

	i = 0;

	while (i != j) {
		function_name[i] = line[i];
		i++;
	}

	function_name[i] = '\0';

	return function_name;
}

char *get_param_function(char *line)
{
	int i = 0;
	int j = 0;
	int count = 0;

	while (line[i] != '\0') {
		if (line[i] == '(') {
			j = i;
		}
		i++;
	}

	char *function_name = malloc(i - j + 1 * sizeof(char));

	while (i != j) {

		if (line[j] != '(' && line[j] != ')' && line[j] != ';') {
			function_name[count] = line[j];
			count++;
		}
		j++;
	}

	function_name[count] = '\0';

	return function_name;
}
