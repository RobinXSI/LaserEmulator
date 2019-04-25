#ifndef LASER_EMULATOR_SRC_START_SILLY_MODE_COMMAND_H
#define LASER_EMULATOR_SRC_START_SILLY_MODE_COMMAND_H

#include "command.h"

namespace emu {
class StartSillyModeCommand : public Command {
public:
  StartSillyModeCommand(bool *silly_mode_activated, Laser *laser, const std::string &name);

  std::string Execute(const std::vector<std::string> &parameters) override;
private:
  bool *silly_mode_activated_;
};
}

#endif //LASER_EMULATOR_SRC_START_SILLY_MODE_COMMAND_H
