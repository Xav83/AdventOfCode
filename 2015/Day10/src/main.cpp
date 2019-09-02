#include <cassert>
#include <iostream>
#include <algorithm>
#include <string>
#include <string_view>

std::string lookAndSay(const std::string_view input)
{
    std::string result;
    size_t index = 0;
    while (index < input.size())
    {
        const auto firstDistinctElement = std::find_if(std::begin(input) + index, std::end(input),[&input, &index](const auto& character){
            return character != input[index];
        });
        const auto count = std::distance(std::begin(input) + index, firstDistinctElement);
        result += std::to_string(static_cast<size_t>(count)) + input[index];
        index += count;
    }
    return result;
}

int main (int argc, char** argv)
{
    assert(argc == 3);

    auto input = std::string(argv[1]);
    const auto expectedResult = atoi(argv[2]);

    for(auto i = 0; i < 40 ; ++i)
    {
        input = lookAndSay(input);
    }

    const auto result = input.size();

    if(expectedResult == result)
    {
        return 0;
    }
    else
    {
       std::cout << "The result found is " << result << " but the expected result is " << expectedResult << std::endl;
        return 1;
    }
}
