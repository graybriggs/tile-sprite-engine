#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

#include <vector>

#include "entity.h"
#include "utility.h"

typedef std::vector<SDL_Event> EventList;

class Tile;

class Player : public Entity {
public:

	const float X_MOVE_SPEED = 2.f;
	const float Y_MOVE_SPEED = 1.5f;

	Player();

	//void handleInput(const EventList&);
	void handleInput();
	void update(const float delta);
	// updateFrame(time);

	SDL_Rect getBoundingBox() const;
	void setBoundingBox(const SDL_Rect rect);
	void setScreenPosition(const int x, const int y);
	void stop();
	void move_back();
	void tile_collide(const Tile& tile);
private:

	enum class PlayerStates { STOP, STAND, LEFT, RIGHT, UP, DOWN, BACK };
	PlayerStates state;
};

#endif
