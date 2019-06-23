# [Day 5: Doesn't He Have Intern-Elves For This?](https://adventofcode.com/2015/day/5)

## Problem

### Part 1

Santa needs help figuring out which strings in his text file are naughty or nice.

A <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">nice string</span> is one with all of the following properties:

- It contains at least three vowels (`aeiou` only), like `aei`, `xazegov`, or `aeiouaeiouaeiou`.
- It contains at least one letter that appears twice in a row, like `xx`, `abcdde` (`dd`), or `aabbccdd` (`aa`, `bb`, `cc`, or `dd`).
- It does <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">not</span> contain the strings `ab`, `cd`, `pq`, or `xy`, even if they are part of one of the other requirements.

For example:

- `ugknbfddgicrmopn` is nice because it has at least three vowels (`u...i...o...`), a double letter (`...dd...`), and none of the disallowed substrings.
- `aaa` is nice because it has at least three vowels and a double letter, even though the letters used by different rules overlap.
- `jchzalrnumimnmhp` is naughty because it has no double letter.
- `haegwjzuvuyypxyu` is naughty because it contains the string `xy`.
- `dvszwmarrgswjxmb` is naughty because it contains only one vowel.

### Part 2

Realizing the error of his ways, Santa has switched to a better model of determining whether a string is naughty or nice. None of the old rules apply, as they are all clearly ridiculous.

Now, a nice string is one with all of the following properties:

- It contains a pair of any two letters that appears at least twice in the string without overlapping, like `xyxy` (`xy`) or `aabcdefgaa` (`aa`), but not like `aaa` (`aa`, but it overlaps).
- It contains at least one letter which repeats with exactly one letter between them, like `xyx`, `abcdefeghi` (`efe`), or even `aaa`.

For example:

- `qjhvhtzxzqqjkmpb` is nice because is has a pair that appears twice (`qj`) and a letter that repeats with exactly one letter between them (`zxz`).
- `xxyxx` is nice because it has a pair that appears twice and a letter that repeats with one between, even though the letters used by each rule overlap.
- `uurcxstgmygtbstg` is naughty because it has a pair (`tg`) but no repeat with a single letter between them.
- `ieodomkazucvgmuy` is naughty because it has a repeating letter with one between (`odo`), but no pair that appears twice.

## Solution

### Part 1

The source of the solution is contained in the file [part_one.cpp](src/part_one.cpp), and a test checking this solution is in the file [CMakeLists.txt](CMakeLists.txt).
The executable generated takes 2 arguments :
- the file containing the list of strings,
- and the expected number of nice string.

If the expected number of nice string doesn't match the one find by the program, then, the result founded is displayed.
Else, the program exits successfully.

### Part 2

The source of the solution is contained in the file [part_two.cpp](src/part_two.cpp), and a test checking this solution is in the file [CMakeLists.txt](CMakeLists.txt).
The executable generated takes 2 arguments :
- the file containing the list of strings,
- and the expected number of nice string.

If the expected number of nice string doesn't match the one find by the program, then, the result founded is displayed.
Else, the program exits successfully.
