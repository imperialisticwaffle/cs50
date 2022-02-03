#include <stdio.h>
#include <cs50.h>
int main(void) {
    int x = get_int("What is x?: ");
    int y = get_int("What is y?: ");
    float z = (float) x / (float) y;
    printf("%f\n", z);
}

// Note that if x and y are integers, your result will be an integer even if defined to be a float. Integers don't hold decimal values and the float will just print zeros.
// Also note that while you could go back and change all of your code to be 'floats', you can "cast" or "typecast" one data type to another.