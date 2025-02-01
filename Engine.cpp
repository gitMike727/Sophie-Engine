#include "Engine.h"
#include <iostream>

Engine* Engine::s_Instance = nullptr;

void Engine::Init()
{
	m_IsRunning = true;
}

bool Engine::Clean()
{
	return false;
}

void Engine::Quit()
{
}

void Engine::Update()
{
	std::cout << "Game is running..." << std::endl;
}

void Engine::Render()
{
}

void Engine::Event()
{
}
