#include <memory>
#include <utility>

#include "device.h"
#include "system_api.h"
#include "image_asset_resource.h"
#include "timer.h"
#include "video.h"


#include "SDL.h"

Device::~Device() {
	SDL_DestroyWindow(window);
}

void Device::setWindowCaption(std::string s) {

}

bool Device::run() {

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT)
			return false;
	}

	return true;
}

std::unique_ptr<VideoDriver> Device::getVideoDriver() {

	auto v = std::make_unique<VideoDriver>();

	v->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	return v;
}

SceneManager* Device::getSceneManager() {
	return nullptr;
}

GUIEnvironment* Device::getGUIEnvironment() {
	// Not implemented
	return nullptr;
}

void Device::drop() {
	SDL_Quit();
}

Texture* Device::getTexture(const std::string path) {
	/*
	SDL_Surface* texImg = SDL_LoadBMP(path.c_str());
	if (texImg == NULL) {
		std::string errMsg(path + "failed to load");
		throw std::exception();
	}

	auto tex = std::make_unique<Texture>();

	SDL_Texture* texture = SDL_CreateTextureFromSurface(SDL_GetRenderer(this->window), texImg);
	tex->tex = texture;
	SDL_FreeSurface(texImg);
	return tex.get();
	*/
	return nullptr;
}

Timer* Device::getTimer() {

	auto timer = std::make_unique<Timer>();
	timer->current_time = std::clock();

	return timer.get();
}


std::unique_ptr<Device> createDevice(DriverType driverType, int width, int height, bool fullscreen) {
	
	auto device = std::make_unique<Device>();
	//Device* device = new Device;

	if (device != nullptr) {
		if (driverType == DriverType::SDL2) {
			SDL_Init(SDL_INIT_VIDEO);

			device->window = SDL_CreateWindow(
				"",
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				width,
				height,
				SDL_WINDOW_SHOWN
			);
		}
		//return device.get();
		return std::move(device);
		/*else if (driverType == OPENGL)
		*/
	}
	else {
		throw "cannot create device";
	}
}
