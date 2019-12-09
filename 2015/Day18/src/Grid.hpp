#pragma once

#include "Light.hpp"
#include <memory>

class Grid {
public:
  Grid();
  ~Grid();

  void emplaceLight(LightState lightState);
  void pushBackLight(std::unique_ptr<Light> light);
  void nextLine();

  void nextStep();
  size_t numberOfLightsOn() const;

  std::vector<std::vector<std::unique_ptr<Light>>> &getLights();

private:
  std::vector<std::vector<std::unique_ptr<Light>>> lights;
};
