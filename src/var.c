#include <stdlib.h>
#include <stdio.h>

void add_int(char **name, int *values, int *count, char *line)
{

	int i = 0;

	int count_new_name = 0;
	int new_value = 0;

	int mid = 0;

	int count_number_in_number = 0;
	int multiply = 1;
	int number = 0;

	while (line[i] != '\0' && line[i] != '=') {

		if (line[i] != ' ')
			count_new_name++;

		i++;

	}

	i = 0;

	/*--------------------------------------------------------------*/

	char *var_name = malloc(sizeof(char) * count_new_name + 1);

	count_new_name = 0;

	while (line[i] != '\0' && line[i] != '=') {

		if (line[i] != ' ') {
			var_name[count_new_name] = line[i];
			count_new_name++;
		}

		i++;
	}

	var_name[count_new_name] = '\0';

	name[*count] = var_name;

	/*--------------------------------------------------------------*/

	while (line[i] != '\0') {

		if (line[i] >= 48 && line[i] <= 57) {
			count_number_in_number++;
			multiply *= 10;
		}

		i++;

	}

	multiply /= 10;

	while (line[mid] != '\0') {

		if (line[mid] >= 48 && line[mid] <= 57) {
			number += (line[mid] - 48) * multiply;
			multiply /= 10;
		}

		mid++;

	}

	values[*count] = number;

	*count += 1;

};

void add_float(char **name, float *values, int *count, char *line)
{

	int i = 0;

	int count_new_name = 0;
	int new_value = 0;

	int mid = 0;

	int count_number_in_number = 0;
	int multiply = 1;
	float number = 0;

	int decimal = 0;
	int multiply_decimal = 1;

	while (line[i] != '\0' && line[i] != '=') {

		if (line[i] != ' ')
			count_new_name++;

		i++;

	}

	i = 0;

    /*--------------------------------------------------------------*/

	char *var_name = malloc(sizeof(char) * count_new_name + 1);

	count_new_name = 0;

	while (line[i] != '\0' && line[i] != '=') {

		if (line[i] != ' ') {
			var_name[count_new_name] = line[i];
			count_new_name++;
		}

		i++;
	}

	var_name[count_new_name] = '\0';

	name[*count] = var_name;

	/*--------------------------------------------------------------*/

	while (line[i] != '\0' && line[i] != '.') {

		if (line[i] >= 48 && line[i] <= 57) {
			count_number_in_number++;
			multiply *= 10;
		}

		i++;

	}

	multiply /= 10;

	while (line[mid] != '\0' && line[mid] != '.') {

		if (line[mid] >= 48 && line[mid] <= 57) {
			number += (line[mid] - 48) * multiply;
			multiply /= 10;
		}

		mid++;

	}

	/*--------------------------------------------------------------*/
	count_number_in_number = 0;
	multiply = 1;
	i++;
	mid++;

	while (line[i] != '\0') {

		if (line[i] >= 48 && line[i] <= 57) {
			count_number_in_number++;
			multiply *= 10;
		}

		i++;

	}

	multiply /= 10;

	while (line[mid] != '\0' && line[mid] != '.') {

		if (line[mid] >= 48 && line[mid] <= 57) {
			decimal += (line[mid] - 48) * multiply;
			multiply /= 10;
		}

		mid++;

	}

	/*--------------------------------------------------------------*/

	for (i = 0; i < count_number_in_number; i++) {
		multiply_decimal *= 10;
	}

	values[*count] = (number + decimal) / multiply_decimal;

	*count += 1;

};
