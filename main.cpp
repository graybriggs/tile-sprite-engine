
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

	auto device = createDevice(VideoDriverType::SDL2, constants::SCREEN_WIDTH, constants::SCREEN_HEIGHT, false);
	auto video = device->getVideoDriver();

	auto player = std::make_unique<Player>();
	player->set_relative_position(600, 425);

	auto current_level = std::make_unique<Level>();
	current_level->setup_level(video.get());

	float delta = static_cast<float>(device->get_current_time());
	float cur_time = static_cast<float>(device->get_current_time());

	while (device->run()) {

		cur_time = static_cast<float>(device->get_current_time());

		//input.moveTiles(device->getFrameEvents(), tiles);
		//player->handleInput(device->getFrameEvents());

		current_level->update_level(delta, cur_time);
		player->update(delta);
		current_level->level_player_logic(player.get());

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