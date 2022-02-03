#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct *node next;
}
node;

int main(void)
{
    node *list = NULL;

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 1;
    n->next = NULL;
    list = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list);
        return 1;
    }
    n->number = 2;
    n->next = NULL;
    list->next = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list->next);
        free(list);
        return 1;
    }
    n->number = 3;
    n->next = NULL;
    list->next->next = n;

    for (node *tmp = list; node !- NULL; tmp = tmp->next)   // No integer for loop as that isn't helpful. Set tmp pointer to first element; as long as tmp isn't NULL, update tmp to the next ptr
    {
        printf("%i\n", tmp->number);        // Print out whatever is in the number field of tmp
    }

    // Now we need to free the linked list. Note that we cannot free a prior node prematurely, as that strands all subsequent nodes
    while(list != NULL)     // While first pointer contains some value
    {
        node *tmp = list->next;     // Set a temporary pointer to the next value in the linked list
        free(list);                 // Free current value
        list = tmp;                 // Update out list to the temporary pointer
    }
}

/* Prof Malan has been more rigorous and shown an example where he hardcoded multiple nodes one by one. In theory you could malloc(3 * sizeof(node)) and update each element using pointer
arithmetic or square bracket notation.

If you wanted to allocate space for a new node/insert a new node into the list, you absolutely cannot go through the motions of initializing a new number n and its pointer to NULL only to
immediately set the first pointer (list) to this new number, n. Doing so without remembering where "list" ORIGINALLY pointed to will result in a memory leak as you stranded multiple nodes.

The proper way to introduce a new element into the linked list is to initialize everything necessary for the new element and FIRST point it to the next element that comes after the location you
are inserting it in. Then you can make the previous element point to the newly inserted one.

e.g. You insert the element "1" in between "list" and "2" (after "2", we have "4" and "5", but they're irrelevant for this particular example). First you point "1" to "2", then update "list" to
point to "1".
In code:
n->next = list; (since list is pointing to "2")
list = n;

A good rule of thumb is to first update everything that comes after the location you are inserting into before updating everything that precedes it.