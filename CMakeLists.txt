cmake_minimum_required(VERSION 3.13)
project(laser_emulator)

set(CMAKE_CXX_STANDARD 17)

add_library(laser_emulator src/laser.cpp src/command_line_parser.cpp)

add_executable(laser_emulator_exe src/main.cpp)
target_link_libraries(laser_emulator_exe laser_emulator)

add_executable(laser_emulator_test src/test.cpp)
target_link_libraries(laser_emulator_test laser_emulator)
target_include_directories(laser_emulator_test PUBLIC dependencies/catch-mini)