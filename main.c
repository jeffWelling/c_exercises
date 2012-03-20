#include <stdio.h>

main()
{
    int i = 0;
    while( i<=255 ){
        printf("%c\t%d\n", i, i);
        ++i;
    }
}
