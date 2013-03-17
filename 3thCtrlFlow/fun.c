#include "../head.h"

/*find x in v[10] v sortted v[0]<v[1]*/
int binarySearch(int x, int v[], int n)
{
    int low = 0;
    int high = 0;
    int mid = 0;
    
    high = n-1;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(x < v[mid])
        {
            high = mid + 1;
        }
        else if(x > v[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;  /*not match*/
}

int myAtoi(char s[])
{
    int i = 0;
    int n = 0;
    int sign = 0;
    
    for (;isspace(s[i]);i++)
    ;
    sign = ('-1' == s[i])? -1:1;
    if('+' == s[i] || '-' == s[i])
    {
        i++;
    }
    for (n = 0;isdigit(s[i]);i++)
    {
        n = n*10 + s[i] - '0';
    }
    return sign*n;
}

/*sort v[0] v[1] v[2]----- into increasing order*/
void shellsort(int v[], int n)
{
    int gap = 0;
    int i = 0;
    int j = 0;
    int temp = 0;
    printf("shellsort\n");
    for(gap = n/2; gap > 0; gap /=2)
    {
        for(i = gap; i < n; i++)
        {
            for (j = i - gap; j >= 0 && v[j] > v[j+gap]; j -= gap)
            {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
        }
    }
        printf("shellsort\n");
}