/* Recall that you have to define how big you would like your array to be before you fill it with values. How then, would you add a new value to the array?

For example, take the array arr[3] = {1, 2, 3}. How would you add arr[4] = 4?

For one you could copy all the contents of the old array into a new array and add 4 at the end, subsequently freeing the memory taken up by the old array. The new array must contain contiguous
elements, else we can't classify the data structure as an array.

For an array already filled with elements (and you would like to append a new one), the upper bound runtime would be O(n); whereas if you had a semi-full array (and would append a new element)
your runtime would be O(1).

Linked lists are more dynamic whereby you can grow and shrink the data without having to touch the original data and move it from the old location to the new. We actually store values ANYWHERE
in the computer's memory, but with each element we include some metadata that will help us navigate to the next element (memory addresses). So our list may in theory take up twice as much
memory with one half being the elements and the other half being the memory addresses of the next respective elements.

Linked lists can be thought of as a collection of nodes, wherein a node is a structure that stores things you care about. We can define a linked list the following way with typedef: */

typedef struct node     // The "struct node" allows us to refer to the very thing we're spending the typedef defining (node) inside the definition itself
{
    int number;     // Number (element)
    struct node *next;      // Address of next element
}
node;

/* We start out with an empty linked list with a NULL pointer; each time we want to add a new element, we need to malloc enough space for that element depending on data type. Then, we go back
to the start and follow the associated pointers to update the memory addresses for each element up until (current element just added - 1), since the current element will have a NULL pointer. */

node *list = NULL;
node *n = malloc(sizeof(node));
if (n != NULL)
{
    (*n).number = 1;    // Go to the address given by malloc of n and into the data structure subtype "number", and change it to 1. Equivalent to n->number = 1;
    n->next = NULL;     // Update pointer to next to NULL as we don't have a new element yet
}
list = n;       // This line is necessary to update the linked list "list" and point it to the element "n". Basically chaining the elements together

// We can do this again for adding the number 2
node *n = malloc(sizeof(node));
if (n != NULL)
{
    (*n).number = 2;
    n->next = NULL;
}
list->next = n;

// And once more for 3
node *n = malloc(sizeof(node));
if (n != NULL)
{
    (*n).number = 3;
    n->next = NULL;
}
list->next->next = n;

/* The worst case runtime of a linked list is O(n), since the only indicator we have of the linked list is the very first pointer (i.e. list). Thus we have to "follow the breadcrumbs" to the
end to find what we're looking for. The runtime for inserting a new element in a linked list is actually O(1), since we have a fixed number of steps IF we decide to insert said new element at
the beginning of the list (disregarding sorting). */