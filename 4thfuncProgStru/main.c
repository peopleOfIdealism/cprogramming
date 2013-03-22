#include "../head.h"

#define MAXLINE 1000

int mygetline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main(void)
{
    char line[MAXLINE];
    int found = 0;
    int countline = 0;
    
    while(mygetline(line, MAXLINE) >0)
    {
        if(strindex(line, pattern) >= 0)
        {
            printf("got it %s", line);
            found++;
        }
        printf("line number is %d\n", countline++);
    }
    
    printf("end of main fount %d\n", found);
    return 0;
}