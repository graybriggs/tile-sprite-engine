#include <memory>
#include <utility>

#include "device.h"
#include "system_api.h"
#include "image_asset_resource.h"
#include "input.h"
#include "timer.h"
#include "video.h"

#include "SDL.h"

Device::~Device() {
	SDL_DestroyWindow(window);
}

void Device::setWindowCaption(std::string s) {

}

EventList& Device::getFrameEvents() {
	return frame_events;
}

void Device::clearFrameEvents() {
	frame_events.clear();
}

bool Device::run() {
	// remember to // clearFrameEvents() at the end of every frame.
	
	input_pump_events();

	if (input_query_state(KeyCode::INPUT_K_ESC)) {
		return false;
	}
	if (event.type == SDL_QUIT) {
		return false;
	}

	/*
	while (SDL_PollEvent(&event)) {

		// push_event_list();

		frame_events.push_back(event);

		for (auto& e : frame_events) {
			if (e.type == SDL_QUIT)
				return false;
			if (e.type == SDL_KEYDOWN) {
				if (e.key.keysym.sym == SDLK_ESCAPE)
					return false;
			}
		}
	}
	*/

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

void Device::input_pump_events() {
	//SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDLK_DOWN) {
			switch (event.key.keysym.sym) {
			case SDLK_UP:
				input_set_button_state(KeyCode::INPUT_K_UP);
				break;
			case SDLK_DOWN:
				input_set_button_state(KeyCode::INPUT_K_DOWN);
				break;
			case SDLK_LEFT:
				input_set_button_state(KeyCode::INPUT_K_LEFT);
				break;
			case SDLK_RIGHT:
				input_set_button_state(KeyCode::INPUT_K_RIGHT);
				break;
			case SDLK_SPACE:
				input_set_button_state(KeyCode::INPUT_K_SPACE);
				break;
			case SDLK_RETURN:
				input_set_button_state(KeyCode::INPUT_K_ENTER);
				break;
			case SDLK_ESCAPE:
				input_set_button_state(KeyCode::INPUT_K_ESC);
				break;
			}
		}
		else if (event.type == SDLK_UP) {
			switch (event.key.keysym.sym) {
			case SDLK_UP:
				input_release_button_state(KeyCode::INPUT_K_UP);
				break;
			case SDLK_DOWN:
				input_release_button_state(KeyCode::INPUT_K_DOWN);
				break;
			case SDLK_LEFT:
				input_release_button_state(KeyCode::INPUT_K_LEFT);
				break;
			case SDLK_RIGHT:
				input_release_button_state(KeyCode::INPUT_K_RIGHT);
				break;
			case SDLK_SPACE:
				input_release_button_state(KeyCode::INPUT_K_SPACE);
				break;
			case SDLK_RETURN:
				input_release_button_state(KeyCode::INPUT_K_ENTER);
				break;
			case SDLK_ESCAPE:
				input_release_button_state(KeyCode::INPUT_K_ESC);
				break;
			}
		}
	}
}

void Device::drop() {
	SDL_Quit();
}

/*
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
	
	return nullptr;
}
*/

Timer* Device::getTimer() {

	auto timer = std::make_unique<Timer>();
	//timer->current_time = std::clock();
	timer->setTime(std::clock());

	return timer.get();
}

int Device::get_current_time() {
	return SDL_GetTicks();
}


std::unique_ptr<Device> createDevice(VideoDriverType driverType, int width, int height, bool fullscreen) {
	
	auto device = std::make_unique<Device>();
	//Device* device = new Device;

	Uint32 init_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER;
		
	if (device != nullptr) {
		if (driverType == VideoDriverType::SDL2) {
			SDL_Init(init_flags);

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
