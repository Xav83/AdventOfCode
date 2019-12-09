#include "Grid.hpp"
#include <algorithm>

Grid::Grid() = default;
Grid::~Grid() = default;

void Grid::emplaceLight(LightState lightState) {
  lights.back().emplace_back(std::make_unique<Light>(lightState));
}

void Grid::pushBackLight(std::unique_ptr<Light> light) {
  lights.back().emplace_back(std::move(light));
}
void Grid::nextLine() { lights.emplace_back(); }

void Grid::nextStep() {
  for (size_t i{0}; i < lights.size(); ++i) {
    for (size_t j{0}; j < lights[i].size(); ++j) {
      std::vector<std::reference_wrapper<Light>> neighbors;
      if (i > 0) {
        neighbors.push_back(*lights[i - 1][j]);
      }
      if (j > 0) {
        neighbors.push_back(*lights[i][j - 1]);
      }

      if (i < (lights.size() - 1)) {
        neighbors.push_back(*lights[i + 1][j]);
      }
      if (j < (lights[i].size() - 1)) {
        neighbors.push_back(*lights[i][j + 1]);
      }

      if (i > 0 && j > 0) {
        neighbors.push_back(*lights[i - 1][j - 1]);
      }
      if (i < (lights.size() - 1) && j < (lights[i].size() - 1)) {
        neighbors.push_back(*lights[i + 1][j + 1]);
      }

      if (i > 0 && j < (lights[i].size() - 1)) {
        neighbors.push_back(*lights[i - 1][j + 1]);
      }
      if (i < (lights.size() - 1) && j > 0) {
        neighbors.push_back(*lights[i + 1][j - 1]);
      }

      lights[i][j]->prepareNextState(neighbors);
    }
  }
  for (size_t i{0}; i < lights.size(); ++i) {
    for (size_t j{0}; j < lights[i].size(); ++j) {
      lights[i][j]->nextState();
    }
  }
}

size_t Grid::numberOfLightsOn() const {
  auto sum = 0;
  for (size_t i{0}; i < lights.size(); ++i) {
    sum += std::count_if(std::begin(lights[i]), std::end(lights[i]),
                         [](const auto &light) { return light->isOn(); });
  }
  return sum;
}

std::vector<std::vector<std::unique_ptr<Light>>> &Grid::getLights() {
  return lights;
}
