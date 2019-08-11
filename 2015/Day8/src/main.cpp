#include "string_manipulation.hpp"
#include <cassert>
#include <fstream>
#include <iostream>

size_t getTotalNumberOfCharacter(const std::string_view line)
{
    return line.size();
}

size_t getNumberOfCharacterInMemory(const std::string_view line)
{
    size_t size{0};
    for(size_t index{0}; index < line.size(); ++index)
    {
        ++size;
        if(index == line.size() - 1)
        {
            continue;
        }
        if(line[index] == '\\' && line[index + 1] == '\\')
        {
            ++index;
        }
        else if(line[index] == '\\' && line[index + 1] == '"')
        {
            ++index;
        }
        else if(line[index] == '\\' && line[index + 1] == 'x')
        {
            index += 3;
        }
    }
    return size - 2; // Subtracts the two " around the word
}

int main (int argc, char** argv)
{
    assert(argc == 3);

    std::ifstream file(argv[1]);
    assert (file.is_open());

    const auto expectedResult = atoi (argv[2]);

    std::string fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    size_t totalNumberOfCharacter{0};
    size_t inMemoryNumberOfCharacter{0};

    foreachLineIn(fileContent, [&totalNumberOfCharacter, &inMemoryNumberOfCharacter](const std::string& line)
    {
        totalNumberOfCharacter += getTotalNumberOfCharacter(line);
        inMemoryNumberOfCharacter += getNumberOfCharacterInMemory(line);
    });

    const auto result = totalNumberOfCharacter - inMemoryNumberOfCharacter;

    if(expectedResult == result)
    {
        return 0;
    }
    else
    {
        std::cout << "The result found is " << result  << " but the expected result is " << expectedResult << std::endl;
        return 1;
    }
}
