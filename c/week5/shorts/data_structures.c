/* So far we've gone through 4 different ways to store data: arrays, linked lists, hash tables, and tries. There are variations (trees and heaps, stacks and queues, etc.).

Arrays:

Insertion is bad - lots of shifting to fit an element into the middle.
Deletion is bad - lots of shifting after removing an element.
Lookup is great - random access, constant time.
Relatively easy to sort.
Relatively small size-wise.
Stuck with a fixed size, no flexibility.


Linked list:

Insertion is easy - tack onto front.
Deletion is easy - once you find the element (just change a few pointers).
Lookup is bad - have to rely on linear search.
Relatively difficult to sort - unless willing to compromise on fast insertion and sort as you add/construct elements.
Relatively small size-wise - not as small as arrays, though.


Hash tables:

Insertion is a two step process - hash, then add (get hash code from hash function, then insert into hash table location given by hash code).
Deletion is easy - once you find the element (delete pointers if using separate chaining; if using probing, simply go to the hash code location).
Lookup on average is better than linked lists because you have the benefit of a real world constant factor.
Not an ideal structure if sorting is the goal - just use an array.
Can run the gamut of size (both big and small, typically bigger than linked list but smaller than trie. Note that a short "array" component means longer linked list components and vice versa).


Tries:

Insertion is complex - lot of dynamic memory allocation, but gets easier as you go (pointer and memory allocation is the biggest hurdel here).
Deletion is easy - just free a node.
Lookup is fast - not quite as fast as an array, but almost.
Already sorted - sorts as you build in almost all situations.
Rapidly becomes huge, even if little data present - not great if space is at a premium. */