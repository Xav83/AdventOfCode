#include "types.hpp"

City::City (const std::string_view name_) : name(name_) {}

City::~City () = default;

bool City::operator==(const City& other) const { return other.name == name; }

bool City::operator<(const City& other) const { return name < other.name; }

// ===================

Route::Route (City& firstTown_, Distance distance_, City& secondTown_) :
    firstTown(firstTown_), secondTown(secondTown_), distance(distance_)
    {}

Route::~Route () = default;

Distance Route::getDistance () const { return distance; }

bool Route::isRouteBetween(const City& firstCity, const City& secondCity) const
{
    return (firstCity == firstTown && secondCity == secondTown) || (secondCity == firstTown && firstCity == secondTown);
}
