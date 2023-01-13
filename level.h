#pragma once


#include <memory>
#include <vector>

#include "asset_loader.h"
#include "tile.h"

//class AssetResourcesStore;
class Entity;
class ImageAssetResource;
class Player;
class Tile;
class VideoDriver;

struct Level {

	void setup_level(VideoDriver* driver);
	void update_level(float delta, float cur_time);
	void level_player_logic(Player* player);
	void level_entity_logic(Entity* entities);
	void render_level(VideoDriver* video);

	std::unique_ptr<ImageAssetResource> iar1;

	AssetResourcesStore asset_resources;
	std::vector<std::unique_ptr<Tile>> tiles;
};

