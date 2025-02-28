#pragma once

class Entity;

class Component {
public: 
	Component() = default;
	virtual ~Component() = default;
	Entity* EntityOwner;

	virtual void Init() {}
	virtual void Draw() {}
	virtual void Update() {}
	

};