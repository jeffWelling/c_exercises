#include <stdio.h>
#define IN 0
#define OUT 1

//Write a program that copies input to output replacing each
// Series of spaces with one space
main()
{
    int c=0;
    while( (c=getchar()) != EOF ){
        if( c==92 ) //   Backslash
            printf("\\");
        if( c==9 )  // Tab
            printf("\\t");
    }
}
