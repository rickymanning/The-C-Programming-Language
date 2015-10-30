/* 1-10 Output the input, replacing tabs, backspaces and backslashes, page 20 */

#include <stdio.h>

/* output the input, but replace all tabs with \t, each backspace with \b and each backslash with \\ */
main()
{
    int c;
    
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("\\t");
        }
        else if (c == '\b') {
            printf("\\b");
        }
        else if (c == '\\') {
            printf("\\\\");
        }
        else {
            putchar(c);
        }
    }
}