#include <stdio.h> 
#include <stdbool.h>

int f(int i, char *s, bool b1, bool b2)
{
    if (i == 3)
        return b1;
    if (!i || s)
        return i;
    if (s)
        return 7;
    if (b1 == b2)
        return 3;

    return 2;
}

int main()
{
    printf("Boolean type checking\n");

    return 0;
}