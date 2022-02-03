// Global variables are traditionally initialized to 0 or nul for you--but it is ALWAYS good practice to initialize any and all variables.

#include <stdio.h>

void swap(int a, int b);
void swap2(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(x, y);
    printf("x is %i, y is %i\n", x, y);

    printf("x is %i, y is %i\n", x, y);
    swap2(&x, &y);
    printf("x is %i, y is %i\n", x, y);
}

void swap(int a, int b)
{
    int tmp = 0;
    tmp = a;
    a = b;
    b = tmp;
}

/* Memory is organized by sections; at the top is machine code (binary), below that is the global variables, and below that is heap. When malloc() is called, we use memory from the top of the
heap. When we call functions, however, we use memory from the bottom of the heap, called the stack, to store local variables or parameters.

The issue with the function above is that it modifies copies of x and y (under the guise of a and b) locally, within the function. The original values of x and y are left unchanged. Hence when
main() is run, x and y stay the same even though swap() runs fine. We can fix this with pointers. */

void swap2(int *a, int *b)
{
    int tmp = 0;    // This is fine staying as an int value, we don't need a pointer
    tmp = *a;       // Set tmp = whatever is at the address of a
    *a = *b;
    *b = tmp;
}

/* Fun bit of knowledge: stack overflow (like the website) refers to the act of calling functions so many times that it runs into the heap section of memory.

Likewise, a buffer overflow is when you allocate (or use malloc) an array and go too far past the end of it (or the allocated memory). */