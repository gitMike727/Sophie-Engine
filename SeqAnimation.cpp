#include "SeqAnimation.h"
#include "Vendor/tinyxml-master/tinyxml.h"
#include <iostream>
#include "TextureManager.h"

SeqAnimation::SeqAnimation(bool repeat) : Animation(repeat)
{
}

void SeqAnimation::Update(float dt)
{
	if(m_Repeat || m_IsEnded) {
		m_IsEnded = true;
		m_CurrentFrame = (SDL_GetTicks() / m_CurrentSeq.speed) % m_CurrentSeq.frameCount;
	}

	if (!m_Repeat && m_CurrentFrame == (m_CurrentSeq.frameCount - 1)) {
		m_IsEnded = true;
		m_CurrentFrame = (m_CurrentSeq.frameCount - 1);
	}
}

void SeqAnimation::Parse(std::string source)
{
	TiXmlDocument xml;
	xml.LoadFile(source);
	if (xml.Error()) {
		std::cout << "Failed to load animation file: " << source << std::endl;
	}

	TiXmlElement* root = xml.RootElement();
	for (TiXmlElement* e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
		if (e->Value() == std::string("sequence")) {
			Sequence seq;
			std::string seqID = e->Attribute("id");
			e->Attribute("speed", &seq.speed);
			e->Attribute("width", &seq.width);
			e->Attribute("height", &seq.height);
			e->Attribute("frameCount", &seq.frameCount);

			for (TiXmlElement* frame = e->FirstChildElement(); frame != nullptr; frame = frame->NextSiblingElement()) {
				seq.TextureIDs.push_back(frame->Attribute("textureID"));
				m_SeqMap[seqID] = seq;
			}
		}
	}
}

void SeqAnimation::SetCurrSeq(std::string seqID)
{
	if (m_SeqMap.count(seqID) > 0) {
		m_CurrentSeq = m_SeqMap[seqID];
	}
	else {
		std::cout << "The given Sequence animation is not matching: " << seqID << std::endl;
	}
}

void SeqAnimation::Draw(float x, float y, float xscale, float yscale, SDL_RendererFlip flip)
{
	TextureManager::GetInstance()->Draw(m_CurrentSeq.TextureIDs[m_CurrentFrame], x, y, m_CurrentSeq.width, m_CurrentSeq.height, xscale, yscale, flip);
}
