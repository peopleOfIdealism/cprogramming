#include "../head.h"

int test(int i)
{
    printf("i %d\n", i);
    return 0;
}

int main()
{
    int i = 0;
    printf("i %d\n", i);
    
    test(i);
    
    printf(" i++:i %d\n", i);
    
    test(i++);
    i = 0;
    printf("++i:i %d\n", i);
    
    test(++i);
    return 0;
}