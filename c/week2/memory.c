/* Data types take up memory, as you'll recall.
bool: 1 byte
char: 1 byte
double: 8 bytes
float: 4 bytes
int: 4 bytes
long: 8 bytes
string: ? bytes

When you open a file, that file is temporarily stored in RAM. RAM is also volatile; it requires electricity to keep it running (when your battery dies mid-paragraph/file you lose that data).
The switches that are flipped to represent binary digits are stored in RAM; these also mean that RAM has size, in a physical/data sense (depending on the number of switches, ram is a certain
number of bytes (mega/giga/etc.)). So, when you run a program that includes a char data type, the char you are storing in that variable may well be stored in a specific square/location in RAM 
(if we think about RAM as a divided grid to represent bytes spacially). */

#include <stdio.h>
int main(void)
{
    int score1 = 72;
    int score2 = 73;
    int score3 = 33;
    printf("Average = %f\n", (score1 + score2 + score3) / 3.0);
}
/* Note that if you did "/3", you would get an error because you are forcing an integer type into a float-formatted string. Methods of resolving this include casting (float) in front of the
variables (numerator/denominator), but the simplest fix is converting 3 to 3.0 (float). */
