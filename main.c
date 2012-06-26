#include <stdio.h>
#include <string.h>
#define MAXLINE 400
int getline_( char s[], int limit );
int squish( char string[], char gsub_chars[] );
int string_has( char string[], char c );

// Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in
// s1 that matches any character in the string s2.
//
int main()
{
    char string[MAXLINE];
    char remove[MAXLINE];
    printf( "Please enter the string:\n" );
    getline_( string, MAXLINE );
    printf( "Please enter the characters to remove from string:\n" );
    getline_( remove, MAXLINE );
    squish( string, remove );
    printf( "%s", string );
    return 0;
}

int getline_( char s[], int limit)
{
    int i, c;
    i=0;
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

int squish( char string[], char gsub_chars[] )
{
    int string_i=0;
    int ns_i=0;
    int len;
    char new_string[MAXLINE];
    for( len=strlen(string); string_i<=len; ){
        if( string[string_i]!='\n' && string_has( gsub_chars, string[string_i] )==1 ){
            string_i++;
        } else {
            new_string[ns_i++]=string[string_i++];
        }
    }
    strcpy( string, new_string );
    return 0;
}

int string_has( char string[], char c )
{
    int i=0;
    while( string[i]!='\0' ){
        if( string[i++]==c )
            return 1;
    }
    return 0;
}
