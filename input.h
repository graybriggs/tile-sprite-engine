#pragma once
#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>

#include <memory>
#include <vector>

class Tile;

class Input {
public:

	void moveTiles(std::vector<SDL_Event>&, std::vector<std::unique_ptr<Tile>>&);


};

#endif