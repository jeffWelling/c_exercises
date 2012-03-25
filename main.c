#include <stdio.h>
#define IN 1
#define OUT 0

/* Write a program to print a histogram of the lengths of words in
    itsinput. */
main()
{
    int c=0;
    int histogram[52]={0};
    int current_length=0;
    int state=OUT;
    int occurances=0;
    int i;

    //Here we borrow C so we don't have to use i
    while( (c=getchar()) != EOF && c!=81){
        if( (c>=65 && c<=90) || (c>=97 && c<=122) ){
            //Valid character
            if( c>=65 && c<=90 ){
                histogram[c-65]++;
            } else {
                histogram[c-71]++;
            }
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
    for( i=0; i<=51; i++ ){
        if( i>=0 && i<=25 ){
            printf("%c  ", i+65);
        } else {
            printf("%c  ", i+71);
        }
    }

    printf("\n");
    return 0;
}
