#include "Engine.h"

void Engine::Init()
{
	int rendererFlags, windowFlags;

	rendererFlags = SDL_RENDERER_ACCELERATED;
	windowFlags = 0;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize... SDL_Error: %s\n", SDL_GetError());
		exit(1);
	}

	window = SDL_CreateWindow("SOPHIE ENGINE | Tiny Bait", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);
	if (!window) {
		printf("Failed to create window...SDL_Error: %s\n", SDL_GetError());
		exit(1);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	renderer = SDL_CreateRenderer(window, -1, rendererFlags);
	if (!renderer) {
		printf("Failed to create renderer...SDL_Error: %s\n", SDL_GetError());
		exit(1);
	}

}

void Engine::Render()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void Engine::Update()
{
	SDL_RenderPresent(renderer);
}

void Engine::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}


