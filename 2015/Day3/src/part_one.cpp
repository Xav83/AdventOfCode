#include "path.hpp"
#include <iostream>
#include <cassert>
#include <fstream>
#include <algorithm>

int main (int argc, char** argv)
{
    assert(argc == 3);

    std::ifstream file(argv[1]);
    assert (file.is_open());

    const auto expectedResult = atoi (argv[2]);

    std::string fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    Coordinate santaPosition;
    Path santaPath;
    santaPath.emplace_back(santaPosition);

    for(auto direction : fileContent)
    {
        switch (direction)
        {
            case '^':
                ++santaPosition.y;
            break;
            case '>':
                ++santaPosition.x;
            break;
            case '<':
                --santaPosition.x;
            break;
            case 'v':
                --santaPosition.y;
            break;
        }
        santaPath.emplace_back(santaPosition);
    }

    std::sort(std::begin(santaPath), std::end(santaPath));
    auto it = std::unique(std::begin(santaPath), std::end(santaPath));

    const auto numberOfHousesVisited = std::distance(std::begin(santaPath), it);

    if(expectedResult == numberOfHousesVisited)
    {
        return 0;
    }
    else
    {
        std::cout << "The result found is " << numberOfHousesVisited << " but the expected result is " << expectedResult << std::endl;
        return 1;
    }
}
