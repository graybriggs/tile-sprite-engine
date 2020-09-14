#pragma once
#ifndef TILE_H
#define TILE_H

#include <SDL.h>

#include <memory>
#include <vector>

#include "constants.h"
#include "entity.h"
#include "utility.h"

typedef std::vector<SDL_Event> EventList;
class ImageAssetResource;

class Tile : public Entity {
public:

	Tile(ImageAssetResource* img, float x, float y, int w, int h);

	void setBoundingBox(float x, float y, int w, int h);
	void setBoundingBox(util::FRect rect);

	void update(float delta, float cur_time);

	void animationLoopInterval(float interval);
	void animAddFrameClip(SDL_Rect clip);
	void forceFrameClip(SDL_Rect clip);

	SDL_Rect getImageClip() const;

private:
	bool can_animate;
	SDL_Rect cur_frame_clip;
	std::vector<SDL_Rect> frame_clips;
	int frame_number;
	float last_time;
	int animation_interval_time;
};


#endif