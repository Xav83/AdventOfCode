# [Day 12: JSAbacusFramework.io](https://adventofcode.com/2015/day/12)

## Problem

### Part 1

Santa's Accounting-Elves need help balancing the books after a recent order. Unfortunately, their accounting software uses a peculiar storage format. That's where you come in.

They have a [JSON](http://json.org/) document which contains a variety of things: arrays (`[1,2,3]`), objects (`{"a":1, "b":2}`), numbers, and strings. Your first job is to simply find all of the <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">numbers</span> throughout the document and add them together.

For example:

- `[1,2,3]` and `{"a":2,"b":4}` both have a sum of `6`.
- `[[[3]]]` and `{"a":{"b":4},"c":-1}` both have a sum of `3`.
- `{"a":[-1,1]}` and `[-1,{"a":1}]` both have a sum of `0`.
- `[]` and `{}` both have a sum of `0`.

You will not encounter any strings containing numbers.

What is the <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">sum of all numbers</span> in the document?

### Part 2

Uh oh - the Accounting-Elves have realized that they double-counted everything <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">red<span>.

Ignore any object (and all of its children) which has any property with the value `"red"`. Do this only for objects (`{...}`), not arrays (`[...]`).

- `[1,2,3]` still has a sum of `6`.
- `[1,{"c":"red","b":2},3]` now has a sum of `4`, because the middle object is ignored.
- `{"d":"red","e":[1,2,3,4],"f":5}` now has a sum of `0`, because the entire structure is ignored.
- `[1,"red",5]` has a sum of `6`, because `"red"` in an array has no effect.

## Solution

### Part 1

The source of the solution is contained in the file [part_one.cpp](src/part_one.cpp), and the tests checking this solution are in the file [CMakeLists.txt](CMakeLists.txt).
The executable generated takes 2 arguments :
- the file containing the json document,
- and the expected result of the sum.

### Part 2

The source of the solution is contained in the file [part_two.cpp](src/part_two.cpp), and the tests checking this solution are in the file [CMakeLists.txt](CMakeLists.txt).
The executable generated takes 2 arguments :
- the file containing the json document,
- and the expected result of the sum.
