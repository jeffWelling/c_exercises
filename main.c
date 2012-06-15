#include <stdio.h>
#include <string.h>
#define MAXLINE 400
int getline_( char s[], int limit );
int strip_comments( char s[], int state );
int substrcp( char s[], int s_from, int s_to, char new_string[], int ns_i, int limit );
int comment_end( char s[], int i );


//Write a program to remove all comments from a C program. Don't forget to
//handle quoted strings and character constants properly. C comments don't nest.
int main()
{
    char string[MAXLINE];
    int state;
    state=0;
    while( getline_(string,MAXLINE)!=0 ){
        state=strip_comments( string, state );
        printf( "%s", string );
    }
    return 0;
}

int getline_( char s[], int limit)
{
    int i, c;
    i=0;
    while( (c=getchar()) != EOF && c != '\n' && i < limit-1 ){
        s[i]=c;
        i++;
    }
    if( c == '\n' ){
        s[i]=c;
        i++;
    }
    s[i]='\0';
    return i;
}

int strip_comments( char s[], int state )
{
    int end_of_comment, ns_i, counter;
    int s_i;
    char new_string[MAXLINE];
    end_of_comment= ns_i= s_i= 0;
    // fubar fubar fubar /*fubar*/
    /* fubar fubar
       */
    // /* fubar
    */
    /* //
     */ //
    
    while( s[s_i] != '\0' && s[s_i] != '\n' ){

        if( state==0 ){
            //not yet in a comment.

            //start of multi-line comment
            if( s[s_i]=='/' && s[s_i+1] == '*' ){
                state=1;

                //find end of comment
                end_of_comment= comment_end( s, s_i );
                // if end_of_comment == 0 then could not find end_of_comment
                // ergo, it ends on one of the following lines.

                // copy s[i] until comment 
                if( end_of_comment==0 ){
                    //comment wraps to next line
                    //copy s[0] to beginning of comment, return 1
                    if( s_i != 0 ){
                        counter=substrcp( s, 0, s_i, new_string, ns_i, MAXLINE-1 );
                        ns_i+=counter;
                    }
                    new_string[ns_i]='\n';
                    ns_i++;
                    new_string[ns_i]='\0';
                    strcpy( s, new_string );
                    //we can return here because we know the comment ends on the next line
                    //If we didn't know that, we would have to look for additional comments
                    return 1;
                } else {
                    //comment ends on same line
                    //copy s[0] to beginning of comment
                    if( s_i != 0 ){
                        counter= substrcp( s, 0, s_i, new_string, ns_i, MAXLINE );
                        ns_i+=counter;
                    }
                    //copy s[end_of_comment] to '\0';
                    if( end_of_comment!=( strlen(s)-1 ) ){
                        counter= substrcp( s, end_of_comment, strlen(s), new_string, ns_i, MAXLINE-1 );
                        ns_i+=counter;
                    }
                    new_string[ns_i]='\n';
                    ns_i++;
                    new_string[ns_i]='\0';
                    strcpy( s, new_string );
                    return 0;
                }
                   //start of single line comment
            } else if( s[s_i]=='/' && s[s_i+1]=='/' ){
                //copy from s[0] to s_i
                if( s_i != 0 ){
                    counter=substrcp( s, 0, s_i, new_string, ns_i, MAXLINE-1 );
                    ns_i+=counter;
                }
                new_string[ns_i]='\n';
                ns_i++;
                new_string[ns_i]='\0';
                strcpy( s, new_string );
                return 0;
            }
        } else if( state==1 ){
            //already in a multi-line comment from previous line
            //find end of comment
            end_of_comment= comment_end( s, 0 );
            if( end_of_comment==0 ){
                //comment continues to next line
                s[0]='\n';
                s[1]='\0';
                return 1;
            } else {
                counter=substrcp( s, end_of_comment, strlen(s), new_string, ns_i, MAXLINE-1 );
                ns_i+=counter;
                new_string[ns_i]='\n';
                ns_i++;
                new_string[ns_i]='\0';
                strcpy( s, new_string );
                return 0;
            }
        }
        s_i++;
    } 
    return state;
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

int comment_end( char s[], int i )
{
    while( (s[i] != '*' && s[i+1] != '/') && s[i] != '\n' && s[i] != '\0' ){ 
        i++;
    }
    if( s[i]=='*' && s[i+1]=='/' ){
        return i+1;
    }
    return 0;
}
