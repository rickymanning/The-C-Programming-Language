/* 1.13 Write a program to print a histogram of the lengths of words in its
input (vertically), page 24 */

#include <stdio.h>

#define MAX 10   /* the maximum amount letters to count per word. */

main()
{
    int c, i, j, nc, lc;
    int nwords[MAX];

    /* initialise the array, set all values to 0 */
    for (i = 0; i < MAX; ++i)
        nwords[i] = 0;

    /* keep reading the input characters until there are no more left. the
    aim is to count the characters in each word and update the array which
    we are using to count the occurrences of differing word lengths.
    */
    nc = lc = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            /* we are not in a word. if we have just finished a word (i.e.
            nc is not greater than 0) then update the array. */
            if (nc > 0 && nc <= MAX) {
                ++nwords[nc-1];
                /* if the new  count for this index is greater than our
                current largest count then update the latest count. */
                if (nwords[nc-1] > lc)
                    lc = nwords[nc-1];
            }
            /* ensure that nc will be 0 for the next iteration */
            nc = 0;
        }
        else
            /* we must be in a word. increment that character counter and
            move on */
            ++nc;
    }

    /* output the histogram (vertical)
    the aim is to plot the histogram values as if they were points on a
    cartesian graph (e.g. a graph with x/y axes). we will do that by
    plotting the points line-by-line, from left-to-right, top-to-bottom. so,
    in the following block, the variable i represents the line (y) and the
    variable j represents the column (x). */
    i = j = 0;
    for (i = 0; i < lc; ++i) {
        /* output a space as the first character of a line */
        putchar(' ');

        /* we are now going to loop through the array of string length
        counts. if the count in the current index is smaller than or equal
        to the 'y' (or line) value then plot the point and if the reverse,
        then output a space instead. */
        for (j = 0; j < MAX; ++j) {
            if ((lc - i) <= nwords[j]) {
                printf("# ");
            }
            else
            {
                printf("  ");
            }
        }

        /* we have finished processing this line so output a newline char */
        putchar('\n');
    }

    /* we have finished outputting the histogram values so now about the
    x-axis */
    printf("---------------------\n");
    printf(" 1 2 3 4 5 6 7 8 9 10 \n");
}
