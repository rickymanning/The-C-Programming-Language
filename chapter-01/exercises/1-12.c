/* 1.12 Write a program that prints its input one word per line */

#include <stdio.h>

/* print words from input, one per line */
main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t')
            c = '\n';
        putchar(c);
    }
}
