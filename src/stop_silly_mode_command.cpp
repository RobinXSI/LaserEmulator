#include "stop_silly_mode_command.h"

namespace emu {
StopSillyModeCommand::StopSillyModeCommand(bool *silly_mode_activated, Laser *laser, const std::string &name)
    : Command(laser, name), silly_mode_activated_(silly_mode_activated) {}

std::string StopSillyModeCommand::Execute(const std::vector<std::string> &parameters) {
  *silly_mode_activated_ = false;
  return "DSM#\n";
}
}