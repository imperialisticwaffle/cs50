/* So far we've written all our programs inside of main(), but C allows us to write our own functions (procedures, methods, subroutines).
A function is a 'black box' with 0+ inputs and 1 output. We use functions for the following reasons:
1. Organization: functions break up code into more manageable subparts
2. Simplification: smaller subparts tend to be easier to manage, design, and debug
3. Reusability: functions can be recycled since you only need to write them once and can reuse them as many time as you need

We first want to declare our functions atop our code, before we start writing main() (prototyping). Typically they look like this:
return-type name(argument-list);
The input variables' names are not what they explicitly need to be called when writing the function, so any name will do. */