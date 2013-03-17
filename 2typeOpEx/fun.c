#include "../head.h"


/*convert s to i*/
int myAtoi(char s[])
{
    int i = 0;
    int n = 0;
    
    for (i = 0; s[i] >= '0'&& s[i] <= '9'; ++i)
    {
        n = n*10 + s[i] - '0';
    }
    return n;
}

/*convert upper to lower*/
int myLower(int c)
{
    if(c >= 'A' && c <= 'z')
    {
        return c + 'a' - 'A';
    }
    return c;
}

/*delete all c from s*/
void squeeze(char s[], int c)
{
    int i = 0;
    int j = 0;
    
    for(; '\0' != s[i]; i++)
    {
        if(c != s[i])
        {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

/*concatenate t to end of s; s must be big enough*/

void myStrcat(char s[], char t[])
{
    int i = 0;
    int j = 0;
    while('\0' != s[i++])/*first find the end of s[]*/
    ;
    while('\0' != (s[i++] = t[j++]))/*copy t to s*/
    ;
}

/*get n bits from position p*/
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n) & ~(~0 << n));
}

/*count 1 bits in x*/
int bitcount(unsigned x)
{
    int b = 0;
    for(b = 0; 0 != x; x>>= 1)
        if(x & 01)
            b++;
    return b;
}











