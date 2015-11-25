/* 1.13 Write a program to print a histogram of the lengths of words in its
input, page 24 */

#include <stdio.h>

#define MAX 10   /* the maximum amount letters to count per word. */

main()
{
    int c, i, j, nc;
    int nwords[MAX];

    /* initialise the array, set all values to 0 */
    for (i = 0; i < MAX; ++i)
        nwords[i] = 0;

    /* keep reading the input characters until there are no more left. the 
    aim is to count the characters in each word and update the array which 
    we are using to count the occurrences of differing word lengths.
    */
    nc = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            /* we are not in a word. if we have just finished a word (i.e.
            nc is not greater than 0) then update the array. */
            if (nc > 0 && nc <= MAX)
                ++nwords[nc-1];

            /* ensure that nc will be 0 for the next iteration */
            nc = 0;
        }
        else 
            /* we must be in a word. increment that character counter and
            move on */
            ++nc;
    }
    
    /* output the historgram (horizontal) */
    for (i = 0; i < MAX; ++i) {
        /* output the axis value for this index */
        printf("%2d|", i+1);

        /* output a number of '#' characters representing the value stored
        in this index of the array */
        for (j = 0; j < nwords[i]; ++j)
            printf("#");
        
        /* print a new line */
        printf("\n");
    }
}
