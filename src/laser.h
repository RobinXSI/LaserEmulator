#ifndef LASER_EMULATOR_SRC_LASER_H
#define LASER_EMULATOR_SRC_LASER_H

#include <chrono>

namespace emu {
/**
 * Emulates a laser
 */
class Laser {
public:
  Laser(std::chrono::milliseconds keep_alive_time = std::chrono::milliseconds(5000));;

  void Start();

  void Stop();

  bool IsEmitting() const;

  int Power() const;

  void SetPower(int power);

  // Updates the keep alive signal to time now
  void KeepAliveSignal();

private:
  bool is_emitting_ = false;
  int power_ = 1;
  const std::chrono::milliseconds keep_alive_time_; // time to be alive in ms

  std::chrono::milliseconds last_keep_alive_signal_;

};
}

#endif //LASER_EMULATOR_SRC_LASER_H
