/* The Coleman-Liau index of a text is designed to output what (U.S.) grade level is needed to understand the text. The formula is:

index = 0.0588 * L - 0.296 * S - 15.8

Here, L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.
Your program should print as output "Grade X" where X is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.
If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output "Grade 16+" instead of giving the exact index
number.
If the index number is less than 1, your program should output "Before Grade 1".

Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was
forced to do it in secret, in the dead of the night. And he also happened to be a wizard.

This text has 214 letters, 4 sentences, and 56 words. That comes out to about 382.14 letters per 100 words, and 7.14 sentences per 100 words. Plugged into the Coleman-Liau formula, we get a
fifth grade reading level.
*/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int count_letters(string str);
int count_words(string str1);
int count_sentences(string str2);

int main(void)
{
    string text = get_string("Text: ");
    printf("Total letters: %i\n", count_letters(text));
    printf("Total words: %i\n", count_words(text));
    printf("Total sentences: %i\n", count_sentences(text));
    float words = count_words(text);
    float sentences = count_sentences(text);
    float letters = count_letters(text);
    float wavg = 100 / words;
    float L = letters * wavg;
    float S = sentences * wavg;
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    if ((int) round(index) < 1)
    {
        printf("Before Grade 1\n");
    }
    else if ((int) round(index) > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}

int count_letters(string str)
{
    int total = 0;
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        if (isupper(str[i]) || islower(str[i])) // Any uppercase/lowercase letters, nonletter characters excluded
        {
            total += 1;
        }
        else
        {
            total += 0;
        }
    }
    return total;
}

int count_words(string str1)    // 1 word off, currently.
{
    int wtotal = 0;
    for (int i = 0, n = strlen(str1); i < n; i++)
    {
        if ((str1[i] == 33 && str1[i + 1] == 0) || (str1[i] == 46 && str1[i + 1] == 0) || (str1[i] == 63 && str1[i + 1] == 0) || (str1[i] == 34 && str1[i + 1] == 0))    // Count last word
        {
            wtotal += 1;
        }
        else if (str1[i] == 32)   // If space, count as word
        {
            wtotal += 1;
        }
        else if (isupper(str1[i]) || islower(str1[i]) || str1[i] == 45 || str1[i] == 39 || str1[i] == 46 || str1[i] == 33 || str1[i] == 58 || str1[i] == 59 || str1[i] == 44)  // If str1[i] is "- ' . ! : ; ,"
        {
            wtotal += 0;
        }
        else
        {
            wtotal += 0;
        }
    }
    return wtotal;
}

int count_sentences(string str2)
{
    int stotal = 0;
    for (int i = 0, n = strlen(str2); i < n; i++)
    {
        if ((str2[i] == 46 && isupper(str2[i - 3])) || (str2[i] == 46 && isupper(str2[i - 2])))    // Account for Mr. Mrs. Dr. Ms. etc.
        {
            stotal += 0;
        }
        else if ((str2[i] == 33 && str2[i + 1] == 0) || (str2[i] == 46 && str2[i + 1] == 0) || (str2[i] == 63 && str2[i + 1] == 0) || (str2[i] == 34 && str2[i + 1] == 0))    // Count last word
        {
            stotal += 1;
        }
        else if ((str2[i] == 33 && str2[i + 1] == 32) || (str2[i] == 46 && str2[i + 1] == 32) || (str2[i] == 63 && str2[i + 1] == 32))    // If current char is punctuation and next char is space
        {
            stotal += 1;
        }
        else
        {
            stotal += 0;
        }
    }
    return stotal;
}