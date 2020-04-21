#ifndef BALL_H
#define BALL_H

#include <random>

#include "paddle.h"

class Ball {
 public:
  Ball(int x, int y, int w, int h, int left, int right, int bottom, int top);
  void move(Paddle& leftPaddle, Paddle& rightPaddle);
  bool checkCollision(Paddle& paddle) const;
  int x() const;
  int y() const;
  int h() const;
  int w() const;

 private:
  int x_, y_, h_, w_;
  int left_, right_, bottom_, top_;
  int xVel_, yVel_;

  std::random_device device_;
  std::mt19937 engine_;
  std::uniform_int_distribution<int> ramdomXVel_;
  std::uniform_int_distribution<int> ramdomYVel_;
};

#endif