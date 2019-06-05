#include <cassert>
#include <fstream>
#include <algorithm>
#include <iostream>

int main(int argc, char** argv)
{
    assert(argc == 3);

    std::ifstream file(argv[1]);
    assert (file.is_open());

    const auto expectedResult = atoi (argv[2]);

    std::string fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    auto floor {0};
    const auto firstEnteringInTheBasement = std::find_if(
        std::begin(fileContent),
        std::end(fileContent),
        [&floor](const auto& character)
        {
            if (character == '(')
            {
                ++floor;
            }
            else if (character == ')')
            {
                --floor;
            }
            return floor < 0;
        });
    if(firstEnteringInTheBasement == std::end(fileContent))
    {
        std::cout << "Never went to the basement" << std::endl;
        return 1;
    }

    const auto result = std::distance(std::begin(fileContent), firstEnteringInTheBasement) + 1;
    if(expectedResult == result)
    {
        return 0;
    }
    else
    {
        std::cout << "The result found is " << result << " but the expected result is " << expectedResult << std::endl;
        return 1;
    }
}
