#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long cc;
    int first = 0;
    cc = get_long("Input credit card number: ");
    int len = (floor(log10(cc))) + 1;
    first = (floor((cc / ((double) pow(10, (len - 2))))));
    printf("%i\n", first);
}