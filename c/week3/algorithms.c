/* We use an italicized O to denote the running time of a program (how many iterations, seconds, etc. it takes to run a program; the unit measurement doesn't really matter).

We can express this efficiency with O(n) as our starting point (read as 'on the order of n steps').
While certain algorithms can generate increases in efficiency (like going two pages at a time for the phone book problem rather than one, making O(n/2) rather than O(n)), these increases are
negligible if we plot them on a cartesian plane and zoom out far enough. Thus we see some general formulas like below:

O represents the upper bound for the running time of a program (worst case scenario, how many steps?).
O(n^2)
O(n log n)
O(n)
O(log n)
O(1)

Conversely, (omega) denotes the lower bound of the running time of a program (best case scenario, how many steps?), and the formulas are the same as O.

Searching the phone book page by page by page was called 'linear search'.
If we perform a linear search on an array for the int '0', for example, our upper bound is O(n) and lower bound is (omega)(1) since we might be lucky and find it in the first element.

We could obtain more efficient code if we have more predictable data; hence we can try sorting an array, for example, from least to greatest and apply our more efficient phonebook algorithm.
In pseudocode:
If number is middle element:
    Return true
Else if desired number is < middle element
    Search left half
Else if desired number is > middle element
    Search right half
Else if no elements left/in the first place
    Return false

We can glean some form of speed by measuring the frequency an algorithm goes through steps (maybe 1 Hz, so 1 iteration per second). CPUs are also measured in Hz (or GHz), and so they can perform
many many many iterations a second. */