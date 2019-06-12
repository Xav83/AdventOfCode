#include <iostream>
#include <cassert>
#include <fstream>
#include <vector>
#include <algorithm>

struct Coordinate
{
    int x{0};
    int y{0};

    bool operator== (const Coordinate& other)
    {
        return x == other.x && y == other.y;
    }

    bool operator< (const Coordinate& other) const
    {
        return x < other.x || (x == other.x && y < other.y);
    }
};

using Path = std::vector<Coordinate>;

struct DeliveryMan
{
    Coordinate position;
    Path path;
};

int main (int argc, char** argv)
{
    assert(argc == 3);

    std::ifstream file(argv[1]);
    assert (file.is_open());

    const auto expectedResult = atoi (argv[2]);

    std::string fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    DeliveryMan santa, roboSanta;
    santa.path.emplace_back(santa.position);
    roboSanta.path.emplace_back(roboSanta.position);

    DeliveryMan* deliveryMan = &santa;

    for(auto direction : fileContent)
    {
        switch (direction)
        {
            case '^':
                ++deliveryMan->position.y;
            break;
            case '>':
                ++deliveryMan->position.x;
            break;
            case '<':
                --deliveryMan->position.x;
            break;
            case 'v':
                --deliveryMan->position.y;
            break;
        }
        deliveryMan->path.emplace_back(deliveryMan->position);
        deliveryMan = deliveryMan == &santa ? &roboSanta: &santa;
    }

    std::sort(std::begin(santa.path), std::end(santa.path));
    std::sort(std::begin(roboSanta.path), std::end(roboSanta.path));

    std::vector<Coordinate> mergedPath;
    std::merge(std::begin(santa.path), std::end(santa.path), std::begin(roboSanta.path), std::end(roboSanta.path), std::back_inserter(mergedPath));

    auto it = std::unique(std::begin(mergedPath), std::end(mergedPath));
    const auto numberOfHousesVisited = std::distance(std::begin(mergedPath), it);

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
