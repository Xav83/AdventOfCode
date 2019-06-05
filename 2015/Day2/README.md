# [Day 1 - I Was Told There Would Be No Math](https://adventofcode.com/2015/day/2)

## Problem

The elves are running low on wrapping paper, and so they need to submit an order for more. They have a list of the dimensions (length `l`, width `w`, and height `h`) of each present, and only want to order exactly as much as they need.

Fortunately, every present is a box (a perfect <span style="color:green">right rectangular prism</span>), which makes calculating the required wrapping paper for each gift a little easier: find the surface area of the box, which is `2*l*w + 2*w*h + 2*h*l`. The elves also need a little extra paper for each present: the area of the smallest side.

For example:

- A present with dimensions `2x3x4` requires `2*6 + 2*12 + 2*8 = 52` square feet of wrapping paper plus `6` square feet of slack, for a total of `58` square feet.
- A present with dimensions `1x1x10` requires `2*1 + 2*10 + 2*10 = 42` square feet of wrapping paper plus `1` square foot of slack, for a total of `43` square feet.

All numbers in the elves' list are in feet. How many total <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">square feet of wrapping paper</span> should they order?
  
### Part Two

The elves are also running low on ribbon. Ribbon is all the same width, so they only have to worry about the length they need to order, which they would again like to be exact.

The ribbon required to wrap a present is the shortest distance around its sides, or the smallest perimeter of any one face. Each present also requires a bow made out of ribbon as well; the feet of ribbon required for the perfect bow is equal to the cubic feet of volume of the present. Don't ask how they tie the bow, though; they'll never tell.

For example:

- A present with dimensions `2x3x4` requires `2+2+3+3 = 10` feet of ribbon to wrap the present plus `2*3*4 = 24` feet of ribbon for the bow, for a total of `34` feet.

- A present with dimensions `1x1x10` requires `1+1+1+1 = 4` feet of ribbon to wrap the present plus `1*1*10 = 10` feet of ribbon for the bow, for a total of `14` feet.

How many total <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">feet of ribbon</span> should they order?

## Solution

The common code between the two parts has been grouped in a shared *static library* which is linked to the solution of the 2 parts. This library is defined in the [CMakeLists.txt](CMakeLists.txt) alongside of the definition of the two other parts.

### Part 1

The source of the solution is contained in the file [part_one.cpp](src/part_one.cpp), and a test checking this solution is in the file [CMakeLists.txt](CMakeLists.txt).
The executable generated takes 2 arguments :
- an input file containing the [puzzle input](res/puzzle_input.txt) from Advent Of Code,
- and the expected final quantity of wrapping paper needed.

If the expected final quantity of wrapping paper doesn't match the one find by the program, then, the result founded is displayed.
Else, the program exits successfully.

### Part 2

The source of the solution is contained in the file [part_two.cpp](src/part_two.cpp), and a test checking this solution is in the file [CMakeLists.txt](CMakeLists.txt).
The executable generated takes 2 arguments :
- an input file containing the [puzzle input](res/puzzle_input.txt) from Advent Of Code,
- and the expected lenght of ribbon needed.

If the expected lenght of ribbon doesn't match the one find by the program, then, the result founded is displayed.
Else, the program exits successfully.
