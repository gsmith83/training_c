#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define MAXVAL 100
#define NUMBER '0'  // signal that a number was found
#define BUFSIZE 100

int getop(char[]);
void push(double);
double pop(void);

// reverse Polish calculator
int main(int argc, char * argv[])
{
    int type, sign;
    double op2;
    char s[MAXOP];

    sign = 1;

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s) * sign);
            sign = 1;
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();        // force order of op
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("ERROR: divide by zero\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push((int)pop() % (int)op2);
            else
                printf("ERROR: modulus by zero\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("ERROR: unknown command\n");
            break;
        }
    }
    return 0;
}

// external variables for push and pop
int sp = 0;         // next free stack position
double val[MAXVAL]; // stack

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("ERROR: stack full\n");
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
        printf("ERROR: stack empty\n");
    
    return 0.0;
}

// external functions for getop
int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i, c, next;

    // build the string while skipping spaces and tabs
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-') // deal with unary minus here
        return c;

    if (c == '-')
    {
        next = getch();
        if (!isdigit(next) && next != '.')
        {
            return c;
        }
        c = next;
    }
    else
        c = getch();

    i = 0;

    while (isdigit(s[++i] = c))
        c = getch();
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;


    s[i] = '\0';

    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

// external variables for getch and ungetch
char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) // push char back on input
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
