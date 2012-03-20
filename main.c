#include <stdio.h>

main()
{
    int blanks =0;
    int tabs =0;
    int newlines=0;
    int other=0;
    int c;

    while( (c=getchar()) != EOF ){
        if(c==9) //9 is /t in ascii
            tabs++;
        else if(c==32)
            blanks++;
        else if (c==10)
            newlines++;
        else
            other++;
    }
    printf("Tabs:\t%d\nBlanks:\t%d\nNewlines:\t%d\nOther:\t%d\n", tabs, blanks, newlines, other);
}
