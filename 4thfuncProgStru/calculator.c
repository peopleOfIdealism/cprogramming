#include "../head.h"

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

/*reverse Polish calculator*/
int main()
{
    int type = 0;
    double op2 = 0.0;
    char s[MAXOP];
    
    while(EOF != (type = getop(s)))
    {
        switch(type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if( 0.0 != op2 )
                    push(pop()/op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error:unknow command %s\n", s);
                break;
        }
        
    }
    return 0;
}

