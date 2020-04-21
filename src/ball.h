#ifndef BALL_H
#define BALL_H
#include <random>

#include "paddle.h"

class Ball {
 public:
  Ball(int x, int y, int w, int h, int left, int right, int top, int bottom);
  void move(Paddle &leftPaddle, Paddle &rightPaddle);
  bool checkCollision(Paddle &paddle) const;
  int x, y, h, w;

 private:
  int xstart, ystart;
  int left, right, top, bottom;
  int xvel, yvel;
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_xvel;
  std::uniform_int_distribution<int> random_yvel;
  void reset();
};
#endif
