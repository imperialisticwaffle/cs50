/* We have a forever loop (while (true)) as well as a regular while loop (while (bool exp)). A do-while loop works like a regular while loop, but is GUARANTEED to run at least one time, which
can be useful.

The for loop's syntax is as follows: for (start; bool exp; increment). First the statement in start is executed; then the bool exp is checked. If it is true, the code inside the for loop executes.
If false it doesn't execute. The statement in 'increment' is executed, then the bool exp is checked again, etc.

While loops: when we want a loop to repeat an unknown number of times, or possibly not at all.
Do-while loops: when we want a loop to repeat an unknown number of times, but at least once.
For loops: when you want to repeat a discrete number of times, though you may not know the number when the code is compiled.
*/