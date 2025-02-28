#include "fish.h" 
#include "Camera.h"
#include "CollisionHandler.h"
#include <iostream>
#include "ObjectFactory.h"

static Register<fish> registerFish("fish");

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
	m_Animation->Draw(m_Transform->X, m_Transform->Y, 0.0f, 0.f, SDL_FLIP_NONE);

	m_Collider->Draw();
}

void fish::Clean()
{
}

void fish::Update(float dt)
{

   m_RigidBody->Update(dt);
    m_LastSafePosition.X = m_Transform->X;
    m_Transform->TranslateX(m_RigidBody->Position().X);
    m_Collider->SetBox(m_Transform->X, m_Transform->Y, 32, 64);

    if (CollisionHandler::GetInstance()->MapCollision(m_Collider->GetBox())) {
        m_Transform->X = m_LastSafePosition.X;
    }


    //Move on Y Axis
    m_RigidBody->Update(dt);
    m_LastSafePosition.Y = m_Transform->Y;
    m_Transform->TranslateY(m_RigidBody->Position().Y);
    m_Collider->SetBox(m_Transform->X, m_Transform->Y, 32, 64);

    if (CollisionHandler::GetInstance()->MapCollision(m_Collider->GetBox())) {
        m_Transform->Y = m_LastSafePosition.Y;
    }

	m_Animation->Update(dt);
	
	if (m_Animation->IsEnded()) {
		m_Animation->SetRepeat(true);
	}
}
