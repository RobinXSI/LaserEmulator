cmake_minimum_required(VERSION 3.13)
project(laser_emulator)

set(CMAKE_CXX_STANDARD 17)

add_library(laser_emulator src/laser.cpp
        src/command_line_parser.cpp
        src/laser_exception.cpp
        src/command.cpp
        src/keep_alive_command.cpp
        src/query_power_command.cpp
        src/query_status_command.cpp
        src/set_power_command.cpp
        src/start_silly_mode_command.cpp
        src/stop_command.cpp
        src/start_command.cpp
        src/stop_silly_mode_command.cpp
        )

add_executable(laser_emulator_exe src/main.cpp)
target_link_libraries(laser_emulator_exe laser_emulator)

add_executable(laser_emulator_test src/test.cpp)
target_link_libraries(laser_emulator_test laser_emulator)
target_include_directories(laser_emulator_test PUBLIC dependencies/catch-mini)