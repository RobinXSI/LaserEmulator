#define CATCH_CONFIG_MAIN // This tells catch-mini to provide a main() - only do this in one cpp file
#include <catch.hpp>

#include "command_line_parser.h"


TEST_CASE("Emulator") {
  using namespace emu;

  CommandLineParser parser{};

  std::string result;
  result = parser.CommandExecuted("STR");
  REQUIRE(result == "STR#\n");

  result = parser.CommandExecuted("PW=|50");
  REQUIRE(result == "PW=#\n");

}