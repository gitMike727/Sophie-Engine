#include "Engine.h"
#include "TextureManager.h"
#include "Transform.h"
#include "PlayerCharacter.h"
#include "Input.h"
#include "Timer.h"
#include "MapParser.h"
#include "Camera.h"
#include <iostream>
#include "fish.h"
#include "ObjectFactory.h"
#include "Vector2D.h"

Engine* Engine::s_Instance = nullptr;

bool Engine::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0) {
		SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
		return false;
	}

	SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
	
	m_Window = SDL_CreateWindow("Sophie Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_HEIGHT, SCREEN_WIDTH, window_flags);
	if (m_Window == nullptr) {
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}

	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_Renderer == nullptr) {
		SDL_Log("Failed to create renderer: %s", SDL_GetError());
		return false;
	}

	if (MapParser::GetInstance()->Load()) {
		std::cout << "Load Map Successful..." << std::endl;
		
	}
	else {
		std::cout << "Load Map Failed..." << std::endl;
		return false;
	}

	m_MainMap = MapParser::GetInstance()->GetMap("MainMap");

	TextureManager::GetInstance()->ParseTextures("assets/textures.tml");

	/*TextureManager::GetInstance()->Load("Jack", "assets/Jack_The_Apprentice.png");
	TextureManager::GetInstance()->Load("JackBack", "assets/Jack_The_Apprentice_Back.png");
	TextureManager::GetInstance()->Load("JackLeft", "assets/Jack_The_Apprentice_Left.png");
	TextureManager::GetInstance()->Load("JackRight", "assets/Jack_The_Apprentice_Right.png");
	TextureManager::GetInstance()->Load("Jack_Walk", "assets/Jack_The_Apprentice_Walk_Sheet.png");
	TextureManager::GetInstance()->Load("Jack_BackWalk", "assets/Jack_The_Apprentice_BackWalk_Sheet.png");
	TextureManager::GetInstance()->Load("Jack_LeftWalk", "assets/Jack_The_Apprentice_LeftWalk_Sheet.png");
	TextureManager::GetInstance()->Load("Jack_RightWalk", "assets/Jack_The_Apprentice_RightWalk_Sheet.png");
	TextureManager::GetInstance()->Load("Jack_Fishing", "assets/Jack_The_Apprentice_Fishing.png");
	TextureManager::GetInstance()->Load("Jack_FishIdle", "assets/Jack_The_Apprentice_FishingIdle.png");*/

	GameObject* jack = ObjectFactory::GetInstance()->CreateObject("PlayerCharacter", new Properties("Jack", 600, 800, 32, 32));
	GameObject* fish_Spawn = ObjectFactory::GetInstance()->CreateObject("fish", new Properties("Fish_Spawn", 600, 760, 32, 64));
	//PlayerCharacter* jack = new PlayerCharacter(new Properties("Jack", 600, 800, 32, 32));
	//fish* fish_Spawn = new fish(new Properties("Fish_Spawn", 600, 760, 32, 32));

	m_GameObjects.push_back(jack);
	m_GameObjects.push_back(fish_Spawn);

	//Transform tf;
	//tf.Log();
	
	Camera::GetInstance()->SetTarget(jack->GetOrigin());
	Camera::GetInstance()->SetTarget(fish_Spawn->GetOrigin());

	return m_IsRunning = true;
}

bool Engine::Clean()
{
	TextureManager::GetInstance()->Clean();
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	IMG_Quit();
	SDL_Quit();

	for (unsigned int i = 0; i != m_GameObjects.size(); i++) {
		m_GameObjects[i]->Clean();
	}

	return false;
}

void Engine::Quit()
{
	m_IsRunning = false;
}

void Engine::Update()
{
	float dt = Timer::GetInstance()->GetDeltaTime();
	m_MainMap->Update();
	
	for (unsigned int i = 0; i != m_GameObjects.size(); i++) {
		m_GameObjects[i]->Update(dt);
	}

	Camera::GetInstance()->Update(dt);
	
}									 

void Engine::Render()
{
	SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);
	SDL_RenderClear(m_Renderer);

	m_MainMap->Render();
	
	for (unsigned int i = 0; i != m_GameObjects.size(); i++) {
		m_GameObjects[i]->Draw();
	}
	
	SDL_RenderPresent(m_Renderer);
}

void Engine::Event()
{
	Input::GetInstance()->Listen();
}
