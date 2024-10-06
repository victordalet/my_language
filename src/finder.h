#ifndef FINDER_H
#define FINDER_H

int is_attribution(char *line);


int is_default_function(char *line, char* param,char **int_name, int *int_values, int int_count,
            char **float_name, float *float_values, int float_count, char **string_name, char **string_values, int count_string,
                        char ** int_array_name, int ** int_array_values, int int_array_count, int * int_array_size);


int is_comment(char *line);

int is_var(char *line);

int is_int(char *line);

int is_float(char *line);

int is_string(char *line);

int is_tab_of_int(char *line);

int is_method(char *line);

int is_condition(char *line);

#endif
