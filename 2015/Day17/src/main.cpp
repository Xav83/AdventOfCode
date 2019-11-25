#include "string_manipulation.hpp"
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>

using id = size_t;
using value = size_t;
using Container = std::pair<id, value>;
using Containers = std::vector<Container>;

std::vector<Containers> createAllCombinations(const Containers &containers) {
  if (containers.size() == 1) {
    return {containers};
  }
  std::vector<Containers> combinations;
  for (auto index = size_t{0}; index < containers.size(); ++index) {
    auto subEnsemble = containers;
    subEnsemble.erase(std::begin(subEnsemble) + index);
    auto subEnsembleCombinations = createAllCombinations(subEnsemble);
    std::copy(subEnsembleCombinations.begin(), subEnsembleCombinations.end(),
              std::back_inserter(combinations));
    std::transform(subEnsembleCombinations.begin(),
                   subEnsembleCombinations.end(),
                   std::back_inserter(combinations),
                   [&index, &containers](Containers combination) {
                     combination.emplace_back(containers[index]);
                     return combination;
                   });
  }
  return combinations;
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

  size_t containersId = 0;
  foreachLineIn(fileContent,
                [&containersId, &containers](const std::string &line) {
                  containers.emplace_back(containersId++, atoi(line.c_str()));
                });

  auto combinations = createAllCombinations(containers);

  for (auto &combination : combinations) {
    std::sort(std::begin(combination), std::end(combination));
  }
  std::sort(std::begin(combinations), std::end(combinations));
  auto last = std::unique(std::begin(combinations), std::end(combinations));
  combinations.erase(last, std::end(combinations));

  combinations.erase(
      std::remove_if(std::begin(combinations), std::end(combinations),
                     [&totalVolumeOfEggnog](const auto &combination) {
                       return std::accumulate(
                                  std::begin(combination),
                                  std::end(combination), 0,
                                  [](int sum, Container container) -> int {
                                    return sum + container.second;
                                  }) != totalVolumeOfEggnog;
                     }),
      std::end(combinations));

  const auto numberOfCombinations = combinations.size();

  if (expectedResult == numberOfCombinations) {
    return 0;
  } else {
    std::cout << "The result found is " << numberOfCombinations
              << " but the expected result is " << expectedResult << std::endl;
    return 1;
  }
}
