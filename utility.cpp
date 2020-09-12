#include <SDL.h>

#include "utility.h"

util::FRect::FRect()
	: x_pos(0.0f), y_pos(0.0f), w(0), h(0)
{}

util::FRect::FRect(float x, float y, int w, int h)
	: x_pos(x), y_pos(y), w(w), h(h)
{
}

util::FRect util::FRect::getFrect() const {
	return util::FRect(this->x_pos, this->y_pos, this->w, this->h);
}

void util::FRect::setFRect(float x, float y, int width, int height) {
	x_pos = x;
	y_pos = y;
	w = width;
	h = height;
}

SDL_Rect util::FRect::toSDL_Rect() const {
	SDL_Rect r;
	r.x = static_cast<int>(x_pos);
	r.y = static_cast<int>(y_pos);
	r.w = static_cast<int>(w);
	r.h = static_cast<int>(h);
	return r;
}

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