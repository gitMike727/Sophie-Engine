#pragma once

#include "Defs.h"
#include <cstdio>
#include <SDL.h>


class Engine {
public:
	Engine() {}

	SDL_Renderer* renderer;
	SDL_Window* window;

	void Init();
	void Render();
	void Update();
	void Clean();
};

