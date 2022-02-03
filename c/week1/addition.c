#include <stdio.h>
#include <cs50.h>
int main(void)
{
    float x = get_float("Input a value for x: ");
    float y = get_float("Input a value for y: ");
    printf("%f\n", x + y);
}