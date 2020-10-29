## Assignment 3 - Presentation UVA: 10901

### Approach to the problem:

- Read the problem and understand the input output.
- Input:
    - first line of input is amount of cases.
    - second line is the (in order) amount of cars that the ferry can carry, time ferry takes to cross and amount of arriving cars. 
- Output:
    - The most efficient time the cars are dropped off in.
- Realizations:
    - The ferry always starts on the left side and will wait for a car to appear to move the car or go get the car on the other side.
    - you always have to look at this greedily in that the ferry will always be attracted to move when there is a car waiting(either take or move to other side to get other car).

### Language used:

- C++.

### Problem solving paradigm:

- Purely greedy in that I don't see any other way to approach this problem.

### Data structures chosen:

- Array of queues that will hold the lines of cars that are waiting to be moved on the other sides.
    - The 0 element being the left side and the 1st element being the right side.
- A vector that stores all of the times when the cars had been dropped off.

### Did speed factor in to previous choices:

- Not primarily since I only see this problem having one real way of solving it.

### Could any speed ups be included but were not:

- My algorithm for this can most likely be condensed for this problem but as for any major speed ups I do not see any real possibilities.
