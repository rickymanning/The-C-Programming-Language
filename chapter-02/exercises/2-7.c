/* Write a function invert(x,p,n) that returns x with the n bits that begin 
at position p inverted (i.e., 1 changed into a 0 and vice versa), leaving the
others unchanged, page 49 */

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned getbits(unsigned x, int p, int n);
unsigned invert(unsigned x, int p, int n);

int main()
{
    unsigned x;
    int p, n;

    x = 209U;
    p = 4;
    n = 3;

    printf("%u\n", invert(x,p,n));
}

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}

/* setbits: replace bits p -> p+1-n of x with rightmost n bits from y */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned bits, mask;

    /* get the rightmost n bits from y and shift them to position p */
    bits = getbits(y, n-1, n);
    bits = bits << (p+1-n);

    /* create a mask containing all 1s apart from bits p to p+1-n */
    mask = ~0;
    mask = mask << n;
    mask = (~mask) << (p+1-n);
    mask = ~mask;

    /* mask off the bits in x that we want to overwrite */
    x = x & mask;
    
    /* return the overwritten bits in x */
    return x | bits;
}

/* invert: switches the bits in positions p -> p+n in x */
unsigned invert(unsigned x, int p, int n)
{
    int bits;
    unsigned mask;
 
    /* get the bits from an inverted x and shift them to position p */
    bits = getbits(~x, p, n);
    bits = bits << (p+1-n);

    /* create a mask containing all 1s apart from bits p to p+1-n */
    mask = ~0;
    mask = mask << n;
    mask = (~mask) << (p+1-n);
    mask = ~mask;

    /* mask off the bits in x that we want to overwrite */
    x = x & mask;

    /* return the overwritten bits in x */
    return x | bits;

    /* this routine looks very similar to setbits() from exercise 2-6. in
    fact I could even replace all of the above with a single line call to
    setbits(), like as follows:

        return setbits(x, p, n, ~x >> (p+1-n));
    */
}
