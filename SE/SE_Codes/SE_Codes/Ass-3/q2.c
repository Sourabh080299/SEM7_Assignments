#include<stdio.h>
#include<string.h>

int main()
{
    char str[3];
    strcpy(str,"anjali"); //buffer overflow
    printf("%c ", str[8]); //reading past end of buffer'
    
    return 0;
}
