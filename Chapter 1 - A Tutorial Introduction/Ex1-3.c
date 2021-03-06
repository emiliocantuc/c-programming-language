#include <stdio.h>
/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300 */
main(){
        int fahr, celsius;
        int lower, upper, step;
        lower = 0; /* lower limit of temperature scale */
        upper = 300; /* upper limit */
        step = 20; /* step size */
        fahr = lower;
        printf("%10s\t%10s\n","Fahrenheit","Celsius");
        while (fahr <= upper) {
                celsius = 5 * (fahr-32) / 9;
                printf("%10d\t%10d\n", fahr, celsius);
                fahr = fahr + step;
        }
}
