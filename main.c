#include <stdio.h>
#define IN 0
#define OUT 1

//Write a program that copies input to output replacing each
// Series of spaces with one space
main()
{
    int c=0;
    int space=0;
    while( (c=getchar()) != EOF ){
        if( c==32 ){
            if( space==0 ){
                printf(" ");
                space=OUT;
            } else if( space==1 ){
                ;
            }
        } else {
            printf("%c", c);
            space=IN;
        }
    }
}
