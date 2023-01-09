#pragma once

#include <memory>
#include <vector>

class ImageAssetResource;
class Tile;
class Video;


struct AssetResources {

	
	void add_image_asset(ImageAssetResource* iar) {
		image_asset_resources.push_back(iar);
	}

	std::vector<ImageAssetResource*> image_asset_resources;
};

void load_asset_resources(AssetResources& ar);
void load_tiles(AssetResources& ar, std::vector<std::unique_ptr<Tile>>& tiles);