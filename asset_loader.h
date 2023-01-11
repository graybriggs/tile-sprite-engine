#pragma once

#include <memory>
#include <string>
#include <map>
#include <utility>
#include <vector>

struct Comparer
{
public:
	bool operator()(const std::string& x, const std::string& y) const
	{
		return x.compare(y) == 0;
	}
};

class ImageAssetResource;
class Tile;

struct AssetResourcesStore {

	void add_image_asset(ImageAssetResource* iar);
	void add_tile_map(const std::string map_path_name);


	std::vector<ImageAssetResource*> image_asset_resources;
	std::vector<std::string> tile_map_data;
};


void load_tiles(AssetResourcesStore& ar, std::vector<std::unique_ptr<Tile>>& tiles);