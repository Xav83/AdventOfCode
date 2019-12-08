#pragma once

#include <vector>

using LightState = bool;

class Light {
public:
  Light(LightState initialState);
  ~Light();

  bool isOn() const;
  bool isOff() const;

  void
  prepareNextState(const std::vector<std::reference_wrapper<Light>> &neighbors);

  void nextState();

private:
  LightState currentState = false;
  LightState willChangeState = false;
};
