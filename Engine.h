#pragma once

#include "SDL.h"
#include "SDL_image.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

class Engine
{
public:
	// Singleton
	static Engine* GetInstance() {
		return s_Instance = (s_Instance != nullptr) ? s_Instance : new Engine();
	}

	bool Init();
	bool Clean();
	void Quit();

	void Update();
	void Render();
	void Event();

	inline bool IsRunning() { return m_IsRunning; }
	inline SDL_Renderer* GetRenderer() { return m_Renderer; }

private:
	Engine() {}
	bool m_IsRunning;

	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;

	static Engine* s_Instance;
	
};

