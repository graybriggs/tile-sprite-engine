#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <SDL.h>

#include "utility.h"

class ImageAssetResource;

class Entity {

public:
	Entity(ImageAssetResource* s, const util::Rect bb);
	virtual ~Entity();

	void moveTo(const double x, const double y);
	void moveBy(const double x, const double y);
	void setPosition(const double x, const double y);
	void setPosition(const SDL_Rect);
	void setPosition(const util::Rect);
	util::Rect getBoundingBox();
	SDL_Rect getSDL_Rect();
	void setBoundingBox(float x, float y, int w, int h);
	void setBoundingBox(SDL_Rect box);
	void setBoundingBox(util::Rect rect);
	ImageAssetResource* getImageAssetResource() const;
	SDL_Rect getImageClip() const;
	void setImageClip(SDL_Rect);

protected:

	SDL_Rect image_clip_box;
	util::Rect bounding_box;
	ImageAssetResource* image;
};

#endif
