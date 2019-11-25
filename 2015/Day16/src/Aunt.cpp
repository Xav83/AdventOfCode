#include "Aunt.hpp"
#include <cassert>

Aunt::Aunt() {
  compounds[0].first = "children";
  compounds[1].first = "cats";
  compounds[2].first = "samoyeds";
  compounds[3].first = "pomeranians";
  compounds[4].first = "akitas";
  compounds[5].first = "vizslas";
  compounds[6].first = "goldfish";
  compounds[7].first = "trees";
  compounds[8].first = "cars";
  compounds[9].first = "perfumes";
}

Aunt::Aunt(std::vector<Compound> knownElements) : Aunt() {
  for (const auto &knownElement : knownElements) {
    auto compound = std::find_if(std::begin(compounds), std::end(compounds),
                                 [&knownElement](const auto &compound) {
                                   return compound.first == knownElement.first;
                                 });
    assert(compound != std::end(compounds));
    compound->second = knownElement.second;
  }
}

Aunt::~Aunt() = default;

const std::array<Compound, 10> &Aunt::getCompounds() const { return compounds; }

std::vector<Compound> extractCompounds(const std::string &line) {
  std::istringstream stream(line);
  std::string useless, firstElement, secondElement, thirdElement;
  size_t firstElementValue, secondElementValue, thirdElementValue;

  stream >> useless >> useless;
  stream >> firstElement >> firstElementValue >> useless;
  stream >> secondElement >> secondElementValue >> useless;
  stream >> thirdElement >> thirdElementValue;
  firstElement.pop_back();
  secondElement.pop_back();
  thirdElement.pop_back();
  return {{firstElement, firstElementValue},
          {secondElement, secondElementValue},
          {thirdElement, thirdElementValue}};
}
