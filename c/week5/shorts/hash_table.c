/* A hash function will return a nonnegative integer value called a hash code; then, we use the hash code to place the new element in an array of the data type we want to store.

What makes a good hash function?
    - Use only data being hashed
    - Use all of the data being hashed
    - Be deterministic (passing the same piece of data into the hash function should always return the same output)
    - Uniformly distribute data
    - Generate very different hash codes for very similar data

You will probably not want to write your own hash functions, and instead find good ones produced on the internet.

Collisions are the same hash code is returned for different inputs. We can resolve this with chaining, where each element in the array is a pointer to the head of a linked list. Just remember
to update the new pointer to the old head of the linked list before updating the array pointer to the new element.