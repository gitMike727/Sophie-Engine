#include <SDL.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "SDL_Init succeeded" << endl;
	}

	return 0;
}
	
