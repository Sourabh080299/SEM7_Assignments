//infinite loops
//fall through switches - no preceding break
// missing switch cases
// empty statement after an if, white or for
#include<stdio.h>

int main()
{
    int i=0;
    if(i==0)
        ;

    switch(i){
        case 1: i = 2; //fall through

        //missing switch case
        case 2: i=3;
                break; 
        case 3: ;
            break;    }
    //infinite loop
    while(i<1)
    {
        printf("%d", i);
    }

    return 0;
}
