/* 1.14 Write a program to print a histogram of the frequencies of different
characters in its input, page 24 */

#include <stdio.h>

#define MAX 256             /* the maximum amount letters to count per word. */
#define MIN_PRINTABLE   32  /* the minimum value that represents a printable char */
#define MAX_PRINTABLE   127 /* the maximum value that represents a printable char */

main()
{
    int c, i, j, lc;
    int nchar[MAX];

    /* initialise the array, set all values to 0 */
    for (i = 0; i < MAX; ++i)
        nchar[i] = 0;

    /* keep reading the input characters until there are no more left. the
    aim is to read the character using its integral base value and then
    increment the counter value stored in the equivalent index in the array
    e.g. character: 0, array[0]. character: 150, array[150] etc. */
    lc = 0;
    while ((c = getchar()) != EOF) {
        if (0 <= c && c < MAX) {
            ++nchar[c];
            /* if the new  count for this index is greater than our
            current largest count then update the latest count. */
            if (nchar[c] > lc)
                lc = nchar[c];
        }
    }

    /* output the histogram (vertical)
    the aim is to plot the histogram values as if they were points on a
    cartesian graph (e.g. a graph with x/y axes). we will do that by
    plotting the points line-by-line, from left-to-right, top-to-bottom. so,
    in the following block, the variable i represents the line (y) and the
    variable j represents the column (x). */
    for (i = 0; i < lc; ++i) {
        /* we are now going to loop through the array of char counts. if the
        count in the current index is smaller than or equal to the 'y' (or
        line) value then plot the point. if not then print a space */
        for (j = MIN_PRINTABLE; j <= MAX_PRINTABLE; ++j) {
            if (nchar[j] == 0)
                continue;
            else if ((lc - i) <= nchar[j])
                printf(" #");
            else
                printf("  ");
        }

        /* we have finished processing this line so output a newline char */
        putchar('\n');
    }

    /* we have finished outputting the histogram values so now print the
    x-axis */
    for (j = MIN_PRINTABLE; j <= MAX_PRINTABLE; ++j) {
        if (nchar[j] == 0)
            continue;
        printf("--");
    }
    printf("\n");

    for (j = MIN_PRINTABLE; j <= MAX_PRINTABLE; ++j) {
        if (nchar[j] == 0)
            continue;printf(" %c", j);
    }
    printf("\n");
}
