#include "input_parser.hpp"
#include <array>
#include <cassert>
#include <regex>

LightAction getActionFromLine(const std::string_view line) {
  if (line.compare(0, 7, "turn on") == 0) {
    return LightAction::TURN_ON;
  }
  if (line.compare(0, 8, "turn off") == 0) {
    return LightAction::TURN_OFF;
  }
  if (line.compare(0, 6, "toggle") == 0) {
    return LightAction::TOGGLE;
  }
  assert(false);
  return LightAction::NONE;
}

Rectangle getRectangleFromLine(std::string line) {
  std::regex word_regex("([0-9]+)");
  auto words_begin = std::sregex_iterator(line.begin(), line.end(), word_regex);
  auto words_end = std::sregex_iterator();

  std::array<int, 4> values;
  auto valueIndex{0};

  for (std::sregex_iterator i = words_begin; i != words_end;
       ++i, ++valueIndex) {
    std::smatch match = *i;
    values[valueIndex] = atoi(match.str().c_str());
  }
  return {{values[0], values[1]}, {values[2], values[3]}};
}
