#ifndef LASER_EMULATOR_SRC_KEEP_ALIVE_COMMAND_H
#define LASER_EMULATOR_SRC_KEEP_ALIVE_COMMAND_H

#include "command.h"

namespace emu {
class KeepAliveCommand : public Command {
public:
  KeepAliveCommand(Laser *laser, const std::string &name);

  std::string Execute(const std::vector<std::string> &parameters) override;
};
}

#endif //LASER_EMULATOR_SRC_KEEP_ALIVE_COMMAND_H
