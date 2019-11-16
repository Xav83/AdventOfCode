#include <nlohmann/json.hpp>

#include <cassert>
#include <fstream>
#include <iostream>

int getSum(const nlohmann::json &jsonDocument) {
  auto sum{0};
  for (const auto &[key, value] : jsonDocument.items()) {
    if (value.is_number()) {
      sum += value.get<int>();
    } else if (value.is_array() || value.is_object()) {
      sum += getSum(value);
    } else if (value.is_string() && jsonDocument.is_object()) {
      if (value.get<std::string>() == "red") {
        sum = 0;
        break;
      }
    }
  }
  return sum;
}

int main(int argc, char **argv) {
  assert(argc == 3);

  std::ifstream file(argv[1]);
  nlohmann::json jsonDocument;
  file >> jsonDocument;

  const auto expectedResult = atoi(argv[2]);

  const auto sum = getSum(jsonDocument);

  if (expectedResult == sum) {
    return 0;
  } else {
    std::cout << "The result found is " << sum << " but the expected result is "
              << expectedResult << std::endl;
    return 1;
  }
}
