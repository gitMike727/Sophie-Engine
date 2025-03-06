#pragma once

#include <SDL.h>

class Hitbox
{
	float x, y;
	int x_offset, y_offset, w, h;
	float angle;
	float radius;
	SDL_Point tl, tr, bl, br;

public:
	Hitbox(float x_offset, float y_offset, int w, int h);
	void update_pos(float x, float y, float angle);
	void render_corners(SDL_Renderer* renderer); // DEBUG METHOD
	int get_center_x();
	int get_center_y();
	float get_radius();
	SDL_Point get_tl();
	SDL_Point get_tr();
	SDL_Point get_bl();
	SDL_Point get_br();
};

