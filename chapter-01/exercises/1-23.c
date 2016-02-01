/* 1-23 Write a program to remove all comments from a C program. Don't
forget to handle quoted strings and character constants properly. C comments
do not nest, page 34 */

#include <stdio.h>

#define MAXLINE 1000    /* maximum input line size */

int getline(char line[], int maxline);

main()
{
    int len, i, multi;
    char line[MAXLINE];

    len = multi = 0;

    // loop through the input line-by-line (and then char-by-char within it)
    // outputting each char that does not belong to a comment
    while ((len = getline(line, MAXLINE)) > 0) {
        for (i = 0; i < len; ++i) {
            // if we're in the middle of a multi-line comment then ignore the
            // input until we come across a comment delimiter (*/)
            if (multi > 0) {
                if (i > 0) {
                    if ((line[i-1] == '*') && (line[i] == '/')) {
                        multi = 0;
                    }
                }
                continue;
            }

            // if we're here we can't be IN a multi-line comment, so check
            // if we're at the beginning of a comment: single-line or
            // multi-line
            if (i < (len - 2)) {
                if (line[i] == '/') {
                    if (line[i+1] == '/') {
                        // single-line comment. forget about the rest of the
                        // line
                        break;
                    } else if (line[i+1] == '*') {
                        // multi-line comment. mark the multi-line comment
                        // flag and contine until the next char, where we
                        // ignore each char until we find a delimiter (*/)
                        ++multi;
                        continue;
                    }
                }
            }

            // if we get here then we're not in the middle of a comment, so
            // output the current character.
            putchar(line[i]);
        }
    }
    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i<lim-1 && (c=getchar()) !=EOF && c!='\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
