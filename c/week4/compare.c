#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int i = get_int("i: ");
    int j = get_int("j: ");

    if (i == j)
        printf("Same\n");
    else
        printf("Different\n");

    char *s = get_string("s: ");
    char *t = get_string("t: ");

    if (*s == *t)       // Need to compare pointer values rather than addresses (without the '*').
        printf("Same\n");
    else
        printf("Different\n");
}