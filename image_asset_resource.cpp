
#include "image_asset_resource.h"


#include <stdexcept>
#include <utility>

#include "video.h"

ImageAssetResource::ImageAssetResource() {}

ImageAssetResource::ImageAssetResource(const VideoDriver& driver, const std::string path) {
	loadSprite(driver, path);
}

ImageAssetResource::~ImageAssetResource() {
	SDL_DestroyTexture(texture);
}

ImageAssetResource::ImageAssetResource(const ImageAssetResource&& other) {
	if (this != &other) {
		texture = std::move(other.texture);
	}
}
ImageAssetResource& ImageAssetResource::operator=(ImageAssetResource&& other) {
	if (this != &other) {
		texture = std::move(other.texture);
	}
	return *this;
}



int ImageAssetResource::load_spritesheet(SDL_Renderer* renderer, SDL_Texture** spritesheet, std::string img_path) {

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

void ImageAssetResource::loadSprite(const VideoDriver& driver, std::string path) {

	load_spritesheet(driver.getRenderer(), &texture, path);
}


SDL_Texture* ImageAssetResource::getTexture() const {
	return texture;
}

SDL_Rect ImageAssetResource::getClipBox() const {
	return clip_box;
}

void ImageAssetResource::setClipBox(SDL_Rect r) {
	clip_box.x = r.x;
	clip_box.y = r.y;
	clip_box.w = r.w;
	clip_box.h = r.h;
}

void ImageAssetResource::setTexture(SDL_Texture* tex) {
	texture = tex;
}
