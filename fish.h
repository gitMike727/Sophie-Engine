#pragma once

#include "PlayerCharacter.h"
#include "RigidBody.h"
#include "Collider.h"
#include "SeqAnimation.h"
#include "SpriteAnimation.h"

class fish : public Character {

public: 
	fish(Properties* props);

	virtual void Draw();
	virtual void Clean();
	virtual void Update(float dt);

private:
	Collider* m_Collider;
	RigidBody* m_RigidBody;
	SeqAnimation* m_Animation;
	Vector2D m_LastSafePosition;
};

