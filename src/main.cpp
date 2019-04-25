#include <iostream>
#include <signal.h>

#include "command_line_parser.h"
#include "laser.h"

void HandleExitEvent(int s) {
  exit(0);
}

int main() {
  using namespace emu;

  // Register exit signals for Ctrl + C and SIGTERM
  signal(SIGTERM, HandleExitEvent);
  signal(SIGINT, HandleExitEvent);

  auto laser = std::make_unique<Laser>();

  // Start emulator
  CommandLineParser(laser.get()).Run(std::cin, std::cout);

  return 0;
}