#include <stdio.h>
#include <stdbool.h>   
    
bool isPalindrome (FILE* s) {
    char *current = (char *) s;
    int i, len = (int) strlen (s);
    for (i = 0; i <= (len+1) / 2; i++) {
        if (current[i] != s[len-i-1])
            return false;
    }

  return true;
}

bool callPal (void) {
    return (isPalindrome ("bob"));
}

int main() {    
    printf("Information hiding violations");
    
    return 0;
}