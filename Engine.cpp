#include "Engine.h"

Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::Init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		printf("Subsystems Initialised...\n");
		
		window = SDL_CreateWindow(title, xPos, yPos, width, height,flags);

		if (window) {
		printf("Window created...\n");
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			printf("Renderer created...\n");
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}
}

void Engine::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Engine::Update()
{
}

void Engine::Render()
{
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void Engine::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	printf("Game cleaned...\n");
}
