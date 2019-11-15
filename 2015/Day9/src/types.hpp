#pragma once

#include <string_view>

using Distance = size_t;

class City {
public:
  explicit City(const std::string_view name_);
  ~City();

  bool operator==(const City &other) const;
  bool operator<(const City &other) const;

private:
  std::string name;
};

// ===================

class Route {
public:
  Route(City &firstTown_, Distance distance_, City &secondTown_);
  ~Route();

  Distance getDistance() const;
  bool isRouteBetween(const City &firstCity, const City &secondCity) const;

private:
  City &firstTown, &secondTown;
  Distance distance{0};
};
