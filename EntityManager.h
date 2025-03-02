#pragma once

#include <vector>
#include <memory>
#include "Entity.h"

class Entity;

class EntityManager
{
public:
	EntityManager() = default;	
	~EntityManager() = default;

	void Draw();
	void Update();
	void Refresh();

	void addEntity(Entity* player);
	void removeEntity(Entity* player);
	Entity* cloneEntity(Entity* player);

private:
	std::vector<std::unique_ptr<Entity>> m_Entities;
};

