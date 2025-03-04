#pragma once

#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class Overlay;
class FontRenderer;

class Graphics
{
	static const int WIDTH, HEIGHT;

	Resources* resources;
	FPSCounter fps_counter;
	FontRenderer* font_renderer;
	Overlay* overlay;
	SDL_Window* window;
	SDL_Renderer* renderer;

	bool init_sdl();

public:
	Graphics();
	void clear_screen();
	void render_overlay(std::vector<Entity*>* entities);
	void present_renderer(float delta);
	void render_entities(std::vector<Entity*>* entities, float delta);
	int get_width();
	int get_height();
	~Graphics();
};

