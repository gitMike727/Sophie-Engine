#include "PlayerCharacter.h"
#include "TextureManager.h"
#include "SDL.h"


PlayerCharacter::PlayerCharacter(Properties* props) : Character(props)
{
    m_Animation = new Animation();
    m_Animation->SetProps(m_TextureID, 1, 8, 80, SDL_FLIP_HORIZONTAL);
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
}
