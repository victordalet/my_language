#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int result_condition(int a, char char1, char char2, int b)
{

	if (char1 == '=' && char2 == '=') {
		return a == b;
	}

	if (char1 == '<' && char2 == ' ') {
		return a < b;
	}

	if (char1 == '>' && char2 == ' ') {
		return a > b;
	}

	if (char1 == '>' && char2 == '=') {
		return a >= b;
	}

	if (char1 == '<' && char2 == '=') {
		return a <= b;
	}

	if (char1 == '!' && char2 == '=') {
		return a != b;
	}

	return 0;

}

int condition(char *line, char **numbers_name, int *number_value,
	      int count_number)
{

	int result = 1;
	int have_par = 0;
	int count = 0;

	int a = 0;
	int b = 0;
	char char1;
	char char2;

	while (line[count] != '\0') {

		if (line[count] == '(')
			have_par = 1;

		else if (line[count] == ')')
			break;

		if (have_par && line[count] == '=' && line[count + 1] == '=')
			char1 = '=', char2 = '=', count++;

		else if (have_par && line[count] == '<'
			 && line[count + 1] == '=')
			char1 = '<', char2 = '=', count++;

		else if (have_par && line[count] == '>'
			 && line[count + 1] == '=')
			char1 = '>', char2 = '=', count++;

		else if (have_par && line[count] == '!'
			 && line[count + 1] == '=')
			char1 = '!', char2 = '=', count++;

		else if (have_par && line[count] == '<'
			 && line[count + 1] != '=')
			char1 = '<', char2 = ' ', count++;

		else if (have_par && line[count] == '>'
			 && line[count + 1] != '=')
			char1 = '>', char2 = ' ', count++;

		count++;
	}

	/*--------------------------------------------------*/

	char strcopy[100];
	strcpy(strcopy, line);
	char *start = strchr(strcopy, '(') + 1;
	char *end = strchr(strcopy, char1);
	char temp[100];
	strncpy(temp, start, end - start);
	temp[end - start] = '\0';
	int len = strlen(temp);
	if (temp[len - 1] == ' ')
		temp[len - 1] = '\0';
	if (temp[0] >= '0' && temp[0] <= '9')
		a = atoi(temp);
	else {
		for (int i = 0; i < count_number; i++) {
			if (!strcmp(temp, numbers_name[i])) {
				a = number_value[i];
				break;
			}
		}
	}

	if (char2 == ' ') {
		start = strchr(strcopy, char1) + 1;
	} else if (char2 == char1) {
		start = strchr(strcopy, char1) + 2;
	} else {
		start = strchr(strcopy, char2) + 1;
	}
	end = strchr(strcopy, ')');
	strncpy(temp, start, end - start);
	temp[end - start] = '\0';
	if (temp[0] == ' ')
		memmove(temp, temp + 1, strlen(temp));
	if (temp[0] >= '0' && temp[0] <= '9')
		b = atoi(temp);
	else {
		for (int i = 0; i < count_number; i++) {
			if (!strcmp(temp, numbers_name[i])) {
				b = number_value[i];
				break;
			}
		}
	}

	/*--------------------------------------------------*/

	result = result_condition(a, char1, char2, b);

    /*--------------------------------------------------*/

	if (result) {

		char strcopy[100];
		strcpy(strcopy, line);

		char *element;
		for (element = strtok(strcopy, ":"); element;
		     element = strtok(NULL, ":")) {
			memmove(element, element + 1, strlen(element));
			strcpy(line, element);
		}

		return 1;

	}

	return 0;

}
