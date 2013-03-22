#include "../head.h"

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int found = 0;
    
    if(argc != 2)
        printf("Usage: find pattern\n");
    else
        while(getline(line, MAXLINE) > 0)
        {
            if(NULL != strstr(line, argv[1]))
            {
                printf("%s", line);
                found++;
            }
        }
    return found;
}
