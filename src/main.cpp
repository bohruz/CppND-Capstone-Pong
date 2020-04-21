#include <iostream>

#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{800};
  constexpr std::size_t kScreenHeight{600};

  Renderer renderer(
      kScreenWidth,
      kScreenHeight);  // created on the stack : destructor called automatically
  Controller controller;
  Game game(kScreenWidth, kScreenHeight);
  game.run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";

  return 0;

  return 0;
}