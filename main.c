#include <stdio.h>
#include <string.h>
#define MAXLINE 400
int getline_( char s[], int limit );
int squish( char string[], char gsub_chars[] );
int string_has( char string[], char c );
int any( char string1[], char string2[] );

//Write the function any(s1,s2), which returns the first location in a string s1
//where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
//(The standard library function strpbrk does the same job but returns a pointer to the
//location.)
int main()
{
    char string[MAXLINE];
    char remove[MAXLINE];
    printf( "Please enter the string:\n" );
    getline_( string, MAXLINE );
    printf( "Please enter the characters to remove from string:\n" );
    getline_( remove, MAXLINE );
    printf( "The first occurance of one of those characters is at: %d\n", any(string, remove) );
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
        if( string[i]==c )
            return i;
        i++;
    }
    return -1;
}

int any( char string1[], char string2[] )
{
    int string2_i=0;
    int loc=0;
    while( string2[string2_i]!='\n' && string2[string2_i]!='\0' ){
        if( (loc=string_has(string1, string2[string2_i])) >= 0 ){
            return loc+1;
        }
        string2_i++;
    }
    return -1;
}
