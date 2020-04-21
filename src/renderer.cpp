#include "renderer.h"

#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t kScreenWidth,
                   const std::size_t kScreenHeight)
    : kScreenWidth(kScreenWidth), kScreenHeight(kScreenHeight) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize." << std::endl;
    std::cerr << "SDL Error: " << SDL_GetError() << std::endl;
  }

  // Create window
  sdl_window = SDL_CreateWindow("Pong Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, kScreenWidth,
                                kScreenHeight, SDL_WINDOW_SHOWN);
  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << std::endl;
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created." << std::endl;
    std::cerr << "SDL Error: " << SDL_GetError() << std::endl;
  }
}

Renderer::~Renderer() {
  // std::cout << "Destructor ~Renderer called !!!" << std::endl;
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::render(const Paddle& p1, const Paddle& p2, const Ball& b) {
  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Set render draw color
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  // Draw the field
  SDL_Rect field = {25, 25, static_cast<int>(kScreenWidth) - 50,
                    static_cast<int>(kScreenHeight) - 50};
  SDL_RenderDrawRect(sdl_renderer, &field);

  // Render paddles and ball
  SDL_Rect p1Quad = {p1.x, p1.y, p1.w, p1.h};
  SDL_Rect p2Quad = {p2.x, p2.y, p2.w, p2.h};
  SDL_Rect bQuad = {b.x, b.y, b.w, b.h};
  SDL_RenderFillRect(sdl_renderer, &p1Quad);
  SDL_RenderFillRect(sdl_renderer, &p2Quad);
  SDL_RenderFillRect(sdl_renderer, &bQuad);

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::updateWindowTitle(const int fps, const Paddle p1,
                                 const Paddle p2) {
  std::string title{" FPS: " + std::to_string(fps) +
                    "  Left Score: " + std::to_string(p1.score) +
                    "  Right Score: " + std::to_string(p2.score)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
