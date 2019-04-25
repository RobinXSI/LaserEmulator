#define CATCH_CONFIG_MAIN // This tells catch-mini to provide a main() - only do this in one cpp file
#include <catch.hpp>

#include "command_line_parser.h"

TEST_CASE("Start Laser twice") {
  using namespace emu;
  auto laser = std::make_unique<Laser>();
  CommandLineParser parser(laser.get());
  std::string result;

  result = parser.CommandExecuted("STR");
  REQUIRE(result == "STR#\n");

  result = parser.CommandExecuted("STR");
  REQUIRE(result == "STR!\n");
}

TEST_CASE("Stop Laser not emitting") {
  using namespace emu;
  auto laser = std::make_unique<Laser>();
  CommandLineParser parser(laser.get());
  std::string result;

  result = parser.CommandExecuted("STP");
  REQUIRE(result == "STP!\n");

  result = parser.CommandExecuted("STR");
  REQUIRE(result == "STR#\n");

  result = parser.CommandExecuted("STP");
  REQUIRE(result == "STP#\n");

  result = parser.CommandExecuted("STP");
  REQUIRE(result == "STP!\n");
}


TEST_CASE("Emulator") {
  using namespace emu;
  auto laser = std::make_unique<Laser>();
  CommandLineParser parser(laser.get());
  std::string result;

  result = parser.CommandExecuted("STR");
  REQUIRE(result == "STR#\n");

  result = parser.CommandExecuted("PW=|50");
  REQUIRE(result == "PW=#\n");

//  result = parser.CommandExecuted("PW?");
//  REQUIRE(result == "PW?|50#\n");

}