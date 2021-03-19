#pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <box2d/box2d.h>

const float M2P = 20;
const float P2M = 1 / M2P;

class Game {

public:
  void init(const char *title, int xpos, int ypos, int width, int height);
  void handleEvents();
  void loop(Game *game);
  void clean();
  void render();
  void update();
  bool isRunning() { return running; }

  static SDL_Renderer *renderer;
  static b2World *world;

private:
  SDL_Window *window;
  bool running;
};

#endif