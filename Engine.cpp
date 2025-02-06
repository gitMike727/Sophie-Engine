#include "Engine.h"
#include "TextureManager.h"
#include "Transform.h"
#include <iostream>

Engine* Engine::s_Instance = nullptr;

bool Engine::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0) {
		SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
		return false;
	}
	
	m_Window = SDL_CreateWindow("Sophie Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_HEIGHT, SCREEN_WIDTH, 0);
	if (m_Window == nullptr) {
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}

	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_Renderer == nullptr) {
		SDL_Log("Failed to create renderer: %s", SDL_GetError());
		return false;
	}

	TextureManager::GetInstance()->Load("Player Character", "assets/Jack_The_Apprentice.png");

	Transform tf;
	tf.Log();

	return m_IsRunning = true;
}

bool Engine::Clean()
{
	TextureManager::GetInstance()->Clean();
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	IMG_Quit();
	SDL_Quit();

	return false;
}

void Engine::Quit()
{
	m_IsRunning = false;
}

void Engine::Update()
{
	
}									 

void Engine::Render()
{
	SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);
	SDL_RenderClear(m_Renderer);

	TextureManager::GetInstance()->Draw("Player Character", 100, 100, 32, 32);
	SDL_RenderPresent(m_Renderer);
}

void Engine::Event()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		m_IsRunning = false;
		break;
	default:
		break;
	}
}
