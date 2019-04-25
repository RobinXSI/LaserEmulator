#include "start_silly_mode_command.h"

namespace emu {
StartSillyModeCommand::StartSillyModeCommand(bool *silly_mode_activated, Laser *laser, const std::string &name)
    : Command(laser, name), silly_mode_activated_(silly_mode_activated) {}

std::string StartSillyModeCommand::Execute(const std::vector<std::string> &parameters) {
  *silly_mode_activated_ = true;
  return SuccessMessage();
}
}