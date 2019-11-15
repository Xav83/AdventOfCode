#include "Reindeer.hpp"
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>

int main(int argc, char **argv) {
  assert(argc == 3);

  std::ifstream file(argv[1]);
  assert(file.is_open());

  const auto expectedResult = atoi(argv[2]);

  std::string fileContent((std::istreambuf_iterator<char>(file)),
                          std::istreambuf_iterator<char>());

  std::vector<Reindeer> reindeers;

  foreachLineIn(fileContent, [&reindeers](const std::string &line) {
    reindeers.emplace_back(extractInformationFrom(line));
  });

  for (auto i = 0; i < 2503; ++i) {
    for (auto &reindeer : reindeers) {
      reindeer.oneSecondPassed();
    }

    const auto winningReindeer = std::max_element(
        std::begin(reindeers), std::end(reindeers),
        [](const auto &firstReindeer, const auto &secondReindeer) {
          return firstReindeer.getCurrentPosition() <
                 secondReindeer.getCurrentPosition();
        });
    const auto distanceOfWinningReindeer =
        winningReindeer->getCurrentPosition();

    for (auto &reindeer : reindeers) {
      if (reindeer.getCurrentPosition() == distanceOfWinningReindeer) {
        reindeer.winBonusPoint();
      }
    }
  }

  const auto winningReindeer = std::max_element(
      std::begin(reindeers), std::end(reindeers),
      [](const auto &firstReindeer, const auto &secondReindeer) {
        return firstReindeer.getCurrentBonusPoint() <
               secondReindeer.getCurrentBonusPoint();
      });
  const auto pointsOfWinningReindeer = winningReindeer->getCurrentBonusPoint();

  if (expectedResult == pointsOfWinningReindeer) {
    return 0;
  } else {
    std::cout << "The result found is " << pointsOfWinningReindeer
              << " but the expected result is " << expectedResult << std::endl;
    return 1;
  }
}
