
#include <cstring> // memset
#include <cmath>
#include <memory>
#include <vector>

#include "asset_loader.h"
#include "camera.h"
#include "device.h"
#include "file_read_main.h"
#include "input.h"
#include "player.h"
#include "tile.h"
#include "utility.h"
#include "video.h"

#include "image_asset_resource.h"

int main(int argc, char* args[]) {

	auto device = createDevice(DriverType::SDL2, constants::SCREEN_WIDTH, constants::SCREEN_HEIGHT, false);
	auto video = device->getVideoDriver();
	

	auto camera = std::make_unique<Camera>();
	camera->setCameraType(Camera::CameraType::LOCK_ON);
	camera->setScrollCollisionBounds(util::init_SDL_Rect(200, 150, constants::SCREEN_WIDTH - 200, constants::SCREEN_HEIGHT - 150));

	std::vector<TileRawInfo> test = read_tile_file("test_map.txt");

	SDL_Rect r = util::init_SDL_Rect(100, 100, 100, 100);


	//auto imr = std::make_unique<ImageAssetResource>(video.get(), "./images/smb_tilesheet.bmp");
	//auto imr2 = std::make_unique<ImageAssetResource>(video.get(), "./images/tile_anim.bmp");

	ImageAssetResource imr(*video, "./images/smb_tilesheet.bmp");
	ImageAssetResource imr2(*video, "./images/tile_anim.bmp");

	AssetResources asset_resources;
	asset_resources.add_image_asset(&imr);
	asset_resources.add_image_asset(&imr2);


	std::vector<std::unique_ptr<Tile>> tiles;
	load_tiles(asset_resources, tiles);

	/*
	for (const auto& tile : test) {
		tiles.push_back(std::make_unique<Tile>(&imr, tile.bb_x, tile.bb_y, 32, 32));
	}
	*/
	/*
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 32; ++j) {
			tiles.push_back(std::make_unique<Tile>(&imr, j * 32.0f, i * 32.0f, 32, 32));
		}
	}
	*/

	//write_tile_data(tiles);

	SDL_Point p;
	p.x = 100;
	p.y = 100;

	double ang = 0.0;

	float delta = (float)SDL_GetTicks();
	float cur_time = (float)SDL_GetTicks();


	auto player = std::make_unique<Player>();
	player->setScreenPosition(600, 425);

	

	while (device->run()) {

		cur_time = (float)SDL_GetTicks();

		//input.moveTiles(device->getFrameEvents(), tiles);
		player->handleInput(device->getFrameEvents());

		//tiles[100]->update(delta, cur_time);

		for (auto& t : tiles) {
			t->update(delta, cur_time);
		}
		player->update(delta);

		camera->moveTiles(device->getFrameEvents(), tiles, *player.get());

		video->beginScene();
		

		for (auto& t : tiles) {
			video->drawSprite(t.get());
			//video->drawRotatedSprite(t->getImageAssetResource(), t->getBoundingBox().toSDL_Rect(), 45, p);
		}

		video->drawRectangle(player->getBoundingBox(), 0xFF000000);

		

		//video->drawSprite(&anim_tile);
		video->endScene();

		++ang;
		if (ang > 360.0)
			ang = 0.0;

		device->clearFrameEvents();
	}

	device->drop();

	return 0;
}