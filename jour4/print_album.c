#include <unistd.h>

struct album {
    char *title;
    char *artist;
    int year;
};

void print_string(const char *str)
{
    while (*str)
        write(1, str++, 1);
}

void print_number(int n)
{
    if (n >= 10)
        print_number(n / 10);
    char c = n % 10 + '0';
    write(1, &c, 1);
}

void print_album(struct album *album)
{
    write(1, "\"", 1);
    print_string(album->title);
    write(1, "\" by \"", 6);
    print_string(album->artist);
    write(1, "\" released in ", 14);
    print_number(album->year);
    write(1, ".\n", 2);
}