/* 4-5 Add access to library functions like sin, exp, and pow. See <math.h>
in Appendix B, Section 4, page 79 */

#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include <math.h>       /* for fmod(), sin(), pow(), exp() */
#include <string.h>     /* for strcmp() */

#define MAXOP   100     /* max size of operand or operator */
#define NUMBER  '0'     /* signal that number was found */
#define WORD    '1'     /* signal that word was found e.g. sin, exp, pow */

int getop(char []);
void push(double);
double pop(void);
void print(void);
void duplicate(void);
void swap(void);
void clear(void);
void handle_word(char []);

/* reverse Polish calculator */
main()
{
    int type;
    double op2;
    char s[MAXOP];
    int skip_newline = 0;

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case WORD:
                handle_word(s);
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
            case 'p':   /* print top */
                print();
                skip_newline = 1;
                break;
            case 'd':   /* duplicate */
                duplicate();
                skip_newline = 1;
                break;
            case 's':   /* swap */
                swap();
                skip_newline = 1;
                break;
            case 'c':   /* clear */
                clear();
                skip_newline = 1;
                break;
            case '\n':
                if (!skip_newline)
                    printf("\t%.8g\n", pop());
                skip_newline = 0;
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

/* print: print the top item of the stack (without popping) */
void print(void)
{
    if (sp > 0)
        printf("top of the stack: \t%.8g\n", val[sp-1]);
    else
        printf("error: stack is empty");
}

/* duplicate: duplicate the top item of the stack */
void duplicate(void)
{
    /* get the top char */
    double dup = pop(); 

    /* replace it, and then add it again */
    push(dup);
    push(dup);
}

/* swap: swap the top two items on the stack */
void swap(void)
{
    double val1 = pop();
    double val2 = pop();

    push(val1);
    push(val2);
}

/* clear: clear the whole stack (note: that we don't actually erase the
items because we do not need to i.e. all references to the stack are 
controlled by sp, we can simply overwrite any old values later on if and 
when we need to */
void clear(void)
{
    sp = 0;    
}

/* handle_word: test the word in s for known operations and execute them */
void handle_word(char s[])
{
    double val1, val2;
    
    /* could place in each if-block if i really wanted to */
    val1 = pop();

    if (!strcmp(s, "sin")) {
        push(sin(val1));
    } else if (!strcmp(s, "exp")) {
        push(exp(val1));
    } else if (!strcmp(s, "pow")) {
        val2 = pop(); /* base */
        push(pow(val2, val1));
    } else {
        printf("error: unknown operation");
        push(val1); /* put val1 back on the stack */
    }
}

#include <ctype.h> /* for isdigit(), isalpha() */

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c, nc;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';
    
    /* process alphas */
    if (isalpha(c)) {
        i = 1;
        /* loop through until the character is no longer alpha */
        while (isalpha(c = getch()))
            s[i++] = c;
        /* add the terminator char */
        s[i] = '\0';

        /* put the last char back as it is non alpha */
        ungetch(c);
        return WORD;
    }
    
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
