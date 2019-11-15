#include "coordinate.hpp"

bool Coordinate::operator==(const Coordinate &other) const {
  return x == other.x && y == other.y;
}

bool Coordinate::operator<(const Coordinate &other) const {
  return x < other.x || (x == other.x && y < other.y);
}
