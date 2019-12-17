#include "string_manipulation.hpp"
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>
#include <variant>
#include <memory>
#include <cctype>
#include <string>

using Atom = std::string;

class Molecule
{
public:
  Molecule(const std::string_view formula)
  {
    assert(!formula.empty());

    Atom atomInContruction;
    for(const auto& character : formula)
    {
      if(static_cast<bool>(std::isupper(character)))
      {
        if(!atomInContruction.empty())
        {
          atoms.emplace_back(atomInContruction);
        }
        atomInContruction.clear();
      }
      atomInContruction.push_back(character);
    }
    if(!atomInContruction.empty())
    {
      atoms.emplace_back(atomInContruction);
    }
    assert(!atoms.empty());
  }

  std::vector<Atom> getAtoms() const { return atoms; }

private:
  std::vector<Atom> atoms;
};

using CYK_Rule_id = Atom;

class CYK_Rule_id_Factory
{
public:
  CYK_Rule_id_Factory() = delete;
  
  static CYK_Rule_id generateNewId(const std::string& base)
  {
    return ids.emplace_back(std::string(base) + std::to_string(ids.size()));
  }

private:
  static std::vector<CYK_Rule_id> ids;
};
std::vector<CYK_Rule_id> CYK_Rule_id_Factory::ids;

class CYK_Rule
{
public:
  using RuleTerm = Atom;
  using SecondRightSideTerm = std::unique_ptr<CYK_Rule>;

  CYK_Rule(const CYK_Rule_id& id, const RuleTerm& firstTerm)
  : leftSide(id), firstRightSideTerm(firstTerm)
  {
  }
  CYK_Rule(const CYK_Rule_id& id, const RuleTerm& firstTerm, const CYK_Rule& secondTerm)
  : leftSide(id), firstRightSideTerm(firstTerm), secondRightSideTerm(std::make_unique<CYK_Rule>(secondTerm))
  {
  }
  CYK_Rule(const CYK_Rule& other)
  : leftSide(other.leftSide), firstRightSideTerm(other.firstRightSideTerm)
  {
    if(other.secondRightSideTerm != nullptr)
    {
      secondRightSideTerm = std::make_unique<CYK_Rule>(*other.secondRightSideTerm);
    }
  }
  ~CYK_Rule() = default;

  void print() const
  {
    std::cout << leftSide << " => " << firstRightSideTerm;
    if(secondRightSideTerm != nullptr)
    {
      std::cout << " : " << secondRightSideTerm->leftSide;
    }
      std::cout << '\n';
  }

private:
  CYK_Rule_id leftSide;
  RuleTerm firstRightSideTerm;
  SecondRightSideTerm secondRightSideTerm;
};

std::vector<CYK_Rule> extract_CYK_RulesFromInputLine (const std::string& inputLine)
{
  std::vector<CYK_Rule> rules;

  CYK_Rule_id ruleId = inputLine.substr(0, inputLine.find(' '));
  Molecule rightSideMolecule(inputLine.substr(inputLine.rfind(' ') + 1));

  const auto& rightSideAtoms = rightSideMolecule.getAtoms();
  rules.emplace_back(ruleId, rightSideAtoms.front());

  if(rightSideMolecule.getAtoms().size() == 1)
  {
    return rules;
  }

  for(size_t atomsIndex = 1; atomsIndex < rightSideAtoms.size(); ++atomsIndex)
  {
      rules.emplace_back(CYK_Rule_id_Factory::generateNewId(ruleId), rightSideAtoms[atomsIndex], rules.back());
  }
  return rules;
}

// void CYKalgorithm(BigMolecule bigMoleculeToCreate, std::vector<Replacement> replacements)
// {
//   const auto N = bigMoleculeToCreate.size();
//   const auto R = replacements.size();
// // let P[n,n,r] be an array of booleans. Initialize all elements of P to false.
//   std::vector<std::vector<std::vector<bool>>> P(N);
//   for(auto& p : P)
//   {
//     p.resize(N);
//     for(auto& p2 : p)
//     {
//       p2.resize(R, false);
//     }
//   }

// // for each s = 1 to n
//   for(size_t s = 0; s < N; ++s)
//   {
// //   for each unit production Rv → as
//     for(size_t v = 0; v < R; ++v)
//     {
//       if(replacements[v].second.size() == 1)
//       {
//         if(replacements[v].second.front() == bigMoleculeToCreate[s])
//         {
// //     set P[1,s,v] = true
//         P[1][s][v] = true;
//         }
//       }
//     }
//   }
// // for each l = 2 to n -- Length of span
//   for(size_t l = 1; l < N; ++l)
//   {
// //   for each s = 1 to n-l+1 -- Start of span
//     for(size_t s = 0; s < N-l+1; ++s)
//     {
// //     for each p = 1 to l-1 -- Partition of span
//       for(size_t p = 0; p < l-1; ++p)
//       {
// //       for each production Ra  → Rb Rc
//         for(size_t a = 0; a < R; ++a)
//         {
//           if(replacements[a].second.size() > 1)
//           {
// //         if P[p,s,b] and P[l-p,s+p,c] then set P[l,s,a] = true
//             // TODO : To adapt
//             // if(P[p][s][b] && P[l-p][s+p][c])
//             // {
//             //   P[l][s][a] = true
//             // }
//           }
//         }
//       }
//     }
//   }
// }

int main(int argc, char **argv) {
  assert(argc == 3);

  std::ifstream file(argv[1]);
  assert(file.is_open());

  const auto expectedResult = atoi(argv[2]);

  std::string fileContent((std::istreambuf_iterator<char>(file)),
                          std::istreambuf_iterator<char>());

  std::vector<CYK_Rule> rules;

  bool stopReadingRules{false};

  foreachLineIn(fileContent, [&stopReadingRules, &rules](const std::string &line) {
    if (line.empty()) {
      stopReadingRules = true;
      return;
    }
    if (stopReadingRules) {
      return;
    }
    const auto& extractedRules = extract_CYK_RulesFromInputLine (line);
    std::copy(std::begin(extractedRules), std::end(extractedRules), std::back_inserter(rules));
  });

  for(const auto& rule: rules)
  {
    rule.print();
  }

  const auto numberOfDistinctMolecules = 0;

  if (expectedResult == numberOfDistinctMolecules) {
    return 0;
  } else {
    std::cout << "The result found is " << numberOfDistinctMolecules
              << " but the expected result is " << expectedResult << std::endl;
    return 1;
  }
}
