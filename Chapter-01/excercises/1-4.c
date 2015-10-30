/* 1-4 Celsius to Fahrenheit, page 13 */

#include <stdio.h>

/* print Celsius-Fahrenheit table
    for fahr = 0, 20, ..., 300 */
main()
{
    float fahr, celsius;
    int lower, upper, step;
    
    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */
    
    /* print the table header */
    printf("%s %3s\n", "Cels", "Fahr");
    
    celsius = lower;
    while (celsius <= upper) {
        //celsius = (5.0/9.0) * (fahr-32.0);
        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}