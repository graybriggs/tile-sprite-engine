#pragma once

#include <string>
#include <vector>

#include "system_api.h"

#include <SDL2/SDL.h>

class GUIEnvironment;
class SceneManager;
class Timer;
class VideoDriver;

typedef std::vector<SDL_Event> EventList;

class Device {
public:

	~Device();

	void setWindowCaption(const std::string& s);

	bool run();
	void drop();

	std::unique_ptr<VideoDriver> getVideoDriver();
	SceneManager* getSceneManager();
	GUIEnvironment* getGUIEnvironment(); // this could have a font text based renderer
	
	bool input_pump_events();

	//Texture* getTexture(const std::string path);
	Timer* getTimer();

	EventList& getFrameEvents();
	int get_current_time();

	void clearFrameEvents();

public:
	EventList frame_events;
	SDL_Window* window;
	SDL_Event event;
};


std::unique_ptr<Device> createDevice(VideoDriverType driverType, int screen_w, int screen_h, bool fullscreen);

