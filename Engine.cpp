
#include "Engine.h"

const int Engine::WIDTH = 1280, Engine::HEIGHT = 720;

bool Engine::Init()
{
    // Initialize SDL_video
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0) {
        printf("Error: Failed to init SDL2: %s\n", SDL_GetError());
        return false;
    }

    // Create SDL Window
    window = SDL_CreateWindow(
        "SOPHIE ENGINE | Tiny Bait",                  
        SDL_WINDOWPOS_UNDEFINED,      
        SDL_WINDOWPOS_UNDEFINED,      
        WIDTH,                        
        HEIGHT,                       
        SDL_WINDOW_OPENGL             
    );
    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return false;
    }

    // Initialize renderer with flags
    renderer = SDL_CreateRenderer(window, -1,
        SDL_RENDERER_ACCELERATED |
        SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        printf("Could not init renderer: %s\n", SDL_GetError());
        return false;
    }

    // Initialize TTF
    //if (TTF_Init() == -1) {
    //    printf("SDL_ttf failed to initialize: %s\n", TTF_GetError());
    //    return false;
    //}

    return true;
}

Engine::Engine()
{
    Init();
    assetManager = new AssetManager(renderer);
    assetManager->load_resources();

    fps_counter = FPSCounter();
}

void Engine::ClearScreen()
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
}

void Engine::Render(float dt)
{
    SDL_RenderPresent(renderer);
}

int Engine::get_width()
{
    return WIDTH;
}

int Engine::get_height()
{
    return HEIGHT;
}

Engine::~Engine()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    delete assetManager;
}


