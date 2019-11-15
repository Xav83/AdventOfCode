#include "input_parser.hpp"
#include <cassert>
#include <regex>

std::pair<City, City>
getCitiesFromInstruction(const std::string_view instruction) {
  const auto citySeparatorPosition = instruction.find(" to ");
  const auto equalSeparatorPosition =
      instruction.substr(citySeparatorPosition + 4).find(" = ");
  return std::make_pair(City(instruction.substr(0, citySeparatorPosition)),
                        City(instruction.substr(citySeparatorPosition + 4,
                                                equalSeparatorPosition)));
}

Distance getDistanceFromInstruction(const std::string &instruction) {
  std::regex word_regex("[0-9]+");
  auto words_begin = std::sregex_iterator(std::begin(instruction),
                                          std::end(instruction), word_regex);
  auto words_end = std::sregex_iterator();

  auto value{0};

  for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
    std::smatch match = *i;
    return static_cast<Distance>(atoi(match.str().c_str()));
  }
  assert(false);
  return 0;
}
