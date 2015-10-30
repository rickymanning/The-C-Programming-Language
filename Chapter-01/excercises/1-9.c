/* 1-9 Output the input, replacing all blanks for single blanks, page 20 */

#include <stdio.h>

/* output the input, but replace all double blanks with a single blank */
main()
{
    int c, previous;
    
    previous = EOF;
    while ((c = getchar()) != EOF) {
        if (!(previous == ' ' && c == ' ')) 
            putchar(c);
        previous = c;
    }
}