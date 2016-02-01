/* 1-21 Write a program entab that replaces strings of blanks by the
minimum number of tabs and blanks to achieve the same spacing. Use the same
tab stops as for detab. When either a tab or a single blank would suffice to
reach a tab stop, which should be given precedence?, page 34 */

#include <stdio.h>

#define TABSTOP 8   /* the number of spaces per tab stop */

main()
{
    int c, pos, spaces, i;
    c = spaces = pos = 0;

    while((c = getchar()) != EOF) {
        ++pos;

        if (c == ' ') {
            // found a space. increment the space counter and if we are at a
            // tabstop then output a tab and reset the spaces and
            ++spaces;
            if (pos == TABSTOP) {
                putchar('\t');
                pos = spaces = 0;
            }
            continue;
        }

        // check for tab. if we get to a tab then print it out, forget about
        // any previous spaces and reset the position back to 0
        if (c == '\t') {
            putchar('\t');
            pos = spaces = 0;
            continue;
        }

        // check for new line. print any left over spaces before printing
        // the new line. reset both spaces and the position
        // any previous spaces and reset the position back to 0
        if (c == '\n') {
            putchar(c);
            pos = spaces = 0;
            continue;
        }

        // anything else print as it is. print any left over spaces first
        // and reset the position if we have reached a tabstop
        for (i = 0; i < spaces; ++i) {
            putchar(' ');
        }
        spaces = 0;
        putchar(c);

        if (pos == TABSTOP) {
            pos =  0;
        }
    }

    return 0;
}
