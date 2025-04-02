#include <stdlib.h> // Pour malloc()

char *my_strdup(const char *src)
{
    if (!src) // Gestion du cas où src est NULL
        return NULL;

    // Calcul de la longueur de la chaîne source
    int len = 0;
    while (src[len] != '\0')
        len++;

    // Allocation de la mémoire pour la copie (+1 pour le '\0')
    char *dest = (char *)malloc(len + 1);
    if (!dest) // Échec de l'allocation
        return NULL;

    // Copie de la chaîne
    for (int i = 0; i <= len; i++)
        dest[i] = src[i];

    return dest;
}