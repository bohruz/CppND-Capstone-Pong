#include "paddle.h"

#include "ball.h"

Paddle::Paddle(int x, int y, int w, int h, int bottom, int top)
    : x_(x), y_(y), w_(w), h_(h), bottom_(bottom), top_(top), score_(0) {}

void Paddle::move(bool upwards) {
  if (upwards) {
    y_ -= 5;
    if (y_ <= top_ + 1) y_ = top_ + 1;
  } else {
    y_ += 5;
    if (y_ >= bottom_ - 1 - h_) y_ = bottom_ - 1 - h_;
  }
}

ManualPaddle::ManualPaddle(int x, int y, int w, int h, int bottom, int top)
    : Paddle(x, y, w, h, bottom, top) {}

AutoPaddle::AutoPaddle(int x, int y, int w, int h, int bottom, int top)
    : Paddle(x, y, w, h, bottom, top) {}

void AutoPaddle::followBall(const Ball& ball) {
  float yTarget = ball.y_ + 0.5 * ball.h_;
  if (y_ + 0.5 * h_ > yTarget) move(true);
  if (y_ + 0.5 * h_ < yTarget) move(false);
}