#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])   /* Function main() takes an integer and array as input. argc = argument count (# words user types at prompt); argv = argument vector (stores all strings someone
types at the prompt) */
{
    if (argc >= 2)
    {
        printf("hello, %s\n", argv[1]);     // argv[0] will always be the filename. Try something like ./argv David at the CLI.
    }
    else
    {
        printf("hello, world\n");
    }
}