/* 2-9 In a two's complement number system x &= (x-1) deletes the rightmost
1-bit in x. Explain why. Use this observation to write a faster version of
bitcount, page 51 */

/* Explanation */

/* 
 * In a two's complement system, subtracting 1 is the equivalent of
 * replacing the right-most 1-bit with a 0 and filling any bits to the right
 * of that with 1s. 
 *
 * This is because (x - 1) can be written as (x + (-1)) and
 * in a two's complement system (with 4 bit numbers for brevity) 1 is 
 * 0001 and -1 is the inverse+1 e.g. 1110 + 0001 = 1111. 
 * 
 * We can see this intuitively by looking at some examples (this time 8-bit
 * and unsigned):
 *
 *    e.g.
 *      1 in binary is 0000 0001 and 0 is 0000 0000
 *      96 in binary is 0110 0000 and 95 is 0101 1111 
 *      200 in binary 1100 1000 and 199 is 1100 0111 
 * 
 * Now lets look at the result of a bitwise & operation between these
 * examples 
 *
 *    e.g.
 *      0000 0001
 *    & 0000 0000
 *      ---------
 *      0000 0000
 *
 *      0110 0000
 *    & 0101 1111
 *      ---------
 *      0100 0000
 * 
 *      1100 1000
 *    & 1100 0111
 *      ---------
 *      1100 0000
 *
 * notice how the only difference between the first binary number and the
 * result of the & operation in each is that the rightmost 1 was changed to
 * a 0.
 */


/* Code */

#include <stdio.h>

int bitcount(unsigned x);

int main()
{
    unsigned x;

	x = 29957238U;  /* binary:	0001 1100 1001 0001 1100 0111 0110 */
                    /* hex:     0x1C91C76 */

    printf("%d\n", bitcount(x));
}

/* bitcount: count 1 bits in x (from book)*/
//int bitcount(unsigned x)
//{
//    int b;
//
//    for (b = 0; x != 0; x >>=1)
//        if (x & 01)
//            b++;
//    return b;
//}


/* bitcount: count 1 bits in x (my version) */
int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= (x-1))
        b++;
    return b;
}
