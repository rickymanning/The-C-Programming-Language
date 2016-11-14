/* 4-3 Given the basic framework, it's straightforward to extend the
calculator. Add the modulus (%) operator and provisions for negative 
numbers, page 79 */

#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include <math.h>       /* for fmod() */

#define MAXOP   100     /* max size of operand or operator */
#define NUMBER  '0'     /* signal that number was found */

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator */
main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
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
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0) 
                     /* % operator not valid with doubles, use fmod() */
                     push(fmod(pop(), op2)); 
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

#define MAXVAL  100     /* maximum length of val stack */

int sp = 0;             /* next free stack position */
double val[MAXVAL];     /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
        printf("error: stack empty\n");
        return 0.0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c, nc;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c; /* not a number */
    
    /* we have found either a digit, a . or a - */
    i = 0;

    /* if the current char is '-' then we might be working with a number. 
    Confirm this by getting the next char. If it is a digit or a decimal 
    point, then we can assume that it is a number. In this case add the char
    to the array and carry on. If it isn't a digit then put the next char 
    back on the stack and drop out, returning the current char. */
    if (c == '-') {
        /* get the next char and drop out if not a digit or period */
        if (!isdigit(nc = getch()) && nc != '.') {
            ungetch(nc);
            return c;
        }
        /* must be a digit or a '.', so continue. the '-' should be in s[0] 
        already, so save the next char in s[1] and also treat it as the 
        current char from now on */
        s[++i] = c = nc;
    }
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

/* getch: get a (possibly push back) character */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters");
    else
        buf[bufp++] = c;
}

