#include "ball.h"

// constructor
Ball::Ball(Vec2D position, Geometry geometry)
    : position_(position),
      geometry_(geometry),
      engine(device_()),
      random_xvel_(-6, 6),
      random_yvel_(-3, 3) {
  reset();
}

// methods
void Ball::move(Paddle &leftPaddle, Paddle &rightPaddle) {
  position_.x += velocity_.x;
  position_.y += velocity_.y;

  if (y_position() < top() + 1 || y_position() > bottom() - 1 - height())
    velocity_.y = -velocity_.y;

  if (x_position() < left() + 1) {
    rightPaddle.scored();
    reset();
  }
  if (x_position() > right() - 1 - width()) {
    leftPaddle.scored();
    reset();
  }

  if (checkCollision(leftPaddle) || checkCollision(rightPaddle))
    velocity_.x = -velocity_.x;
}

// getteres an setteres
float Ball::x_position() const { return position_.x; }
float Ball::y_position() const { return position_.y; }
float Ball::x_velocity() const { return velocity_.x; }
float Ball::y_velocity() const { return velocity_.y; }
int Ball::width() const { return geometry_.width; }
int Ball::left() const { return geometry_.lef; }
int Ball::right() const { return geometry_.right; }
int Ball::height() const { return geometry_.height; }
int Ball::top() const { return geometry_.top; }
int Ball::bottom() const { return geometry_.bottom; }

void Ball::reset() {
  while (velocity_.x == 0) velocity_.x = random_xvel_(engine);
  while (velocity_.y == 0) velocity_.y = random_yvel_(engine);
}

bool Ball::checkCollision(Paddle &paddle) const {
  // if any of the sides of paddle are outside of ball
  if ((y_position() + height()) < paddle.y_position()) return false;
  if (y_position() > paddle.y_position() + paddle.height()) return false;
  if ((x_position() + width()) < paddle.x_position()) return false;
  if (x_position() > paddle.x_position() + paddle.width()) return false;

  return true;
}