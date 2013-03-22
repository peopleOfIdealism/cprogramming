#include "../head.h"

#define MAXLINE 1000

int mygetline(char s[], int lim)
{
    int c = 0;
    int i = 0;
    
    while(--lim > 0 && EOF != (c = getchar()) && '\n' != c)
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

/*strindex: return index of t in s, -1 if none*/
int strindex(char s[], char t[])
{
    int i = 0;
    int j = 0;
    int k = 0;
    for(i = 0; '\0' != s[i]; i++)
    {
        for(j = i, k = 0; '\0' != t[k] && t[k] == s[j]; j++, k++)
        ;
        if(k > 0 && '\0' == t[k])
        return i;
    }
    return -1;
}

/*atof: convert string s to double*/
double atof(char s[])
{
    double val = 0.0;
    double power = 0.0;
    
    int i = 0;
    int sign = 0;
    
    for(i = 0; isspace(s[i]); i++)/*skip white space for beginning*/
        ;
        
    sign = ( '-' == s[i])?-1:1;
    if('+' == s[i] && '-' == s[i])
    {
        i++;
    }
    for(; isdigit(s[i]); i++)
    {
        val = 10.0 *val + (s[i] - '0');
    }
    if('.' == s[i])
        i++;
    for(power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0*val + (s[i] - '0');
        power *= 10;
    }
    return sign*val/power;
}

/*atoi: convert string s to integer using atof*/

int atoi(char s[])
{
    double atof(char s[]);
    return (int) atof(s);
}
























