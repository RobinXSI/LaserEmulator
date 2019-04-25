#ifndef LASER_EMULATOR_SRC_LASER_H
#define LASER_EMULATOR_SRC_LASER_H

namespace emu {
class Laser {
public:
  void Start();

  void Stop();

  bool IsEmitting() const;

  int Power() const;

  void SetPower(int power);


private:
  bool is_emitting_ = false;
  int power_ = 1;


};
}

#endif //LASER_EMULATOR_SRC_LASER_H
