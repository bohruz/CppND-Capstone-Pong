#ifndef PADDLE_H
#define PADDLE_H

#include <vector>

class Ball;

class Paddle {
 public:
  Paddle(int x, int y, int h, int w, int bottom, int top);
  virtual void move(bool);
  int score() const;

  int x_, y_, h_, w_;
  int score_;

 protected:
  int top_, bottom_;
};

class AutoPaddle : public Paddle {
 public:
  AutoPaddle(int, int, int, int, int, int);
  void followBall(const Ball& ball);
};

class ManualPaddle : public Paddle {
 public:
  ManualPaddle(int, int, int, int, int, int);
};

#endif