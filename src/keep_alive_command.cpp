#include "keep_alive_command.h"

namespace emu {
KeepAliveCommand::KeepAliveCommand(Laser *laser, const std::string &name) : Command(laser, name) {}
std::string KeepAliveCommand::Execute(const std::vector<std::string> &parameters) {
  laser_->KeepAliveSignal();
  return SuccessMessage();
}
}