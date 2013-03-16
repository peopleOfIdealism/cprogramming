#include "../head.h"

#define MAXLINE 1000

int mygetline(char *, int);
char *alloc(int);

char *alloc(int n)
{
    char *temp;
    temp = (char *)malloc(n*sizeof(char));
    return temp;
}


int mygetline(char *s, int lim)
{
    int c = 0;
    int i = 0;
    while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if('\n' == c)
    {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

int readlines(char *lineptr[], int maxlines)
{
    int len = 0;
    int nlines = 0;
    char *p = NULL;
    char line[MAXLINE];
    
    while((len = mygetline(line,MAXLINE)) > 0 && nlines <= maxlines )
    {
        if((p = alloc(len)) == NULL)
        {
            return -1;
        }
        else
        {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    int i = 0;
    for(i = 0; i < nlines; i++)
    {
        printf("%s\n", lineptr[i]);
    }
}
    
void myqsort(char *v[], int left, int right)
{
    int i = 0;
    int last = 0;
    void swap(char *v[], int i, int j);
    
    if(left >= right)
    {
        printf("left more than right\n");
        return ;
    }
    
    swap(v, left, (left + right)/2);
    last = left;
    for(i = left + 1; i <= right; i++)
    {
        if(strcmp(v[i], v[left]) < 0)
        {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    myqsort(v, left, last);
    myqsort(v, last+1, right);
}

void swap(char *v[], int i, int j)
{
    printf("i %d, j %d\n", i, j);
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = v[i];
}
    