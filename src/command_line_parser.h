#ifndef LASER_EMULATOR_SRC_COMMAND_LINE_PARSER_H
#define LASER_EMULATOR_SRC_COMMAND_LINE_PARSER_H

#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>
#include <vector>

#include "command.h"

namespace emu {
class CommandLineParser {
public:
  CommandLineParser();
  void Run(std::istream &in, std::ostream &out);

  // Execute command
  std::string CommandExecuted(const std::string &input);

private:
  struct CommandAndParameters {
    std::string command;
    std::vector<std::string> parameters;
  };

  std::unordered_map<std::string, std::unique_ptr<Command>> registered_commands_;

  // Splits input at the character "|" to get command and parameters
  CommandAndParameters ConvertInputToCommand(const std::string &input) const;

  // Searches the required command in the registered commands
  Command *LookupCommand(const std::string &command) const;

  // Registers a command by linking the string command with its implementation
  void RegisterCommand(std::unique_ptr<Command> implementation);





};
}

#endif //LASER_EMULATOR_SRC_COMMAND_LINE_PARSER_H
