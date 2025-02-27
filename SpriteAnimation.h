#pragma once

#include <string>
#include "Animation.h"
#include "SDL.h"

class SpriteAnimation : public Animation
{
public:
	SpriteAnimation(bool repeat = true);



	virtual void Update(float dt);
	void Draw(float x, float y, int spriteWidth, int spriteHeight, float xScale=1, float yScale=1, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void SetProps(std::string textureID, int spriteRow, int frameCount, int animSpeed);

	int GetCurrFrame() { return m_CurrentFrame; }


private:
	int m_SpriteRow, m_SpriteFrame;
	int m_AnimSpeed, m_FrameCount;

	std::string m_TextureID;
	

};

