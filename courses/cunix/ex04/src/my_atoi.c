#include <stdbool.h>

int my_atoi(const char *nptr) 
{
    int negative = nptr[0] == '-' ? -1 : 1;

    if (negative == -1) {
        nptr++;
    }

    if (*nptr < '0' || *nptr > '9') {
        return 0;
    }

    int result = *(nptr++) - '0';

    while (*nptr >= '0' && *nptr <= '9')
    {
        result *= 10;
        result += *(nptr++) - '0';
    }

    return result * negative;
}