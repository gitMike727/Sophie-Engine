#include "TextureManager.h"
#include "Engine.h"

bool TextureManager::Load(std::string id, std::string filename)
{
	SDL_Surface* surface = IMG_Load(filename.c_str());
	if (surface == nullptr) {
		SDL_Log("Failed to load texture: %s, %s", filename.c_str(), SDL_GetError());
		return false;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(), surface);
	if (texture == nullptr) {
		SDL_Log("Failed to create texture from surface: %s", SDL_GetError());
		return false;
	}

	return true;
}
void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip)
{
}

void TextureManager::Drop(std::string id)
{
}

void TextureManager::Clean()
{
}


