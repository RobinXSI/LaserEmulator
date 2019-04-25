#include "query_power_command.h"

namespace emu {
QueryPowerCommand::QueryPowerCommand(Laser *laser, const std::string &name) : Command(laser, name) {}

std::string QueryPowerCommand::Execute(const std::vector<std::string> &parameters) {
  const auto power = laser_->Power();

  return SuccessParameterMessage({std::to_string(power)});
}
}