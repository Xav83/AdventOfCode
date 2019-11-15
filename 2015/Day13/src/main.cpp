#include "string_manipulation.hpp"
#include <algorithm>
#include <cassert>
#include <fstream>
#include <functional>
#include <iostream>
#include <regex>
#include <vector>

using Person = std::string;

using Happiness = int;

class Relationship {
public:
  Relationship(Person &fromPerson_, Person &toPerson_, Happiness happiness_)
      : fromPerson(fromPerson_), toPerson(toPerson_), happiness(happiness_) {}
  ~Relationship() = default;

  bool isRelationBetween(const Person &fromPerson_,
                         const Person &toPerson_) const {
    return fromPerson == fromPerson_ && toPerson == toPerson_;
  }

  Happiness getHappiness() const { return happiness; }

private:
  Person &fromPerson, &toPerson;
  Happiness happiness{0};
};

Happiness extractHappinessFrom(const std::string &instruction) {
  std::regex word_regex("[0-9]+");
  auto words_begin = std::sregex_iterator(std::begin(instruction),
                                          std::end(instruction), word_regex);
  auto words_end = std::sregex_iterator();

  for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
    std::smatch match = *i;
    return static_cast<Happiness>(atoi(match.str().c_str()));
  }
  assert(false);
  return 0;
}

std::tuple<Person, Person, Happiness>
extractInformationFrom(const std::string &instruction) {
  const auto firstSpaceCharacter =
      std::find_if(std::begin(instruction), std::end(instruction),
                   [](const auto &c) { return c == ' '; });
  const auto lastSpaceCharacter =
      std::find_if(std::rbegin(instruction), std::rend(instruction),
                   [](const auto &c) { return c == ' '; });

  Person fromPersonName(std::begin(instruction), firstSpaceCharacter);
  Person toPersonName(lastSpaceCharacter.base()++,
                      std::rbegin(instruction).base());
  toPersonName.pop_back(); // Removes the dot

  auto happiness = extractHappinessFrom(std::string(instruction));
  if (instruction.find("lose") != std::string_view::npos) {
    happiness *= -1;
  }

  return {fromPersonName, toPersonName, happiness};
}

Happiness calculateHappiness(
    const std::vector<std::reference_wrapper<Person>> &personsPlaced,
    const std::vector<Relationship> &relationships) {
  Happiness happiness{0};
  for (auto index = size_t{0}; index < personsPlaced.size(); ++index) {
    const auto neighborLeftIndex =
        (index == 0) ? (personsPlaced.size() - 1) : (index - 1);
    const auto neighborRightIndex =
        (index == (personsPlaced.size() - 1)) ? 0 : (index + 1);

    const auto leftRelationShip = std::find_if(
        std::begin(relationships), std::end(relationships),
        [&personsPlaced, neighborLeftIndex, index](const auto &relationship) {
          return relationship.isRelationBetween(
              personsPlaced[index].get(),
              personsPlaced[neighborLeftIndex].get());
        });
    happiness += leftRelationShip->getHappiness();

    const auto rightRelationShip = std::find_if(
        std::begin(relationships), std::end(relationships),
        [&personsPlaced, neighborRightIndex, index](const auto &relationship) {
          return relationship.isRelationBetween(
              personsPlaced[index], personsPlaced[neighborRightIndex]);
        });
    happiness += rightRelationShip->getHappiness();
  }
  return happiness;
}

Happiness
gerateTablePosition(std::vector<std::reference_wrapper<Person>> &personsPlaced,
                    std::vector<std::reference_wrapper<Person>> &personsToPlace,
                    const std::vector<Relationship> &relationships) {
  if (personsToPlace.empty()) {
    return calculateHappiness(personsPlaced, relationships);
  }

  Happiness optimalHappiness{0};

  for (const auto &personToPlace : personsToPlace) {
    auto newPersonsPlaced = personsPlaced;
    auto newPersonsToPlace = personsToPlace;

    newPersonsPlaced.emplace_back(personToPlace);
    newPersonsToPlace.erase(
        std::remove_if(std::begin(newPersonsToPlace),
                       std::end(newPersonsToPlace),
                       [&personToPlace](const auto &person) {
                         return personToPlace.get() == person.get();
                       }),
        std::end(newPersonsToPlace));

    const auto optimalHappinessSoFar =
        gerateTablePosition(newPersonsPlaced, newPersonsToPlace, relationships);
    optimalHappiness = std::max(optimalHappiness, optimalHappinessSoFar);
  }

  return optimalHappiness;
}

Happiness
getMostOptimalHappiness(std::vector<Person> &persons,
                        const std::vector<Relationship> &relationships) {
  std::vector<std::reference_wrapper<Person>> personsToPlaceRefs,
      personsPlacedRefs;
  std::copy(persons.begin(), persons.end(),
            std::back_inserter(personsToPlaceRefs));

  personsToPlaceRefs.pop_back();
  personsPlacedRefs.emplace_back(persons.back());
  return gerateTablePosition(personsPlacedRefs, personsToPlaceRefs,
                             relationships);
}

int main(int argc, char **argv) {
  assert(argc == 3);

  std::ifstream file(argv[1]);
  assert(file.is_open());

  const auto expectedResult = atoi(argv[2]);

  std::string fileContent((std::istreambuf_iterator<char>(file)),
                          std::istreambuf_iterator<char>());

  std::vector<Person> persons;
  std::vector<Relationship> relationships;

  foreachLineIn(fileContent, [&persons](const std::string &line) {
    const auto elements = extractInformationFrom(line);
    persons.emplace_back(std::get<0>(elements));
  });

  auto last = std::unique(persons.begin(), persons.end());
  persons.erase(last, persons.end());

  foreachLineIn(fileContent, [&persons,
                              &relationships](const std::string &line) {
    const auto elements = extractInformationFrom(line);
    const auto fromPerson = std::find(std::begin(persons), std::end(persons),
                                      Person(std::get<0>(elements)));
    const auto toPerson = std::find(std::begin(persons), std::end(persons),
                                    Person(std::get<1>(elements)));
    relationships.emplace_back(*fromPerson, *toPerson, std::get<2>(elements));
  });

  const auto optimalHappiness = getMostOptimalHappiness(persons, relationships);

  if (expectedResult == optimalHappiness) {
    return 0;
  } else {
    std::cout << "The result found is " << optimalHappiness
              << " but the expected result is " << expectedResult << std::endl;
    return 1;
  }
}
