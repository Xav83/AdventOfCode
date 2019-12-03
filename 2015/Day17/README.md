# [Day 17: No Such Thing as Too Much](https://adventofcode.com/2015/day/17)

## Problem

### Part 1

The elves bought too much eggnog again - `150` liters this time. To fit it all into your refrigerator, you'll need to move it into smaller containers. You take an inventory of the capacities of the available containers.

For example, suppose you have containers of size `20`, `15`, `10`, `5`, and `5` liters. If you need to store `25` liters, there are four ways to do it:

- `15` and `10`
- `20` and `5` (the first `5`)
- `20` and `5` (the second `5`)
- `15`, `5`, and `5`

Filling all containers entirely, how many different <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">combinations of containers</span> can exactly fit all `150` liters of eggnog?

### Part 2

While playing with all the containers in the kitchen, another load of eggnog arrives! The shipping and receiving department is requesting as many containers as you can spare.

Find the minimum number of containers that can exactly fit all `150` liters of eggnog. <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">How many different ways</span> can you fill that number of containers and still hold exactly `150` litres?

In the example above, the minimum number of containers was two. There were three ways to use that many containers, and so the answer there would be `3`.

## Solution

The source of the solution is contained in the files [part_one.cpp](src/part_one.cpp) and [part_two.cpp](src/part_two.cpp), depending on the part of the problem, and a test checking this solution is in the file [CMakeLists.txt](CMakeLists.txt).
The executable generated takes 2 arguments :
- the file containing the values of the containers,
- and the expected number of combinations of containers.

If the expected result doesn't match the one find by the program, then, the result founded is displayed.
Else, the program exits successfully.
