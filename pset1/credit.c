/*
    Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
    Add the sum to the sum of the digits that weren’t multiplied by 2.
    If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
    All American Express numbers start with 34 or 37; most MasterCard numbers start with 51, 52, 53, 54, or 55 (they also have some other potential starting numbers which we won’t concern
    ourselves with for this problem); and all Visa numbers start with 4.
*/
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long cc;
    cc = get_long("Input credit card number: ");
    int len = (floor(log10(cc))) + 1;
    if (len != 13 && len != 15 && len != 16)
    {
        printf("INVALID\n");
    }
    else
    {
        int sum1 = 0, sum2 = 0, rem = 0, pl = 0;
        long cc2 = cc, cc3 = cc;
        if (len % 2 == 0)   // If length is even (case is different)
        {
            while (cc2 > 1)
            {
                if (cc2 == cc) // For second last digit, special case
                {
                    cc2 /= 10; // rm last digit
                    if (2 * (cc2 % 10) > 9) // if 2 * last digit of cc2 is a two digit num
                    {
                        sum1 += (2 * (cc2 % 10)) / 10; // get first digit
                        sum1 += (2 * (cc2 % 10)) % 10; // get second digit
                    }
                    else
                    {
                        sum1 += 2 * (cc2 % 10); // get new last digit
                    }
                }
                else
                {
                    cc2 /= 100; // rm last digit
                    if (2 * (cc2 % 10) > 9) // if 2 * last digit of cc2 is a two digit num
                    {
                        sum1 += (2 * (cc2 % 10)) / 10; // get first digit
                        sum1 += (2 * (cc2 % 10)) % 10; // get second digit
                    }
                    else
                    {
                        sum1 += 2 * (cc2 % 10); // get new last digit
                    }
                }
            }
            while (cc3 > 10)
            {
                rem = cc3 % 10; // get last digit
                sum2 += rem;
                cc3 /= 100;     // get to third last digit, then 5th, then 7th, etc.
            }
        }
        else                // If length is odd
        {
            while (cc2 > 10)
            {
                if (cc2 == cc) // For second last digit, special case
                {
                    cc2 /= 10; // rm last digit
                    if (2 * (cc2 % 10) > 9) // if 2 * last digit of cc2 is a two digit num
                    {
                        sum1 += (2 * (cc2 % 10)) / 10; // get first digit
                        sum1 += (2 * (cc2 % 10)) % 10; // get second digit
                    }
                    else
                    {
                        sum1 += 2 * (cc2 % 10); // get new last digit
                    }
                }
                else
                {
                    cc2 /= 100; // rm last digit
                    if (2 * (cc2 % 10) > 9) // if 2 * last digit of cc2 is a two digit num
                    {
                        sum1 += (2 * (cc2 % 10)) / 10; // get first digit
                        sum1 += (2 * (cc2 % 10)) % 10; // get second digit
                    }
                    else
                    {
                        sum1 += 2 * (cc2 % 10); // get new last digit
                    }
                }
            }
            while (cc3 > 1)
            {
                rem = cc3 % 10; // get last digit
                cc3 /= 100;     // get to third last digit, then 5th, then 7th, etc.
                sum2 += rem;
            }
        }
        if ((len == 16) || (len == 13))
        {
            if (((sum1 + sum2) % 10 == 0) && (floor((cc / ((double) pow(10, (len - 1)) + 0.5))) == 4))
            {
                 printf("VISA\n");
            }
            else if ((len == 16) && ((floor((cc / ((double) pow(10, (len - 2)))))) < 56) && ((floor((cc / ((double) pow(10, (len - 2)))))) > 50) && ((sum1 + sum2) % 10 == 0)) // Determine if first 2 digits are 51 to 55
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");   
            }
        }
        else if (len == 15 && (sum1 + sum2) % 10 == 0)
        {
            if ((floor((cc / ((double) pow(10, (len - 2)) + 0.5))) == 34) || (floor((cc / ((double) pow(10, (len - 2)) + 0.5))) == 37))
            {
                 printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
}



/*
    for (long fac = 10 ^ len; fac < 10 + 1; fac /= 100)
    {
        for (int pos = 0; pos < (len + 1); pos++)
        {
            int numbers[pos] = cc % fac
        }
    }
}
*/