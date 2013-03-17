#include "../head.h"

int main()
{
    char c = '\0';
    int count = 0;
    
    while(EOF != (c = getchar()))
    {
        printf("count %d\n", count++);
        putchar(c);
    }
}