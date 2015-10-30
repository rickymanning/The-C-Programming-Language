/* 1-3 Fahrenheit to Celsius with a header, page 13 */

#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300; floating-point version; with header */
main()
{
    float fahr, celsius;
    int lower, upper, step;
    
    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */
    
    /* print the table header */
    printf("%3s %s\n", "Fahr", "Cels");
    
    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}