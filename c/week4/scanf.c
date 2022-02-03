#include <stdio.h>

int main(void)
{
    int x;
    printf("x: ");
    scanf("%i", &x);
    printf("x: %i\n", x);

    char *s;        // This section of code will return (null) because we have declared a pointer value but have not assigned it anything.
    printf("s: ");
    scanf("%s", s);     // No need for *s as s is already a pointer value
    printf("s: %s\n", s);

    char s1[4];     // We can also make the pointer *s work by intitializing it to malloc().
    printf("s1: ");
    scanf("%s", s1);     // No need for *s as s is already a pointer value
    printf("s1: %s\n", s1);     // This will only work if the length of the string inputted is 3 letters (and a nul terminator).
}