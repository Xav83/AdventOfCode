#include "Aunt.hpp"
#include "string_manipulation.hpp"
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

  std::vector<Aunt> aunts;

  std::array<Compound, 10> ticketTape{
      Compound{"children", 3}, Compound{"cats", 7},
      Compound{"samoyeds", 2}, Compound{"pomeranians", 3},
      Compound{"akitas", 0},   Compound{"vizslas", 0},
      Compound{"goldfish", 5}, Compound{"trees", 3},
      Compound{"cars", 2},     Compound{"perfumes", 1}};

  foreachLineIn(fileContent, [&aunts](const std::string &line) {
    aunts.emplace_back(extractCompounds(line));
  });

  auto aunt = std::find_if(
      std::begin(aunts), std::end(aunts), [&ticketTape](const auto &aunt) {
        const auto &auntCompounds = aunt.getCompounds();
        for (auto i = size_t{0}; i < auntCompounds.size(); ++i) {
          if (!auntCompounds[i].second.has_value()) {
            continue;
          }
          if (auntCompounds[i].first == "cats" ||
              auntCompounds[i].first == "trees") {
            if (auntCompounds[i].second.value() <= ticketTape[i].second) {
              return false;
            }
            continue;
          }
          if (auntCompounds[i].first == "pomeranians" ||
              auntCompounds[i].first == "goldfish") {
            if (auntCompounds[i].second.value() >= ticketTape[i].second) {
              return false;
            }
            continue;
          }
          if (auntCompounds[i].second.has_value() &&
              auntCompounds[i].second.value() != ticketTape[i].second) {
            return false;
          }
        }
        return true;
      });

  const auto numberOfAuntSue = std::distance(std::begin(aunts), aunt) + 1;

  if (expectedResult == numberOfAuntSue) {
    return 0;
  } else {
    std::cout << "The result found is " << numberOfAuntSue
              << " but the expected result is " << expectedResult << std::endl;
    return 1;
  }
}
