char *my_strcpy(char *dest, const char *src)
{
    const char *current_src = src;
    char *current_dest = dest;
    
    while (*current_src != '\0')
    {
        *(current_dest++) = *(current_src++);
    }

    *(current_dest++) = '\0';

    return dest;
}