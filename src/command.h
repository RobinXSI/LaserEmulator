#ifndef LASER_EMULATOR_SRC_COMMAND_H
#define LASER_EMULATOR_SRC_COMMAND_H

#include <string>
#include <vector>

namespace emu {
class Command {
public:
  Command(const std::string &name) : name_(name) {}
  virtual std::string Execute(const std::vector<std::string> &parameters) = 0;

  const std::string name_;
};

class StartCommand : public Command {
public:
  StartCommand(const std::string &name) : Command(name) {}
  std::string Execute(const std::vector<std::string> &parameters) override {
    return name_ + "#\n";
  }

};

class SetPowerCommand : public Command {
public:
  SetPowerCommand(const std::string &name) : Command(name) {}
  std::string Execute(const std::vector<std::string> &parameters) override {
    return name_ + "#\n";
  }

};
}



#endif //LASER_EMULATOR_SRC_COMMAND_H
