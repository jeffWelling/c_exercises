#include <stdio.h>
#define MAXLINE 100

int getaline( char line[], int maxline );
void copy( char to[], char from[] );

// Write a program to remove trailing blanks and tabs from each line
// of input, and to remove blank lines entirely.
main()
{
    int len; // current line length
    int max; // max line length
    char line[MAXLINE]; // current line
    char longest[MAXLINE]; // max line

    max=0;
    while((len = getaline(line, MAXLINE)) > 0){
        if( line[0]!='\n' )
            printf("%s", line);
    }
    return 0;
}

// getaline: read a line into s, return length
int getaline( char s[], int limit )
{
    int c, i, t_i, c_i;
    int in_a_word=0;
    char temp[limit];
    for( i=0; i < limit ; i++ ){
        temp[i]='\0';
    }

    for( i=0; (i < limit-1) && ((c=getchar()) != EOF) && (c!='\n'); i++){
        // beginning of a word
        if( in_a_word==0 && c>=33 && c<=126 ){
            in_a_word=1;
            //copy temp contents to string.
            for( c_i=0; (c_i+i)<(limit-1) && temp[c_i]!='\0'; c_i++ ){
                s[i+c_i]=temp[c_i];
            }
            i=i+c_i;
            s[i]=c;
            
        } else
        //in a word
        if( in_a_word==1 && (c>=33 && c<=126) ){
            s[i]=c;
        } else
        //end of word
        if( in_a_word==1 && (c<=32 || c>=127) ){
            c_i=0;
            temp[c_i]=c;
            temp[c_i+1]='\0';
            in_a_word=0;
            c_i++;
            i--;
        } else
        //between words
        if( in_a_word==0 && (c<=32 || c>=127) ){
            temp[c_i]=c;
            temp[c_i+1]='\0';
            c_i++;
            i--;
        }
    }

    if( c=='\n') {
        s[i]='\n';
        i++;
    }
    s[i]='\0';
    return i;
}
