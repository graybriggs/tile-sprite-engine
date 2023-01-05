#include "entity.h"
#include "utility.h"

Entity::Entity(ImageAssetResource* iar, const util::Rect bb)
	: image(iar),
	bounding_box(bb)
{
}

Entity::~Entity() {

}

void Entity::moveTo(const double x, const double y) {
	bounding_box.x_pos = x;
	bounding_box.y_pos = y;
}

void Entity::moveBy(const double x, const double y) {

	bounding_box.x_pos += x;
	bounding_box.y_pos += y;
}

void Entity::setPosition(const double x, const double y) {
	moveTo(x, y);
}

void Entity::setPosition(const SDL_Rect r) {
	bounding_box.x_pos = r.x;
	bounding_box.y_pos = r.y;
}

void Entity::setPosition(const util::Rect pos) {
	bounding_box.x_pos = pos.x_pos;
	bounding_box.x_pos = pos.y_pos;
}

util::Rect Entity::getBoundingBox() {
	return bounding_box;
}

SDL_Rect Entity::getSDL_Rect() {
	return util::init_SDL_Rect(
		bounding_box.x_pos,
		bounding_box.y_pos,
		bounding_box.w,
		bounding_box.h
	);
}

void Entity::setBoundingBox(util::Rect box) {
	bounding_box = box;
}

void Entity::setBoundingBox(SDL_Rect box) {
	bounding_box.x_pos = box.x;
	bounding_box.y_pos = box.y;
	bounding_box.w = box.w;
	bounding_box.h = box.h;
}

void Entity::setBoundingBox(float x, float y, int w, int h) {
	bounding_box.x_pos = x;
	bounding_box.y_pos = y;
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
