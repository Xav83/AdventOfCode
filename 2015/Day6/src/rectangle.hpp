#pragma once

#include "coordinate.hpp"
#include <functional>

struct Rectangle
{
    Coordinate topLeft, bottomRight;
};

void foreachCoordinateInRectangle(Rectangle rect, std::function<void(const Coordinate)> callback);
