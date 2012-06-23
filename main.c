#include <stdio.h>
#include <string.h>
#define MAXLINE 400
int getline_( char s[], int limit );

// Write a loop equivalent to the for loop above without using && or ||.
//
// for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
//      s[i] = c;
int main(){
    char s[MAXLINE];
    getline_( s, MAXLINE );
    printf( "%s", s );
    return 0;
}

int getline_( char s[], int limit)
{
    int i, c;
    i=0;
// for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
//      s[i] = c;
    for( i=0; (i<limit-1) + ((c=getchar())!='\n') + (c!=EOF) == 3; i++){
           s[i]=c;
    } 
    if( c == '\n' ){
        s[i]=c;
        i++;
    }
    s[i]='\0';
    return i;
}
