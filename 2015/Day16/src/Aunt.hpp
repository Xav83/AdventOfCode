#pragma once

#include <array>
#include <optional>
#include <sstream>
#include <vector>

using CounpoundValue = std::optional<size_t>;
using Counpound = std::pair<std::string, CounpoundValue>;

class Aunt {
public:
  Aunt();
  Aunt(std::vector<Counpound> knownElements);
  ~Aunt();

  const std::array<Counpound, 10> &getCounpounds() const;

private:
  std::array<Counpound, 10> counpounds;
};

std::vector<Counpound> extractCounpounds(const std::string &line);
