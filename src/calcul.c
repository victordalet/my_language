#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int result_calcul(char *string, char **name_variable, int *value_variable,
		  int count_variable)
{

	int len = strlen(string);
	int *numbers = malloc(len * sizeof(int));
	char *symbols = malloc(len * sizeof(char));
	int num_count = 0;
	int sym_count = 0;

	for (int i = 0; i < len; i++) {
		if (isdigit(string[i])) {
			numbers[num_count++] = strtol(&string[i], NULL, 10);
			while (i < len && isdigit(string[i])) {
				i++;
			}
			i--;
		} else if (strchr("+-*/", string[i])) {
			if (string[i] == '*' && string[i + 1] == '*') {
				symbols[sym_count++] = 'p';
				i++;
			} else {
				symbols[sym_count++] = string[i];
			}
		}

		else if (isalpha(string[i])) {
			int var_len = 0;
			int j = i;
			while (j < len && isalpha(string[j])) {
				var_len++;
				j++;
			}
			char *var_name = malloc(sizeof(char) * var_len + 1);
			var_len = 0;
			while (i < len && isalpha(string[i])) {
				var_name[var_len++] = string[i++];
			}
			var_name[var_len] = '\0';
			for (int j = 0; j < count_variable; j++) {
				if (strcmp(name_variable[j], var_name) == 0) {
					numbers[num_count++] =
					    value_variable[j];
					break;
				}
			}
			i--;
		}
	}

	int result = numbers[0];
	for (int i = 0; i < sym_count; i++) {
		if (symbols[i] == '*' || symbols[i] == '/' || symbols[i] == 'p') {
			switch (symbols[i]) {
			case '*':
				numbers[i + 1] = numbers[i] * numbers[i + 1];
				break;
			case '/':
				numbers[i + 1] = numbers[i] / numbers[i + 1];
				break;
			case 'p':
				numbers[i + 1] =
				    (int)pow(numbers[i], numbers[i + 1]);
				break;
			}
			numbers[i] = 0;
			symbols[i] = '+';
		}
	}

	for (int i = 0; i < sym_count; i++) {
		switch (symbols[i]) {
		case '+':
			result += numbers[i + 1];
			break;
		case '-':
			result -= numbers[i + 1];
			break;
		}
	}

	return result;

}
