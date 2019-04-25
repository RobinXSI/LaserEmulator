#include "set_power_command.h"

namespace emu {
SetPowerCommand::SetPowerCommand(Laser *laser, const std::string &name) : Command(laser, name) {}

std::string SetPowerCommand::Execute(const std::vector<std::string> &parameters) {
  if (parameters.size()!=1) {
    return ErrorMessage();
  }

  try {
    const auto power = std::stoi(parameters.front());
    laser_->SetPower(power);
    return SuccessMessage();
  } catch (const LaserException &exception) {
    return ErrorMessage();
  } catch (const std::exception &exception) {
    return ErrorMessage();
  }
}
}