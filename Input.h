#pragma once

#include "SDL.h"

class Input
{
public:
	static Input* GetInstance() {
		return s_Instance = (s_Instance != nullptr) ? s_Instance : new Input();
	}

	void Listen();
	bool GetKeyDown(SDL_Scancode key);


private:
	Input();
	static Input* s_Instance;
	const Uint8* m_KeyStates;

	void KeyUp();
	void KeyDown();

	

};

