#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <SDL.h>

#include "utility.h"

class ImageAssetResource;

class Entity {

public:
	Entity(ImageAssetResource* s, const util::FRect bb);
	virtual ~Entity();

	void moveTo(const double x, const double y);
	void moveBy(const double x, const double y);
	void setPosition(const double x, const double y);
	void setPosition(const SDL_Rect);
	void setPosition(const util::FRect);
	util::FRect getBoundingBox() const;
	void setBoundingBox(float x, float y, int w, int h);
	void setBoundingBox(util::FRect rect);
	ImageAssetResource* getImageAssetResource() const;
	SDL_Rect getImageClip() const;
	void setImageClip(SDL_Rect);

protected:

	SDL_Rect image_clip_box;
	util::FRect bounding_box;
	ImageAssetResource* image;
};

#endif
