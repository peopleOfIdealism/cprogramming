#include "../head.h"

int main(void)
{
    int fah = 1;
    int cel = 0;
    
    printf("%5d%5d\n", fah, 5*(fah - 32)/9);
    for(fah = 20; fah <= 300; fah+=20)
    {
        cel = 500*(fah -32)/9;
        printf("%5d%10.2f\n", fah, ((float)cel/100));
    }
    
    return 0;
}