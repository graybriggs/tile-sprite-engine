#pragma once
#ifndef UTILITY_H
#define UTILITY_H

#include <SDL.h>

namespace util {

	SDL_Rect init_SDL_Rect(int x, int y, int w, int h);
	void copy_SDL_Rect(SDL_Rect dest, const SDL_Rect src);

}

#endif
