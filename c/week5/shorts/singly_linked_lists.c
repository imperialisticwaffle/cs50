/* Becase arrays are inflexible, we can use linked lists.

A node is a special kind of struct w/ two members: data of some data type and a pointer to another node of same type. */

typedef struct sllist   // The third parameter here is optional for typedefs that WILL be self-referential and need to include their own data type name in their definition
{
    VALUE val;
    struct sllist *next;
}
sllnode;        // Ultimately you want to call your SLList "sllnode"; the sllist is a temporary self-referential name to be used inside the struct

/*
1. Create a linked list when not already existing
    - Create linked list: sllnode* create(VALUE val)
    - The create() function should return a pointer to a singly linked list node
    - Steps involved:
        - Dynamically allocate space for a new sllnode
        - Check for no NULL memory
        - Initialize node VAL field
        - Initialize node NEXT field (remember if the element is the only thing in the list/if it's last, intialize "next" to NULL)
        - Return pointer to newly created sllnode

2. Search through linked list to find an element
    - bool find(sllnode* head, VALUE val)
    - Create traversal pointer pointing to the list's head
    - If current node VAL field is what we're looking for, report success
    - If not, set traversal pointer to next pointer in list and go back to step above
    - If end of list is reached report failure

3. Insert new node into linked list
    - sllnode* insert(sllnode* head, VALUE val)
    - Dynamically allocate space for a new sllnode
    - Check for NULL
    - Populate and insert node at beginning of list
    - Return pointer to new head of list (update pointer of new node to following elements first, then update list head to new node)

4. Delete single element from linked list
    - DISCUSSED IN DOUBLY LINKED LISTS

5. Delete entire linked list
    - void destroy(sllnode* head)
    - If reached null pointer, stop
    - Delete rest of list (USE RECURSION FOR THIS)
    - Free current node */