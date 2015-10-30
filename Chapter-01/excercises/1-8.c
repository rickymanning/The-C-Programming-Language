/* 1-8 Count blanks, tabs and newlines, page 20 */

#include <stdio.h>

/* count whitespace in input */
main()
{
    long c, nb, nt, nl;
    
    nb = 0;
    nt = 0;
    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == ' ')
            ++nb;
        else if (c == '\t')
            ++nt;
        else if (c == '\n')
            ++nl;
    printf("The number of blanks: %d\n", nb);
    printf("The number of tabs: %d\n", nt);
    printf("The number of newlines: %d\n", nl);
}