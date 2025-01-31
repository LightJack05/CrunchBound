#ifndef GAMEMANAGEMENT_HPP
#define GAMEMANAGEMENT_HPP

#include "GameObject.hpp"
#include <SDL3/SDL_pixels.h>
#include <memory>
#include <vector>
#include <SDL3/SDL_render.h>

extern std::vector<std::shared_ptr<GameObject>> gameObjects;
extern SDL_Color windowBackgroundColor;

void UpdateObjects(SDL_Renderer *renderer);

void RegisterGameObject(std::shared_ptr<GameObject> object);

#endif // GAMEMANAGEMENT_HPP
