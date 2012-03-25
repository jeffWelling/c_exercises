#include <stdio.h>
#define IN 1
#define OUT 0

/* Write a program to print a histogram of the lengths of words in
    itsinput. */
main()
{
    int c=0;
    int histogram[50]={0};
    int current_length=0;
    int state=OUT;
    int occurances=0;
    int i;

    //Here we borrow C so we don't have to use i
    while( (c=getchar()) != EOF && c!=81){
        if( (c==32 || c==10) && state==IN ){
            //End of word
            state=OUT;
            histogram[current_length]++;
            current_length++;
        }else if( (c>=33 && c<=126) && state==OUT ){
            //Start of word
            state=IN;
            current_length=1;
        }else if( (c>=33 && c<=126) && state==IN ){
            //In a word
            current_length++;
        } else {
            //Not in a word
            //Example, "  " or " \n "
            ;
        }
    }

    //Find the word length that occurs the most
    for( i=0; i<=49; i++){
        if( histogram[i] > occurances )
            occurances=histogram[i];
    }
    //Print the histogran
    //For each row, if histogram[i] >= occurances
    for( occurances; occurances>0; occurances--){  //each row
        for( i=0; i<=49; i++ ){  //each element of histogram
            if( histogram[i] >= occurances ){
                printf("_  ");
            } else {
                printf("   ");
            }

        }
        printf("\n");
    }
    //Print the numbers at the bottom
    for( c=0; c<=49; c++){
        printf("%02d ", c);
    }
    printf("\n");
    return 0;
}
