/* 2-6 Write a function setbits(x,p,n,y) that returns x with the n bits that
begin at position p set to the rightmost n bits of y, leaving the other bits
unchanged, page 49 */

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned getbits(unsigned x, int p, int n);

int main()
{
    int x, p, n, y;

    x = 209;
    p = 4;
    n = 3;
    y = 187;

    printf("%u\n", setbits(x, p, n, y));
}

/* getbits: get the rightmost n bits of y and shift them left to position p */
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}

/* setbits: replace bits p -> p+n of x with rightmost n bits from y */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    int bits;
    unsigned mask;

    /* get the rightmost n bits from y and shift them to position p */
    bits = getbits(y, n-1, n);
    bits = bits << p;

    /* create a mask containing all 1s apart from bits p to p+n */
    mask = ~0;
    mask = mask << n;
    mask = (~mask) << p;
    mask = ~mask;

    /* mask off the bits in x that we want to overwrite */
    x = x & mask;
    
    /* return the overwritten bits in x */
    return x | bits;
}
