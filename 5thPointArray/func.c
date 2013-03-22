#include "../head.h"

int getch(void);
void ungetch(int );

/*getint: get next integer from input into *pn*/
int getint(int *pn)
{
    int c = 0;
    int sign = 0;
    while(isspace(c = getch()))
        ;
    if(!isdigit(c) && EOF != c && '+' != c && '-' != c)
    {
        ungetch(c);
        return 0;
    }
    sign = (c == '-')?-1:1;
    
    if('+' == c || '-' == c)
        c =getch();
    for(*pn = 0; isdigit(c), c=getch())
        *pn = 10 * *pn +(c - '0');
    *pn *= sign;
    if(EOF != c)
        ungetch(c);
    return c;
}

/*strlen: return length of string s*/
int strlen(char *s)
{
    int n = 0;
    
    for(n = 0; '\0' != *s, s++)
        n++;
    return n;
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
    if(allocbuf + ALLOCSIZE - allocp >= n)
        allocp + = n;
        return allocp -n;
    else
        return 0;
}

void afree(char *p)
{
    if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

/*strlen: return length of string s*/
int strlen(char *s)
{
    char *p = s;
    
    while('\0' != *p)
        p++;
    return p - s;
}

/*strcpy : copy t to s, array subscript version*/
void strcpy(char *s, char *t)
{
    int i = 0;
    
    while('\0' != (s[i] = t[i]))
        i++;
}

void strcpy(char *s, char *t)
{
    int i = 0;
    while('\0' != (*s = *t))
    {
        s++;
        t++;
    }
}

void strcpy(char *s, char *t)
{
    while('\0' != (*s++ = *t++))
        ;
}

void strcpy(char *s, char *t)
{
    while(*s++ = *t++)
        ;
}

/*strcmp : return < 0 if s<t, 0 if s==t , >0 if s>t*/
int strcmp(char *s, char *t)
{
    int i = 0;
    for(i = 0; s[i] == t[i]; i++)
    {
        if('\0' == s[i])
            return 0;
    }
    return s[i] - t[i];
}
int strcmp(char *s, char *t)
{
    for(; *s == *t; s++, t++)
    {
        if('\0' == *s)
            return 0;
    }
    return *s - *t;
}













