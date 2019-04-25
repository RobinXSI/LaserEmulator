#ifndef LASER_EMULATOR_SRC_COMMAND_H
#define LASER_EMULATOR_SRC_COMMAND_H

#include <string>
#include <vector>
#include "laser.h"
#include "laser_exception.h"

namespace emu {
class Command {
public:
  Command(Laser *laser, const std::string &name) : laser_(laser), name_(name) {}
  virtual std::string Execute(const std::vector<std::string> &parameters) = 0;

  const std::string name_;
  Laser * const laser_;

protected:
  std::string SuccessMessage() const {
    return  name_ + "#\n";
  }

  std::string ErrorMessage() const {
    return  name_ + "!\n";
  }
};

class StartCommand : public Command {
public:
  StartCommand(Laser *laser, const std::string &name) : Command(laser, name) {}
  std::string Execute(const std::vector<std::string> &parameters) override {
    try {
      laser_->Start();
      return SuccessMessage();
    } catch (const LaserException &exception) {
      return ErrorMessage();
    }
  }
};

class StopCommand : public Command {
public:
  StopCommand(Laser *laser, const std::string &name) : Command(laser, name) {}
  std::string Execute(const std::vector<std::string> &parameters) override {
    try {
      laser_->Stop();
      return SuccessMessage();
    } catch (const LaserException &exception) {
      return ErrorMessage();
    }
  }

};

class SetPowerCommand : public Command {
public:
  SetPowerCommand(Laser *laser, const std::string &name) : Command(laser, name) {}
  std::string Execute(const std::vector<std::string> &parameters) override {
    if (parameters.size() != 1) {
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
};

class QueryPowerCommand : public Command {
public:
  QueryPowerCommand(Laser *laser, const std::string &name) : Command(laser, name) {}
  std::string Execute(const std::vector<std::string> &parameters) override {
    return SuccessMessage();
  }

};
}



#endif //LASER_EMULATOR_SRC_COMMAND_H
