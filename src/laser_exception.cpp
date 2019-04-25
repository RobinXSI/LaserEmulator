#include "laser_exception.h"

namespace emu {
LaserException::LaserException(const std::string &message) noexcept : message_(message) {}

const char *LaserException::what() const noexcept {
  return message_.c_str();
}
}