#include <stdlib.h>

int is_whitespace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f');
}

int count_words(const char *str)
{
    int count = 0;
    int in_word = 0;

    while (*str)
    {
        if (is_whitespace(*str))
        {
            in_word = 0;
        }
        else if (!in_word)
        {
            in_word = 1;
            count++;
        }
        str++;
    }
    return count;
}

char **split(const char *str)
{
    if (!str) return NULL;

    int word_count = count_words(str);
    char **result = malloc((word_count + 1) * sizeof(char *));
    if (!result) return NULL;

    int word_index = 0;
    const char *word_start = str;
    int in_word = 0;

    while (*str)
    {
        if (is_whitespace(*str))
        {
            if (in_word)
            {
                int word_len = str - word_start;
                result[word_index] = malloc(word_len + 1);
                if (!result[word_index])
                {
                    // Libération mémoire en cas d'erreur
                    for (int i = 0; i < word_index; i++)
                        free(result[i]);
                    free(result);
                    return NULL;
                }

                for (int i = 0; i < word_len; i++)
                    result[word_index][i] = word_start[i];
                result[word_index][word_len] = '\0';
                word_index++;
                in_word = 0;
            }
        }
        else if (!in_word)
        {
            word_start = str;
            in_word = 1;
        }
        str++;
    }

    // Gestion du dernier mot
    if (in_word)
    {
        int word_len = str - word_start;
        result[word_index] = malloc(word_len + 1);
        if (!result[word_index])
        {
            for (int i = 0; i < word_index; i++)
                free(result[i]);
            free(result);
            return NULL;
        }

        for (int i = 0; i < word_len; i++)
            result[word_index][i] = word_start[i];
        result[word_index][word_len] = '\0';
        word_index++;
    }

    result[word_index] = NULL;
    return result;
}