#pragma once

#include "Character.h"


class PlayerCharacter: public Character {

public:
	PlayerCharacter(Properties* props);

	virtual void Draw();
	virtual void Clean();
	virtual void Update(float dt);

private:
	int m_Row, m_Frame, m_FrameCount;

	int m_AnimSpeed;
};
