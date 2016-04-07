/* 2-1 Write a program to determine the ranges of char, short, int and long
variables, both signed and unsigned, by printing values from the standard
headers and by direct computation. Harder if you compute them: determine the
ranges of the various floating-point types, page 36 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

main()
{
    char c;
    short s;
    int i;
    long l;

    signed char sc;
    signed short ss;
    signed int si;
    signed long sl;

    // <limits.h>
    printf("The limits.h ranges of char, short, int and long (signed and unsigned)\n");
    printf("-------------------------------------------------------------\n");

    // char
    printf("CHAR_BIT\t\t %11d\t bits in a char\n", CHAR_BIT);
    printf("CHAR_MAX\t\t %11d\t maximum value of char\n", CHAR_MAX);
    printf("CHAR_MIN\t\t %11d\t minimum value of char\n", CHAR_MIN);
    printf("SCHAR_MAX\t\t %11d\t maximum value of signed char\n", SCHAR_MAX);
    printf("SCHAR_MIN\t\t %11d\t minimum value of signed char\n", SCHAR_MIN);
    printf("UCHAR_MAX\t\t %11d\t maximum value of unsigned char\n", UCHAR_MAX);

    // short
    printf("SHRT_MAX\t\t %11d\t maximum value of short int\n", SHRT_MAX);
    printf("SHRT_MIN\t\t %11d\t minimum value of short int\n", SHRT_MIN);
    printf("USHRT_MAX\t\t %11d\t minimum value of unsigned short\n", USHRT_MAX);

    // int
    printf("INT_MAX\t\t\t %11d\t maximum value of int\n", INT_MAX);
    printf("INT_MIN\t\t\t %11d\t minimum value of int\n", INT_MIN);
    printf("UINT_MAX\t\t %11d\t maximum value of unsigned int\n", UINT_MAX);

    //long
    printf("LONG_MAX\t\t %11d\t maximum value of long\n", LONG_MAX);
    printf("LONG_MIN\t\t %11d\t minimum value of long\n", LONG_MIN);
    printf("ULONG_MAX\t\t %11d\t minimum value of unsigned long\n\n", LONG_MAX);


    // <float.h>
    printf("The float.h ranges of floating-point types (signed and unsigned)\n");
    printf("-------------------------------------------------------------\n");

    // char
    printf("FLT_RADIX\t\t %11d\t radix of exponent representation, e.g., 2, 16\n", FLT_RADIX);
    printf("FLT_ROUNDS\t\t %11d\t floating-point rounding mode for addition\n", FLT_ROUNDS);
    printf("FLT_DIG\t\t\t %11d\t decimal digits precision\n", FLT_DIG);
    printf("FLT_EPSILON\t\t %11f\t smallest number x such that 1.0 + x != 1.0\n", FLT_EPSILON);
    printf("FLT_MANT_DIG\t\t %11d\t number of base FLT_RADIX digits in mantissa\n", FLT_MANT_DIG);
    printf("FLT_MAX\t\t\t %e\t maximum floating-point number (%f)\n", FLT_MAX, FLT_MAX);
    printf("FLT_MAX_EXP\t\t %e\t maximum n such that FLT_RADIX^n - 1 is representable (%f)\n", FLT_MAX_EXP, FLT_MAX_EXP);
    printf("FLT_MIN\t\t\t %11f\t minimum floating-point number\n", FLT_MIN);
    printf("FLT_MIN_EXP\t\t %11f\t minumum n such that 10^n is a normalized number\n", FLT_MIN_EXP);

    // double
    printf("DBL_DIG\t\t\t %11d\t decimal digits precision\n", DBL_DIG);
    printf("DBL_EPSILON\t\t %11f\t mallest number x such that 1.0 + x != 1.0\n", DBL_EPSILON);
    printf("DBL_MANT_DIG\t\t %11d\t number of base FLT_RADIX digits in mantissa\n", DBL_MANT_DIG);
    printf("DBL_MAX\t\t\t %e\t maximum double floating-point number\n", DBL_MAX);
    printf("DBL_MAX_EXP\t\t %e\t maximum n such that FLT_RADIX^n - 1 is representable\n", DBL_MAX_EXP);
    printf("DBL_MIN\t\t\t %11f\t minimum normalized double floating-point number\n", DBL_MIN);
    printf("DBL_MIN_EXP\t\t %11f\t minumum n such that 10^n is a normalized number\n\n", DBL_MIN_EXP);

    return 0;
}
