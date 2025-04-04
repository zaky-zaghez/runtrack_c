void func_to_array(char **array, void (*func)(char *))
{
    if (array == NULL || func == NULL)
        return;
        
    for (int i = 0; array[i] != NULL; i++) {
        func(array[i]);
    }
}