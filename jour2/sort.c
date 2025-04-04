void sort(char **array)
{
    int i, j;
    char *temp;
    int length = 0;

    // Calculer la longueur du tableau
    while (array[length] != NULL)
        length++;

    // Tri à bulles
    for (i = 0; i < length - 1; i++) {
        for (j = 0; j < length - i - 1; j++) {
            // Comparaison ASCII
            int k = 0;
            while (array[j][k] == array[j+1][k] && array[j][k] != '\0' && array[j+1][k] != '\0')
                k++;
            
            if (array[j][k] > array[j+1][k]) {
                // Échange des pointeurs
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

#include <stdlib.h>

// Tri à bulles simple
void sort_strings(char **array, int size)
{
    int i, j;
    char *temp;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (strcompare(array[j], array[j+1]) > 0) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}