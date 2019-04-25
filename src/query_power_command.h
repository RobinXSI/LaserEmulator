#ifndef LASER_EMULATOR_SRC_QUERY_POWER_COMMAND_H
#define LASER_EMULATOR_SRC_QUERY_POWER_COMMAND_H

#include "command.h"

namespace emu {
class QueryPowerCommand : public Command {
public:
  QueryPowerCommand(Laser *laser, const std::string &name);

  std::string Execute(const std::vector<std::string> &parameters) override;

};
}

#endif //LASER_EMULATOR_SRC_QUERY_POWER_COMMAND_H
