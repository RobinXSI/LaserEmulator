#include <iostream>
#include <signal.h>

#include "command_line_parser.h"
#include <iomanip>
#include <sstream>

void HandleExitEvent(int s) {
  exit(0);

}

int main() {
  using namespace emu;

  // Register exit signals for Ctrl + C and SIGTERM
  signal(SIGTERM, HandleExitEvent);
  signal(SIGINT, HandleExitEvent);

  // Start emulator
  CommandLineParser().Run(std::cin, std::cout);

  return 0;
}