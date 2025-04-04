#include <stdlib.h>

char **array_clone(char **array, int n)
{
    int i;
    int len = 0;
    char **new_array;

    // Calculer la longueur jusqu'à n ou premier NULL
    while (len < n && array[len] != NULL)
        len++;

    // Allouer le nouveau tableau (+1 pour le NULL final)
    new_array = malloc(sizeof(char *) * (len + 1));
    if (new_array == NULL)
        return NULL;

    // Copier les pointeurs
    for (i = 0; i < len; i++)
        new_array[i] = array[i];

    // Terminer par NULL
    new_array[len] = NULL;

    return new_array;
}