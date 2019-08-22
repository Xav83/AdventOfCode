#include "string_manipulation.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <regex>

using Distance = size_t;

class City
{
public:
    explicit City (const std::string_view name_) : name(name_) {}
    ~City () = default;

    bool operator==(const City& other) const { return other.name == name; }
    bool operator<(const City& other) const { return name < other.name; }

private:
    std::string name;
};

std::pair<City, City> getCitiesFromInstruction (const std::string_view instruction)
{
    const auto citySeparatorPosition = instruction.find(" to ");
    const auto equalSeparatorPosition = instruction.substr(citySeparatorPosition+4).find(" = ");
    return std::make_pair(City(instruction.substr(0, citySeparatorPosition)), City(instruction.substr(citySeparatorPosition+4, equalSeparatorPosition)));
}

Distance getDistanceFromInstruction (const std::string& instruction)
{
    std::regex word_regex("[0-9]+");
    auto words_begin = std::sregex_iterator(std::begin(instruction), std::end(instruction), word_regex);
    auto words_end = std::sregex_iterator();

    auto value{0};

    for (std::sregex_iterator i = words_begin; i != words_end; ++i)
    {
        std::smatch match = *i;
        return static_cast<Distance>(atoi(match.str().c_str()));
    }
    assert (false);
    return 0;
}

class Route
{
public:
    Route (City& firstTown_, Distance distance_, City& secondTown_) :
    firstTown(firstTown_), secondTown(secondTown_), distance(distance_)
    {}
    ~Route () = default;

    Distance getDistance () const { return distance; }

    bool isRouteBetween(const City& firstCity, const City& secondCity) const
    {
        return (firstCity == firstTown && secondCity == secondTown) || (secondCity == firstTown && firstCity == secondTown);
    }

private:
    City& firstTown, &secondTown;
    Distance distance{0};
};

class Graph
{
public:
    Graph () = default;
    ~Graph () = default;

    using Node = City;

    void addCity(const City& city)
    {
        const auto isNewCity = std::end(graph) == std::find(std::begin(graph), std::end(graph), city);
        if(isNewCity)
        {
            graph.emplace_back(city);
            sortedGraph.emplace_back(city);
        }
    }

    void addNewRoute(const City& firstCity, Distance distance, const City& secondCity)
    {
        routes.emplace_back(getStoredCity(firstCity), distance, getStoredCity(secondCity));
    }

    Distance run()
    {
        std::vector<Node> citiesToVisit, citiesVisited;
        std::sort(std::begin(sortedGraph), std::end(sortedGraph));
        citiesToVisit = sortedGraph;
        return travel (citiesToVisit, 0, citiesVisited);
    }

private:
    Distance travel(const std::vector<Node>& citiesToVisit, Distance distanceTraveledUntilNow, const std::vector<Node>& citiesVisited)
    {
        auto getRouteDistance = [this, &citiesVisited]()
        {
            if(citiesVisited.size() < 2)
            {
                return Distance{0};
            }
            const auto route = std::find_if(std::begin(routes), std::end(routes), [&citiesVisited](const auto& route)
            {
                return route.isRouteBetween(citiesVisited.back(), citiesVisited[citiesVisited.size()-2]);
            });
            return route->getDistance();
        };

        if(citiesToVisit.empty())
        {
            return getRouteDistance();
        }
        auto min = std::numeric_limits<Distance>::max();
        for(const auto& city : citiesToVisit)
        {
            std::vector<Node> citiesVisitedWithNewCity, citiesVisitedWithNewCitySorted, lastCitiesToVisit;

            citiesVisitedWithNewCity = citiesVisited;
            citiesVisitedWithNewCity.emplace_back(city);

            citiesVisitedWithNewCitySorted = citiesVisitedWithNewCity;
            std::sort(std::begin(citiesVisitedWithNewCitySorted), std::end(citiesVisitedWithNewCitySorted));

            std::set_difference(std::begin(sortedGraph), std::end(sortedGraph), std::begin(citiesVisitedWithNewCitySorted), std::end(citiesVisitedWithNewCitySorted), std::back_inserter(lastCitiesToVisit));

            const auto distanceTraveled = travel (lastCitiesToVisit, distanceTraveledUntilNow, citiesVisitedWithNewCity);
            min = std::min(min, distanceTraveled);
        }

        return distanceTraveledUntilNow + min + getRouteDistance();
    }

    City& getStoredCity(const City& city)
    {
        auto storedCity = std::find(std::begin(graph), std::end(graph), city);
        assert (storedCity != std::end(graph));
        return *storedCity;
    }

    std::vector<Node> graph, sortedGraph;
    std::vector<Route> routes;    
};

int main (int argc, char** argv)
{
    assert(argc == 3);

    std::ifstream file(argv[1]);
    assert (file.is_open());

    const auto expectedResult = atoi (argv[2]);

    std::string fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    Graph graph;

    foreachLineIn(fileContent, [&graph](const std::string& line)
    {
        const auto cities = getCitiesFromInstruction (line);
        graph.addCity(cities.first);
        graph.addCity(cities.second);
    });

    foreachLineIn(fileContent, [&graph](const std::string& line)
    {
        const auto cities = getCitiesFromInstruction (line);
        const auto distance =  getDistanceFromInstruction (line);
        graph.addNewRoute(cities.first, distance, cities.second);
    });

    auto traveledDistance = graph.run();

    if(expectedResult == traveledDistance)
    {
        return 0;
    }
    else
    {
        std::cout << "The result found is " << traveledDistance << " but the expected result is " << expectedResult << std::endl;
        return 1;
    }
}
