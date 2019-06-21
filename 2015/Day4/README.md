# [Day 4: The Ideal Stocking Stuffer](https://adventofcode.com/2015/day/4)

## Problem

### Part 1

Santa needs help [mining](https://en.wikipedia.org/wiki/Bitcoin#Mining) some AdventCoins (very similar to [bitcoins](https://en.wikipedia.org/wiki/Bitcoin)) to use as gifts for all the economically forward-thinking little girls and boys.

To do this, he needs to find [MD5](https://en.wikipedia.org/wiki/MD5) hashes which, in [hexadecimal](https://en.wikipedia.org/wiki/Hexadecimal), start with at least five zeroes. The input to the MD5 hash is some secret key (your puzzle input, given below) followed by a number in decimal. To mine AdventCoins, you must find Santa the lowest positive number (no leading zeroes: `1`, `2`, `3`, ...) that produces such a hash.

For example:

- If your secret key is `abcdef`, the answer is `609043`, because the MD5 hash of `abcdef609043` starts with five zeroes (`000001dbbfa...`), and it is the lowest such number to do so.

- If your secret key is `pqrstuv`, the lowest number it combines with to make an MD5 hash starting with five zeroes is `1048970`; that is, the MD5 hash of `pqrstuv1048970` looks like `000006136ef...`.

### Part 2

Now find one that starts with <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">six zeroes</span>.

## Solution

The common code between the two parts has been grouped in a shared *static library* which is linked to the solution of the 2 parts. This library is defined in the [CMakeLists.txt](CMakeLists.txt) alongside of the definition of the two other parts.

Moreover, this static library uses [OpenSSL](https://www.openssl.org/) integrated via [Conan package Manager](https://conan.io/) in the [CMakeLists.txt](CMakeLists.txt).

### Part 1

The source of the solution is contained in the file [part_one.cpp](src/part_one.cpp), and a test checking this solution is in the file [CMakeLists.txt](CMakeLists.txt).
The executable generated takes 2 arguments :
- the secret key,
- and the expected final result.

If the expected final result doesn't match the one find by the program, then, the result founded is displayed.
Else, the program exits successfully.

### Part 2

The source of the solution is contained in the file [part_two.cpp](src/part_two.cpp), and a test checking this solution is in the file [CMakeLists.txt](CMakeLists.txt).
The executable generated takes 2 arguments :
- the secret key,
- and the expected final result.

If the expected result doesn't match the one find by the program, then, the result founded is displayed.
Else, the program exits successfully.
