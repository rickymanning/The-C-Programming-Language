/* 1.5.1 File Copying, page 16 */

#include <stdio.h>

/* copy input to output; 1st version */
main()
{
    int c;
    
    c = getchar();
    while(c != EOF) {
        putchar(c);
        c = getchar();
    }
}