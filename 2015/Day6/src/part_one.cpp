#include "string_manipulation.hpp"
#include "coordinate.hpp"
#include <array>
#include <cassert>
#include <functional>
#include <fstream>
#include <iostream>
#include <numeric>
#include <regex>
#include <sstream>

enum class LightAction
{
    TURN_ON,
    TURN_OFF,
    TOGGLE,
};

class Light
{
public:
    Light() = default;
    ~Light() = default;

    void turnOn () { isOn = true; }
    void turnOff () { isOn = false; }
    void toggle () { isOn = !isOn; }

    bool isLit () const { return isOn; }

private:
    bool isOn{false};
};

struct Rectangle
{
    Coordinate topLeft, bottomRight;
};

void foreachCoordinateInRectangle(Rectangle rect, std::function<void(const Coordinate)> callback)
{
        for(auto x = rect.topLeft.x; x <= rect.bottomRight.x; ++x)
        {
            for(auto y = rect.topLeft.y; y <= rect.bottomRight.y; ++y)
            {
                callback({x, y});
            }
        }
}

class Grid
{
public:
    Grid () = default;
    ~Grid () = default;

    void turnOn(Rectangle rect)
    {
        foreachCoordinateInRectangle(rect, [this](const Coordinate coordinate)
        {
            grid[coordinate.x][coordinate.y].turnOn();
        });
    }

    void turnOff(Rectangle rect)
    {
        foreachCoordinateInRectangle(rect, [this](const Coordinate coordinate)
        {
            grid[coordinate.x][coordinate.y].turnOff();
        });
    }

    void toggle(Rectangle rect)
    {
        foreachCoordinateInRectangle(rect, [this](const Coordinate coordinate)
        {
            grid[coordinate.x][coordinate.y].toggle();
        });
    }

    size_t getNumberOfLightTunedOn () const
    {
        Rectangle rect{{0, 0}, {999, 999}};
        size_t numberOfLightTunedOn{0};
        foreachCoordinateInRectangle(rect, [this, &numberOfLightTunedOn](const Coordinate coordinate)
        {
            if(grid[coordinate.x][coordinate.y].isLit())
            {
                ++numberOfLightTunedOn;
            }
        });
        return numberOfLightTunedOn;
    }

private:
    std::array<std::array<Light, 1000>, 1000> grid;
};

LightAction getActionFromLine(const std::string_view line)
{
    if(line.compare(0, 7, "turn on") == 0)
    {
        return LightAction::TURN_ON;
    }
    if(line.compare(0, 8, "turn off") == 0)
    {
        return LightAction::TURN_OFF;
    }
    if(line.compare(0, 6, "toggle") == 0)
    {
        return LightAction::TOGGLE;
    }
    assert(false);
}

Rectangle getRectangleFromLine(std::string line)
{
    std::regex word_regex("([0-9]+)");
    auto words_begin = 
        std::sregex_iterator(line.begin(), line.end(), word_regex);
    auto words_end = std::sregex_iterator();

    std::array<int, 4> values;
    auto valueIndex{0};

    for (std::sregex_iterator i = words_begin; i != words_end; ++i, ++valueIndex)
    {
        std::smatch match = *i;
        values[valueIndex] = atoi(match.str().c_str());
    }
    return {{values[0], values[1]}, {values[2], values[3]}};
}

int main (int argc, char** argv)
{
    assert(argc == 3);

    std::ifstream file(argv[1]);
    assert (file.is_open());

    const auto expectedResult = atoi (argv[2]);

    std::string fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    Grid grid;

    foreachLineIn(fileContent, [&grid](const std::string& line)
    {
        const auto actionId = getActionFromLine(line);
        const auto rectangle = getRectangleFromLine(line);
        switch (actionId)
        {
        case LightAction::TURN_ON:
            grid.turnOn(rectangle);
            break;
        case LightAction::TURN_OFF:
            grid.turnOff(rectangle);
            break;
        case LightAction::TOGGLE:
            grid.toggle(rectangle);
            break;
        default:
            assert(false);
            break;
        }
    });

    const auto numberOfLightsTurnedOn = grid.getNumberOfLightTunedOn();

    if(expectedResult == numberOfLightsTurnedOn)
    {
        return 0;
    }
    else
    {
        std::cout << "The result found is " << numberOfLightsTurnedOn << " but the expected result is " << expectedResult << std::endl;
        return 1;
    }
}
