#pragma once

#include "types.hpp"

std::pair<City, City>
getCitiesFromInstruction(const std::string_view instruction);

Distance getDistanceFromInstruction(const std::string &instruction);
