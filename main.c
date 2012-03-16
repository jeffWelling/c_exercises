#include <stdio.h>

main()
{
    int fahr, celsius;
    int upper, lower, step;

    lower=0;
    upper=300;
    step=20;

    fahr= lower;
    printf("Celsius\tFahr\n");
    while( fahr<= upper ){
        celsius= 5*(fahr-32) /9;
        printf("%d\t%d\n", celsius, fahr);
        fahr=fahr+step;
    }
}
