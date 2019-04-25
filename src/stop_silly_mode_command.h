#ifndef LASER_EMULATOR_SRC_STOP_SILLY_MODE_COMMAND_H
#define LASER_EMULATOR_SRC_STOP_SILLY_MODE_COMMAND_H

#include "command.h"

namespace emu {
class StopSillyModeCommand : public Command {
public:
  StopSillyModeCommand(bool *silly_mode_activated, Laser *laser, const std::string &name);

  std::string Execute(const std::vector<std::string> &parameters) override;


private:
  bool *silly_mode_activated_;
};
}

#endif //LASER_EMULATOR_SRC_STOP_SILLY_MODE_COMMAND_H
