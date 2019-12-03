#include "string_manipulation.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
#include <limits>
#include <vector>

using Container = size_t;
using Containers = std::vector<Container>;

size_t countNumberOfCombination(const Containers &containers, size_t volum,
                                size_t numberOfContainerUsed,
                                size_t &numberMinOfContainerUsed) {
  size_t numberOfCombination{0};
  for (auto index = size_t{0}; index < containers.size(); ++index) {
    const int remainingVolum = volum - containers[index];
    if (remainingVolum == 0) {
      if (numberMinOfContainerUsed > (numberOfContainerUsed + 1)) {
        numberOfCombination = 1;
        numberMinOfContainerUsed = numberOfContainerUsed + 1;
      } else {
        assert(numberMinOfContainerUsed == (numberOfContainerUsed + 1));
        ++numberOfCombination;
      }
      continue;
    }
    if (remainingVolum < 0) {
      continue;
    }
    if ((numberOfContainerUsed + 1) >= numberMinOfContainerUsed) {
      continue;
    }
    Containers containersNotUsed;
    std::copy(containers.begin() + index + 1, containers.end(),
              std::back_inserter(containersNotUsed));

    const auto currentNumberMinOfContainerUsed = numberMinOfContainerUsed;

    const auto numberOfCombinationFound = countNumberOfCombination(
        containersNotUsed, remainingVolum, numberOfContainerUsed + 1,
        numberMinOfContainerUsed);
    if (currentNumberMinOfContainerUsed == numberMinOfContainerUsed) {
      numberOfCombination += numberOfCombinationFound;
    } else {
      numberOfCombination = numberOfCombinationFound;
    }
  }
  return numberOfCombination;
}

int main(int argc, char **argv) {
  assert(argc == 4);

  std::ifstream file(argv[1]);
  assert(file.is_open());

  const auto totalVolumeOfEggnog = atoi(argv[2]);
  const auto expectedResult = atoi(argv[3]);

  std::string fileContent((std::istreambuf_iterator<char>(file)),
                          std::istreambuf_iterator<char>());

  Containers containers;

  foreachLineIn(fileContent, [&containers](const std::string &line) {
    containers.emplace_back(atoi(line.c_str()));
  });

  auto numberMinOfContainerUsed = containers.size();
  const auto numberOfCombinations = countNumberOfCombination(
      containers, totalVolumeOfEggnog, 0, numberMinOfContainerUsed);

  if (expectedResult == numberOfCombinations) {
    return 0;
  } else {
    std::cout << "The result found is " << numberOfCombinations
              << " but the expected result is " << expectedResult << std::endl;
    return 1;
  }
}
