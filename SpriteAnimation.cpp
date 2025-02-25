#include "SpriteAnimation.h"
#include "TextureManager.h"

void SpriteAnimation::Update(float dt)
{
	m_SpriteFrame = (SDL_GetTicks() / m_AnimSpeed) % m_FrameCount;
}

void SpriteAnimation::Draw(float x, float y, int spriteWidth, int spriteHeight, float xScale, float yScale, SDL_RendererFlip flip)
{
	TextureManager::GetInstance()->DrawFrame(m_TextureID, x, y, spriteWidth, spriteHeight, m_SpriteRow, m_SpriteFrame);

}

SpriteAnimation::SpriteAnimation(bool repeat)
{
}

void SpriteAnimation::SetProps(std::string textureID, int spriteRow, int frameCount, int animSpeed)
{
	m_TextureID = textureID;
	m_SpriteRow = spriteRow;
	m_FrameCount = frameCount;
	m_AnimSpeed = animSpeed;
	
}
