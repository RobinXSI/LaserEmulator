#ifndef LASER_EMULATOR_SRC_START_COMMAND_H
#define LASER_EMULATOR_SRC_START_COMMAND_H

#include "command.h"

namespace emu {
class StartCommand : public Command {
public:
  StartCommand(Laser *laser, const std::string &name);

  std::string Execute(const std::vector<std::string> &parameters) override;
};
}

#endif //LASER_EMULATOR_SRC_START_COMMAND_H
