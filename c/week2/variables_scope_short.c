/* Scope defines from which functions a variable may be accessed. Local variables can only be accessed in the function they were defined in; global variables are defined outside of any function,
including main(), and can be accessed by any function as such. */

#include <stdio.h>
#include <cs50.h>

int increment(int x);

int main(void)
{
    int x = 1;
    int y;
    y = increment(x);
    printf("x is %i, y is %i\n", x, y);
}

int increment(int x)
{
    x++;
    return x;
}

// This gives us x = 1 and y = 2, because we pass main()'s local variable of x into the function increment(int x).