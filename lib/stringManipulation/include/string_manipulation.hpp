#pragma once

#include <functional>

// Calls the specified function for each substring delimited by the specified
// delimiter in the specified input
void foreachElementsInStringDelimitedBy(
    const std::string &input, const char delimiter,
    std::function<void(const std::string &)> callback);

// Calls the specified function for each line in the specified input
void foreachLineIn(const std::string &input,
                   std::function<void(const std::string &)> callback);
