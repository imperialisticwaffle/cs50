// int counter = 0;
// counter++; <-- This is equal to counter += 1.

// If statements work as follows.

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float x = get_float("x: "); // Prompt for x
    float y = get_float("y: "); // Prompt for y

    if (x > y) {                // Comparison
        printf("x is > y\n");
    }
    else if (x < y) {
        printf("x is < y\n");
    }
    else {
        printf("x = y\n");
    }
}

/* 
while(true) {   // This is your standard "forever" loop (true is true so if always true it always repeats)
    
}