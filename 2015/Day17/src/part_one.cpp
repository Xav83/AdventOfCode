#include "string_manipulation.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>

using Container = size_t;
using Containers = std::vector<Container>;

size_t countNumberOfCombination(const Containers &containers, size_t volum) {
  size_t numberOfCombination{0};
  for (auto index = size_t{0}; index < containers.size(); ++index) {
    const auto remainingVolum = volum - containers[index];
    if (remainingVolum == 0) {
      ++numberOfCombination;
      continue;
    }
    if (remainingVolum < 0) {
      continue;
    }
    Containers containersNotUsed;
    std::copy(containers.begin() + index + 1, containers.end(),
              std::back_inserter(containersNotUsed));

    numberOfCombination +=
        countNumberOfCombination(containersNotUsed, remainingVolum);
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

  const auto numberOfCombinations =
      countNumberOfCombination(containers, totalVolumeOfEggnog);

  if (expectedResult == numberOfCombinations) {
    return 0;
  } else {
    std::cout << "The result found is " << numberOfCombinations
              << " but the expected result is " << expectedResult << std::endl;
    return 1;
  }
}
