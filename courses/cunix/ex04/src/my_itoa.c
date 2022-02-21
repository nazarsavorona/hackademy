#include <stdlib.h>

char* my_itoa(int nmb) 
{
    int count = nmb <= 0 ? 1 : 0;
    int temp = nmb;

    while (temp != 0) {
        temp /= 10;
        count++;
    }

    char* str = (char*) malloc(count + 1);
    str[count] = '\0';
    
    if (nmb < 0) {
        str[0] = '-';
        nmb *= -1;
    }

    temp = nmb;
    do {
        str[--count] = temp % 10 + '0';
        temp /= 10;
    } while (temp != 0);

    return str;
}