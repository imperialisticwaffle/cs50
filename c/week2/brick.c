#include <stdio.h>
#include <cs50.h>
#include <string.h> // Used for strlen()

int custom_string(void);


int main(void)
{
    char c = '#';
    printf("%i\n", (int) c);


/* It turns out casting an int to a char value will actually give its ascii designated integer.
It also turns out that a string really is just an ARRAY of characters; # characters + 1 = # bytes of string, because there is a null character (\0, ASCII: 0) at the end of the string to indicate
stop point. */
    string s = "HI!";
    printf("%c%c%c\n", s[0], s[1], s[2]);
    printf("%i %i %i\n", s[0], s[1], s[2]);
    printf("%i %i %i %i\n", s[0], s[1], s[2], s[3]);

    custom_string();    // Function calls are performed in main() function in C.
}

// We can use this logic of arrays to print out anything character by character.
int custom_string(void)
{
    string t = get_string("Input: ");
    printf("Output: ");
    for (int i = 0, n = strlen(t); i < n; i++)
    {
        printf("%c", t[i]);
    }
    printf("\n");
    return 0;
}

/* Because strings are arrays of characters, we can have an array of arrays of characters (array of strings), and we can index each individual character in the array of strings by using double
square bracket notation. */