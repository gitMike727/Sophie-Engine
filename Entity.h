#pragma once

#include "ECS.h"
#include <vector>
#include <memory>

class Entity {
public:
	Entity() {}

	template<typename T, typename... TArgs>
	inline T& AddComponent(TArgs&&... mArgs) {

	}
	
private:
	ComponentList compList;
	ComponentBitset compBitset;
	std::vector<std::unique_ptr<Component>> components;
};
