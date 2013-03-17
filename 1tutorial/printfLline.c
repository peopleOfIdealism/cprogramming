#include "../head.h"

#define MAXLINE 1000
int myGetline(char line[], int maxline);
void myCopy(char to[], char from[]);

int main(void)
{
    int len = 0;
    int max = 0;
    char line[MAXLINE] = {0};
    char longest[MAXLINE] = {0};
    
    while((len = myGetline(line,MAXLINE)) > 0)
    {
        if(len > max)
        {
            max = len;
            myCopy(longest, line);
        }
    }
    if(max > 0)
        printf("%s", longest);
    
    return 0;
}

int myGetline(char s[], int lim)
{
    int c = 0;
    int i =0;
    
    for(i = 0; i < lim-1 && EOF != (c = getchar()) && c != '\n'; ++i)
        s[i] = c;
    if('\n' == c)
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void myCopy(char to[], char from[])
{
    int i = 0;
    while('\0' != (to[i] = from[i]))
    {
        ++i;
    }
}