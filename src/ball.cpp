#include "ball.h"

Ball::Ball(int x, int y, int w, int h, int left, int right, int bottom, int top)
    : xStart_(x),
      yStart_(y),
      w_(w),
      h_(h),
      left_(left),
      right_(right),
      bottom_(bottom),
      engine_(device_()),
      ramdomXVel_(-6, 6),
      ramdomYVel_(-3, -3) {
  reset();
}

void Ball::move(Paddle& leftPaddle, Paddle& rightPaddle) {
  x_ += xVel_;
  y_ += yVel_;

  if (y_ < top_ + 1 || y_ > bottom_ - 1 - h_) yVel_ = -yVel_;

  if (x_ < left_ + 1) {
    rightPaddle.score_ += 1;
    reset();
  }

  if (x_ > right_ - 1 - w_) {
    leftPaddle.score_ += 1;
    reset();
  }
  if (checkCollision(leftPaddle) || checkCollision(rightPaddle)) xVel_ = -xVel_;
}

void Ball::reset() {
  x_ = xStart_;
  y_ = yStart_;
  xVel_ = 0;
  while (xVel_ == 0) xVel_ = ramdomXVel_(engine_);
  yVel_ = 0;
  while (yVel_ == 0) yVel_ = ramdomYVel_(engine_);
}

bool Ball::checkCollision(Paddle& paddle) const {
  if ((y_ + h_) < paddle.y_) return false;
  if (y_ > paddle.y_ + paddle.h_) return false;
  if ((x_ + w_) < paddle.x_) return false;
  if (x_ > paddle.x_ + paddle.w_) return false;

  return true;
}