#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "Game.h"

Game *game = nullptr;

int main(int argc, char* argv[])
{
	game = new Game();

	//game window
	game->

	while (game->running()) {

		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();

	return 0;
}


