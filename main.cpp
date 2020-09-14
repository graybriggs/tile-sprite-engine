
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
	imr.setClipBox(util::init_SDL_Rect(0, 0, 256, 256));

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

	while (device->run()) {

		input.moveTiles(device->getFrameEvents(), tiles);

		video->beginScene();

		for (auto& t : tiles) {
			video->drawSprite(t->getImageAssetResource(), t->getBoundingBox().toSDL_Rect());
			//video->drawRotatedSprite(t->getImageAssetResource(), t->getBoundingBox().toSDL_Rect(), 45, p);
		}

		video->endScene();

		SDL_Delay(10);
		++ang;
		if (ang > 360.0)
			ang = 0.0;

		device->clearFrameEvents();
	}

	device->drop();

	return 0;
}