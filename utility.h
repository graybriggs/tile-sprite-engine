#pragma once
#ifndef UTILITY_H
#define UTILITY_H

#include <SDL.h>

namespace util {

	struct Rect {
		Rect();
		Rect(float x, float y, int w, int h);
		float x_pos, y_pos;
		int w, h;

		util::Rect getRect();
		void setRect(float x, float y, int w, int h);
		SDL_Rect toSDL_Rect();
	};

	SDL_Rect init_SDL_Rect(int x, int y, int w, int h);
	void copy_SDL_Rect(SDL_Rect dest, const SDL_Rect src);

}

#endif
