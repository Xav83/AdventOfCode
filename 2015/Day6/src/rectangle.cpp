#include "rectangle.hpp"

void foreachCoordinateInRectangle(Rectangle rect, std::function<void(const Coordinate)> callback)
{
        for(auto x = rect.topLeft.x; x <= rect.bottomRight.x; ++x)
        {
            for(auto y = rect.topLeft.y; y <= rect.bottomRight.y; ++y)
            {
                callback({x, y});
            }
        }
}
