#include "command.h"

namespace emu {
Command::Command(Laser *laser, const std::string &name) : laser_(laser), name_(name) {}
std::string Command::SuccessMessage() const {
  return name_ + "#\n";
}
std::string Command::ErrorMessage() const {
  return name_ + "!\n";
}
std::string Command::SuccessParameterMessage(const std::vector<std::string> &output_parameter) {
  std::string output = name_;

  for (const auto &parameter : output_parameter) {
    output += "|" + parameter;
  }

  return output + "#\n";
}


}