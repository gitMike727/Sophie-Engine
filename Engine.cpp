#include "Engine.h"
#include "TextureManager.h"
#include "Transform.h"
#include "PlayerCharacter.h"
#include "Input.h"
#include <iostream>

Engine* Engine::s_Instance = nullptr;
PlayerCharacter* jack = nullptr;

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

	TextureManager::GetInstance()->Load("Jack", "assets/Jack_The_Apprentice.png");
	TextureManager::GetInstance()->Load("JackBack", "assets/Jack_The_Apprentice_Back.png");
	TextureManager::GetInstance()->Load("Jack_Walk", "assets/Jack_The_Apprentice_Walk_Sheet.png");
	TextureManager::GetInstance()->Load("Jack_BackWalk", "assets/Jack_The_Apprentice_BackWalk_Sheet.png");
	jack = new PlayerCharacter(new Properties("Jack", 100, 100, 64, 64));

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
	jack->Update(0);
	
}									 

void Engine::Render()
{
	SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);
	SDL_RenderClear(m_Renderer);

	jack->Draw();
	
	SDL_RenderPresent(m_Renderer);
}

void Engine::Event()
{
	Input::GetInstance()->Listen();
}
