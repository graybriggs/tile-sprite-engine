
#include "sprite.h"
#include "utility.h"
#include "video.h"

#include <SDL.h>

VideoDriver::~VideoDriver() {
	SDL_DestroyRenderer(renderer);
}

void VideoDriver::beginScene() {
	SDL_RenderClear(renderer);
}

void VideoDriver::beginScene(int r, int g, int b) {
	SDL_RenderClear(renderer);
}

void VideoDriver::endScene() {
	SDL_RenderPresent(renderer);
}

SDL_Renderer* VideoDriver::getRenderer() const {
	return renderer;
}

void VideoDriver::drawAll() {
	// TODO
}

void VideoDriver::drawSprite(const Sprite* sprite, SDL_Rect position) {
	// position = bounding box
	SDL_RenderCopy(renderer, sprite->getTexture(), &sprite->getClipBox(), &position);
}

void VideoDriver::drawRectangle(int x, int y, int w, int h, int colorkey) {

	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	SDL_RenderDrawRect(renderer, &rect);
}