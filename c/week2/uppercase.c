// Goal: convert any lowercase letters to uppercase. VISIT MANUAL.CS50.IO FOR A LIST OF MODULES/LIBRARIES TO USE
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int uppercase(void);

int main(void)
{
    string s = get_string("Input: ");
    printf("Output: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')     // We can treat the chars here like ASCII integers.
        {
            printf("%c", s[i] - 32);    // Lowercase to uppercase is -32 for all 26 letters in ASCII.
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");

    uppercase();
}

int uppercase(void)
{
    string t = get_string("Input string #2: ");
    printf("Output #2: ");
    for (int i = 0, n = strlen(t); i < n; i++)
    {
            printf("%c", toupper(t[i]));    // From ctype.h
    }
    printf("\n");
    return 0;
}