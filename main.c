#include <stdio.h>
#define IN 0
#define OUT 1

// Write a program to copy its input to its output
// replacing each tab with \t, backspace with \b and
// backslash with //. This makes tabs and backspaces visible
// in an unambiguous way
main()
{
    int c=0;
    while( (c=getchar()) != EOF ){
        if( c==9 ){
            printf("\\t");
        }else if( c==8 ){
            printf("\\b");
        }else if( c==92 ){
            printf("\\\\");
        } else {
            putchar(c);
        }
    }
}
