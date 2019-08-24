#include "string_manipulation.hpp"
#include "types.hpp"
#include "input_parser.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
#include <algorithm>

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
        auto max = std::numeric_limits<Distance>::min();
        for(const auto& city : citiesToVisit)
        {
            std::vector<Node> citiesVisitedWithNewCity, citiesVisitedWithNewCitySorted, lastCitiesToVisit;

            citiesVisitedWithNewCity = citiesVisited;
            citiesVisitedWithNewCity.emplace_back(city);

            citiesVisitedWithNewCitySorted = citiesVisitedWithNewCity;
            std::sort(std::begin(citiesVisitedWithNewCitySorted), std::end(citiesVisitedWithNewCitySorted));

            std::set_difference(std::begin(sortedGraph), std::end(sortedGraph), std::begin(citiesVisitedWithNewCitySorted), std::end(citiesVisitedWithNewCitySorted), std::back_inserter(lastCitiesToVisit));

            const auto distanceTraveled = travel (lastCitiesToVisit, distanceTraveledUntilNow, citiesVisitedWithNewCity);
            max = std::max(max, distanceTraveled);
        }

        return distanceTraveledUntilNow + max + getRouteDistance();
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
