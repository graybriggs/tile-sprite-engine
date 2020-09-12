#pragma once
#ifndef UTILITY_H
#define UTILITY_H

#include <SDL.h>

namespace util {

	struct FRect {
		FRect();
		FRect(float x, float y, int w, int h);
		float x_pos, y_pos;
		int w, h;

		FRect getFrect() const;
		void setFRect(float x, float y, int w, int h);
		SDL_Rect toSDL_Rect() const;
	};

	SDL_Rect init_SDL_Rect(int x, int y, int w, int h);
	void copy_SDL_Rect(SDL_Rect dest, const SDL_Rect src);

}

#endif
