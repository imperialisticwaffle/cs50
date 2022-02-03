/* The data to be searched for can now be htought of as a roadmap, where if you can follow the roadmap from beginning to end the data exists in the trie; if you can't it doesn't. No two pieces of
data have the same path unless they are identical.

We can try mapping a trie where keys are four digit years and values are universities founded in those years. The paths from a central root node to a leaf node (where the names would be) would be
labeled with digits of the year.

Each node could have 10 pointers emanating from it, 1 for each digit. To insert an element, simply build the correct path from root to leaf. */

typedef struct _trie
{
    char university[20];    // Name of university
    struct _trie* paths[10];    // Array of pointers to other nodes of same type
}
trie;

/* For our root node, you will probably want to globally declare it so you can always refer to it. Let's take Harvard and 1636 as an example. First you want to allocate a new node, and then
make "1" in the root node point to it. Then you allocate another, and then make "6" point to it. So on and so forth. When we reach the final digit, it points to a new node with all NULL pointers
and "Harvard" in the university attribute.

To search for elements in the trie, use successive digits to navigate from the root, and if you can make it to the end without hitting a NULL pointer, you found it. */