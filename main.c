#include <stdio.h>
#define MAXLINE 100

int getaline( char line[], int maxline );
void copy( char to[], char from[] );

/* print the longest line */
main()
{
    int len; // current line length
    int max; // max line length
    char line[MAXLINE]; // current line
    char longest[MAXLINE]; // max line

    max=0;
    while((len = getaline(line, MAXLINE)) > 0){
        if( len > max ){
            max= len;
            copy(longest,line);
        }
    }
    if( max > 0 ) //there was a line
        printf("Longest line:%s\nLength of line:%d\n", longest, max);
    return 0;
}

// getaline: read a line into s, return length
int getaline( char s[], int limit )
{
    int c, i;

    for( i=0; i < limit-1 && (c=getchar()) != EOF && c!='\n'; i++)
            s[i]=c;

    if( c=='\n') {
        s[i]='\n';
        i++;
    }
    s[i]='\0';
    return i;
}

//copy: copy 'from' into 'to'
void copy( char to[], char from[] )
{
    int i;
    i=0;
    while( (to[i] = from[i]) != '\0' )
        i++;
}
