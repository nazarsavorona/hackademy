
unsigned my_strlen(char *str) {
    unsigned size = 0;

    while(*(str++) != '\0') {
        size++;
    }

    return size;
}