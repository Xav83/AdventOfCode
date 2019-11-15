#pragma once

#include <vector>

// Structure representing the dimensions of wrapping paper
struct Dimensions {
  int length{0};
  int width{0};
  int height{0};

  // Returns a vector with the three areas calculated from the dimensions
  std::vector<int> toAreas() const;
};

// Function extracting the dimensions described on a line of the input
Dimensions &&makeDimensionFromLine(const std::string &input);
