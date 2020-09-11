#include <SDL.h>

#include "utility.h"

SDL_Rect util::init_SDL_Rect(int x, int y, int w, int h) {
	SDL_Rect r;
	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;
	return r;
}

void util::copy_SDL_Rect(SDL_Rect dest, const SDL_Rect src) {
	dest.x = src.x;
	dest.y = src.y;
	dest.w = src.w;
	dest.h = src.h;
}