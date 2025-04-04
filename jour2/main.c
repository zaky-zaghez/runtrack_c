#include <stdlib.h>
#include <unistd.h>

void str_tolower(char *str);

int main(int argc, char **argv)
{
    if (argc < 2)
        return 0;

    for (int i = 1; i < argc; i++) {
        // Convertir en minuscules
        str_tolower(argv[i]);
        
        // Écrire la chaîne
        int len = 0;
        while (argv[i][len])
            len++;
        
        write(1, argv[i], len);
        write(1, "\n", 1);
    }

    return 0;
}

#include <stdlib.h>
#include <unistd.h>

char *strtrim(char *str);
void sort_strings(char **array, int size);

int main(int argc, char **argv)
{
    if (argc < 2) {
        write(1, "\n", 1);
        return 0;
    }

    // Allouer et trimmer les chaînes
    char **trimmed = malloc((argc - 1) * sizeof(char *));
    if (!trimmed) return 1;

    int count = 0;
    for (int i = 1; i < argc; i++) {
        trimmed[count] = strtrim(argv[i]);
        if (trimmed[count] && trimmed[count][0] != '\0')
            count++;
    }

    // Trier les chaînes
    sort_strings(trimmed, count);

    // Afficher le résultat
    for (int i = 0; i < count; i++) {
        int len = 0;
        while (trimmed[i][len]) len++;
        
        write(1, trimmed[i], len);
        if (i < count - 1)
            write(1, " ", 1);
        
        free(trimmed[i]);
    }
    write(1, "\n", 1);

    free(trimmed);
    return 0;
}