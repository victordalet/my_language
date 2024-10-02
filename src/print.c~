#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(char *str, char **int_name, int *int_values, int int_count,
	   char **float_name, float *float_values, int float_count)
{
	int i = 0;
	int j = 0;

	while (str[i] != '\0') {
		if (str[i] != '"' && str[0] != 'f')
			printf("%c", str[i]);

		else if (str[i] != '"' && str[0] == 'f') {
			if (i == 0) {
				i++;
			}
			if (str[i] == '{') {
				i++;
				j = 0;

				char *name = malloc(sizeof(char) * 100);
				while (str[i] != '}') {
					if (str[i] != ' ') {
						name[j] = str[i];
						j++;
					}

					i++;
				}

				name[j] = '\0';

				for (int k = 0; k < int_count; k++) {
					if (strcmp(name, int_name[k]) == 0) {
						printf("%d", int_values[k]);
						break;
					}

					for (int k = 0; k < float_count; k++) {
						if (strcmp(name, float_name[k])
						    == 0) {
							printf("%f",
							       float_values[k]);
							break;
						}
					}

					free(name);
				}
			} else {

				if (str[i] != '"') {
					printf("%c", str[i]);
				}
			}
		}

		i++;
	}

	printf("\n");
}
