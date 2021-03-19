#include "Game.hpp"

int main(int argc, char *argv[]) {
  Game *game = new Game();
  game->loop(game);
  return 0;
}