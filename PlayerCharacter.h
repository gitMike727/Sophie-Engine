#pragma once

#include "Character.h"
#include "Animation.h"
#include "RigidBody.h"

class PlayerCharacter: public Character {

public:
	PlayerCharacter(Properties* props);

	virtual void Draw();
	virtual void Clean();
	virtual void Update(float dt);

	int idle;
	float speed = 3.5;
	

private:
	//int m_Row, m_Frame, m_FrameCount;
	//int m_AnimSpeed;

	Animation* m_Animation;
	RigidBody* m_RigidBody;
};
