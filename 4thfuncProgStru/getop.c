#include "../head.h"

int getch(void);
void ungetch(int);

/*getop: get next character or numeric operand*/
int getop(char s[])
{
    int i = 0;
    int c = 0;
    while( ' ' == (s[0] = c = getch()) || '\t' == c)
        ;
    s[1] = '\0';
    if(isdigit(c) && '.' != c)
        return c;
    i = 0;
    if(isdigit(c))
        while(isdigit(s[++i] = c =getch()))
            ;
    if('.' == c)
        while(isdigit(s[++i] = c =getch()))
            ;
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}

