#include "query_status_command.h"

namespace emu {
QueryStatusCommand::QueryStatusCommand(Laser *laser, const std::string &name) : Command(laser, name) {}

std::string QueryStatusCommand::Execute(const std::vector<std::string> &parameters) {
  const auto is_emitting = laser_->IsEmitting();
  return SuccessParameterMessage({std::to_string(is_emitting)});
}
}