#include "Engine.h"
#include "Timer.h"
#include "Entity.h"
#include "ECS.h"
#include "EntityManager.h"
#include "Transform.h"



int main(int argc, char* argv[])
{
	EntityManager* manager = new EntityManager();	
	Entity* player = new Entity();

	manager->addEntity(player);
	player->GetComponent<Transform>().position = Vector2Df(0,0);

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
	
