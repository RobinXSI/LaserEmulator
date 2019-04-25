#include "stop_command.h"

namespace emu {
StopCommand::StopCommand(Laser *laser, const std::string &name) : Command(laser, name) {}

std::string StopCommand::Execute(const std::vector<std::string> &parameters) {
  try {
    laser_->Stop();
    return SuccessMessage();
  } catch (const LaserException &exception) {
    return ErrorMessage();
  }
}
}