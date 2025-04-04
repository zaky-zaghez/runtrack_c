#include <stdlib.h>

void delete_str_array(char ***array_ptr)
{
    if (array_ptr == NULL || *array_ptr == NULL)
        return;

    char **array = *array_ptr;
    
    // Libérer chaque chaîne du tableau
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    
    // Libérer le tableau lui-même
    free(array);
    
    // Mettre le pointeur à NULL
    *array_ptr = NULL;
}