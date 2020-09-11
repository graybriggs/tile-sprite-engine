
#include <cstring> // memset

#include "device.h"
#include "utility.h"
#include "video.h"


#include "sprite.h"

int main(int argc, char* args[]) {

	auto device = createDevice(DriverType::SDL2, 1200, 750, false);
	auto video = device->getVideoDriver();

	SDL_Rect r = util::init_SDL_Rect(100, 100, 100, 100);
	Sprite s;
	s.setClipBox(util::init_SDL_Rect(0,0,256,256));

	s.loadSprite(*video, "./images/jfr_box_tex1.bmp");
	

	while (device->run()) {

		video->beginScene();

		video->drawSprite(&s, r);

		video->endScene();
	}

	device->drop();

	return 0;
}