#pragma once

#include <map>
#include <string>
#include <vector>
#include "SDL.h"
#include "Animation.h"



struct Sequence {
	int speed;
	int frameCount;
	int width, height;
	std::vector<std::string> TextureIDs;
};

class SeqAnimation : public Animation {
public:
	SeqAnimation(bool repeat = true);

	virtual void Update(float dt);
	void Parse(std::string source);
	void SetCurrSeq(std::string seqID);
	void SetRepeat(bool repeat) { m_Repeat = repeat; }
	void Draw(float x, float y, float xscale = 1, float yscale = 1, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	Sequence m_CurrentSeq;
	std::map<std::string, Sequence> m_SeqMap;
};

