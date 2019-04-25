#include <sstream>
#include "command_line_parser.h"

#include "start_command.h"
#include "stop_command.h"
#include "set_power_command.h"
#include "query_power_command.h"
#include "start_silly_mode_command.h"
#include "stop_silly_mode_command.h"
#include "keep_alive_command.h"
#include "query_status_command.h"

namespace emu {

CommandLineParser::CommandLineParser(Laser *laser) : laser_(laser) {
  RegisterCommand(std::make_unique<StartCommand>(laser_, "STR"));
  RegisterCommand(std::make_unique<StopCommand>(laser_, "STP"));
  RegisterCommand(std::make_unique<SetPowerCommand>(laser_, "PW="));
  RegisterCommand(std::make_unique<QueryPowerCommand>(laser_, "PW?"));
  RegisterCommand(std::make_unique<StartSillyModeCommand>(&silly_mode_activated_, laser_, "ESM"));
  RegisterCommand(std::make_unique<StopSillyModeCommand>(&silly_mode_activated_, laser_, "MSD")); // Inversed
  RegisterCommand(std::make_unique<KeepAliveCommand>(laser_, "KAL"));
  RegisterCommand(std::make_unique<QueryStatusCommand>(laser_, "ST?"));

}

void CommandLineParser::Run(std::istream &in, std::ostream &out) {
  std::string line{};
  while (!in.eof()) {
    std::getline(in, line);
    out << CommandExecuted(line);
  }
}

std::string CommandLineParser::CommandExecuted(const std::string &input) {
  const auto command = ConvertInputToCommand(input);

  const auto exectuable = LookupCommand(command.command);
  if (exectuable==nullptr) {
    return "UK!\n";
  }

  return exectuable->Execute(command.parameters);
}
Command *
CommandLineParser::LookupCommand(const std::string &command) const {
  const auto it = registered_commands_.find(command);
  if (it==registered_commands_.end()) {
    return nullptr;
  }
  return it->second.get();
}

void CommandLineParser::RegisterCommand(std::unique_ptr<Command> implementation) {
  registered_commands_[implementation->name_] = std::move(implementation);
}

CommandLineParser::CommandAndParameters CommandLineParser::ConvertInputToCommand(std::string input) const {
  if (silly_mode_activated_) {
    input = std::string(input.rbegin(), input.rend());
  }

  std::stringstream input_stream(input);
  std::string item;
  std::vector<std::string> splitted_strings;
  while (std::getline(input_stream, item, '|')) {
    splitted_strings.emplace_back(item);
  }

  if (splitted_strings.size() <= 1) {
    return CommandLineParser::CommandAndParameters{
        input,
        std::vector<std::string>()
    };
  }

  return CommandLineParser::CommandAndParameters{
    splitted_strings.front(),
    std::vector<std::string>(splitted_strings.begin() + 1, splitted_strings.end())
  };
}

}