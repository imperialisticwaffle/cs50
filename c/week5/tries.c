/* A trie (try) is a tree whose nodes are arrays.

Say you had "Hagrid" stored in a trie--the first node would be an array of all 26 letters with a pointer to H. The next node would be another 26 letters with a pointer to A. The next, 26 letters
with a pointer to G. And so on. The name "Harry" would share the same first two pointers as "Hagrid".

Notice that the runtime of searching for a name is not affected by how many names you are storing in the trie--the runtime is asymptotically constant O(1), as the number of steps it takes is
simply the length of the person's name.

We have a few abstract data types used in code (not directly translatable to literal code, but the idea applies). Queues represent FIFO (first in first out), and stacks represent LIFO (last in
first out). Dictionaries, as you'll recall from Python, have keys and values, whereby the values can be indexed by the keys. */