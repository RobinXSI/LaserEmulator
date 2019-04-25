# Laser Emulator
A command line interface to an emulated laser implemented using C++17.

## Project description
The C++ library `laser_emulator` serves as base for the application by parsing commands and executing them on the laser.
The library can be accessed using the command line interface `laser_emulator_exe` or by executing the tests in `laser_emulator_test`.

## Building
The project can be built using CMake version 3.13.
From source directory execute following commands in the command line.

```
mkdir build
cd build

cmake ..
make laser_emulator_exe
make laser_emulator_test
```

The build was tested under Ubuntu 18.04 with GCC 8.2 and on Windows 10 with Visual Studio 2019.

## Usage instructions
Using the command line interace execute following commands in the interactive shell of `laser_emulator_exe`:
```
STR
PW=|50
PW?
STP
PW=|20
```
Which executes following commands:
* Start Laser
* Set Power
* Query Power
* Stop Laser
* Set Power

## Testing
To run the tests execute the binary `laser_emulator_test` after building it.

## Code Style
This project was implemented according to the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).


## Acknowledgments
This project uses the minimalistic testing library [catch-mini](https://github.com/GValiente/catch-mini) to run the tests.
