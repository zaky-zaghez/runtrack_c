#include <unistd.h>

void print_number(unsigned int n)
{
    if (n >= 10)
        print_number(n / 10);
    char c = n % 10 + '0';
    write(1, &c, 1);
}

unsigned int fibonacci(unsigned int n)
{
    unsigned int a = 0, b = 1, temp;
    
    if (n == 0)
        return a;
    
    for (unsigned int i = 2; i <= n; i++)
    {
        temp = a + b;
        a = b;
        b = temp;
    }
    
    return b;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 0;

    // Convertir l'argument en entier
    unsigned int n = 0;
    char *str = argv[1];
    while (*str >= '0' && *str <= '9')
    {
        n = n * 10 + (*str - '0');
        str++;
    }

    // Calculer et afficher le résultat
    unsigned int result = fibonacci(n);
    print_number(result);
    write(1, "\n", 1);

    return 0;
}