
#ifndef TEXTURE_H
#define TEXTURE_H
#pragma once

#include <SDL.h>

#include <memory>
#include <string>

class VideoDriver;

class Sprite {
public:

	// note: write copy/move/etc constructors

	~Sprite();
	SDL_Texture* getTexture() const;

	Sprite* getSprite() const;
	SDL_Rect getClipBox() const;
	void setClipBox(SDL_Rect r);
	void setTexture(SDL_Texture* tex);

	void loadSprite(const VideoDriver& driver, std::string path);

private:

	int load_spritesheet(SDL_Renderer* renderer, SDL_Texture** sprite, std::string img_path);

	SDL_Rect clip_box; // apparently this doesn't work
	SDL_Texture* texture;
};


#endif
