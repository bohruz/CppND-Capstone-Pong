#ifndef GAME_H
#define GAME_H
#include <vector>

#include "SDL.h"
#include "ball.h"
#include "controller.h"
#include "paddle.h"
#include "renderer.h"

class Game {
 public:
  Game(std::size_t screenWidth, std::size_t screenHeight);
  void run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);

 private:
  Paddle p1;
  AutoPaddle p2;
  Ball b;

  std::size_t screenWidth_;
  std::size_t screenHeight_;
};

#endif