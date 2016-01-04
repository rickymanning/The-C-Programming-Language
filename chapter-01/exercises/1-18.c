/* 1-18 Write a program to remove trailing blanks and tabs from each line of
input, and to delete entirely blank lines, page 31 */

#include <stdio.h>

#define MAXLINE 1000    /* maximum input line size */

int getline(char line[], int maxline);
void trimright(char line[], int length);

/* print longest input line */
main()
{
    int len;                /* current line length */
    char line[MAXLINE];     /* current input line */

    while ((len = getline(line, MAXLINE)) > 0) {
        trimright(line, len);
        if (line[0] != '\0')
            printf("%s\n", line);
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

/* trimright: trims trailing blanks, tabs and newline chars */
void trimright(char s[], int len)
{
    int i = len - 1;
    while(i >= 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')) {
        s[i] = '\0';
        i--;
    }
}
