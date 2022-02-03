#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("missing command line argument\n");
        return 1;   // We can access this designated error code integer by typing 'echo $?'' at the CLI.
    }
    else
    {
        printf("hello, %s\n", argv[1]);
        return 0;
    }
}