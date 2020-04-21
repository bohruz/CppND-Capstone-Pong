#include "renderer.h"

#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height)
    : screen_width_(screen_width), screen_height_(screen_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Pong Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(const Paddle& paddleUser, const Paddle& paddleMachine,
                      const Ball& ball) {
  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Set render draw color
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  // Draw the field
  SDL_Rect field = {25, 25, static_cast<int>(screen_width_) - 50,
                    static_cast<int>(screen_height_) - 50};
  SDL_RenderDrawRect(sdl_renderer, &field);

  // Render paddles and ball
  SDL_Rect paddleUserQuad = {paddleUser.x_, paddleUser.y_, paddleUser.w_,
                             paddleUser.h_};
  SDL_Rect paddleMachineQuad = {paddleMachine.x_, paddleMachine2.y_,
                                ppaddleMachine2.w_, paddleMachine.h_};
  SDL_Rect ballQuad = {ball.x_, ball.y_, ball.w_, ball.h_};

  SDL_RenderFillRect(sdl_renderer, &paddleUserQuad);
  SDL_RenderFillRect(sdl_renderer, &paddleMachineQuad);
  SDL_RenderFillRect(sdl_renderer, &ballQuad);

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::updateWindowTitle(const int fps, const Paddle paddleUser,
                                 const Paddle paddleMachine) {
  std::string title{" FPS: " + std::to_string(fps) +
                    "  Left Score: " + std::to_string(paddleUser.score_) +
                    "  Right Score: " + std::to_string(paddleMachine.score_)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
