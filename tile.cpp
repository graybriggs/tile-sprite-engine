
#include "image_asset_resource.h"
#include "tile.h"


Tile::Tile(ImageAssetResource* img, float x, float y, int w = constants::TILE_WIDTH, int h = constants::TILE_HEIGHT)
	: Entity(img, util::Rect(x, y, w, h)),
	is_collidable(false),
	can_animate(false),
	animation_interval_time(0),
	frame_number(0)
{
	bounding_box.setRect(x, y, w, h);
	setImageClip(util::init_SDL_Rect(0, 0, 32, 32));
	last_time = (float)SDL_GetTicks();

	//cur_frame_clip = image->getClipBox(); // hack
	//cur_frame_clip = 
}

void Tile::setBoundingBox(const float x, float y, int w, int h) {
	bounding_box.x_pos = x;
	bounding_box.y_pos = y;
	bounding_box.w = w;
	bounding_box.h = h;
}

void Tile::setBoundingBox(const util::Rect rect) {
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

void Tile::setCollidable(bool b) {
	is_collidable = b;
}
bool Tile::getIsCollidable() const {
	return is_collidable;
}

void Tile::setAnimatable(bool b) {
	can_animate = b;
}

bool Tile::getCanAnimate() const {
	return can_animate;
}

int Tile::getNumFrames() const {
	return static_cast<int>(frame_clips.size());
}

int Tile::getFrameDelayTime() const {
	return animation_interval_time;
}

void Tile::animationLoopInterval(float interval) {

	if (interval >= 0)
		animation_interval_time = (float)interval;
	else
	{
		// throw what are you doing?
	}
}

void Tile::animAddFrameClip(SDL_Rect clip) {
	frame_clips.push_back(clip);
	cur_frame_clip = frame_clips.back();
}

void Tile::forceFrameClip(SDL_Rect clip) {
}

std::vector<SDL_Rect> Tile::getFrameClips() const {
	return frame_clips;
}

SDL_Rect Tile::getImageClip() const {
	return cur_frame_clip;
}

std::string Tile::getTileImagePath() const {
	return getImageAssetResource()->getResourcePath();
}