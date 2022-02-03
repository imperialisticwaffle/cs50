/* Alice has two votes, Bob has three votes, and Charlie has four votes. To win an election with nine people, a majority (five votes) is required. Since nobody has a majority, a runoff needs
to be held. Alice has the fewest number of votes (with only two), so Alice is eliminated. The voters who originally voted for Alice listed Bob as second preference, so Bob gets the extra two
vote. Bob now has five votes, and Charlie still has four votes. Bob now has a majority, and Bob is declared the winner.

What corner cases do we need to consider here?

One possibility is that there’s a tie for who should get eliminated. We can handle that scenario by saying all candidates who are tied for last place will be eliminated. If every remaining
candidate has the exact same number of votes, though, eliminating the tied last place candidates means eliminating everyone! So in that case, we’ll have to be careful not to eliminate
everyone, and just declare the election a tie between all remaining candidates.

Some instant runoff elections don’t require voters to rank all of their preferences — so there might be five candidates in an election, but a voter might only choose two. For this problem’s
purposes, though, we’ll ignore that particular corner case, and assume that all voters will rank all of the candidates in their preferred order. */


#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];    // Both MAX_VOTES AND MAX_CANDIDATES are INT types--MAX_CANDIDATES is the index into the candidates[] array.

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];   // Assign each element in argv starting at index 1 to array candidates (names)
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)   // For each voter
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)   // For each candidate
        {
            string name = get_string("Rank %i: ", j + 1);   // Get string input and rank candidate at j + 1th rank

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();     // Look at all of the voters’ preferences and compute the current vote totals, by looking at each voter’s top choice candidate who hasn’t yet been eliminated

        // Check if election has been won
        bool won = print_winner();  // If winner, print and program exits.
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();   // If no winner on first iteration, find minimum candidate and eliminate.
        bool tie = is_tie(min); // If everyone happens to be tied with same number of votes

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)     // line 91, voter = i, rank = j, name = name. Already called on every iteration, no need to nest for loops in function vote()
{
    // TODO
    for (int i = 0; i < candidate_count; i++)   // Check all candidates for string match, 0 indexed
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            // candidates[i].votes += 1;    // Increase candidate tally *** HOLDING OFF ON THIS LINE OF CODE FOR NOW, PERHAPS CALCULATE VOTES IN TABULATE()
            preferences[voter][rank] = i;   // Store index of candidate (i) at "rank" rank of "voter" voter
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO
    for (int i = 0; i < voter_count; i++)   // We want to go through each voter
    {
        int rank = 0;   // Redefine var rank inside for loop because we need to start at rank 0 for EVERY voter.
        if (candidates[preferences[i][rank]].eliminated == false)
        {
            candidates[preferences[i][rank]].votes += 1;    // Using the candidate index of each voter's top choice (of this iteration), add 1 vote to that candidate's tally
        }
        else if (candidates[preferences[i][rank]].eliminated == true)
        {
            do
            {
                rank += 1;
            }
            while (candidates[preferences[i][rank]].eliminated == true);        // Do while block to get to next non-eliminated candidate
            candidates[preferences[i][rank]].votes += 1;
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO
    int maj = floor(voter_count / 2) + 1;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes >= maj)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
    int min = candidates[0].votes, index = 0;
    for (int i = 1; i < candidate_count; i++)
    {
        if (candidates[i].votes < min && candidates[i].eliminated == false)
        {
            min = candidates[i].votes;
            index = i;
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    for (int i = 1; i < candidate_count; i++)
    {
        if (candidates[i].votes != candidates[i - 1].votes && candidates[i].eliminated == false)
            return false;
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min && candidates[i].eliminated == false)
            candidates[i].eliminated = true;
    }
    return;
}
