#include "Reindeer.hpp"
#include <sstream>

Reindeer::Reindeer (const std::string& name_, const Speed flyingSpeed_, const Time flyingTime_, const Time restTime_) : name(name_), flyingSpeed(flyingSpeed_), flyingTime(flyingTime_), restTime(restTime_), timeBeforeChangingState(flyingTime_) { }
Reindeer::~Reindeer () = default;

void Reindeer::oneSecondPassed ()
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

void Reindeer::winBonusPoint () { ++bonusPoints; }

Reindeer::Position Reindeer::getCurrentPosition () const { return position; }

Reindeer::BonusPoint Reindeer::getCurrentBonusPoint () const { return bonusPoints; }

Reindeer extractInformationFrom (const std::string& line)
{
    std::istringstream stream(line);
    std::string reindeerName, can, fly, km_s, for_, seconds, but, then, must, rest, for__, seconds_;
    Reindeer::Speed flyingSpeed;
    Reindeer::Time flyingTime;
    Reindeer::Time restTime;
 
    stream >> reindeerName >> can >> fly >> flyingSpeed >> km_s >> for_ >> flyingTime >> seconds >> but >> then >> must >> rest >> for__ >> restTime >> seconds_;
    return Reindeer(reindeerName, flyingSpeed, flyingTime, restTime);
}
