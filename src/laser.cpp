#include "laser.h"

#include "laser_exception.h"

namespace emu {

void Laser::Start() {
  if (IsEmitting()) {
    throw LaserException("Laser is already emitting");
  }
  is_emitting_ = true;
  power_ = 1;

  KeepAliveSignal();
}
void Laser::Stop() {
  if (!IsEmitting()) {
    throw LaserException("Laser is already stopped");
  }
  is_emitting_ = false;
}

bool Laser::IsEmitting() const {
  const auto time_now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());

  if (time_now - last_keep_alive_signal_ > keep_alive_time_) {
    return false;
  }

  return is_emitting_;
}
int Laser::Power() const {
  if (!IsEmitting()) {
    return 0;
  } else {
    return power_;
  }
}
void Laser::SetPower(int power) {
  if (power < 1 || power > 100) {
    throw LaserException("Invalid power range");
  }

  if (!IsEmitting()) {
    throw LaserException("Laser is not emitting");
  }

  power_ = power;

}
void Laser::KeepAliveSignal() {
  last_keep_alive_signal_ = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
}

}