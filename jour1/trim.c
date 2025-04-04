#include <stdlib.h>

int is_whitespace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f');
}

char *trim(const char *src)
{
    if (!src) return NULL;

    // Trouver le premier caractère non-espace
    const char *start = src;
    while (*start && is_whitespace(*start))
        start++;

    // Si la chaîne est entièrement composée d'espaces
    if (*start == '\0')
        return malloc(1); // Retourne une chaîne vide

    // Trouver le dernier caractère non-espace
    const char *end = start;
    const char *last_non_space = start;
    while (*end)
    {
        if (!is_whitespace(*end))
            last_non_space = end;
        end++;
    }

    // Calcul de la longueur de la nouvelle chaîne
    size_t len = last_non_space - start + 1;

    // Allocation mémoire
    char *dest = (char *)malloc(len + 1);
    if (!dest) return NULL;

    // Copie de la partie utile
    for (size_t i = 0; i < len; i++)
        dest[i] = start[i];
    dest[len] = '\0';

    return dest;
}