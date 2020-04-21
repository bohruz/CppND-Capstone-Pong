#ifndef RENDERER_H
#define RENDERER_H

#include <cstdio>

#include "SDL.h"
#include "ball.h"
#include "paddle.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height);
  ~Renderer();

  void Render(const Paddle& paddleUser, const Paddle& paddleMachine,
              const Ball& ball);

  void UpdateWindowTitle(const int fps, const Paddle paddleUser,
                         const Paddle paddleMachine);

 private:
  SDL_Window* sdl_window;
  SDL_Renderer* sdl_renderer;

  const std::size_t screen_width_;
  const std::size_t screen_height_;
};

#endif