#include "../head.h"

#define IN 1
#define OUT 0

int main(void)
{
    int c = 0;
    int nl = 0;
    int nw = 0;
    int state = 0;
    int nc = 0;
    
    state = OUT;
    while(EOF != (c = getchar()))
    {
        ++nc;
        if('\n' == c)
            ++nl;
        if(' ' == c || '\n' == c || '\t' == c)
        {/*连续空格被吸收到这里了*/
            state = OUT;
        }
        else if(OUT == state)
        {
            state = IN;
            ++nw;
        }
    }
    printf("line %d word %d char %d \n", nl, nw, nc);
}