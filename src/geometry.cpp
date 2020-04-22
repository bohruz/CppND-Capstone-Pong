#include "geometry.h"

Vec2D::Vec2D() : x(0.0f), y(0.0f) {}
Vec2D::Vec2D(float x, float y) : x(x), y(y) {}
Vec2D Vec2D::operator+(Vec2D const& rhs) { return Vec2D(x + rhs.x, y + rhs.y); }
Vec2D& Vec2D::operator+=(Vec2D const& rhs) {
  x += rhs.x;
  y += rhs.y;

  return *this;
}
Vec2D Vec2D::operator*(float rhs) { return Vec2D(x * rhs, y * rhs); }

Vec2D::~Vec2D() {}