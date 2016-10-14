/* 3-4 In a two's complement number representation, our version of itoa does
not handle the largest negative number, that is, the value of n equal to
-(2^wordsize-1). Explain why not. Modify it to print the value correctly,
regardless of the machine on which it runs, page 64  */

/* EXPLANATION 

If we assume a wordsize of 4, the largest negative number is -8 

e.g. -(2^(4-1)) = -(2^3) = -(8)  

Written in binary, -8 would be 1000. Here is the full list of available 
values:

dec bin     dec bin
0   0000    -1  1111
1   0001    -2  1110
2   0010    -3  1101
3   0011    -4  1100
4   0100    -5  1011
5   0101    -6  1010
6   0110    -7  1001
7   0111    -8  1000

We therefore cannot represent the absolute value of -8 in a two's complement
number representation with a wordsize of 4.

The itoa() function tries to get the absolute value of n by flipping the 
minus sign when n is negative...

    if ((sign = n) < 0)
        n = -n;

Because of the vagaries of addition & subtraction with two's complement 
representations, when n is the largest negative number (e.g. -8 in our
system where the wordsize = 4), -n (e.g. -(-8) in our sustem) evaluates to
-8 again:

    0000 (0)
  - 1000 (-8) 
    
    0000
  - 0111 (one's complement of -8)

    0000
  + 1000 (two's complement)

  = 1000 (same as the input)

This can be verified by running a program that simply prints the following:

   printf("%d becomes %d when flipping the minus sign \n", INT_MIN, -INT_MIN);
   printf("%d becomes %d when flipping the minus sign \n", (INT_MIN+1), -(INT_MIN+1));
   printf("%d becomes %d when flipping the minus sign \n", (-3490), -(-3490));

(if the above was executed for every integer, the only one where the minus
sign doesn't actually flip is INT_MIN e.g. the largest negative integer. 
don't forget to include <limits.h> in order to get the definition of 
INT_MIN)

So, back to the itoa() routine. This also means that the do-while condition: 

    (while ((n /= 10) > 0) 

when n is the largest negative integer, ends up negative on the first 
iteration, thus ending the loop prematurely. This is the second problem.

We therefore need to keep n as it comes when we enter the loop, but get the 
absolute number of the result of n % 10 in each iteration instead. 

NOTE: I used a wordsize of 4 above for brevity; in all implementations of C,
the wordsize for integers must be at least 16 so we can use n % 10 safely and
we can also get the absolute values safely also.

*/


/* PROGRAM */

#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[]);
void reverse(char s[]);

main()
{
    int i;
    char a[100];
    int val[5] = { INT_MIN, -5, 0, 5, INT_MAX };
    for (i = 0; i < 5; ++i) {
        /* Call itoa and print results */
        itoa(val[i], a);
        printf("%d is \"%s\"\n", val[i], a);
    }
}

/*itoa: convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;
    
    sign = n;
    i = 0;
    do {                    /* Generate digits in reverse order */
        int abs = n % 10;   /* Get next digit */
        if (abs < 0)        /* Ensure abs really is absolute. of course, */
            abs = -abs;     /* the standard library version of abs is */
                            /* probably better */ 
        s[i++] = abs + '0';      
    } while (n /= 10);    /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}


/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

//
//  Original itoa() from the book
//
//  /* itoa: convert n to characters in s */
//  void itoa(int n, char s[])
//  {
//      int i, sign;
//      
//      if ((sign = n) < 0) /* record sign */
//          n = -n;         /* make n positive */
//      i = 0;
//      do {        /* generate digits in reverse order */
//          s[i++] = n % 10 + '0';  /* get next digit */      
//      } while ((n /= 10) > 0);    /* delete it */
//      if (sign < 0)
//          s[i++] = '-';
//      s[i] = '\0';
//      reverse(s);
//  }



