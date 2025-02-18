#include "PlayerCharacter.h"
#include "TextureManager.h"
#include "SDL.h"
#include "Input.h"


PlayerCharacter::PlayerCharacter(Properties* props) : Character(props)
{
    m_RigidBody = new RigidBody();
    m_Animation = new Animation();
    m_Animation->SetProps(m_TextureID, 1, 1, 100);
}

void PlayerCharacter::Draw()
{
    m_Animation->Draw(m_Transform->X, m_Transform->Y, m_Width, m_Height);
}

void PlayerCharacter::Clean()
{
    TextureManager::GetInstance()->Clean();
}

void PlayerCharacter::Update(float dt)
{
   //m_Frame = (SDL_GetTicks() / m_AnimSpeed) % m_FrameCount;

   if (idle == 1)
   {
       m_Animation->SetProps("JackBack", 1, 1, 100);
   }
   else if ( idle == 2)
   {
       m_Animation->SetProps("Jack", 1, 1, 100);
   }
   else if (idle == 3)
   {
       m_Animation->SetProps("JackLeft", 1, 1, 100);
   }
   else if (idle == 4)
   {
       m_Animation->SetProps("JackRight", 1, 1, 100);
   }

   m_RigidBody->UnSetForce();

    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_W))
    {
        m_RigidBody->ApplyForceY(5*UPWARD);
        m_Animation->SetProps("Jack_BackWalk", 1, 8, 100);
        SDL_Log("Key 'W' Pushed!");
        idle = 1;
    }

    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_S))
    {
        m_RigidBody->ApplyForceY(5*DOWNWARD);
        m_Animation->SetProps("Jack_Walk", 1, 8, 100);
        SDL_Log("Key 'S' Pushed!");
        idle = 2;
    }

    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_A))
    {
        m_RigidBody->ApplyForceX(5*LEFTWARD);
        m_Animation->SetProps("Jack_LeftWalk", 1, 8, 100);
        SDL_Log("Key 'A' Pushed!");
        idle = 3;
    }

    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_D))
    {
        m_RigidBody->ApplyForceX(5*RIGHTWARD);
        m_Animation->SetProps("Jack_RightWalk", 1, 8, 100);
        SDL_Log("Key 'D' Pushed!");
        idle = 4;
    }
    
    m_RigidBody->Update(dt);

    m_Transform->TranslateX(m_RigidBody->Position().X);
    m_Transform->TranslateY(m_RigidBody->Position().Y);

    m_Animation->Update();
    
}
