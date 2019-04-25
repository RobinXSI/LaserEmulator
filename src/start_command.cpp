#include "start_command.h"

namespace emu {
StartCommand::StartCommand(Laser *laser, const std::string &name) : Command(laser, name) {}
std::string StartCommand::Execute(const std::vector<std::string> &parameters) {
  try {
    laser_->Start();
    return SuccessMessage();
  } catch (const LaserException &exception) {
    return ErrorMessage();
  }
}
}