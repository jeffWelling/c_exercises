#include <stdio.h>
#define MAXLINE 200
#define TABSTOP 8
int getline_( char s[], int limit);
int detab( char s[], int limit );

int len=0;
char s[MAXLINE];

//1-20: Write a program detab that replaces tabs in the 
//input with the proper number of blanks to space 
//to the next tab stop. Assume a fixed set of tab 
//stops, say every n columns.
int main(){
    int len;
    char s[MAXLINE];
    //assume tabstop every 4 spaces
    getline_( s, MAXLINE );
    detab( s, MAXLINE );
    printf( "%s", s );
}

int detab( char s[], int limit ){
    int s_i, ns_i, temp;;
    s_i= ns_i= temp= 0;
    char new_string[MAXLINE];
    while( s[s_i] != '\0' && s_i<=limit ){
        if( s[s_i] == 9 ){
            temp=ns_i;
            //If we're already on a tabstop boundary, increment
            if( (temp%TABSTOP) ==0 ){
                new_string[ns_i]=' ';
                ns_i++;
                temp++;
            }
            while( (temp%TABSTOP) != 0 ){
                new_string[ns_i]=' ';
                ns_i++;
                temp++;
            }
            s_i++;
        } else {
            new_string[ns_i]=s[s_i];
            ns_i++;
            s_i++;
        }
    }
    new_string[ns_i]='\0';
    ns_i=0;
    while( new_string[ns_i] != '\0' ){
        s[ns_i]=new_string[ns_i];
        ns_i++;
    }
    s[ns_i]='\0';
    return ns_i;
}

int getline_( char s[], int limit ){
    int c;
    int i=0;
    while( (c=getchar()) != EOF && c!= '\n' && i<limit ){
        s[i]=c;
        i++;
    }
    if( c=='\n' ){
        s[i]=c;
        i++;
    }
    s[i]='\0';
    return i;
}
