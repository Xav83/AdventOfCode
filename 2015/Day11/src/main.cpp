#include <array>
#include <cassert>
#include <iostream>

class PasswordChar {
public:
  PasswordChar() = default;
  explicit PasswordChar(const char value_) : value(value_) {}
  ~PasswordChar() = default;

  operator char() const { return value; }

  void increment() { value = willWrapAroundToA() ? 'a' : value + 1; }

  bool willWrapAroundToA() const { return value == 'z'; }

private:
  char value{'a'};
};

class Password {
public:
  explicit Password(const std::string_view input) {
    assert(input.size() == value.size());
    std::generate(value.begin(), value.end(), [index = 0, &input]() mutable {
      return PasswordChar(input[index++]);
    });
  }
  ~Password() = default;

  bool operator==(const Password &other) const { return value == other.value; }

  void increment() {
    for (int index{static_cast<int>(value.size()) - 1}; index >= 0; --index) {
      const auto characterWillWrap = value[index].willWrapAroundToA();
      value[index].increment();
      if (!characterWillWrap) {
        break;
      }
    }
  }

  std::string toString() const {
    std::string result(8, '0');
    std::generate(result.begin(), result.end(),
                  [index = 0, this]() mutable { return value[index++]; });
    return result;
  }

  bool isSafe() const {
    return hasIncreasingStraight() && hasNoConfusingLetters() &&
           hasTwoNonOverlappingPairs();
  }

private:
  bool hasIncreasingStraight() const {
    for (auto index = size_t{0}; index < value.size() - 2; ++index) {
      if (value[index] == value[index + 1] - 1 &&
          value[index] == value[index + 2] - 2) {
        return true;
      }
    }
    return false;
  }

  bool hasNoConfusingLetters() const {
    return std::none_of(std::begin(value), std::end(value),
                        [](const auto &passwordChar) {
                          return passwordChar == 'i' || passwordChar == 'o' ||
                                 passwordChar == 'l';
                        });
  }

  bool hasTwoNonOverlappingPairs() const {
    bool hasAtLeastOnePair{false};
    for (auto index = size_t{0}; index < value.size() - 1; ++index) {
      if (value[index] == value[index + 1]) {
        if (hasAtLeastOnePair) {
          return true;
        }
        hasAtLeastOnePair = true;
        ++index;
      }
    }
    return false;
  }

  std::array<PasswordChar, 8> value;
};

int main(int argc, char **argv) {
  assert(argc == 3);

  const auto oldPassword = Password(argv[1]);
  const auto expectedResult = Password(argv[2]);

  Password newPassword(oldPassword);
  do {
    newPassword.increment();
  } while (!newPassword.isSafe());

  if (expectedResult == newPassword) {
    return 0;
  } else {
    std::cout << "The result found is " << newPassword.toString().c_str()
              << " but the expected result is "
              << expectedResult.toString().c_str() << std::endl;
    return 1;
  }
}
