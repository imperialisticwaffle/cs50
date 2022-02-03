#include <math.h>
#include <stdio.h>

int main(void)
{
    int voter_count = 99;
    int maj = floor(voter_count / 2) + 1;
    printf("Majority: %i\n", maj);
}