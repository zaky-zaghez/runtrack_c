#include <unistd.h>

void print_number(int n)
{
    char c;
    if (n >= 10)
        print_number(n / 10);
    c = n % 10 + '0';
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 0;

    int n = 0;
    char *str = argv[1];
    
    // Conversion de la chaîne en entier
    while (*str >= '0' && *str <= '9')
    {
        n = n * 10 + (*str - '0');
        str++;
    }

    // Calcul de la factorielle
    int result = 1;
    for (int i = 1; i <= n; i++)
        result *= i;

    // Affichage du résultat
    print_number(result);
    write(1, "\n", 1);

    return 0;
}