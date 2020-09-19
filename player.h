#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>

#include <vector>

#include "entity.h"

typedef std::vector<SDL_Event> EventList;

class Player : public Entity {
public:

	Player();

	void handleInput(const EventList&);
	void update(const float delta);
	// updateFrame(time);


private:

	enum class PlayerStates { STOP, STAND, LEFT, RIGHT, UP, DOWN, BACK };
	PlayerStates state;
};

#endif
