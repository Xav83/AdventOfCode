#pragma once

struct Coordinate
{
    int x{0};
    int y{0};

    bool operator== (const Coordinate& other) const;
    bool operator< (const Coordinate& other) const;
};
