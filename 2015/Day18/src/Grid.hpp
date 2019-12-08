#pragma once

#include "Light.hpp"

class Grid {
public:
  Grid();
  ~Grid();

  void emplaceLight(LightState lightState);
  void nextLine();

  void nextStep();
  size_t numberOfLightsOn() const;

private:
  std::vector<std::vector<Light>> lights;
};
