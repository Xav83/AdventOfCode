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
  const auto openParenthesisCount =
      std::count(std::begin(fileContent), std::end(fileContent), '(');
  const auto closeParenthesisCount =
      std::count(std::begin(fileContent), std::end(fileContent), ')');
  const auto result = openParenthesisCount - closeParenthesisCount;

  if (expectedResult == result) {
    return 0;
  } else {
    std::cout << "The result found is " << result
              << " but the expected result is " << expectedResult << std::endl;
    return 1;
  }
}
