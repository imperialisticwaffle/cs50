#include <stdio.h>
#include <cs50.h>

int get_positive_int(void); // Function 'prototype' - to be defined later

int main(void) {
    int i = get_positive_int();
    printf("%i\n", i); // Format codes go first
}

int get_positive_int(void) { // Reminder that 'void' indicates no parameters, but function returns an int value.
    int n; // Declare variable
    do {                    // Do-while loops do one thing blindly first before checking a condition (i.e. getting an integer from a user before checking if that int (n) is < 1. If so, repeat.)
        n = get_int("Input postiive integer: ");
    }
    while (n < 1);
    return n;
}

/* Note that if we declared n in the do-while loop (line 13), we would be unable to check its condition in line 15 or return it in line 16. This is because of the issue of scope. */