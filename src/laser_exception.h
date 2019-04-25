#ifndef LASER_EMULATOR_SRC_LASER_EXCEPTION_H
#define LASER_EMULATOR_SRC_LASER_EXCEPTION_H

#include <exception>
#include <string>

namespace emu {
class LaserException : public std::exception {
public:
  explicit LaserException(const std::string &message) noexcept : message_(message) {};

  const char *what() const noexcept override {
    return message_.c_str();
  }

private:
  const std::string message_;
};
}

#endif //LASER_EMULATOR_SRC_LASER_EXCEPTION_H
