#ifndef LASER_EMULATOR_SRC_COMMAND_H
#define LASER_EMULATOR_SRC_COMMAND_H

#include <string>
#include <vector>
#include "laser.h"
#include "laser_exception.h"

namespace emu {
/**
 * Abstract base class for a command
 */
class Command {
public:
  Command(Laser *laser, const std::string &name);
  virtual std::string Execute(const std::vector<std::string> &parameters) = 0;

  const std::string name_;
  Laser *const laser_;

protected:
  std::string SuccessMessage() const;

  std::string ErrorMessage() const;

  std::string SuccessParameterMessage(const std::vector<std::string> &output_parameter);
};

















}

#endif //LASER_EMULATOR_SRC_COMMAND_H
