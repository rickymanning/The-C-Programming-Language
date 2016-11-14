/* 4-2 Extend atof to handle scientific notation of the form: 123.45e-6
where a floating-point number may be followed by e or E and an optionally
signed exponent, page 73 */

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXLINE 100

/* rudimentary calculator */
main()
{
    double sum, atof(char []);
    char line[MAXLINE];
    int getline(char line[], int max);

    sum = 0;
    while (getline(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));
    return 0;
}

/* atof: convert string s to double */
double atof(char s[])
{
    double val, power, exp;
    int i, sign, expsign;

    for (i = 0; isspace(s[i]); i++)     /* skip whitespace */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    
    /* assume that we are not using scientific notation for now and set the
    exp value to 1.0. */
    exp = 1.0;

    /* test for scientific notation */
    if (s[i] == 'e' || s[i] == 'E') {
        /* the presence of 'e' or 'E' means that this may well be scientific
        notation, so investigate further... */
        expsign = (s[++i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (exp = 0.0; isdigit(s[i]); i++)
            exp = 10.0 * exp + (s[i] - '0');
        exp = pow(10.0, exp);
        exp = (expsign < 0) ? 1.0/exp : exp;
    }
        
    return (sign * val / power) * (exp);
}

/* getline: get line int s, return length */
int getline(char s[], int lim)
{
   int c, i;

   i = 0;
   while (--lim > 0 && (c=getchar()) != EOF && c!= '\n')
       s[i++] = c;
   if (c == '\n')
       s[i++] = c;
   s[i] = '\0';
   return i;
}

// /* atof: convert string s to double (original example from book) */
// double atof(char s[])
// {
//     double val, power;
//     int i, sign;
// 
//     for (i = 0; isspace(s[i]); i++)     /* skip whitespace */
//         ;
//     sign = (s[i] == '-') ? -1 : 1;
//     if (s[i] == '+' || s[i] == '-')
//         i++;
//     for (val = 0.0; isdigit(s[i]); i++)
//         val = 10.0 * val + (s[i] - '0');
//     if (s[i] == '.')
//         i++;
//     for (power = 1.0; isdigit(s[i]); i++) {
//         val = 10.0 * val + (s[i] - '0');
//         power *= 10.0;
//     }
//     return sign * val / power;
// }
