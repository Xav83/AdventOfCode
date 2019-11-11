#include "Aunt.hpp"
#include <cassert>

Aunt::Aunt()
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

Aunt::Aunt(std::vector<Counpound> knownElements) : Aunt()
{
    for(const auto& knownElement : knownElements)
    {
        auto counpound = std::find_if(std::begin(counpounds), std::end(counpounds), [&knownElement](const auto& counpound){ return counpound.first == knownElement.first; });
        assert(counpound != std::end(counpounds));
        counpound->second = knownElement.second;
    }
}

Aunt::~Aunt() = default;

const std::array<Counpound, 10>& Aunt::getCounpounds() const { return counpounds; }

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
