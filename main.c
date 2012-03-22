#include <stdio.h>
#define IN 1
#define OUT 0

/* Write a program to print a histogram of the lengths of words in
    itsinput. */
main()
{
    int histogram[50];
    int c;
    int current_length=0;
    int state=OUT;

    //Here we borrow C so we don't have to use i
    printf("Initializing...");
    for(c=0;c<=50;c++){
        histogram[c]=0;
    }
    printf("Done\n");
    
    while( (c=getchar()) != EOF){
        if( (c==32 || c==10) && state==IN ){
            //End of word
            state=OUT;
            histogram[current_length++];
        }else if( (c>=33 && c<=126) && state==OUT ){
            //Start of word
            state=IN;
            current_length=0;
        }else if( (c>=33 && c<=126) && state==IN ){
            //In a word
            current_length++;
        } else {
            //Not in a word
            //Example, "  " or " \n "
            ;
        }
    }

    //Print the histogram
    //Recycle current_length to hold the length of the longest word
    for(     

}
