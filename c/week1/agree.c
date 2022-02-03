#include <stdio.h>
#include <cs50.h>

int main(void) {
    char c = get_char("Do you agree? (y/n) ");
    
    if (c == 'y' || c == 'Y') { // If performing boolean comparisons on charaacters, we need SINGLE quotes. || is logical OR operand.
        printf("Agreed.\n");
    }
    if (c == 'n' || c == 'N') {
        printf("Not agreed.\n");
    }
    
}