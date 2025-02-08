#include "PlayerCharacter.h"
#include "TextureManager.h"
#include "SDL.h"


PlayerCharacter::PlayerCharacter(Properties* props) : Character(props)
{
    m_Row = 1;
    m_FrameCount = 1;
    m_AnimSpeed = 80;
}

void PlayerCharacter::Draw()
{
    TextureManager::GetInstance()->DrawFrame(m_TextureID, m_Transform->X, m_Transform->Y, m_Width, m_Height, m_Row, m_Frame, m_Flip);
}

void PlayerCharacter::Clean()
{
    TextureManager::GetInstance()->Clean();
}

void PlayerCharacter::Update(float dt)
{
    
    m_Frame = (SDL_GetTicks() / m_AnimSpeed) % m_FrameCount;
}
