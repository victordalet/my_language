#ifndef FINDER_H
#define FINDER_H

int is_attribution(char *line);


int is_default_function(char *line, char* param,char **int_name, int *int_values, int int_count,
            char **float_name, float *float_values, int float_count);


int is_comment(char *line);

#endif				//FINDER_H
