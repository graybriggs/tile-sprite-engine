
#include "image_asset_resource.h"
#include "tile.h"


Tile::Tile(ImageAssetResource* img, float x, float y, int w = constants::TILE_WIDTH, int h = constants::TILE_HEIGHT)
	: Entity(img, util::FRect(x,y,w,h)),
	can_animate(false),
	animation_interval_time(0),
	frame_number(0)
{
	bounding_box.setFRect(x, y, w, h);
	setImageClip(util::init_SDL_Rect(0, 0, 32, 32));
	last_time = SDL_GetTicks();

	cur_frame_clip = image->getClipBox(); // hack
}

void Tile::setBoundingBox(const float x, float y, int w, int h) {
	bounding_box.x_pos = x;
	bounding_box.y_pos = y;
	bounding_box.w = w;
	bounding_box.h = h;
}

void Tile::setBoundingBox(const util::FRect rect) {
	bounding_box = rect;
}

void Tile::update(float delta, float cur_time) {

	if (can_animate) {

		if (cur_time > last_time + animation_interval_time) {

			if (frame_number > frame_clips.size() - 2)
				frame_number = 0;
			else
				++frame_number;

			cur_frame_clip = frame_clips[frame_number];
			setImageClip(cur_frame_clip);

			last_time = cur_time;
		}
	}
}

void Tile::setAnimatable(bool b) {
	can_animate = b;
}

void Tile::animationLoopInterval(float interval) {

	if (interval >= 0)
		animation_interval_time = interval;
	else
	{
		// throw what are you doing?
	}
}

void Tile::animAddFrameClip(SDL_Rect clip) {
	frame_clips.push_back(clip);
}

SDL_Rect Tile::getImageClip() const {
	return cur_frame_clip;
}