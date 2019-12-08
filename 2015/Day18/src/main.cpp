#include "string_manipulation.hpp"
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>

using LightState = bool;

class Light {
public:
  Light(LightState initialState) : currentState(initialState) {}
  ~Light() = default;

  bool isOn() const { return currentState; }
  bool isOff() const { return !currentState; }

  void prepareNextState(
      const std::vector<std::reference_wrapper<Light>> &neighbors) {
    const auto numberOfNeighborsOn =
        std::count_if(std::begin(neighbors), std::end(neighbors),
                      [](const auto &light) { return light.get().isOn(); });
    if (isOff() && numberOfNeighborsOn == 3) {
      willChangeState = true;
    } else if (isOn() &&
               (numberOfNeighborsOn != 2 && numberOfNeighborsOn != 3)) {
      willChangeState = true;
    }
  }

  void nextState() {
    if (willChangeState) {
      currentState = !currentState;
      willChangeState = false;
    }
  }

private:
  LightState currentState = false;
  LightState willChangeState = false;
};

class Grid {
public:
  Grid() = default;
  ~Grid() = default;

  void emplaceLight(LightState lightState) {
    lights.back().emplace_back(lightState);
  }
  void nextLine() { lights.emplace_back(); }

  void nextStep() {
    for (size_t i{0}; i < lights.size(); ++i) {
      for (size_t j{0}; j < lights[i].size(); ++j) {
        std::vector<std::reference_wrapper<Light>> neighbors;
        if (i > 0) {
          neighbors.push_back(lights[i - 1][j]);
        }
        if (j > 0) {
          neighbors.push_back(lights[i][j - 1]);
        }

        if (i < (lights.size() - 1)) {
          neighbors.push_back(lights[i + 1][j]);
        }
        if (j < (lights[i].size() - 1)) {
          neighbors.push_back(lights[i][j + 1]);
        }

        if (i > 0 && j > 0) {
          neighbors.push_back(lights[i - 1][j - 1]);
        }
        if (i < (lights.size() - 1) && j < (lights[i].size() - 1)) {
          neighbors.push_back(lights[i + 1][j + 1]);
        }

        if (i > 0 && j < (lights[i].size() - 1)) {
          neighbors.push_back(lights[i - 1][j + 1]);
        }
        if (i < (lights.size() - 1) && j > 0) {
          neighbors.push_back(lights[i + 1][j - 1]);
        }

        lights[i][j].prepareNextState(neighbors);
      }
    }
    for (size_t i{0}; i < lights.size(); ++i) {
      for (size_t j{0}; j < lights[i].size(); ++j) {
        lights[i][j].nextState();
      }
    }
  }

  size_t numberOfLightsOn() const {
    auto sum = 0;
    for (size_t i{0}; i < lights.size(); ++i) {
      sum += std::count_if(std::begin(lights[i]), std::end(lights[i]),
                           [](const auto &light) { return light.isOn(); });
    }
    return sum;
  }

private:
  std::vector<std::vector<Light>> lights;
};

int main(int argc, char **argv) {
  assert(argc == 3);

  std::ifstream file(argv[1]);
  assert(file.is_open());

  const auto expectedResult = atoi(argv[2]);

  std::string fileContent((std::istreambuf_iterator<char>(file)),
                          std::istreambuf_iterator<char>());

  Grid lights;

  foreachLineIn(fileContent, [&lights](const std::string &line) {
    lights.nextLine();
    for (const auto &character : line) {
      lights.emplaceLight(character == '#');
    }
  });

  for (auto i = 0; i < 100; ++i) {
    lights.nextStep();
  }

  const auto numberOfLightsOn = lights.numberOfLightsOn();

  if (expectedResult == numberOfLightsOn) {
    return 0;
  } else {
    std::cout << "The result found is " << numberOfLightsOn
              << " but the expected result is " << expectedResult << std::endl;
    return 1;
  }
}
