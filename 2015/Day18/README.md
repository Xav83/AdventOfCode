# [Day 18: Like a GIF For Your Yard](https://adventofcode.com/2015/day/1)

## Problem

### Part 1

After the [million lights incident](../Day6/README.md), the fire code has gotten stricter: now, at most ten thousand lights are allowed. You arrange them in a 100x100 grid.

Never one to let you down, Santa again mails you instructions on the ideal lighting configuration. With so few lights, he says, you'll have to resort to <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">animation</span>.

Start by setting your lights to the included initial configuration (your puzzle input). A `#` means "on", and a `.` means "off".

Then, animate your grid in steps, where each step decides the next configuration based on the current one. Each light's next state (either on or off) depends on its current state and the current states of the eight lights adjacent to it (including diagonals). Lights on the edge of the grid might have fewer than eight neighbors; the missing ones always count as "off".

For example, in a simplified 6x6 grid, the light marked `A` has the neighbors numbered `1` through `8`, and the light marked `B`, which is on an edge, only has the neighbors marked `1` through `5`:
```
1B5...
234...
......
..123.
..8A4.
..765.
```
The state a light should have next is based on its current state (on or off) plus the <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">number of neighbors that are on</span>:

A light which is <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">on</span> stays on when `2` or `3` neighbors are on, and turns off otherwise.
A light which is <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">off</span> turns on if exactly `3` neighbors are on, and stays off otherwise.
All of the lights update simultaneously; they all consider the same current state before moving to the next.

Here's a few steps from an example configuration of another 6x6 grid:
```
Initial state:
.#.#.#
...##.
#....#
..#...
#.#..#
####..

After 1 step:
..##..
..##.#
...##.
......
#.....
#.##..

After 2 steps:
..###.
......
..###.
......
.#....
.#....

After 3 steps:
...#..
......
...#..
..##..
......
......

After 4 steps:
......
......
..##..
..##..
......
......
```
After `4` steps, this example has four lights on.

In your grid of 100x100 lights, given your initial configuration, <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">how many lights are on after 100 steps</span>?

### Part 2

You flip the instructions over; Santa goes on to point out that this is all just an implementation of [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway's_Game_of_Life). At least, it was, until you notice that something's wrong with the grid of lights you bought: four lights, one in each corner, are <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">stuck on</span> and can't be turned off. The example above will actually run like this:
```
Initial state:
##.#.#
...##.
#....#
..#...
#.#..#
####.#

After 1 step:
#.##.#
####.#
...##.
......
#...#.
#.####

After 2 steps:
#..#.#
#....#
.#.##.
...##.
.#..##
##.###

After 3 steps:
#...##
####.#
..##.#
......
##....
####.#

After 4 steps:
#.####
#....#
...#..
.##...
#.....
#.#..#

After 5 steps:
##.###
.##..#
.##...
.##...
#.#...
##...#
```
After `5` steps, this example now has `17` lights on.

In your grid of 100x100 lights, given your initial configuration, but with the four corners always in the <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">on</span> state, <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">how many lights are on after `100` steps</span>?

## Solution

The source of the solution is contained in the files [part_one.cpp](src/part_one.cpp) and [part_two.cpp](src/part_two.cpp), depending on the part of the problem, and a test checking this solution is in the file [CMakeLists.txt](CMakeLists.txt). There also other files in the folder `src` for source code common to the two parts.
The executable generated takes 2 arguments :
- the file containing the initial Grid of lights,
- and the expected number of lights turned on.

If the expected result doesn't match the one find by the program, then, the result founded is displayed.
Else, the program exits successfully.
