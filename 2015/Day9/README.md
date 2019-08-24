# [Day 9: All in a Single Night](https://adventofcode.com/2015/day/9)

## Problem

### Part 1

Every year, Santa manages to deliver all of his presents in a single night.

This year, however, he has some new locations to visit; his elves have provided him the distances between every pair of locations. He can start and end at any two (different) locations he wants, but he must visit each location exactly once. What is the <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">shortest distance</span> he can travel to achieve this?

For example, given the following distances:

```
London to Dublin = 464
London to Belfast = 518
Dublin to Belfast = 141
```

The possible routes are therefore:

```
Dublin -> London -> Belfast = 982
London -> Dublin -> Belfast = 605
London -> Belfast -> Dublin = 659
Dublin -> Belfast -> London = 659
Belfast -> Dublin -> London = 605
Belfast -> London -> Dublin = 982
```

The shortest of these is `London -> Dublin -> Belfast = 605`, and so the answer is `605` in this example.

### Part 2

The next year, just to show off, Santa decides to take the route with the <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">longest distance</span> instead.

He can still start and end at any two (different) locations he wants, and he still must visit each location exactly once.

For example, given the distances above, the longest route would be `982` via (for example) `Dublin -> London -> Belfast`.

## Solution

### Part 1

The source of the solution is contained in the file [part_one.cpp](src/part_one.cpp), and the tests checking this solution are in the file [CMakeLists.txt](CMakeLists.txt). There is also some common code from the two parts of this problem in the other files of the `src` folder.
The executable generated takes 2 arguments :
- the file containing the list,
- and the expected shortest distance.

### Part 2

The source of the solution is contained in the file [part_two.cpp](src/part_two.cpp), and the tests checking this solution are in the file [CMakeLists.txt](CMakeLists.txt). There is also some common code from the two parts of this problem in the other files of the `src` folder.
The executable generated takes 2 arguments :
- the file containing the list,
- and the expected longest.
