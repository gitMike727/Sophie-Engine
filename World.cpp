#include "World.h"
#include <SDL.h>
#include "Player.h"

const float World::respawn_delay = 3.0f;

void World::check_spawn_players()
{
}

World::World(int screen_w, int screen_h) : player_respawn_timers()
{
    this->screen_w = screen_w;
    this->screen_h = screen_h;
    collision_manager = new CollisionManager(&entities);
    entities.push_back(new Player(screen_w / 6 + 32, screen_h / 2 - 32, 1, screen_w, screen_h, &entities));
    entities.push_back(new Player(screen_w * 5 / 6 - 32, screen_h / 2 - 32, 2, screen_w, screen_h, &entities));
}

void World::update(Inputs* inputs)
{
    // Respawn players if they die
    check_spawn_players();

    // Reset delta since last cycle
    clock.tick();

    // Handle input
    // Deliver input to each Player
    for (int i = 0; i < entities.size(); i++) {
        if (entities[i]->get_id() == 0) {
            ((Player*)entities[i])->handle_inputs(clock.get_delta(), inputs);
        }
    }

    // Update entities
    for (int i = 0; i < entities.size(); i++) {
        entities[i]->update(clock.get_delta());
    }

    // Check for collisions
    collision_manager->check_collisions();

    // Prune dead entities from entites vector
    for (int i = 0; i < entities.size(); i++) {
        if (!entities[i]->is_alive()) {
            if (entities[i]->get_id() == 0) {
                player_respawn_timers[
                    ((Player*)entities[i])->get_player_num() - 1] = respawn_delay;
            }
            delete entities[i];
            entities[i] = NULL;
            entities.erase(entities.begin() + i);
            i -= 1;
        }
    }

    // Update player respawn timers
    for (int i = 0; i < NUM_PLAYERS; i++) {
        if (player_respawn_timers[i] > 0) {
            player_respawn_timers[i] -= clock.get_delta();
            if (player_respawn_timers[i] < 0) {
                player_respawn_timers[i] = 0;
            }
        }
    }
}

float World::get_delta()
{
    return clock.get_delta();
}

std::vector<Entity*>* World::get_entities()
{
    return &entities;
}

World::~World()
{
    // Free all entities
    for (int i = 0; i < entities.size(); i++) {
        delete entities[i];
        entities[i] = NULL;
    }

    // Free collision manager
    delete collision_manager;
    collision_manager = NULL;
}
