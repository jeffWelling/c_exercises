#include <stdio.h>
#define IN 1
#define OUT 0

/* Write a program that prints its input one word per line */
main()
{
    int c=0;
    int state=OUT;
    while( (c=getchar()) != EOF){
        if( state==OUT && (c>=32 && c<=126 )){
            state=IN;
            putchar(c);
        } else if( state==IN && (c<=32 || c>=176 )){
            state=OUT;
            printf("\n");
            putchar(c);
        } else {
            putchar(c);
        }
    }

}
