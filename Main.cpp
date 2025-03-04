#include "Engine.h"
#include "SDL.h"
#include <stdio.h>
#include "Inputs.h"



int main(int argc, char* argv[])
{
	Inputs inputs;
	Engine engine;

	bool loop = true;

	while (loop) {
		inputs.update();
		loop = !inputs.get_quit();
		engine.ClearScreen();
	}

	return 0;
}