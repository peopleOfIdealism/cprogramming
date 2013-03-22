#include "../head.h"

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    long lineno = 0;
    int c = 0;
    int except = 0;
    int number = 0;
    int found = 0;
    
    while(--argc > 0 && ('-' == (*++argv)[0]))
        while(c = *++argv[0])
        switch(c)
        {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("find: illegal option %c\n", c);
                argc = 0;
                found = -1;
                break;
        }
    if(1 != argc)
        printf("Usage: find -x -n pattern\n");
    else
        while(getline(line, MAXLINE) > 0)
        {
            lineno++;
            if(except != (strstr(line, *argv) != NULL))
                if(number)
                    printf("%ld:", lineno);
                printf("%s", line);
                found++;
        }
    return found;
}