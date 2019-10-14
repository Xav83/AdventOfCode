#include "string_manipulation.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>

using Speed = size_t;
using Position = size_t;
using Time = size_t;

class Reindeer
{
public:
    Reindeer (const std::string& name_, const Speed flyingSpeed_, const Time flyingTime_, const Time restTime_) : name(name_), flyingSpeed(flyingSpeed_), flyingTime(flyingTime_), restTime(restTime_), timeBeforeChangingState(flyingTime_) { }
    ~Reindeer () = default;

    void oneSecondPassed ()
    {
        if(timeBeforeChangingState == 0)
        {
            isFlying = !isFlying;
            timeBeforeChangingState = isFlying ? flyingTime : restTime;
        }

        if(isFlying)
        {
            position += flyingSpeed;
        }
        --timeBeforeChangingState;
    }

    Position getCurrentPosition () const { return position; }

private:
    std::string name;
    Speed flyingSpeed{0};
    Time flyingTime{0};
    Time restTime{0};

    Position position{0};
    Time currentTimePassed{0};
    Time timeBeforeChangingState{0};
    bool isFlying{true};
};

Reindeer extractInformationFrom (const std::string& line)
{
    std::istringstream stream(line);
    std::string reindeerName, can, fly, km_s, for_, seconds, but, then, must, rest, for__, seconds_;
    Speed flyingSpeed;
    Time flyingTime;
    Time restTime;
 
    stream >> reindeerName >> can >> fly >> flyingSpeed >> km_s >> for_ >> flyingTime >> seconds >> but >> then >> must >> rest >> for__ >> restTime >> seconds_;
    return Reindeer(reindeerName, flyingSpeed, flyingTime, restTime);
}

int main (int argc, char** argv)
{
    assert(argc == 3);

    std::ifstream file(argv[1]);
    assert (file.is_open());

    const auto expectedResult = atoi (argv[2]);

    std::string fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    std::vector<Reindeer> reindeers;

    foreachLineIn(fileContent, [&reindeers](const std::string& line)
    {
        reindeers.emplace_back(extractInformationFrom (line));
    });

    for(auto i = 0; i < 2503; ++i)
    {
        for(auto& reindeer: reindeers)
        {
            reindeer.oneSecondPassed();
        }
    }

    const auto winningReindeer = std::max_element(std::begin(reindeers), std::end(reindeers), [](const auto& firstReindeer, const auto& secondReindeer){ return firstReindeer.getCurrentPosition () < secondReindeer.getCurrentPosition (); });
    const auto distanceOfWinningReindeer = winningReindeer->getCurrentPosition ();

    if(expectedResult == distanceOfWinningReindeer)
    {
        return 0;
    }
    else
    {
        std::cout << "The result found is " << distanceOfWinningReindeer << " but the expected result is " << expectedResult << std::endl;
        return 1;
    }
}
