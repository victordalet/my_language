#include "stdlib.h"
#include "string.h"
#include "stdio.h"

void store_lambda_function(char *line, int *count_function,
			   char **function_name, char **line_function,
			   int line_number)
{

	*count_function += 1;

	function_name =
	    realloc(function_name, sizeof(char *) * *count_function);

	line_function =
	    realloc(line_function, sizeof(char *) * *count_function);

	char *start = strchr(line, ' ') + 1;
	char *end = strchr(line, '(');
	int length = end - start;
	function_name[*count_function - 1] = malloc(length + 1);
	strncpy(function_name[*count_function - 1], start, length);
	function_name[*count_function - 1][length] = '\0';

	line_function[*count_function - 1] = malloc(strlen(line) + 1);
	strcpy(line_function[*count_function - 1], line);
	char *token = strtok(line_function[*count_function - 1], ":");
	line_function[*count_function - 1] = strtok(NULL, "\0");
	line_function[*count_function -
		      1][strlen(line_function[*count_function - 1]) - 1] = '\0';

}

int execute_function(int *count_function,
		     char **function_name, char **line_function, char *line)
{

	char *name = strtok(line, "(");

	for (int i = 0; i < *count_function; i++) {
		if (!strcmp(function_name[i], name)) {
			return i;
		}

	}

	return -1;

}
