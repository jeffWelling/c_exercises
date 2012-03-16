#include <stdio.h>

main()
{
    long n;

    n=0;
    while(getchar() != EOF)
        n++;
    printf("%ld/n", n);
}
