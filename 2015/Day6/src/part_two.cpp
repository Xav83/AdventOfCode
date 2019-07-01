#include "string_manipulation.hpp"
#include "input_parser.hpp"
#include <array>
#include <cassert>
#include <fstream>
#include <iostream>
#include <numeric>

class Light
{
public:
    Light() = default;
    ~Light() = default;

    void turnOn () { ++brightness; }
    void turnOff () { if(brightness != 0) { --brightness; } }
    void toggle () { brightness +=2; }

    size_t getBrightness () const { return brightness; }

private:
    size_t brightness{0};
};

class Grid
{
public:
    Grid () = default;
    ~Grid () = default;

    void turnOn(const Rectangle& rect)
    {
        foreachCoordinateInRectangle(rect, [this](const Coordinate coordinate)
        {
            grid[coordinate.x][coordinate.y].turnOn();
        });
    }

    void turnOff(const Rectangle& rect)
    {
        foreachCoordinateInRectangle(rect, [this](const Coordinate coordinate)
        {
            grid[coordinate.x][coordinate.y].turnOff();
        });
    }

    void toggle(const Rectangle& rect)
    {
        foreachCoordinateInRectangle(rect, [this](const Coordinate coordinate)
        {
            grid[coordinate.x][coordinate.y].toggle();
        });
    }

    size_t getBrightness () const
    {
        Rectangle rect{{0, 0}, {999, 999}};
        size_t brightness{0};
        foreachCoordinateInRectangle(rect, [this, &brightness](const Coordinate coordinate)
        {
            brightness += grid[coordinate.x][coordinate.y].getBrightness();
        });
        return brightness;
    }

private:
    std::array<std::array<Light, 1000>, 1000> grid;
};

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

    const auto numberOfLightsTurnedOn = grid.getBrightness ();

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
