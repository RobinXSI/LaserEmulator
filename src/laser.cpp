#include "laser.h"

#include "laser_exception.h"

namespace emu {

void Laser::Start() {
  if (IsEmitting()) {
    throw LaserException("Laser is already emitting");
  }
  is_emitting_ = true;
  power_ = 1;
}
void Laser::Stop() {
  if (!IsEmitting()) {
    throw LaserException("Laser is already stopped");
  }
  is_emitting_ = false;
}

bool Laser::IsEmitting() const {
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

}