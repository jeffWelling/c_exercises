#include <stdio.h>
#define MAXLINE 100

int getaline( char line[], int maxline );
void copy( char to[], char from[] );
void reverse( char s[] );

//Write a function reverse(s) that reverses the character string s. 
//Use it to write a program that reverses its input a line at a time.
main()
{
    int len; // current line length
    int max; // max line length
    char line[MAXLINE]; // current line
    char longest[MAXLINE]; // max line

    max=0;
    while((len = getaline(line, MAXLINE)) > 0){
        reverse(line);
        printf("%s", line);
    }
    return 0;
}

// getaline: read a line into s, return length
int getaline( char s[], int limit )
{
    char c;
    int i=0;
    while( (c=getchar()) != '\n' && c!=EOF && i < limit ){
        s[i]=c;
        i++;
    }

    if( c=='\n') {
        s[i]='\n';
        i++;
    }
    s[i]='\0';
    return i;
}

void reverse( char s[] ){
    int a=0;
    int b=0;
    int temp;
    while( s[b] != '\0' && b<=MAXLINE ){ b++; }
    //For '\n' and '\0'
    b--;
    while( a<=b ){
        temp=s[a];
        s[a]=s[b];
        s[b]=temp;
        a++;
        b--;
    }
}
