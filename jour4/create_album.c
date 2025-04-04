#include <stdlib.h>
#include <string.h>

struct album {
    char *title;
    char *artist;
    int year;
    struct album *next;
};

struct album *create_album(const char *title, const char *artist, int year)
{
    struct album *new_album = malloc(sizeof(struct album));
    if (!new_album)
        return NULL;

    new_album->title = strdup(title);
    new_album->artist = strdup(artist);
    if (!new_album->title || !new_album->artist) {
        free(new_album->title);
        free(new_album->artist);
        free(new_album);
        return NULL;
    }

    new_album->year = year;
    new_album->next = NULL;

    return new_album;
}