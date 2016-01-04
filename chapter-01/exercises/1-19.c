/* 1-19 Write a program to remove trailing blanks and tabs from each line of
input, and to delete entirely blank lines, page 31 */

#include <stdio.h>

#define MAXLINE 1000    /* maximum input line size */

int getline(char line[], int maxline);
void reverse(char line[]);

/* print longest input line */
main()
{
    char line[MAXLINE];     /* current input line */

    while (getline(line, MAXLINE) > 0) {
        reverse(line);
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

/* reverse: reverses a char array s */
void reverse(char s[])
{
    int i, len;
    char buffer;

    i = 0;
    while (s[i] != '\n' && s[i] != '\0')
        ++i;

    len = i - 1;

    for (i = 0; i <= (len / 2); ++i) {
        buffer = s[i];
        s[i] = s[len-i];
        s[len-i] = buffer;
    }
}
