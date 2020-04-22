#ifndef PADDLE_H
#define PADDLE_H

#include "geometry.h"

class Ball;

class Paddle {
 public:
  // constructor
  Paddle(Vec2D position, Geometry geometry);

  // methods
  virtual void move(bool);

  // getteres an setteres
  float x_position() const;
  float y_position() const;
  float x_velocity() const;
  float y_velocity() const;
  int width() const;
  int height() const;
  int left() const;
  int right() const;
  int top() const;
  int bottom() const;
  int score() const;
  void scored();

 protected:
  // geometry
  Geometry const geometry_;

  // physics
  Vec2D position_;

  // score
  int score_{0};
};

class AutoPaddle : public Paddle {
 public:
  AutoPaddle(Vec2D position, Geometry geometry);
  void follow(const Ball& b);
};

#endif
