#include "string_manipulation.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
#include <optional>
#include <array>
#include <sstream>

using CounpoundValue = std::optional<size_t>;
using Counpound = std::pair<std::string, CounpoundValue>;

class Aunt
{
public:
    Aunt()
    {
        counpounds[0].first = "children";
        counpounds[1].first = "cats";
        counpounds[2].first = "samoyeds";
        counpounds[3].first = "pomeranians";
        counpounds[4].first = "akitas";
        counpounds[5].first = "vizslas";
        counpounds[6].first = "goldfish";
        counpounds[7].first = "trees";
        counpounds[8].first = "cars";
        counpounds[9].first = "perfumes";
    }
    Aunt(std::vector<Counpound> knownElements) : Aunt()
    {
        for(const auto& knownElement : knownElements)
        {
            auto counpound = std::find_if(std::begin(counpounds), std::end(counpounds), [&knownElement](const auto& counpound){ return counpound.first == knownElement.first; });
            assert(counpound != std::end(counpounds));
            counpound->second = knownElement.second;
        }
    }
    ~Aunt() = default;

    const std::array<Counpound, 10>& getCounpounds() const { return counpounds; }

private:
    std::array<Counpound, 10> counpounds;
};

std::vector<Counpound> extractCounpounds(const std::string& line)
{
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
    return {{firstElement, firstElementValue}, {secondElement, secondElementValue}, {thirdElement, thirdElementValue}};
}



int main (int argc, char** argv)
{
    assert(argc == 3);

    std::ifstream file(argv[1]);
    assert (file.is_open());

    const auto expectedResult = atoi (argv[2]);

    std::string fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    std::vector<Aunt> aunts;

    std::array<Counpound, 10> ticketTape
    {
        Counpound{"children", 3},
        Counpound{"cats", 7},
        Counpound{"samoyeds", 2},
        Counpound{"pomeranians", 3},
        Counpound{"akitas", 0},
        Counpound{"vizslas", 0},
        Counpound{"goldfish", 5},
        Counpound{"trees", 3},
        Counpound{"cars", 2},
        Counpound{"perfumes", 1}
    };


    foreachLineIn(fileContent, [&aunts](const std::string& line)
    {
        aunts.emplace_back(extractCounpounds(line));
    });

    auto aunt = std::find_if(std::begin(aunts), std::end(aunts), [&ticketTape](const auto& aunt)
    {
        const auto& auntCounpounds = aunt.getCounpounds();
        for(auto i = size_t{0}; i < auntCounpounds.size(); ++i)
        {
            if(auntCounpounds[i].second.has_value() &&
               auntCounpounds[i].second.value() != ticketTape[i].second)
            {
                return false;
            }
        }
        return true;
    });

    const auto numberOfAuntSue = std::distance(std::begin(aunts), aunt) + 1;

    if(expectedResult == numberOfAuntSue)
    {
        return 0;
    }
    else
    {
        std::cout << "The result found is " << numberOfAuntSue << " but the expected result is " << expectedResult << std::endl;
        return 1;
    }
}
