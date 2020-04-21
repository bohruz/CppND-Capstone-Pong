#include "controller.h"

#include "SDL.h"
#include "paddle.h"

void Controller::handleInput(bool &running, Paddle &paddle) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else {
      const Uint8 *state = SDL_GetKeyboardState(NULL);
      if (state[SDL_SCANCODE_UP]) paddle.move(true);
      if (state[SDL_SCANCODE_DOWN]) paddle.move(false);
    }
  }
}