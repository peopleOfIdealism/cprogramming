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

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main()
{
    int nlines = 0;
    if( (nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error\n");
        return 1;
    }
}

#define MAXLEN 10000
int getline(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines)
{
    int len = 0;
    int nlines = 0;
    char *p = NULL;
    char line[MAXLEN];
    
    while((len = getline(line, MAXLEN)) > 0)
    {
        if(nlines >= maxlines || NULL == ( p=alloc(len)))
            return -1;
        else
        {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writelines(char * lineptr[], int nlines)
{
    int i = 0;
    for(i = 0;i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

void writelines(char *lineptr[], int nlines)
{
    while(nlines-- > 0)
        printf("%s\n", *lineptr);
}

void qsort(char *v[], int left, int right)
{
    int i = 0;
    int last = 0;
    void swap(char *v[], int i, int j);
    
    if(left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for(i = left + 1; i <= right; i++)
    {
        if(strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    }
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}
void swap(char *v[], int i,int j)
{
    char *temp = NULL;
    
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


static char daytab[2][13] = {
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
}

int dayofyear (int year, int month, int day)
{
    int i = 0;
    int leap = 0;
    leap = year%4 == 0 && year%100 != 0 ||year%400 == 0；
    for(i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

void monthday(int year, int yearday, int *pmonth, int *pday)
{
    int i = 0;
    int leap = 0;
    leap = year%4 == 0 && year%100 != 0 ||year%400 == 0；
    for(i = 1;yearday > daytab[leap][i]; i++)
        yearday -=daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

char *month_name(int n)
{
    static char *name[] = {
        "ILLEGAL MONTH",
        "JAN","FEB",
    };
    return(n<1||n>12)?name[0]:name[n];
}


P95
int main(int argc, char *argv[])
{
    int i = 0;
    for(i = 1; i < argc; i++)
        printf("%s%s", argv[i], (i < argc - 1)?" ":"");
    printf("\n");
    return 0;
}









