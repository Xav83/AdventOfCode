#pragma once

#include "string_manipulation.hpp"

class Reindeer {
public:
  using Speed = size_t;
  using Position = size_t;
  using Time = size_t;
  using BonusPoint = size_t;

  Reindeer(const std::string &name_, const Speed flyingSpeed_,
           const Time flyingTime_, const Time restTime_);
  ~Reindeer();

  void oneSecondPassed();
  void winBonusPoint();

  Position getCurrentPosition() const;
  BonusPoint getCurrentBonusPoint() const;

private:
  std::string name;
  Speed flyingSpeed{0};
  Time flyingTime{0};
  Time restTime{0};

  Position position{0};
  BonusPoint bonusPoints{0};
  Time timeBeforeChangingState{0};
  bool isFlying{true};
};

Reindeer extractInformationFrom(const std::string &line);