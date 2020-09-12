
#ifndef TEXTURE_H
#define TEXTURE_H
#pragma once

#include <SDL.h>

#include <memory>
#include <string>

class VideoDriver;

class ImageAssetResource {
public:

	// note: write copy/move/etc constructors

	ImageAssetResource();
	ImageAssetResource(const VideoDriver& driver, const std::string path);
	~ImageAssetResource();

	ImageAssetResource(const ImageAssetResource& other) = delete;
	ImageAssetResource& operator=(const ImageAssetResource& other) = delete;
	ImageAssetResource(const ImageAssetResource&& other);
	ImageAssetResource& operator=(ImageAssetResource&& other);

	void loadSprite(const VideoDriver& driver, const std::string path); // re constructor

	SDL_Texture* getTexture() const;
	ImageAssetResource* getSprite() const;
	SDL_Rect getClipBox() const;
	void setClipBox(SDL_Rect r);
	void setTexture(SDL_Texture* tex);

private:

	int load_spritesheet(SDL_Renderer* renderer, SDL_Texture** sprite, std::string img_path);

	SDL_Rect clip_box; // apparently this doesn't work
	SDL_Texture* texture;
};


#endif
