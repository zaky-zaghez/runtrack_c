struct album {
    char *title;
    char *artist;
    int year;
    struct album *next;
};

void push_back_album(struct album **list, struct album *new_album)
{
    // Si la liste est vide, le nouvel album devient la tête de liste
    if (*list == NULL) {
        *list = new_album;
        return;
    }

    // Sinon, parcourir jusqu'au dernier élément
    struct album *current = *list;
    while (current->next != NULL) {
        current = current->next;
    }

    // Ajouter le nouvel album à la fin
    current->next = new_album;
}