#pragma once

#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class Engine
{

	static const int WIDTH, HEIGHT;

	SDL_Window* window;
	SDL_Renderer* renderer;

	bool Init();

public:
	Engine();
	void ClearScreen();
	void Render(float dt);
	int get_width();
	int get_height();
	~Engine();
};

