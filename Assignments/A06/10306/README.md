## Assignment 6 - Presentation UVA: 1213 

### What type of Dynamic Programing program is this?:

- Knapsack

### What the question is asking:

- To find the largest amount of prime numbers that can be added together in a set of x numbers
- which means if given find most primes that add to 24 in a set of 3 you would do:
    - {2, 5, 17} and {2, 5, 19} since addition is communicative so the answer is 2

### Initial thoughts:

- DP way you could just write out all of the primes up to 1120 since that is the largest number given

### Walk through:

- Make an array that holds all primes up to 1120
- Write a DP function that would check:
    - if it asks for a set of 0 print 0
    - if it asks for a the amount of 0 in 0 sets print 1
    - if it asks for a number less then 2 print 0
    - recursively call the function changing the set until you find a answer in the set 

### sources:

- book pg. 67-68, 72-73