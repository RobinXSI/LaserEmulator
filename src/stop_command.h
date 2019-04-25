#ifndef LASER_EMULATOR_SRC_STOP_COMMAND_H
#define LASER_EMULATOR_SRC_STOP_COMMAND_H

#include "command.h"

namespace emu {
class StopCommand : public Command {
public:
  StopCommand(Laser *laser, const std::string &name);
  std::string Execute(const std::vector<std::string> &parameters) override;

};
}

#endif //LASER_EMULATOR_SRC_STOP_COMMAND_H
