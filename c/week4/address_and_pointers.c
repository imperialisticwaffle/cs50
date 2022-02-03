#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = 50;     // This will take up 4 bytes in our computer's memory (32 bits).
    printf("%p\n", &n);     /* The ampersand is the "address of" operator (tell me what address this variable is stored in). The asterisk "*" tells the computer to look inside an address (go to
    said address). %p is the format code for printing out the address of variables. */
    printf("%i\n", *&n);    // This is the same as just printing out n, but for the sake of rigor we can see that the program literally says "go to the address of n".
    int *p = &n;
    printf("%p\n", p);  // Prints the address of n, stored in a pointer variable. Again, we print out the value of n by using *p.

    string s = "HI!";
    printf("%p\n", s);  // This gives us the memory address of the first char in the string.
    printf("%p\n", &s[1]);      // This should be immediately after the first byte of memory above.

    char *s2 = "HI!!";      // This is the exact same as "string".
    printf("%c\n", *s2);     // Because s is a pointer variable to the first character of "HI!", we can access that character by using '*' to go to the address of s.
    printf("%c\n", *(s2 + 1));      // Pointer arithmetic!
    printf("%c\n", *(s2 + 2));

}

/* Here we get into pointers, which are variables containing the address of some other value. Pointers reference the specific type of variable it is referring to. Pointers also take up 8 bytes.

Abstraction is the removal of lower level details that are not necessary to be fussed over.

For strings, since they are an array of characters, and by extension arrays of values are stored back to back to back in memory, it is sufficient to conclude that we only need to know where
the string begins in our computer's memory. */