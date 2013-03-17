#include "../head.h"

int main(void)
{
    int n = 0xF1E5;
    int ret = 0;
    
    ret = getbits(n, 2, 3);
    
    printf("%x\n", ret);
    
    ret = bitcount(n);
    printf("bit count %d\n", ret);
    return 0;
}





/*
void squeeze(char s[], int c);

int main(void)
{
    char c[] = "i can do it";
    printf("%s\n", c);
    squeeze(c, 'c');
    printf("%s\n", c);
return 0;
}*/