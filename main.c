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
        if( len >= 80 ){
            printf("%s", line);
        }
    }
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
