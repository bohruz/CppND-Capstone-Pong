#include "paddle.h"

#include <cstdlib>
#include <ctime>

#include "ball.h"

Paddle::Paddle(int x, int y, int w, int h, int top, int bottom)
    : x(x), y(y), w(w), h(h), top(top), bottom(bottom), score(0){};

void Paddle::move(bool upwards) {
  if (upwards) {
    y -= 5;
    if (y <= top + 1) y = top + 1;
  } else {  // downwards
    y += 5;
    if (y >= bottom - 1 - h) y = bottom - 1 - h;
  }
}

ManualPaddle::ManualPaddle(int x, int y, int w, int h, int top, int bottom)
    : Paddle(x, y, w, h, top, bottom){};

AutoPaddle::AutoPaddle(int x, int y, int w, int h, int top, int bottom)
    : Paddle(x, y, w, h, top, bottom){};

void AutoPaddle::follow(const Ball& ball) {
  float ytarget = ball.y + 0.5 * ball.h;
  if (y + 0.5 * h > ytarget) move(true);
  if (y + 0.5 * h < ytarget) move(false);
}
