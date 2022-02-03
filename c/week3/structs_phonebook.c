// We can create our own custom datatypes in C; let's say we want to create a 'persons' datatype for the phonebook problem.
#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct {
    string name;    // Specify data types you want and names of those data types.
    string number;
}
person;     // Name of whole data type you want to invent.

/* We could implement a basic phonebook problem with two separate arrays for names and phone numbers, and index the names array until we get to the desired name and index the numbers array
with that specific index.

The problem with this is that we may unintentionally 'unlink' the two arrays, which may displace numbers from their respective person. */

int main(void) {
    person people[2];
    people[0].name = "Brian";
    people[0].number = "+1-617-495-1000";
    people[1].name = "David";
    people[1].number = "+1-949-468-2750";

    for (int i = 0; i < 2; i++) {
        if (strcmp(people[i].name, "David") == 0) {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}