#ifndef GEOMETRY_H
#define GEOMETRY_H

struct Geometry {};

class Vec2D {
 public:
  Vec2D();
  Vec2D(float x, float y);
  ~Vec2D();
  Vec2D operator+(Vec2D const& rhs);
  Vec2D& operator+=(Vec2D const& rhs);
  Vec2D operator*(float rhs);

  float x, y;
};

#endif  // GEOMETRY_H