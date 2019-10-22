#include "string_manipulation.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <array>

constexpr auto numberOfProperties = 5;
using PropertyValue = int;
using Ingredient = std::array<PropertyValue, numberOfProperties>;

Ingredient extractIngredientFrom (const std::string& line)
{
    std::istringstream stream(line);
    std::string ingredientName, capacity, comma, durability, flavor, texture, calories;
    PropertyValue capacityValue, durabilityValue, flavorValue, textureValue, caloriesValue;
 
    stream >> ingredientName >> capacity >> capacityValue >> comma >> durability >> durabilityValue >> comma >> flavor >> flavorValue >> comma >> texture >> textureValue >> comma >> calories >> caloriesValue;
    return Ingredient{capacityValue, durabilityValue, flavorValue, textureValue, caloriesValue};
}

using Proportions = std::vector<size_t>;

std::vector<Proportions> createAllProportionPossibles(size_t numberOfIngredients, size_t teaspoonNumber)
{
    if (numberOfIngredients == 1)
    {
        return {Proportions{teaspoonNumber}};
    }
    std::vector<Proportions> proportions;
    for(auto i = size_t{1}; i < teaspoonNumber; ++i)
    {
        const auto proportionsOfLessIngredients = createAllProportionPossibles (numberOfIngredients - 1, teaspoonNumber - i);
        for(const auto& proportionsOfLessIngredient : proportionsOfLessIngredients)
        {
            Proportions p {i};
            p.insert(p.end(), proportionsOfLessIngredient.begin(), proportionsOfLessIngredient.end());
            proportions.push_back(p);
        }
    }
    return proportions;
}

int calculateTotalScore(std::vector<Ingredient> ingredients, Proportions proportion)
{
    auto score{1};
    for(auto propertyIndex = size_t{0}; propertyIndex < numberOfProperties; ++propertyIndex)
    {
        auto propertyScore{0};
        for(auto indexIngredient = size_t{0}; indexIngredient < ingredients.size(); ++indexIngredient)
        {
            const auto& ingredient = ingredients[indexIngredient];
            propertyScore += ingredient[propertyIndex] * proportion[indexIngredient];
        }
        if(propertyIndex == numberOfProperties - 1)
        {
            return (propertyScore != 500) ? 0 : score;
        }
        if(propertyScore < 0)
        {
            return 0;
        }
        score *= propertyScore;
    }
    return score;
}

int main (int argc, char** argv)
{
    assert(argc == 3);

    std::ifstream file(argv[1]);
    assert (file.is_open());

    const auto expectedResult = atoi (argv[2]);

    std::string fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    std::vector<Ingredient> ingredients;

    foreachLineIn(fileContent, [&ingredients](const std::string& line)
    {
        ingredients.emplace_back(extractIngredientFrom(line));
    });

    constexpr auto teaspoonsNumber = 100;
    const auto allProportionsPossible = createAllProportionPossibles (ingredients.size(), teaspoonsNumber);

    const auto winningProportion = std::max_element(
        std::begin(allProportionsPossible),
        std::end(allProportionsPossible),
        [&ingredients](const auto& firstProportion, const auto& secondProportion)
        {
            return calculateTotalScore(ingredients, firstProportion) < calculateTotalScore(ingredients, secondProportion);
        });

    const auto bestTotalScore = calculateTotalScore(ingredients, *winningProportion);

    if(expectedResult == bestTotalScore)
    {
        return 0;
    }
    else
    {
        std::cout << "The result found is " << bestTotalScore << " but the expected result is " << expectedResult << std::endl;
        return 1;
    }
}
