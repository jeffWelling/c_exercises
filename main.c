#include <stdio.h>

int fahr_to_cels( int fahr );

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
        celsius= fahr_to_cels(fahr);
        printf("%d\t%d\n", fahr, celsius);
        fahr=fahr+step;
    }
}

int fahr_to_cels( int fahr){
    return (5*(fahr-32) /9);
}
