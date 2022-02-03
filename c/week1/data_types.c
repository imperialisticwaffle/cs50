/* Data Types:
bool, char, double, float, int, string, long...

Some of these data types have a finite number due to limiting bits. For example an int has 32 bits, and thus cannot go past 4 billion written in binary. Type 'long' adds more numbers that can
be expressed in binary.

printf() using format codes can print out other data types:
%c - char
    - Used for variables that will store single characters. Chars take up 1 byte of memory (8 bits) meaning the range of values (-128 to 127) is necessarily limited by 8 bits worth of imformation
    - ASCII maps characters like a, b, c to numerical positive values of the range mentioned above

%f - float
    - Used for variables that will store real numbers. Floats always take up 4 bytes of memory (32 bits)
    - Float ranges are a bit difficult to say but given that a part of the 32 bits is used for the integer portion of a float we are limited in how PRECISE we can be
    - DOUBLE is like float; it differs from float in that double is 64 bits (8 bytes of memory). With an additional 32 bits of precision we specify more precise real nubmers.

%i - int
    - Ints take up 4 bytes of memory (32 bits), meaning that the range of values they can store is necessarily limited to 32 bits (roughly -2 bill to 2 bil)
    - Unsigned is a qualifier that can be applied to certain data types and effectively doubles the positive range of values of that type at the cost of disallowing negative values.
        - This means for int data types the range is from 0 to approximately 4 bill.
%li - long

%s - string

void
    - A type, but not a data type. Functions can have a void return type (meaning they don't return any values). The parameter list of a function can also be void.
    - It may be easier to think of 'void' as 'nothing'

bool
    - Stores only true or false; not included by default in C but is part of the cs50 library so be sure to include it if necessary.

string
    - Series of characters; not included by default in C but is part of the cs50 library so include it if necessary.

C supports your standard math operators, including remainder (%).

To declare variables, you only need to declare the data type and give the variable a name, and then add a semicolon (like JavaScript).
If you want to create MULTIPLE variables of the same type you only need to specify the data type once. It's good practice to declare variables only when you need them.

Redeclaring a variable's type can have unintended consequences, so don't do it. Moreover, consolidating the declaration and assignment steps is called 'initialization'
>> int number = 17 <-- initialization
*/