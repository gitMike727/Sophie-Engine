#include "Player.h"
#include <math.h>


#define WIDTH 36
#define HEIGHT 40

Player::Player(float x, float y, int player_num, int screen_w, int screen_h, std::vector<Entity*>* entities, float invincible_time)
	: Entity(x, y, WIDTH, HEIGHT, screen_w, screen_h)
{
	this->w = WIDTH;
	this->h = HEIGHT;
	hitbox = new Hitbox(0, 0, w, h);
	vx = vy = 0.0f;
	max_speed = 300.0f;
	this->player_num = player_num;
	this->entities = entities;
}

void Player::update(float delta)
{

    // Apply change in x and y directions
    x += delta * vx;
    y += delta * vy;

    // Enforce speed limit
    if (vx > max_speed) {
        vx = max_speed;
    }
    if (vy > max_speed) {
        vy = max_speed;
    }
    if (vx < -max_speed) {
        vx = -max_speed;
    }
    if (vy < -max_speed) {
        vy = -max_speed;
    }

    check_bounds();

    hitbox->update_pos(x, y, angle);
}

void Player::render(SDL_Renderer* renderer, AssetManager* resources, float delta)
{
    SDL_Texture* texture;
    if (player_num == 1) {
        texture = resources->get_texture("player", 1);
    }
    else {
        texture = resources->get_texture("player2", 1);
    }

    int texture_width, texture_height;
    SDL_QueryTexture(texture, NULL, NULL, &texture_width, &texture_height);
    SDL_Rect dst = {
        (int)x,
        (int)y,
        texture_width,
        texture_height };

    SDL_RenderCopyEx(renderer, texture, NULL, &dst, angle / M_PI * 180 + 90,
        NULL, SDL_FLIP_NONE);
}

void Player::handle_inputs(float delta, Inputs* inputs)
{
    if (player_num == 1) {
        // Movement Controls
        if (inputs->is_key_down(KEY_P1_MOVE_UP)) {
            vx += delta * linear_accel * cos(angle);
            vy += delta * linear_accel * sin(angle);
        }
        else if (inputs->is_key_down(KEY_P1_MOVE_DOWN)) {
            vx -= delta * linear_accel * cos(angle);
            vy -= delta * linear_accel * sin(angle);
        }
        if (inputs->is_key_down(KEY_P1_MOVE_LEFT)) {
            angle -= delta * turn_speed;
        }
        else if (inputs->is_key_down(KEY_P1_MOVE_RIGHT)) {
            angle += delta * turn_speed;
        }
    }
}


bool Player::is_alive()
{
    return alive;
}

const int Player::get_id()
{
    return 0;
}

const bool Player::collides()
{
    return true;
}

bool Player::does_collide(int id)
{
    return id == 1 || id == 4;
}

void Player::collide_entity(Entity* entity)
{
}

int Player::get_player_num()
{
    return 0;
}
