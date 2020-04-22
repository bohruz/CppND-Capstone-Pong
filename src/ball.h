#ifndef BALL_H
#define BALL_H
#include <random>

#include "geometry.h"
#include "paddle.h"

class Ball {
 public:
  // constructor
  Ball(Vec2D position, Geometry geometry);

  // methods
  void move(Paddle &leftPaddle, Paddle &rightPaddle);
  bool checkCollision(Paddle &paddle) const;

  // getteres
  int x_position() const;
  int y_position() const;
  int width() const;
  int height() const;
  int left() const;
  int right() const;
  int top() const;
  int bottom() const;

 private:
  // geometry
  Geometry const geometry_;

  // physics
  Vec2D position_;
  Vec2D const startPosition_;
  Vec2D velocity_;

  // random engine
  std::random_device device_;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_xvel_;
  std::uniform_int_distribution<int> random_yvel_;
  void reset();
};
#endif
