#include "../head.h"

#define MAXLINE 1000

int getline(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines)
{
	int len = 0;
	int nlines = 0;

	while((len = getline(line,MAXLINE))>0)
	{
		if(nlines >= maxlines || p = alloc(len) == NULL)
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
		printf("%s\n", lineprt[i]);
	}
}
