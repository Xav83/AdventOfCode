#include "Grid.hpp"
#include "string_manipulation.hpp"
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char **argv) {
  assert(argc == 3);

  std::ifstream file(argv[1]);
  assert(file.is_open());

  const auto expectedResult = atoi(argv[2]);

  std::string fileContent((std::istreambuf_iterator<char>(file)),
                          std::istreambuf_iterator<char>());

  Grid lights;

  foreachLineIn(fileContent, [&lights](const std::string &line) {
    lights.nextLine();
    for (const auto &character : line) {
      lights.emplaceLight(character == '#');
    }
  });

  for (auto i = 0; i < 100; ++i) {
    lights.nextStep();
  }

  const auto numberOfLightsOn = lights.numberOfLightsOn();

  if (expectedResult == numberOfLightsOn) {
    return 0;
  } else {
    std::cout << "The result found is " << numberOfLightsOn
              << " but the expected result is " << expectedResult << std::endl;
    return 1;
  }
}
