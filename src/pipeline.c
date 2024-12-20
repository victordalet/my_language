#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "finder.h"
#include "spliter.h"
#include "var.h"
#include "append.h"
#include "pop.h"
#include "condition.h"
#include "max.h"
#include "min.h"
#include "sort.h"
#include "lambda.h"
#include "mean.h"

void pipeline(char *line, char **numbers_name, int *number_value,
	      int *count_number, char **floats_name, float *float_value,
	      int *count_floats, char **strings_name, char **strings_value,
	      int *count_strings, char **int_array_name, int **int_array_value,
	      int *count_number_int_array, int *int_array_size_value,
	      int *image_number, char **image_url, int *image_x_position,
	      int *image_y_position, int *last_condition, int *touche_number,
	      char *touche_name, int *touche_image_index_postion,
	      int *touche_image_x_action, int *touche_image_y_action,
	      int *count_function, char **function_name, char **line_function,
	      int number_line, char *file_name)
{

	int type_line = 0;

	int number_point_virgule_in_line = 0;
	int i = 0;
	while (line[i] != '\0') {
		if (line[i] == ';') {
			number_point_virgule_in_line++;
		}
		i++;
	}

	if (is_while_loop(line) || is_for_loop(line) || is_else_condition(line)
	    || is_condition(line) || is_lambda_function(line))
		number_point_virgule_in_line = 0;

	if (number_point_virgule_in_line > 0) {
		char *line_splited = strtok(line, ";");
		for (int i = 0; i < number_point_virgule_in_line; i++) {
			line_splited = strtok(NULL, ";");
			pipeline(line_splited, numbers_name, number_value,
				 count_number, floats_name, float_value,
				 count_floats, strings_name, strings_value,
				 count_strings, int_array_name, int_array_value,
				 count_number_int_array, int_array_size_value,
				 image_number, image_url, image_x_position,
				 image_y_position, last_condition,
				 touche_number, touche_name,
				 touche_image_index_postion,
				 touche_image_x_action, touche_image_y_action,
				 count_function, function_name, line_function,
				 number_line, file_name);
		}
	}
	  if (strstr(line, ".mean()") != NULL) {
	        float result = -1;
	
	        if (line[0] == '[') {
	            result = process_mean_direct(line);  
	        }
	        
	        else {
	            result = process_mean_variable(line, int_array_name, int_array_value, 
	                                           count_number_int_array, int_array_size_value); 
	        }
	
	        if (result != -1) {
	            printf("%.2f\n", result);
	        } else {
	            printf("Erreur dans le calcul de la moyenne pour %s\n", line);
	        }
	    }
	if (!is_comment(line)) {
		if (is_var(line)) {
			if (is_string(line)) {
				strings_name =
				    realloc(strings_name,
					    sizeof(char *) *
					    *count_strings + 1);
				strings_value =
				    realloc(strings_value,
					    sizeof(char *) *
					    *count_strings + 1);
				add_string(strings_name, strings_value,
					   count_strings, line);
			} else if (is_tab_of_int(line)) {

				int_array_name =
				    realloc(int_array_name,
					    sizeof(char *) *
					    *count_number_int_array + 1);
				int_array_value =
				    realloc(int_array_value,
					    sizeof(int *) *
					    *count_number_int_array + 1);
				int_array_size_value =
				    realloc(int_array_size_value,
					    sizeof(int) *
					    *count_number_int_array + 1);
				add_int_array(int_array_name,
					      int_array_value,
					      int_array_size_value,
					      count_number_int_array, line);

			} else if (is_float(line)) {
				floats_name =
				    realloc(floats_name,
					    sizeof(char *) * *count_floats + 1);
				float_value =
				    realloc(float_value,
					    sizeof(float) * *count_floats + 1);
				add_float(floats_name, float_value,
					  count_floats, line);
			} else if (is_int(line)) {
				numbers_name =
				    realloc(numbers_name,
					    sizeof(char *) * *count_number + 1);
				number_value =
				    realloc(number_value,
					    sizeof(int) * *count_number + 1);
				add_int(numbers_name, number_value,
					count_number, line);
			}
		}

		else if (is_method(line)) {
			if (is_append_method(line)) {
				append_array_int(int_array_name,
						 int_array_value,
						 *count_number_int_array,
						 int_array_size_value,
						 is_method(line), line);

			} else if (is_pop_method(line)) {
				pop_array_int(int_array_name,
					      int_array_value,
					      *count_number_int_array,
					      int_array_size_value,
					      is_method(line), line);

			} else if (is_min_method(line)) {
				min_array_int(int_array_name,
					      int_array_value,
					      *count_number_int_array,
					      int_array_size_value, line);
			} else if (is_max_method(line)) {
				max_array_int(int_array_name,
					      int_array_value,
					      *count_number_int_array,
					      int_array_size_value, line);
			} else if (is_sort_method(line)) {
				sort_array_int(int_array_name,
					       int_array_value,
					       *count_number_int_array,
					       int_array_size_value, line);
			}

		}

		else if (is_condition(line)) {
			*last_condition = 1;
			if (condition
			    (line, numbers_name, number_value, *count_number)) {
				*last_condition = 2;

				pipeline(line, numbers_name, number_value,
					 count_number, floats_name, float_value,
					 count_floats, strings_name,
					 strings_value, count_strings,
					 int_array_name, int_array_value,
					 count_number_int_array,
					 int_array_size_value, image_number,
					 image_url, image_x_position,
					 image_y_position, last_condition,
					 touche_number, touche_name,
					 touche_image_index_postion,
					 touche_image_x_action,
					 touche_image_y_action, count_function,
					 function_name, line_function,
					 number_line, file_name);
			}

		}

		else if (is_else_condition(line)) {
			if (*last_condition != 2) {
				remove_else(line);
				pipeline(line, numbers_name, number_value,
					 count_number, floats_name, float_value,
					 count_floats, strings_name,
					 strings_value, count_strings,
					 int_array_name, int_array_value,
					 count_number_int_array,
					 int_array_size_value, image_number,
					 image_url, image_x_position,
					 image_y_position, last_condition,
					 touche_number, touche_name,
					 touche_image_index_postion,
					 touche_image_x_action,
					 touche_image_y_action, count_function,
					 function_name, line_function,
					 number_line, file_name);
			}
		}

		else if (is_while_loop(line)) {
			char *copy = malloc(strlen(line) + 1);
			if (copy) {
				strcpy(copy, line);
			}
			if (condition
			    (line, numbers_name, number_value, *count_number)) {
				pipeline(line, numbers_name, number_value,
					 count_number, floats_name, float_value,
					 count_floats, strings_name,
					 strings_value, count_strings,
					 int_array_name, int_array_value,
					 count_number_int_array,
					 int_array_size_value, image_number,
					 image_url, image_x_position,
					 image_y_position, last_condition,
					 touche_number, touche_name,
					 touche_image_index_postion,
					 touche_image_x_action,
					 touche_image_y_action, count_function,
					 function_name, line_function,
					 number_line, file_name);

				pipeline(copy, numbers_name, number_value,
					 count_number, floats_name, float_value,
					 count_floats, strings_name,
					 strings_value, count_strings,
					 int_array_name, int_array_value,
					 count_number_int_array,
					 int_array_size_value, image_number,
					 image_url, image_x_position,
					 image_y_position, last_condition,
					 touche_number, touche_name,
					 touche_image_index_postion,
					 touche_image_x_action,
					 touche_image_y_action, count_function,
					 function_name, line_function,
					 number_line, file_name);
			}
		}

		else if (is_lambda_function(line)) {
			store_lambda_function(line, count_function,
					      function_name, line_function,
					      number_line);
		}

		else {
			char *function = get_function(line, &type_line);
			if (type_line == 1) {
				char *param = get_param_function(line);
				int is_default_func =
				    is_default_function(function,
							param,
							numbers_name,
							number_value,
							*count_number,
							floats_name,
							float_value,
							*count_floats,
							strings_name,
							strings_value,
							*count_strings,
							int_array_name,
							int_array_value,
							*count_number_int_array,
							int_array_size_value,
							image_number,
							image_url,
							image_x_position,
							image_y_position,
							touche_number,
							touche_name,
							touche_image_index_postion,
							touche_image_x_action,
							touche_image_y_action);

				if (!is_default_func) {
					int line_to_execute =
					    execute_function(count_function,
							     function_name,
							     line_function,
							     line);

					if (line_to_execute != -1) {

						pipeline(line_function
							 [line_to_execute],
							 numbers_name,
							 number_value,
							 count_number,
							 floats_name,
							 float_value,
							 count_floats,
							 strings_name,
							 strings_value,
							 count_strings,
							 int_array_name,
							 int_array_value,
							 count_number_int_array,
							 int_array_size_value,
							 image_number,
							 image_url,
							 image_x_position,
							 image_y_position,
							 last_condition,
							 touche_number,
							 touche_name,
							 touche_image_index_postion,
							 touche_image_x_action,
							 touche_image_y_action,
							 count_function,
							 function_name,
							 line_function,
							 number_line,
							 file_name);

					}

				}

				free(param);
			}
			free(function);
		}
	}

}
