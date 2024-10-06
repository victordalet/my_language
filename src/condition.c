#include <string.h>

int condition(char *line)
{

	int result = 1;

	int is_equal_condition = 0;
	int have_par = 0;

	int count = 0;

	while (line[count] != '\0') {

		if (line[count] == '(')
			have_par = 1;

		else if (line[count] == ')')
			break;

		else if (have_par && line[count] == '='
			 && line[count + 1] == '=') {
			is_equal_condition = 1;
		}

		count++;
	}

	if (result) {

		char *first_step = strtok(line, ":");
		char *second_step = strtok(line, ":");
		line = second_step;

		return 1;

	}

	return 0;

}