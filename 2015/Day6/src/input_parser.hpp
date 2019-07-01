#pragma once

#include "light_action.hpp"
#include "rectangle.hpp"
#include <string_view>

LightAction getActionFromLine(const std::string_view line);

Rectangle getRectangleFromLine(std::string line);
