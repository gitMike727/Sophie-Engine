#pragma once

#include <map>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class AssetManager
{
	static const std::string RES_DIR;
	std::map<std::string, TTF_Font*> fonts;
	std::map<std::string, std::map<int, SDL_Texture*> > textures;
	SDL_Renderer* renderer;
	bool load_font(TTF_Font** font, std::string filename, int size);
	bool load_texture(SDL_Texture** texture, std::string filename);

public:
	AssetManager(SDL_Renderer* renderer);
	void load_resources();
	TTF_Font* get_font(std::string name);
	SDL_Texture* get_texture(std::string name, int frame);
	~AssetManager();
};

