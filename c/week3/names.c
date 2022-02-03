#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void) {
    string names[] = {"Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"};
    for (int i = 0; i < 7; i++) {
        // In C, we can't compare strings with an '=='. This works in other languages like Python, but not in C. Thus we use strcmp().
        if (strcmp(names[i], "Ron") == 0) {     // strcmp() returns a value that must be compared with an int for an if statement to work.
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}

/* Note that strcmp() returns '0' if the two strings are the same letter for letter ASCII wise. If the first string comes before the second string ASCII wise, it returns a negative value.
And finally if the first string comes after the second string ASCII wise, it returns a positive value. */