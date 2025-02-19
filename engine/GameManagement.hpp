#ifndef GAMEMANAGEMENT_HPP
#define GAMEMANAGEMENT_HPP

#include "GameObject.hpp"
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_render.h>
#include <memory>
#include <vector>

extern std::vector<std::shared_ptr<GameObject>> GameObjects;
extern SDL_Color WindowBackgroundColor;
extern const int ScreenHeight;
extern const int ScreenWidth;
extern bool QuitGame;

void UpdateObjects(SDL_Renderer *renderer);

void RegisterGameObject(std::shared_ptr<GameObject> object);
void OnGameStart();

#endif // GAMEMANAGEMENT_HPP
