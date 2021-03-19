#pragma once
#ifndef BOX_HPP
#define BOX_HPP

#include "Game.hpp"
#include <vector>
class Box {
public:
  void createBox(int x, int y, int w, int h, bool dyn = true);
  void update();
  void render();

private:
  std::vector<SDL_Rect> rects;
  std::vector<b2Body *> bodies;
};

#endif