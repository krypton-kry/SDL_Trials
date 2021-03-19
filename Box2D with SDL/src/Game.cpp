#include "Game.hpp"
#include "Box.hpp"
#include <iostream>

SDL_Renderer *Game::renderer;
b2World *Game::world = new b2World(b2Vec2(0, 10.0f));
Box *box = new Box();

void Game::init(const char *title, int xpos, int ypos, int width, int height) {

  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

    window = SDL_CreateWindow(title, xpos, ypos, width, height, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer) {
      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    }
    box->createBox(0, 400, 640, 30, false);
    running = true;
  }
}

void Game::loop(Game *game) {
  game->init("Game Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480);

  const int FPS = 60;
  const int frameDelay = 1000 / FPS;

  Uint32 frameStart;
  int frameTime;

  float timeStep = 1.0f / 60.0f;
  int32 velocityIterations = 6;
  int32 positionIterations = 2;

  while (game->isRunning()) {
    world->Step(timeStep, velocityIterations, positionIterations);

    frameStart = SDL_GetTicks();

    game->handleEvents();
    game->render();
    game->update();

    frameTime = SDL_GetTicks() - frameStart;

    if (frameDelay > frameTime) {
      SDL_Delay(frameDelay - frameTime);
    }
  }

  game->clean();
}

void Game::handleEvents() {
  SDL_Event event;
  SDL_PollEvent(&event);

  switch (event.type) {
  case SDL_QUIT:
    running = false;
  case SDL_KEYDOWN:
    switch (event.key.keysym.sym) {
    case SDLK_LEFT:

      break;
    case SDLK_RIGHT:

      break;
    case SDLK_UP:
      box->createBox(10, 100, 10, 10, true);
      break;
    case SDLK_DOWN:

      break;
    }
  case SDL_MOUSEBUTTONDOWN:
    while(SDL_MOUSEBUTTONDOWN){
      box->createBox(event.button.x, event.button.y, 1, 1, true);
    }
    break;
  }
}

void Game::render() {
  SDL_RenderClear(renderer);
  box->render();
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  //SDL_RenderPresent(renderer);
}

void Game::update() {
  box->update();
}

void Game::clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}
