/* 1.5.3 Line counting, page 19 */

#include <stdio.h>

/* count lines in input */
main()
{
    long c, nl;
    
    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);
}