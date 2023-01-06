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
	void setBoundingBox(util::Rect rect);

	void update(float delta, float cur_time);

	void setCollidable(bool);
	bool getIsCollidable() const;
	void setAnimatable(bool);
	bool getCanAnimate() const;
	int getNumFrames() const;
	int getFrameDelayTime() const;
	void animationLoopInterval(float interval);
	void animAddFrameClip(SDL_Rect clip);
	void forceFrameClip(SDL_Rect clip);
	std::vector<SDL_Rect> getFrameClips();
	SDL_Rect getImageClip() const;
	std::string getTileImagePath();

private:
	bool is_collidable;
	bool can_animate;
	SDL_Rect cur_frame_clip;
	std::vector<SDL_Rect> frame_clips;
	int animation_interval_time;

	int frame_number;
	float last_time;
};


#endif