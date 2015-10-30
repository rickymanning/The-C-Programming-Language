/* 1.5.1 File Copying improved, page 17 */

#include <stdio.h>

/* copy input to output; 2nd version */
main()
{
    int c;
    
    while ((c = getchar()) != EOF)
        putchar(c);
}