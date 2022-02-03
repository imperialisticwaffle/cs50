/* In merge sort the idea is to sort smaller arrays and merge them in sorted order by leveraging recursion. In pseudocode:
If n > 1, sort left half of array
If n > 1, sort right half of array
Merge sorted halves, placing lower element first

e.g. array = [5] [2] [1] [3] [6] [4]
LEFT HALF:
array =    [2] [1]
temp = [5]

temp = [5] [1] [2]

temp2 = [1] [2] [5]

RIGHT HALF:
array =     [6] [4]
temp3 = [3]

temp3 = [3] [4] [6]

temp4 = [3] [4] [6] (Note that we still merge and sort temp 3; when we do so 3 is lower than 4, so it comes down first. However there is now nothing for 4 to be compared to, hence we now know
that everything to the right of 4 must already be sorted).

FINAL MERGE:
temp5 = [1] [2] [5] | [3] [4] [6]
temp6 = [1] (smaller than 3) [2] (smaller than 3) [3] (smaller than 5) [4] (smaller than 5) [5] (smaller than 6) [6]

1. We divide this array into two arrays of length 3; then redivide length 3 arrays into two uneven arrays (can't have 1.5 length array).
2. Considering only the left half, we are left with a single element array [5] and a two element array [2] [1].
3. Since [5] is already necessarily sorted, we set it aside in a temp array.
4. Dividing [2] and [1] makes them sorted, so we merge and order the two elements--[1] comes first, then [2].
5. We add these sorted elements to the temp array with the [5]--now we have [5] [1] [2], but these 3 elements are unmerged.

Worst case: split n elements up and recombine them, doubling the sorted subarrays as we build them up (combine sorted 1 element arrays into 2 element arrays, combine sorted 2 element arrays
into 4 element arrays, etc.)

Best case: the array is perfectly sorted, but we don't know this so we still have to split and recombine it together with this algorithm.

Thus runtime is Theta(n log n).