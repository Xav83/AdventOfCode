# [Day 1 - Not Quite Lisp](https://adventofcode.com/2015/day/1)

## Problem

Santa is trying to deliver presents in a large apartment building, but he can't find the right floor - the directions he got are a little confusing. He starts on the ground floor (floor `0`) and then follows the instructions one character at a time.

An opening parenthesis, `(`, means he should go up one floor, and a closing parenthesis, `)`, means he should go down one floor.

The apartment building is very tall, and the basement is very deep; he will never find the top or bottom floors.

For example:

- `(())` and `()()` both result in floor `0`.
- `(((` and `(()(()(` both result in floor `3`.
- `))(((((` also results in floor `3`.
- `())` and `))(` both result in floor `-1` (the first basement level).
- `)))` and `)())())` both result in floor `-3`.

To what floor do the instructions take Santa?

### Part Two

Now, given the same instructions, find the position of the first character that causes him to enter the basement (floor `-1`). The first character in the instructions has position `1`, the second character has position `2`, and so on.

For example:

- `)` causes him to enter the basement at character position `1`.
- `()())` causes him to enter the basement at character position `5`.

What is the position of the character that causes Santa to first enter the basement?

## Solution

### Part 1

The source of the solution is contained in the file [part_one.cpp](src/part_one.cpp), and a test checking this solution is in the file [CMakeLists.txt](CMakeLists.txt).
The executable generated takes 2 arguments :
- an input file containing the [puzzle input](res/puzzle_input.txt) from Advent Of Code,
- and the expected final floor.

If the expected final floor doesn't match the one find by the program, then, the result founded is displayed.
Else, the program exits successfully.

### Part 2

The source of the solution is contained in the file [part_two.cpp](src/part_two.cpp), and a test checking this solution is in the file [CMakeLists.txt](CMakeLists.txt).
The executable generated takes 2 arguments :
- an input file containing the [puzzle input](res/puzzle_input.txt) from Advent Of Code,
- and the expected position at which we entering the basement for the first time.

If the expected result doesn't match the one find by the program, then, the result founded is displayed.
Else, the program exits successfully.
