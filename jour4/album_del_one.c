#include <stdlib.h>
#include <string.h>
#include "album_del_one.h" // si vous avez un fichier header

void album_del_one(album** liste, album target) {
    album* courant = *liste;
    album* precedent = NULL;

    while (courant != NULL) {
        // Comparer le titre et l'année
        if (strcmp(courant->titre, target.titre) == 0 && courant->annee == target.annee) {
            if (precedent == NULL) {
                // Suppression en tête de liste
                *liste = courant->suivant;
            } else {
                // Suppression au milieu ou en fin de liste
                precedent->suivant = courant->suivant;
            }
            free(courant);
            return; // On supprime un seul album
        }

        precedent = courant;
        courant = courant->suivant;
    }
}
