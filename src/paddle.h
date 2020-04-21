#ifndef PADDLE_H
#define PADDLE_H
#include <vector>

class Ball;

class Paddle {
 public:
  Paddle(int, int, int, int, int, int);
  virtual void move(bool);

  int x, y, h, w;
  int score;

 protected:
  int top, bottom;
};

class AutoPaddle : public Paddle {
 public:
  AutoPaddle(int, int, int, int, int, int);
  void follow(const Ball& b);
};

class ManualPaddle : public Paddle {
 public:
  ManualPaddle(int, int, int, int, int, int);
};

#endif
