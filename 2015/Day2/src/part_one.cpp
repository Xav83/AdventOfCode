#include "dimension.hpp"
#include "string_manipulation.hpp"

#include <cassert>
#include <fstream>
#include <algorithm>
#include <iostream>

int main(int argc, char** argv)
{
    assert(argc == 3);

    std::ifstream file(argv[1]);
    assert (file.is_open());

    const auto expectedResult = atoi (argv[2]);

    std::string fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    auto wrappingPaperArea{0};
    foreachLineIn(fileContent, [&wrappingPaperArea](const auto& line)
    {
        const auto dimension = makeDimensionFromLine(line);
        const auto areas = dimension.toAreas();
        const auto min = std::min_element(std::begin(areas), std::end(areas));
        wrappingPaperArea += 2 * areas[0] + 2 * areas[1] + 2 * areas[2] + *min;
    });

    if(expectedResult == wrappingPaperArea)
    {
        return 0;
    }
    else
    {
        std::cout << "The result found is " << wrappingPaperArea << " but the expected result is " << expectedResult << std::endl;
        return 1;
    }
}
