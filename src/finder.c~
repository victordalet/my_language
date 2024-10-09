#include <stdio.h>
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

int is_default_function(char *line, char *param, char **int_name,
			int *int_values, int int_count, char **float_name,
			float *float_values, int float_count,
			char **string_name, char **string_values,
			int count_string, char **int_array_name,
			int **int_array_values, int int_array_count,
			int *int_array_size, int *image_number,
			char **image_url, int *image_x_position,
			int *image_y_position, int *touche_number,
			char *touche_name, int *touche_image_index_postion,
			int *touche_image_x_action, int *touche_image_y_action)
{
	if (!strcmp(line, "print")) {
		print(param, int_name, int_values, int_count, float_name,
		      float_values, float_count, string_name, string_values,
		      count_string, int_array_name, int_array_values,
		      int_array_count, int_array_size);
		return 1;
	}

	if (!strcmp(line, "system")) {
		int i = 0;
		while (param[i] != '\0') {
			if (param[i] == '"') {
				memmove(param + i, param + i + 1,
					strlen(param) - i);
			}
			i++;
		}
		system(param);
		return 1;
	}

	if (!strcmp(line, "exit")) {
		exit(0);
	}

	if (!strcmp(line, "displayUrl")) {
		char *url = strtok(param, ",");
		char *x = strtok(NULL, ",");
		char *y = strtok(NULL, ",");
		image_url =
		    realloc(image_url, sizeof(char *) * *image_number + 1);
		image_x_position =
		    realloc(image_x_position, sizeof(int) * *image_number + 1);
		image_y_position =
		    realloc(image_y_position, sizeof(int) * *image_number + 1);
		image_url[*image_number] = malloc(sizeof(char) * (strlen(url)));
		strcpy(image_url[*image_number], url);
		image_x_position[*image_number] = atoi(x);
		image_y_position[*image_number] = atoi(y);
		(*image_number)++;
	}

	if (!strcmp(line, "keyEvent")) {
		char *name = strtok(param, ",");
		char *index = strtok(NULL, ",");
		char *x = strtok(NULL, ",");
		char *y = strtok(NULL, ",");
		touche_name =
		    realloc(touche_name, sizeof(char) * *touche_number + 1);
		touche_image_index_postion =
		    realloc(touche_image_index_postion,
			    sizeof(int) * *touche_number + 1);
		touche_image_x_action =
		    realloc(touche_image_x_action,
			    sizeof(int) * *touche_number + 1);
		touche_image_y_action =
		    realloc(touche_image_y_action,
			    sizeof(int) * *touche_number + 1);
		touche_name[*touche_number] = name[1];
		touche_image_index_postion[*touche_number] = atoi(index);
		touche_image_x_action[*touche_number] = atoi(x);
		touche_image_y_action[*touche_number] = atoi(y);
		(*touche_number)++;
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

int is_var(char *line)
{
	int i = 0;
	while (line[i] != '\0') {
		if (line[i] == '=' && line[i - 1] != '!' && line[i - 1] != '<'
		    && line[i - 1] != '>') {
			if (line[i + 1] != '=')
				return 1;
			return 0;
		}
		i++;
	}
	return 0;
}

int is_int(char *line)
{
	int i = 0;
	while (line[i] != '\0') {
		if (line[i] == '"') {
			return 0;
		}

		if (line[i] == '=' && line[i + 1] != '=') {
			return 1;
		}
		i++;
	}
	return 0;
}

int is_float(char *line)
{
	int i = 0;
	int equal = 0;
	int point = 0;
	while (line[i] != '\0') {
		if (line[i] == '"') {
			return 0;
		}

		if (line[i] == '=' && line[i + 1] != '=') {
			equal = 1;
		}
		if (line[i] == '.' && equal) {
			point = 1;
		}
		i++;
	}

	if (equal && point) {
		return 1;
	}

	return 0;
}

int is_string(char *line)
{

	int i = 0;
	int have_equal = 0;
	int have_par = 0;

	while (line[i] != '\0') {

		if (line[i] == '=' && line[i + 1] != '=') {
			have_equal = 1;
		}

		if (line[i] == '"')
			have_par++;

		i++;
	}

	if (have_equal && have_par == 2) {
		return 1;
	}

	return 0;

}

int is_tab_of_int(char *line)
{
	int i = 0;
	int crochet = 0;
	int have_equal = 0;

	while (line[i] != '\0') {
		if (line[i] == '"') {
			return 0;
		}

		if (line[i] == '=' && line[i + 1] != '=') {
			have_equal = 1;
		}

		if (line[i] == '[') {
			crochet = 1;
		}

		if (line[i] == ']' && crochet) {
			crochet = 2;
		}

		i++;
	}

	if (have_equal && crochet == 2)
		return 1;

	return 0;
}

int is_method(char *line)
{
	int have_point = 0;
	int parameter = 0;
	int start = 0;
	int stop = 0;

	int count = 0;

	while (line[count] != '\0') {

		if (line[count] == '.' && count != 0) {
			have_point = 1;
		}

		if (have_point && line[count] == '(') {
			start = count + 1;
		}

		if (have_point && line[count] == ')') {
			stop = count;
			break;
		}

		count++;
	}

	if (have_point && start) {

		if (start == stop)
			return 1;

		char *value = malloc(sizeof(char) * stop - start + 1);
		strncpy(value, &line[start], stop - start);
		value[stop - start] = '\0';
		return atoi(value);
	}

	return 0;
}

int is_condition(char *line)
{
	char strcopy[100];
	strcpy(strcopy, line);

	char *first_element = strtok(strcopy, " ");

	if (!strcmp(first_element, "if")) {
		return 1;
	}

	return 0;

}

int is_else_condition(char *line)
{

	char strcopy[100];
	strcpy(strcopy, line);

	char *first_element = strtok(strcopy, ":");

	if (!strcmp(first_element, "else")) {
		return 1;
	}

	return 0;
}

int is_for_loop(char *line)
{
	char strcopy[100];
	strcpy(strcopy, line);

	char *first_element = strtok(strcopy, " ");

	if (!strcmp(first_element, "for")) {
		return 1;
	}

	return 0;
}

int is_while_loop(char *line)
{
	char strcopy[100];
	strcpy(strcopy, line);

	char *first_element = strtok(strcopy, " ");

	if (!strcmp(first_element, "while")) {
		return 1;
	}

	return 0;
}
