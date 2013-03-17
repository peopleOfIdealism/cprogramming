#include "../head.h"

#define MAXLINE 1000
int myGetline(void);
void myCopy(void);

char line[MAXLINE] = {0};
char longest[MAXLINE] = {0};
    int max = 0;
int main(void)
{
    int len = 0;


    
    while((len = myGetline()) > 0)
    {
        if(len > max)
        {
            max = len;
            myCopy();
        }
    }
    if(max > 0)
        printf("%s", longest);
    
    return 0;
}

int myGetline(void)
{
    int c = 0;
    int i =0;
    
    for(i = 0; i < MAXLINE-1 && EOF != (c = getchar()) && c != '\n'; ++i)
        line[i] = c;
    if('\n' == c)
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void myCopy(void)
{
    int i = 0;
    while('\0' != (longest[i] = line[i]))
    {
        ++i;
    }
}