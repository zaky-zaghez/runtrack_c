#include <stdlib.h>

static int count_hex_digits(unsigned int n)
{
    int count = 1;
    while (n > 15) {
        count++;
        n /= 16;
    }
    return count;
}

char *itoa_hex(int n)
{
    unsigned int num = n;
    int is_negative = 0;
    int length;
    char *str;
    int i;

    // Gestion du cas particulier 0
    if (n == 0) {
        str = malloc(2);
        if (!str) return NULL;
        str[0] = '0';
        str[1] = '\0';
        return str;
    }

    // Gestion des nombres négatifs
    if (n < 0) {
        is_negative = 1;
        num = -n;
    }

    // Calcul de la longueur nécessaire
    length = count_hex_digits(num) + is_negative;
    str = malloc(length + 1);
    if (!str) return NULL;

    // Remplissage de la chaîne
    i = length;
    str[i--] = '\0';
    do {
        int digit = num % 16;
        str[i--] = (digit < 10) ? (digit + '0') : (digit - 10 + 'A');
        num /= 16;
    } while (num > 0);

    // Ajout du signe '-' si nécessaire
    if (is_negative)
        str[i] = '-';

    return str;
}