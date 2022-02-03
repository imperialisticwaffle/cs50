/* Recall that binary search was extremely powerful on a sorted array, but it was only powerful because we could access array elements in constant time by performing array arithmetic (square
bracket notation). Linked lists are more dynamic and subsequently remove that possibility for arithmetic.

If we think of linked lists in a more 2 dimensional manner, things change:
            4
    2               6
1       3       5       7

Notice the intentional division/split of elements (think of binary search). Notice as well that data structure can be recursive (fractals???)--one branch of the biggest tree becomes two trees.
We will have to redefine our node structure: */

typedef struct node
{
    int number;
    struct node *left;  // Smaller subtree
    struct node *right; // Bigger subtree
}

// Let's make a recursive function for searching a tree.

bool search(node *tree, int number)
{
    if (tree == NULL)
    {
        return false;
    }
    else if (number < tree->number)
    {
        return search(tree->left, number);      // Recursion
    }
    else if (number > tree->number)
    {
        return search(tree->right, number);
    }
    else if (number == tree->number)
    {
        return true;
    }
}

/* The runtime of inserting into a binary saerch tree will be O(log n); as it turns out the number of steps it will take to find the appropriate place for insertion is log(base 2)(n), the
formula of which ALSO represents the height of the tree. So if you want to insert an 8th element, it will take 3 steps to get to where you need to be.

Note that it's possible your binary search tree may, in the words of Prof Malan, get "long and stringy". At this point it will become quite linear and reminiscent of a linked list; the remedy
is to change your perspective and in effect "rotate" the list diagrammatically (in actuality, shift your code so that a new middle element becomes the new pointer for tree). */