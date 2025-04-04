#include <stdlib.h>

// Supprime les espaces en début et fin de chaîne
char *strtrim(char *str)
{
    if (!str) return NULL;

    // Trouver le début sans espaces
    int start = 0;
    while (str[start] == ' ' || str[start] == '\t' || str[start] == '\n')
        start++;

    // Trouver la fin sans espaces
    int end = 0;
    while (str[end]) end++;
    while (end > start && (str[end-1] == ' ' || str[end-1] == '\t' || str[end-1] == '\n'))
        end--;

    // Allouer et copier la nouvelle chaîne
    char *res = malloc(end - start + 1);
    if (!res) return NULL;

    for (int i = 0; i < end - start; i++)
        res[i] = str[start + i];
    res[end - start] = '\0';

    return res;
}

// Compare deux chaînes pour le tri
int strcompare(const char *a, const char *b)
{
    while (*a && *b && *a == *b) {
        a++;
        b++;
    }
    return *a - *b;
}