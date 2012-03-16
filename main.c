#include <stdio.h>

main()
{
    int fahr, celsius;
    int upper, lower, step;

    lower=0;
    upper=300;
    step=20;

    fahr= lower;
    printf("Fahr\tCelsius\n");
    while( fahr<= upper ){
        celsius= 5*(fahr-32) /9;
        printf("%d\t%d\n", fahr, celsius);
        fahr=fahr+step;
    }
}
