/* 1.5.2 Count characters improved, page 18 */

#include <stdio.h>

/* count characters in input; 2nd version */
main()
{
    double nc;
    
    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%.0f\n", nc);
}