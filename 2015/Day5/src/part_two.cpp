#include "string_manipulation.hpp"
#include <iostream>
#include <cassert>
#include <fstream>
#include <algorithm>
#include <string_view>

bool hasTwiceAPairOfLetters(const std::string_view str)
{
    for(size_t i = 0; i < str.size() - 2; ++i)
    {
        std::string_view str_toSearch(&str[i], 2);
        std::string_view str_toSearchIn(&str[i + 2], str.size() - i - 2);
        if(str_toSearchIn.find(str_toSearch) != std::string_view::npos)
        {
            return true;
        }
    }
    return false;
}

bool hasOneLetterAppearingTwiceWithOnlyOneLetterBetween(const std::string_view str)
{
    for(size_t i = 0; i < str.size() - 2; ++i)
    {
        if(str[i] == str[i + 2])
        {
            return true;
        }
    }
    return false;
}

bool isNice(const std::string_view str)
{
    return hasTwiceAPairOfLetters(str) && hasOneLetterAppearingTwiceWithOnlyOneLetterBetween(str);
}

int main (int argc, char** argv)
{
    assert(argc == 3);

    std::ifstream file(argv[1]);
    assert (file.is_open());

    const auto expectedResult = atoi (argv[2]);

    std::string fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    auto numberOfNiceString{0};

    foreachLineIn(fileContent, [&numberOfNiceString](const auto& str)
    {
        if(isNice(str))
        {
            ++numberOfNiceString;
        }
    });

    if(expectedResult == numberOfNiceString)
    {
        return 0;
    }
    else
    {
        std::cout << "The result found is " << numberOfNiceString << " but the expected result is " << expectedResult << std::endl;
        return 1;
    }
}
