/* When we compile programs in C we use a compiler called "clang". "clang" is also a command included in the CS50 IDE, and is executable in the CLI. We can type "clang" 'filename', which produces
an 'a.out' (assembly output) file, rather than an executable in binary with the same filename as what we compiled.

Commands like 'rm' or 'make' take command line arguments, most common of which we use is simply 'filename'. 'clang' takes CLAs as well.
e.g. clang -o hello hello.c translates to: run clang, output a file called 'hello', and take as input a file called hello.c

In many cases the -o will not be enough; because we are referring to cs50's custom library, we will need to include another CLA '-lcs50'; this tells the computer that, when compiling, make sure
to incorporate all the machine code from cs50's library as well.

*/

#include <stdio.h>
#include <cs50.h>
int main(void)
{
    string name = get_string("What is your name? ");
    printf("hello, %s\n", name);
}

/* The compiling process has 4 steps: preprocessing, compiling, assembling, and linking.
Preprocessing involves the header files (#includes) which essentially define prototype functions that will be used in your code later.
Compiling, in the more precise sense, means to convert your source code (like above) into another type of source code (assembly code).
Assembling means to take the assembly code from the compile step and finally convert it to machine code (binary).
Linking links the binary code of your source code to the binary code of cs50.h and to the binary code of stdio.h, combining them into one giant binary code blob.

Call stack in debug50 refers to all the functions your program has executed and not yet returned from. The 'step into' button allows you to dive into function calls/functions