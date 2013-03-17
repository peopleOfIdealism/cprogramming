#include "../head.h"

int main(void)
{
    int c = 0;
    int i = 0;
    int nwhite = 0;
    int nother = 0;
    
    int ndigit[10] = {0};
    
    while(EOF != (c = getchar()))
    {
        if(c >= '0' && c <= '9')
        {
            ++ndigit[c - '0'];
        }
        else if(' ' == c || '\t' == c || '\n' == c)
        {
            ++nwhite;
        }
        else
        {
            ++nother;
        }
    }
    printf("digit = ");
    for(i = 0; i < 10; ++i)
    {
        printf(" %d", ndigit[i]);
    }
    printf(", while space = %d, other = %d\n", nwhite, nother);
}