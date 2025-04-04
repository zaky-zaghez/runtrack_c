int char_is_digit(char c); // Déclaration

int str_is_digit(const char *str)
{
    if (!str || !*str) // Gère NULL et chaîne vide
        return 0;

    while (*str)
    {
        if (!char_is_digit(*str))
            return 0;
        str++;
    }
    return 1;
}