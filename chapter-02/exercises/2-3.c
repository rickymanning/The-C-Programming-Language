/* 2-3 Write the function htoi(s), which converts a string of hexadecimal
digits (including an optional 0x or 0X) into its equivalent integer value.
The allowable digits are 0 through 9, a through f and A through F,
page 42 */

#include <stdio.h>

#define MAXLINE 1000    /* maximum input line size */

int htoi(char s[]);

main()
{
    char s[MAXLINE+1];
    int i, c, val;

    i = c = val = 0;

    // loop through the whole input until either we've read too many
    // characters or we find a new line character
    for (i = 0; i < MAXLINE && (c = getchar()) != '\n'; ++i)
        s[i] = c;

    // ensure that we terminate the char array
    s[i+1] = '\0';

    // convert the char array to its hex to integer equivalent
    val = htoi(s);

    // print the result, assuming the conversion was successful
    if (val > 0) {
        printf("The value of [%s] is [%d]\n", s, val);
    }

    return 0;
}

/* htoi: receives a hex number and converts it to an integer, returning 0 if
the conversion is not possible */
int htoi(char s[])
{
    int i, c, tot;

    i = c = tot = 0;

    // loop through the array, handling char-by-char
    while ((c = s[i]) != '\0') {
        // we are reading from left-to-right as opposed to right-to-left, so
        // with each iteration we need multiply our working calculation by
        // 16 (e.g. the base)
        tot *= 16;

        // determine whether or not there is an 0x or 0X prefix, dropping
        // outand printing an error message if we find a 0 followed by
        // anything other than x or X.
        if (i == 0 && c == '0') {
            c = s[++i];
            if (c != 'x' && s[i] != 'X') {
                printf("Incorrect character ['%c'] found in second index of [%s]. Expecting ['x'] or ['X']\n", c, s);
                return 0;
            }
        } else if ('0' <= c && c <= '9') {
            // matched [0-9], so add it to the total
            tot += c - '0';
        } else if ('a' <= c && c <= 'f') {
            // matched [a-f], so calculate it's value and add to the total
            tot += 10 + (c - 'a');
        } else if ('A' <= c && c <= 'F') {
            // matched [A-F], so calculate it's value and add to the total
            tot += 10 + (c - 'A');
        } else {
            // found an invalid char. print error message and return 0
            printf("Incorrect character ['%c'] found in index [%d] of [%s]. Expecting [0-9a-fA-F]\n", c, i, s);
            return 0;
        }
        ++i;
    }

    return tot;
}
