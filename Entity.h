#pragma once

#include "ECS.h"
#include <vector>
#include <memory>
#include "Component.h"
#include "Transform.h"

using ComponentList = std::vector<std::unique_ptr<Component>>;

class Entity {
public: 
	Entity() {
		this->AddComponent<Transform>(0, 0);
	}
	virtual ~Entity() = default;

	template<typename T, typename... TArgs>
	inline T& AddComponent(TArgs&&... mArgs)
	{
		T* component(new T(std::forward<TArgs>(mArgs)...));
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

	template<typename T>
	inline bool HasComponent() const {
		return compBitSet[GetComponentTypeID<T>()];
	}

	inline bool IsActive() const { return active; }

	inline void Destroy() { active = false; }

	virtual void Draw() { 
		for (auto& c : components) 
			c->Draw();
	}

	virtual void Update() {
		for (auto& c : components)
			c->Update();
	}

private:
	bool active;
	ComponentList compList;
	ComponentBitSet compBitSet;
	std::vector<std::unique_ptr<Component>> components;
};