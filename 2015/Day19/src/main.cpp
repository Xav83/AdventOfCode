#include "string_manipulation.hpp"
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>

using Molecule = std::string;
using Replacement = std::pair<Molecule, Molecule>;

int main(int argc, char **argv) {
  assert(argc == 3);

  std::ifstream file(argv[1]);
  assert(file.is_open());

  const auto expectedResult = atoi(argv[2]);

  std::string fileContent((std::istreambuf_iterator<char>(file)),
                          std::istreambuf_iterator<char>());

  std::vector<Replacement> replacements;
  Molecule baseMolecule;
  bool readBaseMolecule{false};

  foreachLineIn(fileContent, [&readBaseMolecule, &baseMolecule,
                              &replacements](const std::string &line) {
    if (line.empty()) {
      readBaseMolecule = true;
      return;
    }
    if (readBaseMolecule) {
      baseMolecule = line;
      return;
    }
    Molecule fromMolecule = line.substr(0, line.find(' '));
    Molecule toMolecule = line.substr(line.rfind(' ') + 1);
    replacements.emplace_back(fromMolecule, toMolecule);
  });

  std::vector<Molecule> moleculesCreated;

  for (const auto &replacement : replacements) {
    for (size_t baseMoleculeIndex = 0; baseMoleculeIndex < baseMolecule.size();
         ++baseMoleculeIndex) {
      bool found = true;
      for (size_t i = 0; i < replacement.first.size(); ++i) {
        if (baseMoleculeIndex + i > baseMolecule.size()) {
          break;
        }
        if (replacement.first[i] != baseMolecule[baseMoleculeIndex + i]) {
          found = false;
          break;
        }
      }
      if (found) {
        Molecule moleculeCreated = baseMolecule;
        moleculeCreated.erase(baseMoleculeIndex, replacement.first.size());
        moleculeCreated.insert(baseMoleculeIndex, replacement.second);
        moleculesCreated.push_back(moleculeCreated);
      }
    }
  }

  std::sort(std::begin(moleculesCreated), std::end(moleculesCreated));
  auto last =
      std::unique(std::begin(moleculesCreated), std::end(moleculesCreated));
  moleculesCreated.erase(last, std::end(moleculesCreated));
  const auto numberOfDistinctMolecules = moleculesCreated.size();

  if (expectedResult == numberOfDistinctMolecules) {
    return 0;
  } else {
    std::cout << "The result found is " << numberOfDistinctMolecules
              << " but the expected result is " << expectedResult << std::endl;
    return 1;
  }
}
