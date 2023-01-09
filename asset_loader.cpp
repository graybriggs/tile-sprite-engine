
#include "image_asset_resource.h"
#include "asset_loader.h"
#include "video.h"
#include "tile.h"

#include "file_read_main.h" // change this and remove TileRawData from it

#include <memory>
#include <vector>
#include <unordered_map>

void load_asset_resources(AssetResources& ar) {
	//ar.image_asset_resource = ImageAssetResource(*video, "./images/smb_tilesheet.bmp");
	
}

// Load raw tiles from file
// load their image asset
// convert to normal tiles
// return to calling program

void load_tiles(AssetResources& ar, std::vector<std::unique_ptr<Tile>>& tiles) {

	std::unordered_map<std::string, ImageAssetResource> spritesheets;

	std::vector<TileRawInfo> raw_tiles = read_tile_file("test_map.txt");

	//ImageAssetResource iar;

	for (const auto& rt : raw_tiles) {

		
		if (rt.tile_type == TileType::STATC) {
			tiles.push_back(std::make_unique<Tile>(ar.image_asset_resources[0], rt));
			
		}
		else if (rt.tile_type == TileType::ANIM) {
			
			tiles.push_back(std::make_unique<Tile>(ar.image_asset_resources[1], rt));

			//anim_res.setClipBox(util::init_SDL_Rect(100, 100, 32, 32));
			

			/*
			auto anim_tile = std::make_unique<Tile>(&p_ar, 100, 100, 32, 32);
		
			anim_tile->setAnimatable(true);
			anim_tile->animAddFrameClip(util::init_SDL_Rect(0, 0, 32, 32));
			anim_tile->animAddFrameClip(util::init_SDL_Rect(32, 0, 32, 32));
			anim_tile->animAddFrameClip(util::init_SDL_Rect(64, 0, 32, 32));
			anim_tile->animAddFrameClip(util::init_SDL_Rect(0, 32, 32, 32));
			anim_tile->animAddFrameClip(util::init_SDL_Rect(32, 32, 32, 32));
			anim_tile->animAddFrameClip(util::init_SDL_Rect(64, 32, 32, 32));
			anim_tile->animationLoopInterval(250);
			*/

			/*
			auto anim_tile2 = std::make_unique<Tile>(Tile(p_ar, 200, 200, 32, 32));
			anim_tile2->setAnimatable(true);
			anim_tile2->animAddFrameClip(util::init_SDL_Rect(32, 0, 32, 32));
			anim_tile2->animAddFrameClip(util::init_SDL_Rect(0, 32, 32, 32));
			anim_tile2->animAddFrameClip(util::init_SDL_Rect(64, 32, 32, 32));
			anim_tile2->animationLoopInterval(300);

			util::Rect re = tiles[100]->getBoundingBox();
			anim_tile->setBoundingBox(re.x_pos, re.y_pos, re.w, re.h);
			tiles[100] = std::move(anim_tile);

			util::Rect re2 = tiles[200]->getBoundingBox();
			anim_tile2->setBoundingBox(re2.x_pos, re2.y_pos, re2.w, re2.h);
			tiles[200] = std::move(anim_tile2);
			*/


			//tiles.push_back(anim_tile);
		}
	}
}
