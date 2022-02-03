#include <stdio.h>
#include <cs50.h>

void bricks(void) {
    for (int i = 0; i < 4; i++) {
        printf("?");
    }
    printf("\n");
}

/* ^^ This is effectively the same as:
printf("????\n")

Using the loop rather than hardcoded values is preferable. */

// We can combine the code from positive.c with mario.c:
int main(void) {
    // Get positive int
    int n;
    do {
        n = get_int("Input a width: ");
    }
    while (n < 1);

    // Print out n question marks
    for (int x = 0; x < n; x++) {
        printf("?");
    }
    printf("\n");
}

/* If you wanted to print out a grid of bricks, you could do the following with nested for loops:
int main(void) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("#");
        }
        printf("\n");
    }
}

*/
