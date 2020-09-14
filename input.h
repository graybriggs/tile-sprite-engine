#pragma once
#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>

#include <memory>
#include <vector>

typedef std::vector<SDL_Event> EventList;
class Tile;

class Input {
public:

	void moveTiles(EventList& events, std::vector<std::unique_ptr<Tile>>& tiles);
};

#endif