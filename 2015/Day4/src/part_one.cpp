#include "md5_wrapper.hpp"
#include <cassert>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  assert(argc == 3);

  const std::string secretKey = argv[1];
  const auto expectedResult = atoi(argv[2]);

  size_t result = 0;

  while (true) {
    const auto str = secretKey + std::to_string(result);
    const auto md5Result = getMD5(str);
    const auto md5Str = byteToString(md5Result);
    if (md5Str.substr(0, 5) == "00000") {
      break;
    }
    ++result;
  }
  if (result == expectedResult) {
    return 0;
  } else {
    std::cout << "The result found is " << result
              << " but the expected result is " << expectedResult << std::endl;
    return 1;
  }
}
