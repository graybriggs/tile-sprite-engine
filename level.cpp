
#include "level.h"

#include "entity.h"
#include "image_asset_resource.h"
#include "player.h"
#include "tile.h"
#include "video.h"

void Level::setup_level(VideoDriver* video) {

	iar1 = std::make_unique<ImageAssetResource>(*video, "./images/smb_tilesheet.bmp");
	//iar.push_back(std::make_unique<ImageAssetResource>(*video, "./images/tile_anim.bmp"));

	asset_resources.add_image_asset(iar1.get());
	//asset_resources.add_image_asset(iar2.get());
	asset_resources.add_tile_map("test_map.txt");


	std::vector<std::unique_ptr<Tile>> tiles;
	load_tiles(asset_resources, tiles);
	
}


void Level::update_level(float delta, float cur_time) {
	for (auto& t : tiles) {
		t->update(delta, cur_time);
	}
}

void Level::level_player_logic(Player* player) {

}

void Level::level_entity_logic(Entity* entities) {

}

void Level::render_level(VideoDriver* video) {
	for (auto& t : tiles) {
		video->drawSprite(t.get());
		//video->drawRotatedSprite(t->getImageAssetResource(), t->getBoundingBox().toSDL_Rect(), 45, p);
	}
}