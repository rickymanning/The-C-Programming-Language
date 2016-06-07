/* 2-8 Write a function rightrot(x,n) that returns the value of the integer 
rotated to the right by n bit positions, page 49 */

#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned rightrot(unsigned x,int n);

int main()
{
	unsigned x;
    int n;
    
    x = 209U;
    n = 3;

    printf("%u\n", rightrot(x,n));
}

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}

/* rightrot: rotate the bits in x such that the rightmost n bits get pushed
off to the right and then appear on the left */
unsigned rightrot(unsigned x, int n)
{   
    /* 
     * the idea is to do this in the following broad steps:
     *
     *  1) capture the rightmost bit in x
     *  2) shift the bits in x to the right by one 
     *  3) set the leftmost bit to the bit that we captured
     *  4) repeat the above until we have done it n times 
     *
     * it occured to me that shifting the bits to the right (step 2) always
     * creates a 0 in the leftmost bit. We therefore only need to set it 
     * explicitly if the previous rightmost bit (step 1) is a 1. 
     */  
    int i;
    for (i = 0; i < n; i++) {
        if (getbits(x, 0, 1))
            x = (x >> 1) | ~(~0U >> 1);
        else
            x = (x >> 1);
    }
    return x;
}
