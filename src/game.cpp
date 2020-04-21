#include "game.h"

#include <iostream>
#include <iterator>
#include <map>
#include <thread>

Game::Game(std::size_t kScreenWidth, std::size_t kScreenHeight)
    : p1(45, (kScreenHeight - 50) / 2 - 90, 20, 180, 25, kScreenHeight - 25),
      p2(kScreenWidth - 65, (kScreenHeight - 50) / 2 - 90, 20, 180, 25,
         kScreenHeight - 25),
      b((kScreenWidth - 50) / 2 - 15, (kScreenHeight - 50) / 2 - 15, 30, 30, 25,
        kScreenWidth - 25, 25, kScreenHeight - 25){

      };

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
      std::cout << "Left Score : " << this->p1.score
                << " - Right Score : " << this->p2.score << std::endl;
    }
    std::cout << "Game loop has ended !" << std::endl;
    std::cout << "Final Left Score : " << this->p1.score
              << " - Final Right Score : " << this->p2.score << std::endl;
    std::cout << std::endl;
  });

  while (running) {
    frame_start = SDL_GetTicks();

    p2.follow(b);
    controller.handleInput(running, p1);
    b.move(p1, p2);

    renderer.render(p1, p2, b);
    frame_end = SDL_GetTicks();

    // keep track of how long each loop through the input/update/render cycle
    // takes
    frame_count++;
    frame_duration = frame_end - frame_start;

    // Update the window title and keep scores after every second
    if (frame_end - title_timestamp >= 1000) {
      renderer.updateWindowTitle(frame_count, p1, p2);
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
