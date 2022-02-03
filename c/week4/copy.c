#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>     // For malloc()
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");
    char *t = s;    // Copy s to t
    t[0] = toupper(t[0]);   // Change first letter of t to uppercase

    printf("s: %s\n", s);
    printf("t: %s\n", t);
    /* These two print statements will print out s normally, s with a capital first letter, and t with a capital first letter. This is because we are LITERALLY assigning the pointer of string s
    to t--thus making them one and the same string as the address is the same. So when we modify t, we modify s. */

    // If you wanted to copy one string to another new one, you would need to allocate new memory and loop over the elements inside the char array.

    char *s1 = get_string("s1: ");
    char *t1 = malloc(strlen(s1) + 1);        // + 1 to account for nul terminator.
    if (t1 == NULL)     // If t1 is unable to be assigned a memory address
        return 1;

    for (int i = 0, n = strlen(s1); i <= n; i++)     // Include <= n to account for nul terminator.
        t1[i] = s1[i];
    t1[0] = toupper(t1[0]);
    printf("s1: %s\n", s1);
    printf("t1: %s\n", t1);

    free(t1);   // Good practice to free up allocated memory. Free() takes as input the address malloc gave
}