
#include "sprite.h"


#include <stdexcept>
#include <utility>

#include "video.h"
#include "sprite.h"


int Sprite::load_spritesheet(SDL_Renderer* renderer, SDL_Texture** spritesheet, std::string img_path) {

	SDL_Surface* surface_img = SDL_LoadBMP(img_path.c_str());
	if (surface_img == nullptr) {
		fprintf(stderr, "Error loading image file");
		throw - 1;
	}

	// specify a color key for transparent pixels - here it's 0xFF00FF - bright pink
	Uint32 colorkey = SDL_MapRGB(surface_img->format, 0xFF, 0x00, 0xFF);
	SDL_SetColorKey(surface_img, SDL_TRUE, colorkey);

	*spritesheet = SDL_CreateTextureFromSurface(renderer, surface_img);
	SDL_FreeSurface(surface_img);

	if (spritesheet == nullptr) {
		throw - 1;
	}
	return 0;
}

void Sprite::loadSprite(const VideoDriver& driver, std::string path) {

	load_spritesheet(driver.getRenderer(), &texture, path);
	
}

Sprite::~Sprite() {
	SDL_DestroyTexture(texture);
}


SDL_Texture* Sprite::getTexture() const {
	return texture;
}

SDL_Rect Sprite::getClipBox() const {
	return clip_box;
}

void Sprite::setClipBox(SDL_Rect r) {
	clip_box.x = r.x;
	clip_box.y = r.y;
	clip_box.w = r.w;
	clip_box.h = r.h;
}

void Sprite::setTexture(SDL_Texture* tex) {
	texture = tex;
}
