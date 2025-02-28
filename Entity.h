#pragma once

#include "ECS.h"
#include <vector>
#include <memory>
#include "Component.h"

using ComponentList = std::vector<std::unique_ptr<Component>>;

class Entity {
public: 
	Entity() {}
	virtual ~Entity() {}

	template<typename T, typename... TArgs>
	inline T& AddComponent(TArgs&&... mArgs)
	{
		T* component(new T(std::forward<TArgs>(mArgs...)));
		std::unique_ptr<Component> uPtr{ component };
		components.emplace_back(std::move(uPtr));

		if (component->Init()) {
			compList. [getComponentTypeID<T>()] = component;
			compBitSet.[GetComponentTypeID<T>()] = true;
			component->EntityOwner = this;
			return *component;
		}
		return *static_cast<T*>(nullptr);
	}
	template<typename T>
	inline T& GetComponent() const {
		auto ptr(compList[GetComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}

private:
	ComponentList compList;
	ComponentBitSet compBitSet;
	std::vector<std::unique_ptr<Component>> components;
};