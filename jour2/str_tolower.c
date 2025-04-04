#include <stdlib.h>

void str_tolower(char *str)
{
    if (!str)
        return;
        
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
}