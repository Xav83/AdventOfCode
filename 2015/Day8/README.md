# [Day 8: Some Assembly Required](https://adventofcode.com/2015/day/8)

## Problem

### Part 1

--- Day 8: Matchsticks ---
Space on the sleigh is limited this year, and so Santa will be bringing his list as a digital copy. He needs to know how much space it will take up when stored.

It is common in many programming languages to provide a way to escape special characters in strings. For example, <span style="color:green">C</span>, <span style="color:green">JavaScript</span>, <span style="color:green">Perl</span>, <span style="color:green">Python</span>, and even <span style="color:green">PHP</span> handle special characters in very similar ways.

However, it is important to realize the difference between the number of characters <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">in the code representation of the string literal</span> and the number of characters <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">in the in-memory string itself</span>.

For example:

- `""` is `2` characters of code (the two double quotes), but the string contains zero characters.
- `"abc"` is `5` characters of code, but `3` characters in the string data.
- `"aaa\"aaa"` is `10` characters of code, but the string itself contains six "a" characters and a single, escaped quote character, for a total of 7 characters in the string data.
- `"\x27"` is `6` characters of code, but the string itself contains just one - an apostrophe (`'`), escaped using hexadecimal notation.

Santa's list is a file that contains many double-quoted string literals, one on each line. The only escape sequences used are `\\` (which represents a single backslash), `\"` (which represents a lone double-quote character), and `\x` plus two hexadecimal characters (which represents a single character with that ASCII code).

Disregarding the whitespace in the file, what is <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">the number of characters of code for string literals</span> minus <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">the number of characters in memory for the values of the strings</span> in total for the entire file?

For example, given the four strings above, the total number of characters of string code (`2 + 5 + 10 + 6 = 23`) minus the total number of characters in memory for string values (`0 + 3 + 7 + 1 = 11`) is `23 - 11 = 12`.

### Part 2

Now, let's go the other way. In addition to finding the number of characters of code, you should now <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">encode each code representation as a new string</span> and find the number of characters of the new encoded representation, including the surrounding double quotes.

For example:

- `""` encodes to `"\"\""`, an increase from `2` characters to `6`.
- `"abc"` encodes to `"\"abc\""`, an increase from `5` characters to `9`.
- `"aaa\"aaa"` encodes to `"\"aaa\\\"aaa\""`, an increase from `10` characters to `16`.
- `"\x27"` encodes to `"\"\\x27\""`, an increase from `6` characters to `11`.

Your task is to find <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">the total number of characters to represent the newly encoded strings</span> minus <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">the number of characters of code in each original string literal</span>. For example, for the strings above, the total encoded length (`6 + 9 + 16 + 11 = 42`) minus the characters in the original code representation (`23`, just like in the first part of this puzzle) is `42 - 23 = 19`.

## Solution

### Part 1

The source of the solution is contained in the file [part_one.cpp](src/part_one.cpp), and the tests checking this solution are in the file [CMakeLists.txt](CMakeLists.txt).
The executable generated takes 2 arguments :
- the file containing the list,
- and the expected value for the substraction of the total number of characters in memory for string values to the total number of characters of string code.

### Part 2

The source of the solution is contained in the file [part_two.cpp](src/part_two.cpp), and the tests checking this solution are in the file [CMakeLists.txt](CMakeLists.txt).
The executable generated takes 2 arguments :
- the file containing the list,
- and the expected value for the substraction of the number of characters of code in each original string literal to the total number of characters to represent the newly encoded strings.
