#include "Box.hpp"
#include <iostream>
void Box::createBox(int x, int y, int w, int h, bool dyn) {

  SDL_Rect rect = {.x = x, .y = y, .w = w, .h = h};

  b2BodyDef bodyDef;
  if (dyn) {
    bodyDef.type = b2_dynamicBody;
  }
  //bodyDef.type = b2_dynamicBody;
  bodyDef.position.Set(x, y);

  b2PolygonShape dynamicBox;
  dynamicBox.SetAsBox(w * 0.20, h * 0.20);

  b2FixtureDef fixtureDef;
  fixtureDef.shape = &dynamicBox;
  fixtureDef.density = 1.0f;
  fixtureDef.friction = 0.3f;

  b2Body *body = Game::world->CreateBody(&bodyDef);
  body->CreateFixture(&fixtureDef);
  body->SetBullet(true);
  bodies.push_back(body);
  rects.push_back(rect);
}

void Box::render() {
  SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);

  for (auto rect : rects) {
    //SDL_RenderFillRect(Game::renderer, &rect);
    SDL_RenderDrawRect(Game::renderer, &rect);
  }

  SDL_RenderPresent(Game::renderer);
}

void Box::update() {

  // for (auto body : bodies) {
  //   for (auto &recr : rects) {
  //     if (body != NULL) {
  //       recr.x = body->GetPosition().x;
  //       recr.y = body->GetPosition().y;
  //       //std::cout << body->GetPosition().x << " || " << body->GetPosition().y << std::endl;
  //     }
  //   }
  // }
  for (Uint32 i = 0; i < bodies.size(); i++) {
    if (bodies[i] != NULL) {
      rects[i].x = bodies[i]->GetPosition().x;
      rects[i].y = bodies[i]->GetPosition().y;
    }
  }
}