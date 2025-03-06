#pragma once

#include <string>
#include "Entity.h"
#include "Hitbox.h"
#include "Inputs.h"

class Player : public Entity
{

	std::vector<Entity*>* entities;
	float vx, vy;
	float max_speed;
	int player_num;
	float angle;
	float turn_speed, linear_accel;
	bool alive;

public:
	Player(float x, float y, int player_num, int screen_w, int screen_h,
		std::vector<Entity*>* entities, float invincible_time = 3.0f);
	void update(float delta);
	void render(SDL_Renderer* renderer, AssetManager* resources, float delta);
	void handle_inputs(float delta, Inputs* inputs);
	bool is_alive();
	const int get_id();
	const bool collides();
	bool does_collide(int id);
	void collide_entity(Entity* entity);
	int get_player_num();

};

