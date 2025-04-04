#include <stdlib.h>

struct album {
    char *title;
    char *artist;
    int year;
};

struct album *realloc_album(struct album *albums, int current_size, int new_size)
{
    struct album *new_albums;
    int copy_size;
    int i;

    // Si la nouvelle taille est 0, libérer et retourner NULL
    if (new_size == 0) {
        free(albums);
        return NULL;
    }

    // Allouer le nouveau tableau
    new_albums = malloc(sizeof(struct album) * new_size);
    if (!new_albums)
        return NULL;

    // Déterminer combien d'éléments copier
    copy_size = (current_size < new_size) ? current_size : new_size;

    // Copier les anciens albums
    for (i = 0; i < copy_size; i++) {
        new_albums[i].title = albums[i].title;
        new_albums[i].artist = albums[i].artist;
        new_albums[i].year = albums[i].year;
    }

    // Libérer l'ancien tableau
    free(albums);

    return new_albums;
}