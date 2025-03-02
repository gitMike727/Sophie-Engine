#include "EntityManager.h"

void EntityManager::Draw()
{
	for (auto& e : m_Entities)
	{
		e->Draw();
	}
}

void EntityManager::Update()
{
	for (auto& e : m_Entities)
	{
		e->Update();
	}
}

void EntityManager::Refresh()
{
}

void EntityManager::addEntity(Entity* player)
{
	std::unique_ptr<Entity> uPtr{ player };
	m_Entities.emplace_back(std::move(uPtr));
}

void EntityManager::removeEntity(Entity* player)
{
}

Entity* EntityManager::cloneEntity(Entity* player)
{
	return nullptr;
}
