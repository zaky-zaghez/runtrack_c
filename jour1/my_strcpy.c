char *my_strcpy(char *dest, const char *src)
{
    char *original_dest = dest; // Sauvegarde de l'adresse de départ
    
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; // Ajout du terminateur nul
    
    return original_dest;
}