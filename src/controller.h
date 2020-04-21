#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "paddle.h"

class Controller {
 public:
  void handleInput(bool &running, Paddle &paddle) const;
};

#endif