#include <stdio.h> /* Standard Input Output.h */
#include <cs50.h> /* Like Python's import statement. */
int main(void) /* Function definition. 'Int' defines returned data type; 'main' always returns int values. This is the convention: return_type function_name( parameter list )*/
{
    string answer = get_string("What is your name? ");
    printf("hello, %s\n", answer); /* \n creates a new line.*/
}

/* Each time you make a change to your code you must recompile it. Note that the 'make' and './filename' conventions perform the same action and the "run code"/play button in VSCode's editor.*/
/* Header files, the ".h" statements, give you more access to other functions than you would normally get without the statements.*/

/* help50 is a help tool that can be added in front of the compile statement in the CLI to explain in layman's terms where you may have missed/formatted something incorrectly.
style50 is a help tool that helps you format your code nicely and in a readable fashion. And last, check50 helps you check the correctness of your code. */