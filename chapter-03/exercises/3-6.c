/* Write a version of itoa that accepts three arguments instead of two. The
third argument is a minimum field width; the converted number must be padded
with blanks on the left if necessary to make it wide enough, page 64  */

#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[], int p);
void reverse(char s[]);

main()
{
    int i;
    char a[100];
    int val[] = { 
        INT_MIN, -8888888, -123456,
        -5, 0, 5, 123, 1234, INT_MAX 
    };
    for (i = 0; i < 9; ++i) {
        /* Call itoa and print results */
        itoa(val[i], a, 8);
        printf("%d is\n\"%s\"\n\n", val[i], a);
    }
}

/*itoa: convert n to characters in s */
void itoa(int n, char s[], int p)
{
    int i, sign;
    
    sign = n;
    i = 0;
    do {                    /* Generate digits in reverse order */
        int abs = n % 10;   /* Get next digit */
        if (abs < 0)        /* Ensure abs really is absolute. of course, */
            abs = -abs;     /* the standard library version of abs is */
                            /* probably better */ 
        s[i++] = abs + '0';      
    } while (n /= 10);    /* delete it */
    
    if (sign < 0)
        s[i++] = '-';
    
    while (i < p)
        s[i++] = ' ';
    
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
