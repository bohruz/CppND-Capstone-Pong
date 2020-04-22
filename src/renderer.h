#ifndef RENDERER_H
#define RENDERER_H
#include <cstdio>

#include "SDL.h"
#include "ball.h"
#include "paddle.h"

class Renderer {
 public:
  // constructor
  Renderer(const std::size_t screenWidth, const std::size_t screenHeight);

  ~Renderer();  // destructor

  void render(const Paddle &p1, const Paddle &p2, const Ball &b);

  void updateWindowTitle(const int fps, const Paddle p1, const Paddle p2);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  // screen size
  const std::size_t screenWidth_;
  const std::size_t screenHeight_;
};
#endif