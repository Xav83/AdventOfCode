#pragma once

#include <vector>

using LightState = bool;

class Light {
public:
  Light(LightState initialState);
  ~Light();

  virtual bool isOn() const;
  virtual bool isOff() const;

  void
  prepareNextState(const std::vector<std::reference_wrapper<Light>> &neighbors);

  void nextState();

private:
  LightState currentState = false;
  LightState willChangeState = false;
};
