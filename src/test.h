#define CATCH_CONFIG_MAIN // This tells catch-mini to provide a main() - only do this in one cpp file
#include <catch.hpp>

#include "command_line_parser.h"


TEST_CASE("Emulator") {
  using namespace emu;

  CommandLineParser parser{};

  const auto result = parser.CommandExecuted("Test");

  REQUIRE(result == "Test");
}