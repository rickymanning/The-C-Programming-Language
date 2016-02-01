/* 1-22 Write a program to "fold" long input lines into two or more shorter
lines after the last non-blank character that occurs before the n-th column
of input. Make sure your program does something intelligent with very long
lines, and if there are no blanks or tabs before the specified column, page
34 */

#include <stdio.h>

#define MAXLINE 80  /* maximum input line size */

int getword(char word[], int maxline);

main()
{
    int len, pos;
    char word[MAXLINE];

    // set inital values for the variables that we use
    len = pos = 0;

    // get the input one word at a time. a word here is defined as a group
    // of non-whitespace characters that are teminated by a whitespace
    // character or an EOF character.
    // e.g.
    // the input "mary had a little lamb" could be said to contain the
    // following words: "mary ", "had ", "a ", "little " and "lamb".
    while ((len = getword(word, MAXLINE)) > 0) {
        // if the word would extend beyond the line limit then we need to
        // fold it by printing a newline
        if ((pos = pos + len) > MAXLINE) {
            putchar('\n');
            pos = len;
        }
        printf("%s", word);
    }

    return 0;
}

/* getword: read a word into w, return length, borrowed from getline */
int getword(char w[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF; ++i) {
        w[i] = c;
        if (c == ' ' || c == '\t' || c == '\n') {
            ++i;
            break;
        }
    }
    w[i] = '\0';
    return i;
}
