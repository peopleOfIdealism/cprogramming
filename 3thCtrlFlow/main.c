#include "../head.h"

int main(void)
{
    int v[7]= {7,9,3,4,2,6,7};
    int i = 0;
    for(; i < 7;i++)
    {
        printf("%5d%5d\n", i, v[i]);
    }
    shellsort(v, 7);
    for(i = 0; i < 7;i++)
    {
        printf("%5d%5d\n", i, v[i]);
    }
    return 0;
}