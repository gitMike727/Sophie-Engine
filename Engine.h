#pragma once

#include "SDL.h"
#include <stdio.h>

class Engine
{
public:
	Engine();
	~Engine();
	
	void Init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);
	void HandleEvents();
	void Update();
	void Render();
	void Clean();

	bool running() { return isRunning; }

private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
};

