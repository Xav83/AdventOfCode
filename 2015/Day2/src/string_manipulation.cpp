#include "string_manipulation.hpp"
#include <sstream>

void foreachElementsInStringDelimitedBy(const std::string& input, const char delimiter, std::function<void(const std::string&)> callback)
{
    std::stringstream ss(input);
    std::string token;

    while(std::getline(ss,token, delimiter)){
        callback(token);
    }
}

void foreachLineIn(const std::string& input, std::function<void(const std::string&)> callback)
{
    foreachElementsInStringDelimitedBy(input, '\n', callback);
}
