
#include "level.h"

#include "collision.h"
#include "entity.h"
#include "image_asset_resource.h"
#include "player.h"
#include "tile.h"
#include "video.h"

#include "camera.h"

void Level::setup_level(VideoDriver* video) {

	camera = std::make_unique<Camera>();
	camera->setCameraType(Camera::CameraType::LOCK_ON);
	camera->setScrollCollisionBounds(util::init_SDL_Rect(200, 150, constants::SCREEN_WIDTH - 200, constants::SCREEN_HEIGHT - 150));

	iar1 = std::make_unique<ImageAssetResource>(*video, "./images/smb_tilesheet.bmp");
	//iar.push_back(std::make_unique<ImageAssetResource>(*video, "./images/tile_anim.bmp"));

	asset_resources.add_image_asset(iar1.get());
	//asset_resources.add_image_asset(iar2.get());
	asset_resources.add_tile_map("test_map.txt");

	load_tiles(asset_resources, tiles);	
}


void Level::update_level(float delta, float cur_time) {


	for (auto& t : tiles) {
		t->update(delta, cur_time);
	}
}

void Level::level_player_logic(const Player* player) {

	camera->moveTiles(tiles, player);

	for (auto& t : tiles) {
		if (t->getIsCollidable()) {
			if (aabb_collision(t->getBoundingBox().toSDL_Rect(), player->getBoundingBox().toSDL_Rect())) {
				//player->stop();
			}
		}
	}

}

void Level::level_entity_logic(Entity* entities) {

}

void Level::render_level(VideoDriver* video) {
	for (auto& t : tiles) {
		video->drawSprite(t.get());
		//video->drawRotatedSprite(t->getImageAssetResource(), t->getBoundingBox().toSDL_Rect(), 45, p);
	}
}