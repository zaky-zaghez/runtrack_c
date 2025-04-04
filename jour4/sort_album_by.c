#include "sort_album_by.h" // si un header est défini

void sort_album_by(album** liste, int (*compare)(album*, album*)) {
    if (liste == 0 || *liste == 0) return;

    int trie;
    album* p;
    album tmp;

    do {
        trie = 1;
        p = *liste;

        while (p->suivant != 0) {
            if (compare(p, p->suivant) > 0) {
                // Échanger les contenus de p et p->suivant
                tmp = *p;
                *p = *(p->suivant);
                *(p->suivant) = tmp;

                // Restaurer les bons pointeurs
                album* tmp_suivant = p->suivant->suivant;
                p->suivant->suivant = p;
                album temp_ptr = *p;
                *p = *(p->suivant);
                *(p->suivant) = temp_ptr;
                p->suivant = tmp_suivant;

                trie = 0;
            }
            p = p->suivant;
        }
    } while (!trie);
}
