// Iterate across an array from left to right, searching for a specified element. Worst case O(n) and best case (omega)(1).


// For binary, the idea is to divide and conquer, reducing search area by half each time and trying to find a target number. The array must be sorted.
Repeat until sub-array is of size 0
    Calculate midpoint of current array
    If target element is at middle
        Quit
    Else if target < midpoint
        Repeat and change endpoint of new array to be just left of last midpoint
    Else if target > midpoint
        Repeat and change endpoint of new array to be just right of last midpoint
// We should keep sore variables for the target, the beginning and end elements of the subarray, and the midpoint. Worst case O(log n) and best case (omega)(1).