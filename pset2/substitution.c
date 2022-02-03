/* In a substitution cipher, we “encrypt” (i.e., conceal in a reversible way) a message by replacing every letter with another letter. To do so, we use a key: in this case, a mapping of each of
the letters of the alphabet to the letter it should correspond to when we encrypt it. To “decrypt” the message, the receiver of the message would need to know the key, so that they can reverse
the process: translating the encrypt text (generally called ciphertext) back into the original message (generally called plaintext).

A key, for example, might be the string NQXPOMAFTRHLZGECYJIUWSKDVB. This 26-character key means that A (the first letter of the alphabet) should be converted into N (the first character of the
key), B (the second letter of the alphabet) should be converted into Q (the second character of the key), and so forth.

Let’s write a program called substitution that enables you to encrypt messages using a substitution cipher. At the time the user executes the program, they should decide, by providing a
command-line argument, on what the key should be in the secret message they’ll provide at runtime. */
#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int duplicates(string str);

int main(int argc, string argv[])
{

    if (argc < 2 || argc > 2)   // Sufficient command line args?
    {
        printf("error: insufficient/excessive command line arguments\n");
        return 1;
    }
    else if (argc == 2 && strlen(argv[1]) != 26)    // Sufficient characters?
    {
        printf("error: insufficient/excessive characters in key\n");
        return 1;
    }
    else
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (argv[1][i] < 65 || (argv[1][i] > 90 && argv[1][i] < 97) || argv[1][i] > 122 || duplicates(argv[1]) >= 1)    // Alphabetic characters? Duplicates?
            {
                printf("error: non-alphabetic or duplicate character\n");
                return 1;
            }
            else if (isupper(argv[1][i]) || islower(argv[1][i]))
            {
                continue;
            }
        }
        string plaintext = get_string("plaintext: ");
        int n2 = strlen(plaintext);
        char ciphertext[n2 + 1];    // Allocate space for the null terminator
        for (int i3 = 0; i3 < n2 + 2; i3++)     // Loop up to strlen(plaintext) + 2 to account for EOS
        {
            if (i3 == n2 + 1)   // Null terminator condition
            {
                ciphertext[i3] = '\0';
            }
            else if (isupper(plaintext[i3]))    // Uppercase
            {
                ciphertext[i3] = toupper(argv[1][(plaintext[i3] - 65)]);
            }
            else if (islower(plaintext[i3]))    // Lowercase
            {
                ciphertext[i3] = tolower(argv[1][(plaintext[i3] - 97)]);
            }
            else    // Non alphabetic characters
            {
                ciphertext[i3] = plaintext[i3];
            }
        }
        printf("ciphertext: %s\n", ciphertext);
    }
}

int duplicates(string str)
{
    int dcount = 0;
    for (int i = 0; i < strlen(str); i++)   // For each letter
    {
        for (int j = i + 1; j < strlen(str); j++)   // For each letter after letter 'i'
        {
            if (toupper(str[i]) == toupper(str[j])) // Case insensitive, check dupes
            {
                dcount++;
            }
            else
            {
                continue;
            }
        }
    }
    return dcount;
}

/* Understand how printf and strlen work. Both of them (and several other functions) depend on the existence of the end of string marker, \0 at the end of the target string. If the EOS marker
isn't there, they will keep reading data from memory until they find some random data byte that looks like the EOS marker, or 0x00.

Next, you need to understand that strlen() returns the number of chars in a string, excluding the EOS marker. BUT, when declared, a string needs to have 1 added to a strlen()
result to allow space for the EOS marker. Your code doesn't allow for this when ciphertext is declared.

More importantly, during processing, the code inserts characters into ciphertext one at a time, BUT IT DOESN'T ADD AN EOS MARKER AT THE END! Even if it did, there's no room for it.
We'll come back to the impact of that.

So, because there's no EOS marker at the end of ciphertext, the printf statement will read whatever physical data follows in memory because it thinks it's part of the string, treating it as
ASCII codes, until it hits a 0x00 byte. That's why it prints random printable and unprintable characters at the end. */