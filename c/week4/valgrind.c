#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // We will assign a string to a char pointer manually
    char *s = malloc(4);    // Changed from 3 to 4
    s[0] = 'H';
    s[1] = 'I';
    s[2] = '!';
    s[3] = '\0';
    printf("%s\n", s);

    /*  We can check for errors in this program with "valgrind ./'filename'" at the CLI. In the output of valgrind, write refers to changing a value; read refers to reading, using, or printing
    a value. You will receive a memory leak notice if you did not free up the allocated memory. */
    free(s);

    // IF YOU TRY TO DE-REFERENCE AN UNINITIALIZED VARIABLE, YOUR PROGRAM MAY CRASH. (if you try to use the asterisk '*' to go to the memory address of a variable and assign a value there)
}