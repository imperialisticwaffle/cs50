// In bubble sort we move higher valued elements generally to the right and lower valued elements generally to the left.
Pseudocode:
Set swap counter to nonzero value   // Otherwise the algorithm would not even begin
Repeat until swap counter = 0
    Reset swap counter to 0
    Examine adjacent pair
        If two adjacent pairs are not in ascending order, swap them and add 1 to the swap counter

/* Because bubble sort by nature moves the largest element on each pass to the end, we do not have to consider these sorted elements in our next iteration. Our worst case scenario is O(n^2) and
best case scenario is (omega)(n).