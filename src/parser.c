#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fptr;

char *read_file(char file_name[50], int line_index)
{
	fptr = fopen(file_name, "r");
	char line[100];
	char *line_out = malloc(sizeof(char) * 100);
	int i = 0;
	while (fgets(line, 100, fptr)) {
		if (i == line_index) {
			strcpy(line_out, line);
			break;
		}
		i++;
	}
	fclose(fptr);
	return line_out;
}

int get_number_line_in_file(char file_name[50])
{
	fptr = fopen(file_name, "r");
	char line[100];
	int i = 0;
	while (fgets(line, 100, fptr)) {
		i++;
	}
	fclose(fptr);
	return i;
}
