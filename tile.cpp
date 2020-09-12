
#include "image_asset_resource.h"
#include "tile.h"


Tile::Tile(ImageAssetResource* img, float x, float y, int w = constants::TILE_WIDTH, int h = constants::TILE_HEIGHT)
	: image(img)
{
	bounding_box.setFRect(x, y, w, h);
}

ImageAssetResource* Tile::getImageAssetResource() const {
	return image;
}

util::FRect Tile::getBoundingBox() const {
	return bounding_box;
}