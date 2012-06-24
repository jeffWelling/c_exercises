#include <stdio.h>
#include <string.h>
#define MAXLINE 400
int getline_( char s[], int limit );
int htoi( char s[] );

static const long hextable[] = {
    [0 ... 255] = -1,
    ['0'] = 0,1,2,3,4,5,6,7,8,9,
    ['A'] = 10,11,12,13,14,15,
    ['a'] = 10,11,12,13,14,15
};

// Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in
// s1 that matches any character in the string s2.
//
int main(){
    char s[MAXLINE];
    getline_( s, MAXLINE );
    printf( "%d", htoi(s) );
    return 0;
}

int getline_( char s[], int limit)
{
    int i, c;
    i=0;
    for( i=0; (i<limit-1) + ((c=getchar())!='\n') + (c!=EOF) == 3; i++){
           s[i]=c;
    } 
    c=getchar();
    while( ((i<limit-1)+(c!='\n')+(c!=EOF))==3 ){
        s[i++]=c;
        c=getchar();
    }
    if( c == '\n' ){
        s[i]=c;
        i++;
    }
    s[i]='\0';
    return i;
}

int htoi( char s[] ){
    int i=0;
    long ret=0;
    while( s[i]!='\n' && s[i]!=0 ){
        if( i==0 && s[i]=='0' && (s[i+1]=='x' || s[i+1]=='X') ){
            i+=2;
        } else {
            ret= (ret << 4) | hextable[ (int) s[i++] ];
        }
    }
    return ret;
}
