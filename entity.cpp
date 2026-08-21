#include "entity.h"
#include "utility.h"

Entity::Entity(ImageAssetResource* iar, const SDL_Rect bb)
	: image(iar),
	bounding_box(bb),
	image_clip_box({0,0,32,32})
{
}

Entity::~Entity() {

}

void Entity::moveTo(const float x, const float y) {
	bounding_box.x = x;
	bounding_box.y = y;
}

void Entity::moveBy(const float x, const float y) {
	bounding_box.x += x;
	bounding_box.y += y;
}

void Entity::setPosition(const float x, const float y) {
	moveTo(x, y);
}

void Entity::setPosition(const SDL_Rect r) {
	bounding_box.x = (float)r.x;
	bounding_box.y = (float)r.y;
}

void Entity::setPosition(const util::Rect pos) {
	bounding_box.x = pos.x_pos;
	bounding_box.y = pos.y_pos;
}

SDL_Rect Entity::getBoundingBox() const {
	return bounding_box;
}

SDL_Rect Entity::getSDL_Rect() const {
	return util::init_SDL_Rect(
		bounding_box.x,
		bounding_box.y,
		bounding_box.w,
		bounding_box.h
	);
}

void Entity::setBoundingBox(SDL_Rect box) {
	bounding_box = box;
}

void Entity::setBoundingBox(float x, float y, int w, int h) {
	bounding_box.x = x;
	bounding_box.y = y;
	bounding_box.w = w;
	bounding_box.h = h;

}

ImageAssetResource* Entity::getImageAssetResource() const {
	return image;
}

SDL_Rect Entity::getImageClip() const {
	return image_clip_box;
}

void Entity::setImageClip(SDL_Rect clip) {
	image_clip_box = clip;
}
