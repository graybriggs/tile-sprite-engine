
#include "entity.h"
#include "image_asset_resource.h"
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

/*
void VideoDriver::drawSprite(const ImageAssetResource* img, SDL_Rect position) {
	// position = bounding box
	SDL_RenderCopy(renderer, img->getTexture(), &img->getClipBox(), &position);
}
*/

void VideoDriver::drawSprite(Entity* entity) {

	SDL_Texture* tex = entity->getImageAssetResource()->getTexture();

	SDL_Rect r = entity->getSDL_Rect();
	// needs to remain for duration of SDL_RenderCopy
	SDL_Rect clip = entity->getImageClip();

	SDL_RenderCopy(renderer, tex, &clip, &r);
}

/*
void VideoDriver::drawRotatedSprite(const ImageAssetResource* img, const SDL_Rect position, const double angle, const SDL_Point rot_point) {

	//SDL_RenderCopyEx(renderer, img->getTexture(), &img->getClipBox(), &position, angle, &rot_point, SDL_FLIP_NONE);
}
*/

void VideoDriver::drawRectangle(int x, int y, int w, int h, int colorkey) {

	SDL_Rect rect = { x, y, w, h };

	//SDL_RenderDrawRect(renderer, &rect);
	SDL_RenderFillRect(renderer, &rect);
}

void VideoDriver::drawRectangle(util::Rect rect, int colorkey) {
	
	drawRectangle((int)rect.x_pos, (int)rect.y_pos, rect.w, rect.h, colorkey);
}