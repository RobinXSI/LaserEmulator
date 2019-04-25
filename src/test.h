#define CATCH_CONFIG_MAIN // This tells catch-mini to provide a main() - only do this in one cpp file
#include <catch.hpp>
#include <thread>

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


TEST_CASE("Laser power settings") {
  using namespace emu;
  auto laser = std::make_unique<Laser>();
  CommandLineParser parser(laser.get());
  std::string result;

  result = parser.CommandExecuted("PW?");
  REQUIRE(result == "PW?|0#\n");

  result = parser.CommandExecuted("STR");
  REQUIRE(result == "STR#\n");

  result = parser.CommandExecuted("PW?");
  REQUIRE(result == "PW?|1#\n");

  result = parser.CommandExecuted("PW=|50");
  REQUIRE(result == "PW=#\n");

  result = parser.CommandExecuted("PW?");
  REQUIRE(result == "PW?|50#\n");

  result = parser.CommandExecuted("STP");
  REQUIRE(result == "STP#\n");

  result = parser.CommandExecuted("PW?");
  REQUIRE(result == "PW?|0#\n");

  result = parser.CommandExecuted("PW=|20");
  REQUIRE(result == "PW=!\n");
}

TEST_CASE("Unknown Command") {
  using namespace emu;
  auto laser = std::make_unique<Laser>();
  CommandLineParser parser(laser.get());
  std::string result;

  result = parser.CommandExecuted("HLO");
  REQUIRE(result == "UK!\n");
}

TEST_CASE("Silly Mode") {
  using namespace emu;
  auto laser = std::make_unique<Laser>();
  CommandLineParser parser(laser.get());
  std::string result;

  result = parser.CommandExecuted("STR");
  REQUIRE(result == "STR#\n");

  result = parser.CommandExecuted("ESM");
  REQUIRE(result == "ESM#\n");

  result = parser.CommandExecuted("05|=WP");
  REQUIRE(result == "PW=#\n");

  result = parser.CommandExecuted("DSM");
  REQUIRE(result == "DSM#\n");

  result = parser.CommandExecuted("05|=WP");
  REQUIRE(result == "UK!\n");

  result = parser.CommandExecuted("PW?");
  REQUIRE(result == "PW?|50#\n");
}

TEST_CASE("Keep Alive") {
  using namespace emu;
  auto laser = std::make_unique<Laser>(std::chrono::milliseconds(10));
  CommandLineParser parser(laser.get());
  std::string result;

  result = parser.CommandExecuted("STR");
  REQUIRE(result == "STR#\n");

  result = parser.CommandExecuted("ST?");
  REQUIRE(result == "ST?|1#\n");

  result = parser.CommandExecuted("KAL");
  REQUIRE(result == "KAL#\n");

  result = parser.CommandExecuted("ST?");
  REQUIRE(result == "ST?|1#\n");

  std::this_thread::sleep_for(std::chrono::milliseconds(11));

  result = parser.CommandExecuted("ST?");
  REQUIRE(result == "ST?|0#\n");

  result = parser.CommandExecuted("STR");
  REQUIRE(result == "STR#\n");

  result = parser.CommandExecuted("ST?");
  REQUIRE(result == "ST?|1#\n");

  std::this_thread::sleep_for(std::chrono::milliseconds(11));

  result = parser.CommandExecuted("ST?");
  REQUIRE(result == "ST?|0#\n");

  result = parser.CommandExecuted("STR");
  REQUIRE(result == "STR#\n");

  std::this_thread::sleep_for(std::chrono::milliseconds(9));

  result = parser.CommandExecuted("ST?");
  REQUIRE(result == "ST?|1#\n");

  std::this_thread::sleep_for(std::chrono::milliseconds(2));
  result = parser.CommandExecuted("ST?");
  REQUIRE(result == "ST?|0#\n");

}



