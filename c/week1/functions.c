#include <stdio.h>
#include <cs50.h>

void meow(void) {   // Python def 'function_name'(params). Note that the first void in function definitions refers to the return type.
    printf("meow\n");
}

void meow2(int n) { // We can pass parameters to functions by specifying the type and giving a variable. Then we transfer in this example the for loop from the main function to this one.
    for (int i = 0; i < n; i++) {
        printf("meow\n");
    }
}

int main(void) {
    meow2(3); // function call
}

/* The following code also works:
void meow(void);    // This tells the compiler that there is a function definition later so calling meow() "before" its definition doesn't result in an error.

int main(void) {
    for (int i = 0; i < 3; i++) {
        meow(); // function call
    }
}

void meow(void) {
    printf("meow\n");
}

*/