#ifndef GEOMETRY_H
#define GEOMETRY_H

struct Geometry {
  int width{0}, height{0};
  int bottom{0}, top{0};
  int lef{0}, right{0};
};

class Vec2D {
 public:
  Vec2D();
  Vec2D(int x, int y);
  ~Vec2D();
  Vec2D operator+(Vec2D const& rhs);
  Vec2D& operator+=(Vec2D const& rhs);
  Vec2D operator*(int rhs);

  int x{0}, y{0};
};

#endif  // GEOMETRY_H