#pragma once

#include <array>
#include <optional>
#include <sstream>
#include <vector>

using CompoundValue = std::optional<size_t>;
using Compound = std::pair<std::string, CompoundValue>;

class Aunt {
public:
  Aunt(std::vector<Compound> knownElements);
  ~Aunt();

  const std::array<Compound, 10> &getCompounds() const;

private:
  Aunt();

  std::array<Compound, 10> compounds;
};

std::vector<Compound> extractCompounds(const std::string &line);
