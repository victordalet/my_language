#ifndef LAMBDA_H
#define LAMBDA_H

void store_lambda_function(char *line, int *count_function,
			   char **function_name, char **line_function,
			   int line_number);

int execute_function(int *count_function,
		     char **function_name, char **line_function, char *name);

#endif
