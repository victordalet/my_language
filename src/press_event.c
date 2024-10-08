#include <stdio.h>

void add_action_press_event(int *image_x_position,
			    int *image_y_position, int *last_condition,
			    int *touche_number, char *touche_name,
			    int *touche_image_index_postion,
			    int *touche_image_x_action,
			    int *touche_image_y_action, int key[256])
{

	for (int i = 0; i < *touche_number; i++) {

		if (key[(int)touche_name[i] - 93] == 1) {
			image_x_position[touche_image_index_postion[i] - 1] +=
			    touche_image_x_action[i];
			image_y_position[touche_image_index_postion[i] - 1] +=
			    touche_image_y_action[i];
		}
	}

}
