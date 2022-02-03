/* A hash table is an array of linked lists. We can use a contacts list as an example (with a vertical array for clarity's sake, purely stylistic):

Each box represents 1 letter of the alphabet, starting at A and ending at Z.

[] Albus
[]
[] Cedric
[] Draco
[]
[] Fred
[] Ginny -> George          // Here we see the linked lists come into play.
[] Hermione -> Harry -> Hagrid
[]
[] etc
[]
[]
[]
[]
[]
[]
[] etc...
[]
[]
[]
[]
[]
[]
[]
[]
[]

There is a small issue if we want quick constant access to names like with array arithmetic, since names starting with the same letter will end up in the same "bucket"/linked list.

The solution is to have each element in the array be for letters "AAA" through "ZZZ"; thus, Hermione will go into the "Her" bucket, Harry will go into the "Har" bucket, and Hagrid will go into
the "Hag" bucket. The price we pay is that, while we may get constant access time, this new array will take up a lot of memory (26^3 total elements.) */