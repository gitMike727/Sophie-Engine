#include "fish.h" 
#include "Camera.h"
#include "CollisionHandler.h"
#include <iostream>

fish::fish(Properties* props) :Character(props)
{
	m_RigidBody = new RigidBody();
	m_RigidBody->SetGravity(0);
	m_Collider = new Collider();

	m_Animation = new SeqAnimation();
	m_Animation->Parse("assets/animations.aml");
	m_Animation->SetCurrSeq("Fish_Spawn");
}

void fish::Draw()
{
	m_Animation->Draw(m_Transform->X, m_Transform->Y, 0.3f, 0.3f, SDL_FLIP_NONE);
}

void fish::Clean()
{
}

void fish::Update(float dt)
{
	m_Animation->Update(dt);
	
	if (m_Animation->IsEnded()) {
		m_Animation->SetRepeat(true);
	}
}
