#include "game.h"

#include <iostream>
#include <iterator>
#include <map>
#include <thread>

#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : paddleUser_(45, (grid_height - 50) / 2 - 90, 20, 180, 25,
                  grid_height - 25),
      paddleMachine_(grid_width - 65, (grid_height - 50) / 2 - 90, 20, 180, 25,
                     grid_height - 25),
      ball_((grid_width - 50) / 2 - 15, (grid_height - 50) / 2 - 15, 30, 30, 25,
            grid_width - 25, 25, grid_height - 25) {}

void Game::run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start = 0;
  Uint32 frame_end = 0;
  Uint32 frame_duration = 0;
  int frame_count = 0;
  bool running = true;

  std::thread observer([&running, this]() {
    while (running) {
      std::this_thread::sleep_for(std::chrono::milliseconds(2000));
      std::cout << "Left Score : " << this->paddleUser_.score_
                << " - Right Score : " << this->paddleMachine_.score_
                << std::endl;
    }
    std::cout << "Game loop has ended !" << std::endl;
    std::cout << "Final Left Score : " << this->paddleUser_.score_
              << " - Final Right Score : " << this->paddleMachine_.score_
              << std::endl;
    std::cout << std::endl;
  });

  while (running) {
    frame_start = SDL_GetTicks();

    paddleMachine_.follow(ball_);
    controller.handleInput(running, paddleUser_);
    ball_.move(paddleUser_, paddleMachine_);

    renderer.render(paddleUser_, paddleMachine_, ball_);
    frame_end = SDL_GetTicks();

    // keep track of how long each loop through the input/update/render cycle
    // takes
    frame_count++;
    frame_duration = frame_end - frame_start;

    // Update the window title and keep scores after every second
    if (frame_end - title_timestamp >= 1000) {
      renderer.updateWindowTitle(frame_count, paddleUser_, paddleMachine_);
      frame_count = 0;
      title_timestamp = frame_end;
    }
    // delay the loop to achieve the correct frame rate
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
  observer.join();
}
