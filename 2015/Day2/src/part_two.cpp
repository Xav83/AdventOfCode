#include <cassert>
#include <fstream>
#include <functional>
#include <sstream>
#include <algorithm>
#include <iostream>

// Calls the specified function for each substring delimited by the specified delimiter in the specified input
void foreachElementsInStringDelimitedBy(const std::string& input, const char delimiter, std::function<void(const std::string&)> callback)
{
    std::stringstream ss(input);
    std::string token;

    while(std::getline(ss,token, delimiter)){
        callback(token);
    }
}

// Calls the specified function for each line in the specified input
void foreachLineIn(const std::string& input, std::function<void(const std::string&)> callback)
{
    foreachElementsInStringDelimitedBy(input, '\n', callback);
}

// Structure representing the dimensions of wrapping paper
struct Dimensions
{
    int length{0};
    int width{0};
    int height{0};

    // Returns a vector with the three areas calculated from the dimensions
    std::vector<int> toAreas() const
    {
        return {length * width, width * height, height * length};
    }
};

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

int main(int argc, char** argv)
{
    assert(argc == 3);

    std::ifstream file(argv[1]);
    assert (file.is_open());

    const auto expectedResult = atoi (argv[2]);

    std::string fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    auto ribbonLength{0};
    foreachLineIn(fileContent, [&ribbonLength](const auto& line)
    {
        const auto dimension = makeDimensionFromLine(line);
        const auto max = std::max({dimension.length, dimension.width, dimension.height});
        ribbonLength += 2 * dimension.length + 2 * dimension.width + 2 * dimension.height - 2 * max + dimension.length * dimension.width * dimension.height;
    });

    if(expectedResult == ribbonLength)
    {
        return 0;
    }
    else
    {
        std::cout << "The result found is " << ribbonLength << " but the expected result is " << expectedResult << std::endl;
        return 1;
    }
}
