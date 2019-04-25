#ifndef LASER_EMULATOR_SRC_COMMAND_LINE_PARSER_H
#define LASER_EMULATOR_SRC_COMMAND_LINE_PARSER_H

#include <iostream>
#include <string>

namespace emu {
class CommandLineParser {
public:

  void Run(std::istream &in, std::ostream &out) {
    std::string line{};
    int counter{0};

    while (!in.eof()) {
      std::getline(in, line);
      out << line << "#" << CommandExecuted(line);
    }
  }

  std::string CommandExecuted(const std::string &command) {
    return command;
  }

};
}

#endif //LASER_EMULATOR_SRC_COMMAND_LINE_PARSER_H
