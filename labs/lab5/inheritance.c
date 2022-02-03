/* A person’s blood type is determined by two alleles (i.e., different forms of a gene). The three possible alleles are A, B, and O, of which each person has two (possibly the same, possibly
different). Each of a child’s parents randomly passes one of their two blood type alleles to their child. The possible blood type combinations, then, are: OO, OA, OB, AO, AA, AB, BO, BA, and
BB.

For example, if one parent has blood type AO and the other parent has blood type BB, then the child’s possible blood types would be AB and OB, depending on which allele is received from each
parent. Similarly, if one parent has blood type AO and the other OB, then the child’s possible blood types would be AO, OB, AB, and OO. */

// Simulate genetic inheritance of blood type

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Each person has two parents and two alleles
typedef struct person
{
    struct person *parents[2];      // Pointer to another "person" struct
    char alleles[2];                // Either A, B, or O
}
person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;
int total_ppl = 7;

person *create_family(int generations);         // create_family(3) should return a pointer to a person with two parents, where each parent also has two parents.
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();               // The oldest generation randomly has alleles assigned to them

int main(void)
{
    // Seed random number generator
    srand(time(0));

    // Create a new family with three generations
    person *p = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);
}

// Create a new individual with `generations`
person *create_family(int generations)
{
    // TODO: Allocate memory for new person
    person *n = malloc(sizeof(person));     // When recursively calling this function below, we will continue mallocing for new people

    // Generation with parent data
    if (generations > 1)
    {
        // TODO: Recursively create blood type histories for parents
        n->parents[0] = create_family(generations - 1);
        n->parents[1] = create_family(generations - 1);

        // TODO: Randomly assign child alleles based on parents
        n->alleles[0] = n->parents[0]->alleles[(rand() % 2)];   // Update first allele by going into n's parents's alleles
        n->alleles[1] = n->parents[1]->alleles[(rand() % 2)];   // Update second allele
    }

    // Generation without parent data
    else
    {
        // TODO: Set parent pointers to NULL
        n->parents[0] = NULL;
        n->parents[1] = NULL;
        // TODO: Randomly assign alleles
        n->alleles[0] = random_allele();
        n->alleles[1] = random_allele();
        // printf("Allele 1: %c\nAllele 2: %c\n", n->alleles[0], n->alleles[1]);
    }

    // TODO: Return newly created person
    return n;
}

// Free `p` and all ancestors of `p`.
void free_family(person *p)
{
    // TODO: Handle base case
    if (p == NULL)
    {
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        free_family(p->parents[i]);     // Call free_family for each of the parents if our person p isn't NULL, and free the current person.
    }
    free(p);
}
    // TODO: Free parents

    // TODO: Free child

// Print each family member and their alleles.
void print_family(person *p, int generation)
{
    // Handle base case
    if (p == NULL)
    {
        return;
    }

    // Print indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print person
    printf("Generation %i, blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Randomly chooses a blood type allele.
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}
