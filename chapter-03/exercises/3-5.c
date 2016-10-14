/* 3-5 Write the function itob(n,s,b) that converts the integer n into a 
base b character representation in the string s. In particular, 
itob(n,s,16) formats n as a hexadecimal integer in s, page 64 */

#include<stdio.h>
#include<string.h>
#include<limits.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

#define MIN_BASE    2   /* e.g. we can't to base 0 or 1 */
#define MAX_BASE    36  /* the num different chars e.g 0-9A-Z */

main()
{
    int i, j;
    char s[100];
    int val[5] = { INT_MIN, -5, 0, 5, INT_MAX };
    
    for (i = 0; i < 5; ++i) {
        for (j = 2; j < MAX_BASE; ++j) {
            /* Call itob and print results */
            itob(val[i], s, j);
            printf("%d in base %d is \"%s\"\n", val[i], j, s);
        }
        printf("\n");
    }
}

/* itob:  covert n to base b chars in s */
void itob(int n, char s[], int b)
{
    int i, sign;
    
    sign = n;
    i = 0;
    do {                    /* Generate symbols in reverse order */
        int abs = n % b;    /* Get the next digit */
        if (abs < 0)        /* Ensure abs really is absolute. of course, */
            abs = -abs;     /* the standard library version of abs is */
                            /* probably better */         
        
        if (abs > 9)        /* Use chars A-Z */
            s[i++] = (abs - 10) + 'A';
        else                /* Use chars 0-9 */
            s[i++] = abs + '0';

    } while (n /= b);       /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
