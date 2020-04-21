#include "ball.h"

Ball::Ball(int x, int y, int w, int h, int left, int right, int top, int bottom)
    : xstart(x),
      ystart(y),
      w(w),
      h(h),
      left(left),
      right(right),
      top(top),
      bottom(bottom),
      engine(dev()),
      random_xvel(-6, 6),
      random_yvel(-3, 3) {
  reset();
}

void Ball::move(Paddle &leftPaddle, Paddle &rightPaddle) {
  x += xvel;
  y += yvel;

  if (y < top + 1 || y > bottom - 1 - h) yvel = -yvel;

  if (x < left + 1) {
    rightPaddle.score += 1;
    reset();
  }
  if (x > right - 1 - w) {
    leftPaddle.score += 1;
    reset();
  }

  if (checkCollision(leftPaddle) || checkCollision(rightPaddle)) xvel = -xvel;
}

void Ball::reset() {
  x = xstart;
  y = ystart;
  xvel = 0;
  while (xvel == 0) xvel = random_xvel(engine);
  yvel = 0;
  while (yvel == 0) yvel = random_yvel(engine);
}

bool Ball::checkCollision(Paddle &paddle) const {
  // if any of the sides of paddle are outside of ball
  if ((y + h) < paddle.y) return false;
  if (y > paddle.y + paddle.h) return false;
  if ((x + w) < paddle.x) return false;
  if (x > paddle.x + paddle.w) return false;

  return true;
}