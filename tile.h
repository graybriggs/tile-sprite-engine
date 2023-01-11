#pragma once
#ifndef TILE_H
#define TILE_H

#include <SDL.h>

#include <memory>
#include <string>
#include <vector>

#include "constants.h"
#include "entity.h"
#include "utility.h"

typedef std::vector<SDL_Event> EventList;
class ImageAssetResource;
//class TileRawInfo;
#include "file_read_main.h"

class Tile : public Entity {
public:

	Tile(ImageAssetResource* iar, float x, float y, int w, int h);
	Tile(ImageAssetResource* iar, const TileRawInfo& tri);

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
	std::vector<SDL_Rect> getFrameClips() const;
	SDL_Rect getImageClip() const;
	std::string getTileImagePath() const;

private:
	// data
	bool is_collidable;
	bool can_animate;
	std::vector<SDL_Rect> frame_clips;
	int animation_interval_time;

	// state
	SDL_Rect cur_frame_clip;
	int frame_number;
	float last_time;
};


#endif