#include "string_manipulation.hpp"
#include <cassert>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

size_t getTotalNumberOfCharacters(const std::string_view line) {
  return line.size();
}

size_t getNumberOfCharactersWhenEncoded(const std::string_view line) {
  std::stringstream ss;
  ss << std::quoted(line);
  return ss.str().size();
}

int main(int argc, char **argv) {
  assert(argc == 3);

  std::ifstream file(argv[1]);
  assert(file.is_open());

  const auto expectedResult = atoi(argv[2]);

  std::string fileContent((std::istreambuf_iterator<char>(file)),
                          std::istreambuf_iterator<char>());

  size_t totalNumberOfCharacter{0};
  size_t encodedNumberOfCharacter{0};

  foreachLineIn(
      fileContent, [&totalNumberOfCharacter,
                    &encodedNumberOfCharacter](const std::string &line) {
        totalNumberOfCharacter += getTotalNumberOfCharacters(line);
        encodedNumberOfCharacter += getNumberOfCharactersWhenEncoded(line);
      });

  const auto result = encodedNumberOfCharacter - totalNumberOfCharacter;

  if (expectedResult == result) {
    return 0;
  } else {
    std::cout << "The result found is " << result
              << " but the expected result is " << expectedResult << std::endl;
    return 1;
  }
}
