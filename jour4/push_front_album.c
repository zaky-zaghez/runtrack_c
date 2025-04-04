#include "push_front_album.h"  // On suppose qu'il existe un header correspondant

void push_front_album(album** liste, album new_album) {
    // Allouer dynamiquement un nouvel élément
    album* nouvel_album = (album*)malloc(sizeof(album));
    if (nouvel_album == 0) {
        // Erreur d'allocation mémoire, on peut faire un return ou autre traitement d'erreur
        return;
    }

    // Copier le contenu de l'album passé en paramètre
    *nouvel_album = new_album;

    // Insérer au début de la liste
    nouvel_album->suivant = *liste;
    *liste = nouvel_album;
}
