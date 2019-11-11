# [Day 16: Aunt Sue](https://adventofcode.com/2015/day/16)

## Problem

### Part 1

Your Aunt Sue has given you a wonderful gift, and you'd like to send her a thank you card. However, there's a small problem: she signed it "From, Aunt Sue".

You have 500 Aunts named "Sue".

So, to avoid sending the card to the wrong person, you need to figure out which Aunt Sue (which you conveniently number 1 to 500, for sanity) gave you the gift. You open the present and, as luck would have it, good ol' Aunt Sue got you a My First Crime Scene Analysis Machine! Just what you wanted. Or needed, as the case may be.

The My First Crime Scene Analysis Machine (MFCSAM for short) can detect a few specific compounds in a given sample, as well as how many distinct kinds of those compounds there are. According to the instructions, these are what the MFCSAM can detect:

- `children`, by human DNA age analysis.
- `cats`. It doesn't differentiate individual breeds.
- Several seemingly random breeds of dog: `samoyeds`, `pomeranians`, `akitas`, and `vizslas`.
- `goldfish`. No other kinds of fish.
- `trees`, all in one group.
- `cars`, presumably by exhaust or gasoline or something.
- `perfumes`, which is handy, since many of your Aunts Sue wear a few kinds.

In fact, many of your Aunts Sue have many of these. You put the wrapping from the gift into the MFCSAM. It beeps inquisitively at you a few times and then prints out a message on ticker tape:

```
children: 3
cats: 7
samoyeds: 2
pomeranians: 3
akitas: 0
vizslas: 0
goldfish: 5
trees: 3
cars: 2
perfumes: 1
```
You make a list of the things you can remember about each Aunt Sue. Things missing from your list aren't zero - you simply don't remember the value.

What is the <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">number</span> of the Sue that got you the gift?

### Part 2

As you're about to send the thank you note, something in the MFCSAM's instructions catches your eye. Apparently, it has an outdated retroencabulator, and so the output from the machine isn't exact values - some of them indicate ranges.

In particular, the cats and trees readings indicates that there are <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">greater than</span> that many (due to the unpredictable nuclear decay of cat dander and tree pollen), while the pomeranians and goldfish readings indicate that there are <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">fewer than</span> that many (due to the modial interaction of magnetoreluctance).

What is the <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">number</span> of the real Aunt Sue?

## Solution

The source of the solution is contained in the files [part_one.cpp](src/part_one.cpp) and [part_two.cpp](src/part_two.cpp), depending on the part of the problem, and a test checking this solution is in the file [CMakeLists.txt](CMakeLists.txt). Moreover, there are some common code between the two parts of the solution in the files [Aunt.hpp](src/Aunt.hpp) and [Aunt.cpp](src/Aunt.cpp)
The executable generated takes 2 arguments :
- the file containing the data about the 500 Aunts,
- and the expected number of the Aunt.

If the expected result doesn't match the one find by the program, then, the result founded is displayed.
Else, the program exits successfully.
