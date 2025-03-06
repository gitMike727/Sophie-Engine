#include "AssetManager.h"
#include "Engine.h"

#include <iostream>

const std::string AssetManager::RES_DIR = "assets/";


bool AssetManager::load_font(TTF_Font** font, std::string filename, int size)
{
	std::string filepath = std::string(RES_DIR) + "fonts/" + filename;
	//*font = TTF_OpenFont(filepath.c_str(), size);
	if (*font == NULL) {
		std::cout << "Failed to load font: " << filename << std::endl;
		return false;
	}
	return true;
}

bool AssetManager::load_texture(SDL_Texture** texture, std::string filename)
{
	*texture = NULL;

	SDL_Surface* loaded_surface = NULL;

	std::string filepath = std::string(RES_DIR) + "images/" + filename;

	loaded_surface = IMG_Load(filepath.c_str());
	if (loaded_surface == NULL) {
		std::cout << "Failed to load image: " << filename << std::endl;
		return false;
	}

	*texture = SDL_CreateTextureFromSurface(renderer, loaded_surface);
	if (*texture == NULL) {
		std::cout << "Failed to create texture: " << filename << std::endl;
	
	}

	SDL_SetTextureBlendMode(*texture, SDL_BLENDMODE_BLEND);

	// Free the temporary surface
	SDL_FreeSurface(loaded_surface);

	return true;
}

AssetManager::AssetManager(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}

void AssetManager::load_resources()
{
	load_texture(&textures["Player"][1], "Jack/Jack_The_Apprentice.png");
}

TTF_Font* AssetManager::get_font(std::string name)
{
	return fonts[name];
}

SDL_Texture* AssetManager::get_texture(std::string name, int frame)
{
	return textures[name][frame];
}

AssetManager::~AssetManager()
{
	// Iterate through fonts and free them
	std::map<std::string, TTF_Font*>::iterator font_it;
	for (font_it = fonts.begin(); font_it != fonts.end(); font_it++) {
		//TTF_CloseFont(font_it->second);
	}

	// Iterate through textures and free them
	std::map<std::string, std::map<int, SDL_Texture*> >::iterator frames;
	for (frames = textures.begin(); frames != textures.end(); frames++) {
		std::map<int, SDL_Texture*>::iterator frame;
		for (frame = frames->second.begin(); frame != frames->second.end(); frame++) {
			//SDL_DestroyTexture(frame->second);
			frame->second = NULL;
		}
	}
}

