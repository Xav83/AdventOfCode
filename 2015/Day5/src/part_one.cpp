#include "string_manipulation.hpp"
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <string_view>

bool hasThreeVowels(const std::string_view str) {
  return 3 <=
         std::count_if(std::begin(str), std::end(str), [](const auto &letter) {
           return letter == 'a' || letter == 'e' || letter == 'i' ||
                  letter == 'o' || letter == 'u';
         });
}

bool hasLettersAppearingTwiceInRow(const std::string_view str) {
  char previousCharacter = CHAR_MIN;
  for (const auto &character : str) {
    if (character == previousCharacter) {
      return true;
    }
    previousCharacter = character;
  }
  return false;
}

bool hasForbiddenSubString(const std::string_view str) {
  return str.find("ab") != std::string_view::npos ||
         str.find("cd") != std::string_view::npos ||
         str.find("pq") != std::string_view::npos ||
         str.find("xy") != std::string_view::npos;
}

bool isNice(const std::string_view str) {
  return hasThreeVowels(str) && hasLettersAppearingTwiceInRow(str) &&
         !hasForbiddenSubString(str);
}

int main(int argc, char **argv) {
  assert(argc == 3);

  std::ifstream file(argv[1]);
  assert(file.is_open());

  const auto expectedResult = atoi(argv[2]);

  std::string fileContent((std::istreambuf_iterator<char>(file)),
                          std::istreambuf_iterator<char>());

  auto numberOfNiceString{0};

  foreachLineIn(fileContent, [&numberOfNiceString](const std::string &str) {
    if (isNice(str)) {
      ++numberOfNiceString;
    }
  });

  if (expectedResult == numberOfNiceString) {
    return 0;
  } else {
    std::cout << "The result found is " << numberOfNiceString
              << " but the expected result is " << expectedResult << std::endl;
    return 1;
  }
}
