#include <stdio.h>
#define MAXLINE 400
#define TABSTOP 4
#define MAX_COL 80
int getline_( char s[], int limit);
int fold( char s[], int limit);
int last_nonblank( char s[], int s_i ); 
int substrcp( char s[], int s_from, int s_to, char new_string[], int ns_i, int limit);
void copy_str( char from[], int f_i, char to[], int t_i, int limit );

//1-22. Write a program to ``fold'' long input lines into 
//two or more shorter lines after the last non-blank character 
//that occurs before the n-th column of input. Make sure your
//program does something intelligent with very long lines, 
//and if there are no blanks or tabs before the specified 
//column.
int main(){
    char s[MAXLINE];
    getline_( s, MAXLINE );
    fold( s, MAXLINE );
    printf( "%s", s );
    return 0;
}

int fold( char s[], int limit ){
    int s_i, ns_i, current_col;
    int s_last_copy, last_space;
    int num_copied;
    char new_string[MAXLINE];
    s_i= s_last_copy= num_copied= 0;
    ns_i= current_col= 0;
    //seek first non-blank character before nth column
    while( s[s_i] != '\0' && s_i < limit && ns_i < limit ){
        //at the end of a line, copy said line into new_string

        if( current_col == MAX_COL ){
            //find last space
            last_space=last_nonblank(s, s_i);
            last_space++; //so that we have the space after the last non-blank char

            //copy s from s_last_copy to last_space into new_string
            num_copied= substrcp( s, s_last_copy, last_space, new_string, ns_i, MAXLINE );
            ns_i= ns_i + num_copied;
            s_last_copy= last_space;

            //insert newline into new_string, increment ns_i
            new_string[ns_i]='\n';
            ns_i++;
            new_string[ns_i]='\0';
            // s_i= last_space
            s_i=last_space;
            current_col=0;
        } else {
            current_col++;
            s_i++;
        }
    }
    //copy last of s to new_string
    last_space= last_nonblank(s, s_i);
    if( s[s_i]!='\0' )
        last_space++;
    //need to make sure that substrcp doesn't copy past
    //the end of new_string.
    num_copied= substrcp( s, s_last_copy, MAXLINE, new_string, ns_i, MAXLINE );
    ns_i= ns_i+num_copied;
    new_string[ns_i]='\0';
    s_i=last_space;
    copy_str( new_string, 0, s, 0, MAXLINE );
    return 0;
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

int last_nonblank( char s[], int s_i ){
    int found_blank=0;
    if( s_i <= 0 )
        return -1;

    if( s[s_i]=='\0' )
        return s_i;

    while( s_i >= 0 ){
       if( found_blank==1 && s[s_i]!='\t' && s[s_i]!=32 )
           return s_i+1;

       if( found_blank==0 && (s[s_i]=='\t' || s[s_i]==32))
           found_blank=1;

       s_i--;
    }
    return -1;
}

int substrcp( char s[], int s_from, int s_to, char new_string[], int ns_i, int limit ){
    //copy s[ s_from - s_to ] into new_string
    int i=s_from;
    int counter=0;
    while( i<s_to && i<limit && ns_i<limit){
        new_string[ns_i]= s[i];
        ns_i++;
        i++;
        counter++;
    }
    new_string[ns_i]='\0';
    return counter;
}

void copy_str( char string[], int s_i, char new_string[], int ns_i, int limit ){
    while( s_i<=limit && string[s_i]!='\0' && ns_i<=limit){
        new_string[ns_i]=string[s_i];
        ns_i++;
        s_i++;
    }
    new_string[ns_i]='\0';
    return;
}
