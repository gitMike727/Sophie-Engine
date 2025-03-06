#include "Engine.h"
#include "Inputs.h"

int main(int argc, char* argv[])
{
	Engine engine;
	Inputs inputs;
	
	engine.Init();
	
	while (1) {
		engine.Render();
		inputs.HandleInputs();
		engine.Update();
		SDL_Delay(16);
	}
	
	engine.Clean();
	return 0;
}