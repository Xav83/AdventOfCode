# [Day 7: Some Assembly Required](https://adventofcode.com/2015/day/7)

## Problem

### Part 1

This year, Santa brought little Bobby Tables a set of wires and <span style="color:green">bitwise logic gates</span>! Unfortunately, little Bobby is a little under the recommended age range, and he needs help assembling the circuit.

Each wire has an identifier (some lowercase letters) and can carry a <span style="color:green">16-bit</span> signal (a number from `0` to `65535`). A signal is provided to each wire by a gate, another wire, or some specific value. Each wire can only get a signal from one source, but can provide its signal to multiple destinations. A gate provides no signal until all of its inputs have a signal.

The included instructions booklet describes how to connect the parts together: `x AND y -> z` means to connect wires `x` and `y` to an AND gate, and then connect its output to wire `z`.

For example:

- `123 -> x` means that the signal `123` is provided to wire `x`.
- `x AND y -> z` means that the <span style="color:green">bitwise AND</span> of wire `x` and wire `y` is provided to wire `z`.
- `p LSHIFT 2 -> q` means that the value from wire `p` is <span style="color:green">left-shifted</span> by `2` and then provided to wire `q`.
- `NOT e -> f` means that the <span style="color:green">bitwise complement</span> of the value from wire `e` is provided to wire `f`.

Other possible gates include `OR` (<span style="color:green">bitwise OR</span>) and `RSHIFT` (<span style="color:green">right-shift</span>). If, for some reason, you'd like to <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">emulate</span> the circuit instead, almost all programming languages (for example, <span style="color:green">C</span>, <span style="color:green">JavaScript</span>, or <span style="color:green">Python</span>) provide operators for these gates.

For example, here is a simple circuit:

```
123 -> x
456 -> y
x AND y -> d
x OR y -> e
x LSHIFT 2 -> f
y RSHIFT 2 -> g
NOT x -> h
NOT y -> i
```

After it is run, these are the signals on the wires:

```
d: 72
e: 507
f: 492
g: 114
h: 65412
i: 65079
x: 123
y: 456
```

In little Bobby's kit's instructions booklet (provided as your puzzle input), what signal is ultimately provided to wire <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">a</span>?

### Part 2

Now, take the signal you got on wire `a`, override wire `b` to that signal, and reset the other wires (including wire `a`). What new signal is ultimately provided to wire `a`?

## Solution

The source of the solution is contained in the file [main.cpp](src/main.cpp), and the tests checking this solution are in the file [CMakeLists.txt](CMakeLists.txt).
The executable generated takes 2 arguments :
- the file containing the instructions,
- and the expected value of the signal for the wire named `a`.

If the expected value of the signal on doesn't match the one find by the program, then, the result founded is displayed.
Else, the program exits successfully.

For each part, there is only an input different.