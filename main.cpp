
#include <cstring> // memset
#include <cmath>
#include <memory>
#include <vector>

#include "asset_loader.h"
#include "camera.h"
#include "constants.h"
#include "device.h"
#include "file_read_main.h"
#include "input.h"
#include "level.h"
#include "player.h"
#include "utility.h"
#include "video.h"

#include "image_asset_resource.h"

int main(int argc, char* args[]) {

	auto device = createDevice(DriverType::SDL2, constants::SCREEN_WIDTH, constants::SCREEN_HEIGHT, false);
	auto video = device->getVideoDriver();
	

	auto camera = std::make_unique<Camera>();
	camera->setCameraType(Camera::CameraType::LOCK_ON);
	camera->setScrollCollisionBounds(util::init_SDL_Rect(200, 150, constants::SCREEN_WIDTH - 200, constants::SCREEN_HEIGHT - 150));

	auto player = std::make_unique<Player>();
	player->setScreenPosition(600, 425);

	auto current_level = std::make_unique<Level>();
	current_level->setup_level(video.get());

	float delta = (float)SDL_GetTicks();
	float cur_time = (float)SDL_GetTicks();

	while (device->run()) {

		cur_time = (float)SDL_GetTicks();

		//input.moveTiles(device->getFrameEvents(), tiles);
		player->handleInput(device->getFrameEvents());

		//tiles[100]->update(delta, cur_time);

		current_level->update_level(delta, cur_time);
		player->update(delta);
		current_level->level_player_logic(player.get());

		//camera->moveTiles(device->getFrameEvents(), tiles, *player.get());

		video->beginScene();
		
		current_level->render_level(video.get());
		video->drawRectangle(player->getBoundingBox(), 0xFF000000);

		//video->drawSprite(&anim_tile);
		video->endScene();

		device->clearFrameEvents();
	}

	device->drop();

	return 0;
}