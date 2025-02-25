#pragma once

#include "Character.h"
#include "Animation.h"
#include "RigidBody.h"
#include "Collider.h"
#include "Vector2D.h"

class PlayerCharacter: public Character {

public:
	PlayerCharacter(Properties* props);

	virtual void Draw();
	virtual void Clean();
	virtual void Update(float dt);

	int idle;
	int fishIdle;
	float speed = 3.5f;

private:
	void AnimationState();
	

private:
	
	bool m_isFishing;

	float m_FishTime = 4.0f;

	Animation* m_Animation;
	RigidBody* m_RigidBody;
	Collider* m_Collider;
	Vector2D m_LastSafePosition;


};
