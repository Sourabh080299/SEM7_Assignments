#include <stdio.h>
//function-like macro
#define abs(i) ((i) >= 0 ? (i) : -(i))

int main()
{
    int x = -8;
    // Should return 7 but returns 6
    printf("\nMacro expected value: 7\nActual value: %d\n\n", abs(++x));
    return 0;
}