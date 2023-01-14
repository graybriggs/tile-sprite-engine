#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>

#include <vector>

#include "entity.h"
#include "utility.h"

typedef std::vector<SDL_Event> EventList;

class Tile;

class Player : public Entity {
public:

	const float X_MOVE_SPEED = 0.5f;
	const float Y_MOVE_SPEED = 0.25f;

	Player();

	void handleInput(const EventList&);
	void update(const float delta);
	// updateFrame(time);

	util::Rect getBoundingBox() const;
	void setBoundingBox(const util::Rect);
	void setScreenPosition(const int x, const int y);
	void stop();
	void tile_collide(const Tile& tile);
private:

	enum class PlayerStates { STOP, STAND, LEFT, RIGHT, UP, DOWN, BACK };
	PlayerStates state;
};

#endif
