#include "Light.hpp"
#include <algorithm>

Light::Light(LightState initialState) : currentState(initialState) {}
Light::~Light() = default;

bool Light::isOn() const { return currentState; }
bool Light::isOff() const { return !currentState; }

void Light::prepareNextState(
    const std::vector<std::reference_wrapper<Light>> &neighbors) {
  const auto numberOfNeighborsOn =
      std::count_if(std::begin(neighbors), std::end(neighbors),
                    [](const auto &light) { return light.get().isOn(); });
  if (isOff() && numberOfNeighborsOn == 3) {
    willChangeState = true;
  } else if (isOn() && (numberOfNeighborsOn != 2 && numberOfNeighborsOn != 3)) {
    willChangeState = true;
  }
}

void Light::nextState() {
  if (willChangeState) {
    currentState = !currentState;
    willChangeState = false;
  }
}
