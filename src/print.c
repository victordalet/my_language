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

			if (str[i] == '{') {

				i++;
				j = 0;

				char *name = (char *)malloc(100);
				while (str[i] != '}') {

					name[j] = str[i];
					i++;
					j++;
				}

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

			} else
				printf("%c", str[i]);
		}

		i++;
	}

	printf("\n");

}
