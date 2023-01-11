
#include "image_asset_resource.h"
#include "asset_loader.h"
#include "tile.h"

#include "file_read_main.h" // change this and remove TileRawData from it




void AssetResourcesStore::add_image_asset(ImageAssetResource* iar) {
	std::string key = iar->getResourcePath();
	image_asset_resources.push_back(iar);
}

void AssetResourcesStore::add_tile_map(const std::string map_path_name) {
	tile_map_data.push_back(map_path_name);
}

// Load raw tiles from file
// load their image asset
// convert to normal tiles
// return to calling program


void load_tiles(AssetResourcesStore& ar, std::vector<std::unique_ptr<Tile>>& tiles) {

		std::vector<TileRawInfo> raw_tiles = read_tile_file(ar.tile_map_data[0]);

		for (const auto& rt : raw_tiles) {
			tiles.push_back(std::make_unique<Tile>(ar.image_asset_resources[0], rt));
			
		}
}
