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
  Laser *const laser_;

protected:
  std::string SuccessMessage() const {
    return name_ + "#\n";
  }

  std::string ErrorMessage() const {
    return name_ + "!\n";
  }

  std::string SuccessParameterMessage(const std::vector<std::string> &output_parameter) {
    std::string output = name_;

    for (const auto &parameter : output_parameter) {
      output += "|" + parameter;
    }

    return output + "#\n";
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
};

class QueryPowerCommand : public Command {
public:
  QueryPowerCommand(Laser *laser, const std::string &name) : Command(laser, name) {}
  std::string Execute(const std::vector<std::string> &parameters) override {
    const auto power = laser_->Power();

    return SuccessParameterMessage({std::to_string(power)});
  }

};

class StartSillyModeCommand : public Command {
public:
  explicit StartSillyModeCommand(bool *silly_mode_activated, Laser *laser, const std::string &name)
      : Command(laser, name), silly_mode_activated_(silly_mode_activated) {}

  std::string Execute(const std::vector<std::string> &parameters) override {
    *silly_mode_activated_ = true;
    return SuccessMessage();
  }
private:
  bool *silly_mode_activated_;
};

class StopSillyModeCommand : public Command {
public:
  explicit StopSillyModeCommand(bool *silly_mode_activated, Laser *laser, const std::string &name)
      : Command(laser, name), silly_mode_activated_(silly_mode_activated) {}

  std::string Execute(const std::vector<std::string> &parameters) override {
    *silly_mode_activated_ = false;
    return "DSM#\n";
  }


private:
  bool *silly_mode_activated_;
};

class KeepAliveCommand : public Command {
public:
  explicit KeepAliveCommand(Laser *laser, const std::string &name) : Command(laser, name) {}

  std::string Execute(const std::vector<std::string> &parameters) override {
    laser_->KeepAliveSignal();
    return SuccessMessage();
  }
};

class QueryStatusCommand : public Command {
public:
  explicit QueryStatusCommand(Laser *laser, const std::string &name) : Command(laser, name) {}

  std::string Execute(const std::vector<std::string> &parameters) override {
    const auto is_emitting = laser_->IsEmitting();
    return SuccessParameterMessage({std::to_string(is_emitting)});
  }
};

}

#endif //LASER_EMULATOR_SRC_COMMAND_H
