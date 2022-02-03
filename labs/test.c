#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = sizeof(int16_t);

    printf("size of int16_6 is %i\n", n);

    uint8_t test = 255;
    printf("%hhu\n", test);

    printf("%i\n", 9 / 2);
}
