#pragma once

#include <vector>
#include "Entity.h"

class Entity;

class CollisionManager
{
	std::vector<Entity*>* entities;

public:

	CollisionManager(std::vector<Entity*>* entites);
	void check_collisions();
};

