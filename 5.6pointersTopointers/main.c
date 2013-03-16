#include "../head.h"

#define MAXLINES 6

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void myqsort(char *lineptr[], int left, int right);

int main()
{
    int nlines;
	printf("main start\n");
    if((nlines = readlines(lineptr, MAXLINES)) > 0)
    {
        myqsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}

