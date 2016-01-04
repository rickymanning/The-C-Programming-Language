/* 1-20 Write a program detab that replaces tabs in the input with the
proper number of blanks to space to the next tab stop. Assume a fixed set of
tab stops, say every n columns. Should n be a variable or or a symbolic
parameter?, page 34 */

#include <stdio.h>

#define TABSTOP 8   /* the number of spaces per tab stop */

main()
{
    int c, pos, next, i;

    c = next = 0;
    pos = -1;
    while ((c = getchar()) != EOF)
    {
        ++pos;

        switch (c) {
            case '\t' :
                next = TABSTOP - (pos % TABSTOP);
                for (i = 0; i < next; ++i) {
                    putchar(' ');
                }
                pos = -1;
                break;

            case '\n' :
                pos = -1;
                break;

            default :
                putchar(c);
        }
    }

    return 0;
}
