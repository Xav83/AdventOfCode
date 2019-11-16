#include "input_parser.hpp"
#include "string_manipulation.hpp"
#include <array>
#include <cassert>
#include <fstream>
#include <iostream>
#include <numeric>

class Light {
public:
  Light() = default;
  ~Light() = default;

  void turnOn() { isOn = true; }
  void turnOff() { isOn = false; }
  void toggle() { isOn = !isOn; }

  bool isLit() const { return isOn; }

private:
  bool isOn{false};
};

class Grid {
public:
  Grid() = default;
  ~Grid() = default;

  void turnOn(const Rectangle &rect) {
    foreachCoordinateInRectangle(rect, [this](const Coordinate coordinate) {
      grid[coordinate.x][coordinate.y].turnOn();
    });
  }

  void turnOff(const Rectangle &rect) {
    foreachCoordinateInRectangle(rect, [this](const Coordinate coordinate) {
      grid[coordinate.x][coordinate.y].turnOff();
    });
  }

  void toggle(const Rectangle &rect) {
    foreachCoordinateInRectangle(rect, [this](const Coordinate coordinate) {
      grid[coordinate.x][coordinate.y].toggle();
    });
  }

  size_t getNumberOfLightTunedOn() const {
    Rectangle rect{{0, 0}, {999, 999}};
    size_t numberOfLightTunedOn{0};
    foreachCoordinateInRectangle(
        rect, [this, &numberOfLightTunedOn](const Coordinate coordinate) {
          if (grid[coordinate.x][coordinate.y].isLit()) {
            ++numberOfLightTunedOn;
          }
        });
    return numberOfLightTunedOn;
  }

private:
  std::array<std::array<Light, 1000>, 1000> grid;
};

int main(int argc, char **argv) {
  assert(argc == 3);

  std::ifstream file(argv[1]);
  assert(file.is_open());

  const auto expectedResult = atoi(argv[2]);

  std::string fileContent((std::istreambuf_iterator<char>(file)),
                          std::istreambuf_iterator<char>());

  Grid grid;

  foreachLineIn(fileContent, [&grid](const std::string &line) {
    const auto actionId = getActionFromLine(line);
    const auto rectangle = getRectangleFromLine(line);
    switch (actionId) {
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

  if (expectedResult == numberOfLightsTurnedOn) {
    return 0;
  } else {
    std::cout << "The result found is " << numberOfLightsTurnedOn
              << " but the expected result is " << expectedResult << std::endl;
    return 1;
  }
}
