#include "paddle.h"

#include <cstdlib>
#include <ctime>

#include "ball.h"

// constructor
Paddle::Paddle(Vec2D position, Geometry geometry)
    : position_(position), geometry_(geometry){};

// methods
void Paddle::move(bool upwards) {
  if (upwards) {
    position_.y -= 5;
    if (y_position() <= top() + 1) position_.y = top() + 1;
  } else {  // downwards
    position_.y += 5;
    if (y_position() >= bottom() - 1 - height())
      position_.y = bottom() - 1 - height();
  }
}

// getteres an setteres
float Paddle::x_position() const { return position_.x; }
float Paddle::y_position() const { return position_.y; }
int Paddle::width() const { return geometry_.width; }
int Paddle::height() const { return geometry_.height; }
int Paddle::left() const { return geometry_.lef; }
int Paddle::right() const { return geometry_.right; }
int Paddle::top() const { return geometry_.top; }
int Paddle::bottom() const { return geometry_.bottom; }
int Paddle::score() const { return score_; }
void Paddle::scored() { ++score_; }

AutoPaddle::AutoPaddle(Vec2D position, Geometry geometry)
    : Paddle(position, geometry){};

void AutoPaddle::follow(const Ball& ball) {
  float ytarget = ball.y_position() + 0.5 * ball.height();
  if (y_position() + 0.5 * height() > ytarget) move(true);
  if (y_position() + 0.5 * height() < ytarget) move(false);
}
