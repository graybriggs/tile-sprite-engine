
#include <cmath>
#include <memory>
#include <print>
#include <vector>

#include "asset_loader.h"
#include "camera.h"
#include "globals.h"
#include "device.h"
#include "file_read_main.h"
#include "image_asset_resource.h"
#include "input.h"
#include "level.h"
#include "player.h"
#include "tile.h"
#include "utility.h"
#include "video.h"

#include "collision.h"

int main(int argc, char* args[]) {


	auto s = file_read("./test_map.txt");
	std::println("{}", s);
	auto v = file_read_lines(s);
	auto tri = read_tile_file("./test_map.txt");



	auto device = createDevice(VideoDriverType::SDL2, globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, false);
	auto video = device->getVideoDriver();

	auto player = std::make_unique<Player>();
	//player->set_relative_position(600, 425);

	//auto current_level = std::make_unique<Level>();
	//current_level->setup_level(video.get());

	auto delta = device->get_current_time();
	auto cur_time = device->get_current_time();

	std::string ts_path = "./images/smb_tilesheet.bmp";
	auto iar = std::make_unique<ImageAssetResource>(video.get(), ts_path);


	// Tile tile(iar.get(), 256, 256, 32, 32);
	// tile.setImageClip(SDL_Rect{0 ,0,32,32});

	// Tile collision_tile(iar.get(), 128, 256, 32, 32);
	// collision_tile.setImageClip(SDL_Rect{64,0,32,32});
	// collision_tile.setCollidable(true);


	//std::vector<Tile> tiles {tile, collision_tile };
	std::vector<Tile> tiles;
	//tiles.push_back(test_read_tile);
	for (auto rti : tri) {
		Tile temp(iar.get(), rti.bb_x, rti.bb_y, rti.bb_w, rti.bb_h);
		SDL_Rect img_clip{rti.tilesheet_x, rti.tilesheet_y, 32, 32};
		temp.setImageClip(img_clip);
		
		if (rti.is_collide) {
			temp.setCollidable(true);
			std::println("setColliadable(true);");
		}
		else {
			temp.setCollidable(false);
		}
		tiles.push_back(temp);
	}

	for (auto t : tiles) {
		if (t.getIsCollidable()) {
			std::println("Collidable");
			
		}
		else {
			std::println("not collidable");
		}
	}

	while (device->run()) {

		cur_time = device->get_current_time();

		//input.moveTiles(device->getFrameEvents(), tiles);
		//player->handleInput(device->getFrameEvents());
		device->input_pump_events();
		player->handleInput();
		player->update(delta);
		//current_level->update_level(delta, cur_time);
		//current_level->level_player_logic(player.get());

		for (auto t : tiles) {

			const SDL_Rect& pbb = player->getBoundingBox();
			const SDL_Rect& tbb = t.getBoundingBox();

			//ayer->tile_collide(t);
			// if (aabb_collision(pbb, tbb)) {
			// 	if (t.getIsCollidable()) {
			// 		std::cout << "collision" << std::endl;
			// 	}
			// }
			
			if (t.getIsCollidable()) {
				player->tile_collide(t);
			}
		}
		

		video->beginScene();
		
		//current_level->render_level(video.get());
		video->setDrawColor(0, 0, 255, 255);
		video->setDrawColor(42, 69, 1, 255);
		video->drawRectangle(800, 800, 64, 64);
		//video->drawSprite(&anim_tile);
		
		for (auto t : tiles) {
			video->drawSprite(&t);
		}

		//video->drawSprite(&tile);
		//video->drawSprite(&collision_tile);
		
		video->drawRectangle(player->getBoundingBox());

		video->endScene();

		//device->clearFrameEvents();
	}

	video->destory();
	device->drop();

	return 0;
}