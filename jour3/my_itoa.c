#include <stdlib.h>

static int count_digits(int n)
{
    int count = 1;
    if (n < 0) {
        count++;
        n = -n;
    }
    while (n > 9) {
        count++;
        n /= 10;
    }
    return count;
}

char *my_itoa(int n)
{
    int len = count_digits(n);
    char *str = malloc(len + 1);
    if (str == NULL)
        return NULL;

    int i = len;
    str[i--] = '\0';

    int is_negative = n < 0;
    if (is_negative)
        n = -n;

    do {
        str[i--] = (n % 10) + '0';
        n /= 10;
    } while (n > 0);

    if (is_negative)
        str[i] = '-';

    return str;
}