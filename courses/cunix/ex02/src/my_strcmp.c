int my_strcmp(char *str1, char *str2) {
    while(*(str1++) == *(str2++) 
    && *str1 != '\0' && *str2 != '\0') {}

    return *(--str1) - *(--str2);
}