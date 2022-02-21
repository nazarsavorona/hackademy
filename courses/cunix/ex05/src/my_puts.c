#include <unistd.h>
#include <string.h>

int my_puts(const char *s) 
{
    write(STDOUT_FILENO, s, strlen(s));
    write(STDOUT_FILENO, "\n", 1);
    return 0;
}