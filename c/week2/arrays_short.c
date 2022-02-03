/* C arrays are zero indexed. Last element index is n - 1. Be careful, as C will not prevent you from indexing out of bounds. The convention for array declaration is:
type name[size];

We can also initialize small arrays via the following code:
e.g. bool truthtable[3] = {true, false, false}  <-- Note that if you initialize an array like this you don't need to specify the size in the square brackets.

We can create 'multidimensional' arrays (e.g. int battleship[10][10]) and visualize them like grids. In reality multidimensional arrays are just 1 dimensional arrays of length dimension
by dimension...by dimension (e.g. battleship[10][10] == battleship[100]).

We cannot treat entire arrays as variables (i.e. foo[5] = bar[5] is NOT valid code). Instead we need a for loop to copy over each element one at a time.

Arrays are actually passed themselves to a function call, not like regular variables which, when passed, become a copy of themselves. See code below: */

#include <stdio.h>
#include <cs50.h>

void set_array(int array[4]);
void set_int(int x);

int main(void)
{
    int a = 10;
    int b[4] = {0, 1, 2, 3};
    set_int(a);
    set_array(b);
    printf("%d %d\n", a, b[0]);
}

void set_array(int array[4])
{
    array[0] = 22;
}

void set_int(int x)
{
    x = 22;
}

// main() prints out 10 and 22 respectively, because the array itself gets passed to the function rather than being made as a copy.