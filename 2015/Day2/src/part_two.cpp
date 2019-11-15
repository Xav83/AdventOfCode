#include "dimension.hpp"
#include "string_manipulation.hpp"

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

  auto ribbonLength{0};
  foreachLineIn(fileContent, [&ribbonLength](const auto &line) {
    const auto dimension = makeDimensionFromLine(line);
    const auto max =
        std::max({dimension.length, dimension.width, dimension.height});
    ribbonLength += 2 * dimension.length + 2 * dimension.width +
                    2 * dimension.height - 2 * max +
                    dimension.length * dimension.width * dimension.height;
  });

  if (expectedResult == ribbonLength) {
    return 0;
  } else {
    std::cout << "The result found is " << ribbonLength
              << " but the expected result is " << expectedResult << std::endl;
    return 1;
  }
}
