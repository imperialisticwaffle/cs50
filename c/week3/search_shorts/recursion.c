/* We might describe a solution to a problem as being 'elegant' if it solves a problem in an interesting and easy to visualize manner.

Recursion is one such method for implementing elegant solutions. Recursive functions are functions that, when executed, invoke themselves.

We can define the mathematical factorial as a recursive function:
fact(1) = 1
fact(2) = 2 * 1     OR      2 * fact(1)
fact(3) = 3 * 2 * 1     OR      3 * fact(2)
etc.

Generalizing, we see that fact(n) = n * fact(n - 1).

For all recursive functions, we need:
1. A base case, which when triggered will terminate the recursive process.
2. The recursive case, which is where the recursion will actually occur.

Generally but not always recursive functions replace loops in non-recursive functions. It is also possible to have more than one bsae case if the program might recurse or terminate in different
ways depending on input being passed in.
Multiple base cases: Fibonacci number sequence (sum of the preceding two numbers)
Multiple recursive cases: the Collatz Conjecture
    - The CC states that it is always possible to get back to 1 if:
        1. If n = 1, stop.
        2. If n % 2 = 0, repeat this process on n/2.
        3. If n % 2 = 1, repeat this process on 3n + 1.*/

#include <stdio.h>
#include <cs50.h>

int fact(int n);
int fact2(int n);
int collatz(int n);

int main(void)
{
    printf("Num. steps: %i\n", collatz(27));
}

int fact(int n)     // If there is only one line of code inside the curly braces we can take said braces out.
{
    // base case
    if (n == 1)
        return 1;
    // recursive case
    else
        return n * fact(n - 1);     // We continue going backward until we hit the base case, at which point we stop.
}

int fact2(int n)    // This is the iterative method, as opposed to the recursive method outlined above.
{
    int product = 1;
    while (n > 0)
    {
        product *= n;
        n--;
    }
    return product;
}

int collatz(int n)
{
    if (n == 1)
        return 0;
    else if (n % 2 == 0)
        return 1 + collatz(n / 2);
    else
        return 1 + collatz((3 * n) + 1);
}

// Here is an explanation of why we write 1 + collatz(): https://stackoverflow.com/questions/61809826/cs50-why-is-return-value-1-collatz-and-not-just-collatz