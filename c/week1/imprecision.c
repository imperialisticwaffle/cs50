/* Computers due to the finite nature of their memory cannot count infinitely high or infinitely precisely. See the following by running the code: */

#include <stdio.h>
#include <cs50.h>

int main(void) {
    float x = get_int("x: ");
    float y = get_int("y: ");
    printf("%.50f\n", x / y);   // %.50 means show 50 decimal places.
}
