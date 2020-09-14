#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>

#include <vector>

typedef std::vector<SDL_Event> EventList;

class Player {
public:

	void handleInput(EventList&);

	// updateFrame(time);


};

#endif
