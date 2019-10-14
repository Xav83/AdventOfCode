# [Day 14: Reindeer Olympics](https://adventofcode.com/2015/day/14)

## Problem

### Part 1

This year is the Reindeer Olympics! Reindeer can fly at high speeds, but must rest occasionally to recover their energy. Santa would like to know which of his reindeer is fastest, and so he has them race.

Reindeer can only either be <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">flying</span> (always at their top speed) or <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">resting</span> (not moving at all), and always spend whole seconds in either state.

For example, suppose you have the following Reindeer:

- Comet can fly <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">14 km/s for 10 seconds</span>, but then must rest for <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">127 seconds</span>.
- Dancer can fly <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">16 km/s for 11 seconds</span>, but then must rest for <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">162 seconds</span>.

After one second, Comet has gone 14 km, while Dancer has gone 16 km. After ten seconds, Comet has gone 140 km, while Dancer has gone 160 km. On the eleventh second, Comet begins resting (staying at 140 km), and Dancer continues on for a total distance of 176 km. On the 12th second, both reindeer are resting. They continue to rest until the 138th second, when Comet flies for another ten seconds. On the 174th second, Dancer flies for another 11 seconds.

In this example, after the 1000th second, both reindeer are resting, and Comet is in the lead at `1120` km (poor Dancer has only gotten `1056` km by that point). So, in this situation, Comet would win (if the race ended at 1000 seconds).

Given the descriptions of each reindeer (in your puzzle input), after exactly `2503` seconds, <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">what distance has the winning reindeer traveled</span>?

### Part 2

Seeing how reindeer move in bursts, Santa decides he's not pleased with the old scoring system.

Instead, at the end of each second, he awards one point to the reindeer currently in the lead. (If there are multiple reindeer tied for the lead, they each get one point.) He keeps the traditional 2503 second time limit, of course, as doing otherwise would be entirely ridiculous.

Given the example reindeer from above, after the first second, Dancer is in the lead and gets one point. He stays in the lead until several seconds into Comet's second burst: after the 140th second, Comet pulls into the lead and gets his first point. Of course, since Dancer had been in the lead for the 139 seconds before that, he has accumulated 139 points by the 140th second.

After the 1000th second, Dancer has accumulated `689` points, while poor Comet, our old champion, only has `312`. So, with the new scoring system, Dancer would win (if the race ended at 1000 seconds).

Again given the descriptions of each reindeer (in your puzzle input), after exactly `2503` seconds, <span style="color:white;text-shadow: 1px 1px 2px black, 0 0 25px blue, 0 0 5px darkblue;">how many points does the winning reindeer have</span>?

## Solution

The source of the solution is contained in the files [part_one.cpp](src/part_one.cpp) and [part_two.cpp](src/part_two.cpp), depending on the part of the problem, and a test checking this solution is in the file [CMakeLists.txt](CMakeLists.txt). Also, their is some shared code for the [Reindeer](src/Reindeer.cpp).
The executable generated takes 2 arguments :
- the file containing the stats of the reindeers,
- and the expected distance or bonus points.

If the expected result doesn't match the one find by the program, then, the result founded is displayed.
Else, the program exits successfully.
