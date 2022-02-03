#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
            //  A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q   R  S  T  U  V  W  X  Y  Z

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    printf("%s %i\n", "Player 1 score: ", compute_score(word1));
    printf("%s %i\n", "Player 2 score: ", compute_score(word2));
    if (compute_score(word1) > compute_score(word2))
    {
        printf("Player 1 wins!\n");
    }
    else if (compute_score(word1) < compute_score(word2))
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int sum = 0, ind = 0;
    for (int i = 0, n = strlen(word); i < n; i++)     // Break down word letter by letter for their scores
    {
        if (isupper(word[i]))   // If uppercase
        {
            ind = word[i] - 65;     // According to ASCII, 'A' is int 65, so we subtract 64 to get 1. This will be our index for POINTS[].
            sum += POINTS[ind];
        }
        else if (islower(word[i]))
        {
            ind = word[i] - 97;
            sum += POINTS[ind];
        }
        else
        {
            sum += 0;
        }
    }
    return sum;
}
