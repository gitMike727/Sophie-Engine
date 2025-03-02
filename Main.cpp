#include "Engine.h"
#include "Timer.h"
#include "Entity.h"


int main(int argc, char* argv[])
{
	Engine::GetInstance()->Init();

	while (Engine::GetInstance()->IsRunning())
	{
		Engine::GetInstance()->Event();
		Engine::GetInstance()->Update();
		Engine::GetInstance()->Render();
		Timer::GetInstance()->Tick();
	}

	Engine::GetInstance()->Clean();
	return 0;


}
	
