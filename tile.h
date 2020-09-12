#pragma once
#ifndef TILE_H
#define TILE_H

#include <SDL.h>

#include "constants.h"
#include "utility.h"

class ImageAssetResource;

class Tile {
public:

	Tile(ImageAssetResource* img, float x, float y, int w, int h);
	
	ImageAssetResource* getImageAssetResource() const;
	util::FRect getBoundingBox() const;

private:
	ImageAssetResource* image;
	SDL_Rect img_clip;

	util::FRect bounding_box;
};


#endif