# [Day 3 - Perfectly Spherical Houses in a Vacuum](https://adventofcode.com/2015/day/3)

## Problem

### Part 1

Santa is delivering presents to an infinite two-dimensional grid of houses.

He begins by delivering a present to the house at his starting location, and then an elf at the North Pole calls him via radio and tells him where to move next. Moves are always exactly one house to the north (`^`), south (`v`), east (`>`), or west (`<`). After each move, he delivers another present to the house at his new location.

However, the elf back at the north pole has had a little too much eggnog, and so his directions are a little off, and Santa ends up visiting some houses more than once. How many houses receive <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">at least one present</span>?

For example:

- `>` delivers presents to `2` houses: one at the starting location, and one to the east.
- `^>v<` delivers presents to `4` houses in a square, including twice to the house at his starting/ending location.
- `^v^v^v^v^v` delivers a bunch of presents to some very lucky children at only `2` houses.

### Part Two

The next year, to speed up the process, Santa creates a robot version of himself, <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">Robo-Santa</span>, to deliver presents with him.

Santa and Robo-Santa start at the same location (delivering two presents to the same starting house), then take turns moving based on instructions from the elf, who is eggnoggedly reading from the same script as the previous year.

This year, how many houses receive <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">at least one present</span>?

For example:

- `^v` delivers presents to `3` houses, because Santa goes north, and then Robo-Santa goes south.
- `^>v<` now delivers presents to `3` houses, and Santa and Robo-Santa end up back where they started.
- `^v^v^v^v^v` now delivers presents to `11` houses, with Santa going one direction and Robo-Santa going the other.

## Solution

The common code between the two parts has been grouped in a shared *static library* which is linked to the solution of the 2 parts. This library is defined in the [CMakeLists.txt](CMakeLists.txt) alongside of the definition of the two other parts.

### Part 1

The source of the solution is contained in the file [part_one.cpp](src/part_one.cpp), and a test checking this solution is in the file [CMakeLists.txt](CMakeLists.txt).
The executable generated takes 2 arguments :
- an input file containing the [puzzle input](res/puzzle_input.txt) from Advent Of Code,
- and the expected final number of houses visited.

If the expected final number of houses visited doesn't match the one find by the program, then, the result founded is displayed.
Else, the program exits successfully.

### Part 2

The source of the solution is contained in the file [part_two.cpp](src/part_two.cpp), and a test checking this solution is in the file [CMakeLists.txt](CMakeLists.txt).
The executable generated takes 2 arguments :
- an input file containing the [puzzle input](res/puzzle_input.txt) from Advent Of Code,
- and the expected number of houses visited.

If the expected number of houses visited doesn't match the one find by the program, then, the result founded is displayed.
Else, the program exits successfully.
