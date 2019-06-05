#include "dimension.hpp"
#include "string_manipulation.hpp"
#include <cassert>

std::vector<int> Dimensions::toAreas() const
{
    return {length * width, width * height, height * length};
}

// Function extracting the dimensions described on a line of the input
Dimensions&& makeDimensionFromLine(const std::string& input)
{
    Dimensions dimensions;
    int counter{0};
    foreachElementsInStringDelimitedBy(input, 'x', [&counter, &dimensions](const auto& dimensionsStr)
    {
        switch (counter)
        {
        case 0:
            dimensions.length = atoi(dimensionsStr.c_str());
            break;
        case 1:
            dimensions.width = atoi(dimensionsStr.c_str());
            break;
        case 2:
            dimensions.height = atoi(dimensionsStr.c_str());
            break;
        default:
            assert(false);
            break;
        }
        ++counter;
    });
    return std::move(dimensions);
}
