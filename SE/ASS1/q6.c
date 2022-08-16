#include <stdio.h>
# include <string.h> 

void capitalize (/*@out@*/ char *s, char *t) {
    strcpy (s, t);
    *s = toupper (*s);
}

int main() {    
    printf("Dangerous aliasing");
    
    return 0;
}