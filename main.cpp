
#include <cstring> // memset
#include <cmath>
#include <memory>
#include <vector>

#include "device.h"
#include "input.h"
#include "tile.h"
#include "utility.h"
#include "video.h"

#include "image_asset_resource.h"

int main(int argc, char* args[]) {

	auto device = createDevice(DriverType::SDL2, 1200, 750, false);
	auto video = device->getVideoDriver();

	Input input;

	SDL_Rect r = util::init_SDL_Rect(100, 100, 100, 100);

	ImageAssetResource imr(*video, "./images/jfr_box_tex1.bmp");
	imr.setClipBox(util::init_SDL_Rect(0, 0, 32, 32));

	std::vector<std::unique_ptr<Tile>> tiles;

	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 32; ++j) {
			tiles.push_back(std::make_unique<Tile>(&imr, j * 32.0f, i * 32.0f, 32, 32));
		}
	}

	SDL_Point p;
	p.x = 100;
	p.y = 100;

	double ang = 0.0;

	float delta = SDL_GetTicks();
	float cur_time = SDL_GetTicks();

	ImageAssetResource anim_res(*video, "./images/tile_anim.bmp");
	anim_res.setClipBox(util::init_SDL_Rect(100, 100, 32, 32));
	Tile anim_tile(&anim_res, 100, 100, 32, 32);
	anim_tile.animAddFrameClip(util::init_SDL_Rect(0, 0, 32, 32));
	anim_tile.animAddFrameClip(util::init_SDL_Rect(32, 0, 32, 32));
	anim_tile.animAddFrameClip(util::init_SDL_Rect(64, 0, 32, 32));
	anim_tile.animAddFrameClip(util::init_SDL_Rect(0, 32, 32, 32));
	anim_tile.animAddFrameClip(util::init_SDL_Rect(32, 32, 32, 32));
	anim_tile.animAddFrameClip(util::init_SDL_Rect(64, 32, 32, 32));
	anim_tile.animationLoopInterval(250);

	while (device->run()) {

		cur_time = SDL_GetTicks();

		input.moveTiles(device->getFrameEvents(), tiles);

		anim_tile.update(delta, cur_time);

		video->beginScene();

		for (auto& t : tiles) {
			video->drawSprite(t.get());
			//video->drawRotatedSprite(t->getImageAssetResource(), t->getBoundingBox().toSDL_Rect(), 45, p);
		}

		video->drawSprite(&anim_tile);
		video->endScene();

		++ang;
		if (ang > 360.0)
			ang = 0.0;

		device->clearFrameEvents();
	}

	device->drop();

	return 0;
}