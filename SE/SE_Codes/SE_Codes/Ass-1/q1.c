#include <stdio.h>
char firstChar1(/*@null@*/ char *s)
{
    return *s;
}
char firstChar2(/*@null@*/ char *s)
{
    if (s == NULL)
        return '\0';
    return *s;
}
int main()
{
    printf("\n\n->derefencing null ptr\n\n");
    return 0;
}