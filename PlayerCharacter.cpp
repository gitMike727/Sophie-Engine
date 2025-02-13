#include "PlayerCharacter.h"
#include "TextureManager.h"
#include "SDL.h"
#include "Input.h"


PlayerCharacter::PlayerCharacter(Properties* props) : Character(props)
{
    m_RigidBody = new RigidBody();
    m_Animation = new Animation();
    m_Animation->SetProps(m_TextureID, 1, 8, 100);
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
    m_Animation->Update();
   // m_Frame = (SDL_GetTicks() / m_AnimSpeed) % m_FrameCount;
    m_RigidBody->Update(0.2);
    
    //m_Transform->TranslateX(m_RigidBody->Position().X);
    m_Transform->TranslateY(m_RigidBody->Position().Y);

    m_Animation->SetProps("Jack", 1, 1, 100);
    m_RigidBody->UnSetForce();

    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_S))
    {
        m_RigidBody->ApplyForceY(4);
        m_Animation->SetProps("Jack_Walk", 1, 8, 100);
        SDL_Log("Key S Pushed!");
    }

    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_W))
    {
        m_RigidBody->ApplyForceY(-4);
        m_Animation->SetProps("Jack_Walk", 1, 8, 100);
        SDL_Log("Key W Pushed!");
    }
}
