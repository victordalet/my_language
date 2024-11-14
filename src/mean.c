#include "mean.h"



void print_array(int *array, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}


float calculate_mean(int *array, int size) {
    if (size == 0) return -1;  

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return (float)sum / size;
}

float process_mean_direct(char *line) {
    int *array = NULL;
    int array_size = 0;

    char *start = strchr(line, '[');
    char *end = strchr(line, ']');
    
    if (start && end && start < end) {
        start++;  
        char *token = strtok(start, ",");
        while (token != NULL) {
            while (isspace((unsigned char)*token)) token++;  
            array = realloc(array, sizeof(int) * (array_size + 1));
            array[array_size++] = atoi(token);
            token = strtok(NULL, ",");
        }
    } else {
        printf("Erreur: tableau mal formaté\n");
        return -1; 
    }

    printf("Tableau direct : ");
    print_array(array, array_size);

    float mean = calculate_mean(array, array_size);
    

    free(array);
    return mean;
}


float process_mean_variable(char *line, char **int_array_name, int **int_array_value, int count_number_int_array, int *int_array_size_value) {
    char array_name[100];
    sscanf(line, "%99[^.]", array_name);  
    for (int i = 0; i < count_number_int_array; i++) {
        
        if (strcmp(array_name, int_array_name[i]) == 0) {

            int *array = int_array_value[i];
            int size = int_array_size_value[i];

            printf("Tableau %s : ", array_name);
            print_array(array, size);

            return calculate_mean(array, size);
        }
    }

    printf("Erreur : tableau %s non trouvé.\n", array_name);
    return -1;
}

float process_mean_method(char *line, char **int_array_name, int **int_array_value, int count_number_int_array, int *int_array_size_value) {
    if (strstr(line, ".mean()") != NULL) {
        if (line[0] == '[') {
            return process_mean_direct(line);
        } else {
            return process_mean_variable(line, int_array_name, int_array_value, count_number_int_array, int_array_size_value);
        }
    }
    return -1;  
}
