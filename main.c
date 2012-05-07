#include <stdio.h>
#define MAXLINE 200
#define TABSTOP 4
int getline_( char s[], int limit);
int entab( char s[], int limit );
int seq_spaces( char s[], int i );

int len=0;
char s[MAXLINE];

// 1-21: Write a program `entab` that replaces strings of blanks by the
// minimum number of tabs and blanks to achieve the same spacing. Use
// the same tab stops as for detab. When either a tab or a single blank
// would suffice to reach a tab stop, which should be given preference?
int main(){
    char s[MAXLINE];
    //assume tabstop every 4 spaces
    getline_( s, MAXLINE );
    entab( s, MAXLINE );
    printf( "%s", s );
    return 0;
}

int entab( char s[], int limit ){
    int s_i, ns_i, temp;;
    s_i= ns_i= temp= 0;
    char new_string[MAXLINE];
    while( s[s_i] != '\0' && s_i<=limit ){
        //If spaces? > TABSTOP
        //      delete_spaces(TABSTOP)
        //      insert_tab(s)
        if( s[s_i] == 32 ){
            if( seq_spaces(s,s_i) >= TABSTOP ){
                while( seq_spaces(s,s_i) >= TABSTOP ){
                    s_i=s_i+TABSTOP;
                    new_string[ns_i]='\t';
                    ns_i++;
                }
            } else {
                new_string[ns_i]=s[s_i];
                ns_i++;
                s_i++;
            }
            /*temp=ns_i;
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
            s_i++;*/
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

int seq_spaces( char s[], int i ){
	int counter=0;
	while( s[i] == 32 ){
		counter++;
		i++;
	}
    return counter;
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
