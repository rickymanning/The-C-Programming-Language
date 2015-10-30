/* 1-6 Verify that getchar() != EOF is equal to 0 or 1 , page 17 */

#include <stdio.h>

/* verify that the statement getchar() != EOF is either 0 or 1 */
main()
{
    int c;
    while (c = getchar() != EOF) {
        /* c is not EOF so print 1 */
        printf("%d", c);
    }
    /* c is EOF so print 0 */
    printf("\n%d\n", c);
}
    