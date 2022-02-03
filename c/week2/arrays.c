/* We can store the 'scores' listed in the main function in memory.c within an array, which the format is as follows. */

#include <stdio.h>
#include <cs50.h>
void array(void)
{
    int scorestest[3]; // # in square brackets denotes number of elements.
    scorestest[0] = 72;
    scorestest[1] = 73;
    scorestest[2] = 33;
}

// We can also declare constants, whose value will never change (similar to Python tuples?).


// Now let's update the scores code more concisely and with better practice.
float average(int length, int array[]); // Prototype function

int main(void)
{
    const int TOTAL = 3;    // Convention to capitalize const variables names to indicate const.
    int scores[TOTAL];      // Define array
    for (int i = 0; i < TOTAL; i++)     // Loop through index 0 to index TOTAL - 1.
    {
        scores[i] = get_int("Input score %i: \n", i); // Not hardcoding values for 'scores[]'
    }
    // printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / TOTAL) <-- note indexing the array won't work well because we're referring to hardocded values. Let's define an avg function.
    printf("Average: %f\n", average(TOTAL, scores));
}

float average(int length, int array[])  // This function takes the length of an array and the array itself (we can pass arrays as parameters by including the square brackets w/o a value in them)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float) length;    // Cast float type to integer division.
}

