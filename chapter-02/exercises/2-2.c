/* 2-2 Write a loop equivalent to the for loop above [below] without using
&& or ||.

    i<lim-1 && (c = getchar()) != '\n' && c != EOF

page 42 */

#include <stdio.h>

#define MAXLINE 1000    /* maximum input line size */

main()
{
    int i, lim, c;

    i = c = 0;
    lim = MAXLINE;

    while (i < lim-1) {
        c = getchar();
        if (c == '\n')
            lim = 0;
        else if (c == EOF)
            lim = 0;
        else {
            // do whatever needs to be done (including incrementing i)
            printf("%c",c);
            ++i;
        }
    }

    printf("\n");

    return 0;
}
