#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/parser.h"
#include "src/finder.h"
#include "src/spliter.h"
#include "src/var.h"
#include "src/append.h"
#include "src/pop.h"
#include "src/condition.h"
#include "src/pipeline.h"
#include "src/view.h"
#include "src/press_event.h"
#include "src/calcul.h"
#include <math.h>
#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{

	int number_line = 1;
	int last_condition = 0;

	if (argc >= 2)
		number_line = get_number_line_in_file(argv[1]);

	int count_number = 0;
	int count_strings = 0;
	int count_floats = 0;
	int count_number_int_array = 0;

	char **numbers_name = malloc(count_number * sizeof(char *));
	int *number_value = malloc(count_number * sizeof(int));

	char **floats_name = malloc(count_floats * sizeof(char *));
	float *float_value = malloc(count_floats * sizeof(float));

	char **strings_name = malloc(count_strings * sizeof(char *));
	char **strings_value = malloc(count_strings * sizeof(char *));

	char **int_array_name = malloc(count_number_int_array * sizeof(char *));
	int **int_array_value = malloc(count_number_int_array * sizeof(int *));
	int *int_array_size_value =
	    malloc(count_number_int_array * sizeof(int));

	/*--------------------------------------------------------------------------*/

	int image_number = 0;
	char **image_url = malloc(sizeof(char *) * image_number);
	int *image_x_position = malloc(sizeof(int *) * image_number);
	int *image_y_position = malloc(sizeof(int *) * image_number);

	int touche_number = 0;
	char *touche_name = malloc(sizeof(char) * touche_number);
	int *touche_image_index_postion = malloc(sizeof(int) * touche_number);
	int *touche_image_x_action = malloc(sizeof(char) * touche_number);
	int *touche_image_y_action = malloc(sizeof(char) * touche_number);

	int KEYS[322] = { 0 };
    /*--------------------------------------------------------------------------*/

	for (int i = 0; i < number_line; i++) {
		char *line = malloc(sizeof(char) * 100);
		if (argc >= 2)
			line = read_file(argv[1], i);
		else {
			scanf("%s", line);
			number_line++;
		}

		pipeline(line, numbers_name, number_value, &count_number,
			 floats_name, float_value, &count_floats,
			 strings_name, strings_value, &count_strings,
			 int_array_name, int_array_value,
			 &count_number_int_array, int_array_size_value,
			 &image_number, image_url, image_x_position,
			 image_y_position, &last_condition, &touche_number,
			 touche_name, touche_image_index_postion,
			 touche_image_x_action, touche_image_y_action);
		free(line);
	}

	/*--------------------------------------------------------------------------*/

	if (image_number > 0) {
		SDL_Window *window = init_view(argv[1]);
		SDL_Renderer *renderer = init_renderer(window);
		SDL_Texture **images =
		    malloc(sizeof(SDL_Texture *) * image_number);

		for (int i = 0; i < image_number; i++) {

			images[i] = load_picture(image_url[i], renderer);
		}

		while (1) {
			SDL_Delay(30);
			clear_renderer(renderer);

			for (int i = 0; i < image_number; i++) {
				display_picture(renderer, images[i],
						image_x_position[i],
						image_y_position[i], 100, 100);
			}

			add_action_press_event(image_x_position,
					       image_y_position,
					       &last_condition, &touche_number,
					       touche_name,
					       touche_image_index_postion,
					       touche_image_x_action,
					       touche_image_y_action, KEYS);

			SDL_Event event;
			while (SDL_PollEvent(&event)) {

				if (event.type == SDL_QUIT) {
					SDL_DestroyRenderer(renderer);
					SDL_DestroyWindow(window);
					SDL_Quit();
					return 0;
				}

				if (event.type == SDL_KEYDOWN) {
					KEYS[event.key.keysym.scancode] = 1;
				}

				if (event.type == SDL_KEYUP) {
					KEYS[event.key.keysym.scancode] = 0;
				}

			}

			SDL_RenderPresent(renderer);

		}

	}

	/*--------------------------------------------------------------------------*/

	for (int i = 0; i < count_number; i++) {
		free(numbers_name[i]);
	}
	for (int i = 0; i < count_strings; i++) {
		free(strings_name[i]);
		free(strings_value[i]);
	}
	for (int i = 0; i < count_floats; i++) {
		free(floats_name[i]);
	}
	for (int i = 0; i < count_number_int_array; i++) {
		free(int_array_name[i]);
		free(int_array_value[i]);
	}
	for (int i = 0; i < image_number; i++) {
		free(image_url[i]);
	}
	free(numbers_name);
	free(number_value);
	free(floats_name);
	free(float_value);
	free(strings_name);
	free(strings_value);
	free(int_array_name);
	free(int_array_value);
	free(int_array_size_value);
	free(image_url);
	free(image_x_position);
	free(image_y_position);


	return 0;
}
