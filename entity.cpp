#include "entity.h"

Entity::Entity(ImageAssetResource* iar, const util::FRect bb)
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

void Entity::setPosition(const util::FRect pos) {
	bounding_box.x_pos = pos.x_pos;
	bounding_box.x_pos = pos.y_pos;
}

util::FRect Entity::getBoundingBox() const {
	return bounding_box;
}

void Entity::setBoundingBox(util::FRect box) {
	bounding_box = box;
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
