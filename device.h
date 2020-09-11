#ifndef DEVICE_H
#define DEVICE_H
#pragma once

#include <string>

#include "system_api.h"

#include "SDL.h"

class GUIEnvironment;
class SceneManager;
class Texture;
class Timer;
class VideoDriver;

class Device {
public:

	~Device();

	void setWindowCaption(std::string s);

	bool run();
	void drop();

	std::unique_ptr<VideoDriver> getVideoDriver();
	SceneManager* getSceneManager();
	GUIEnvironment* getGUIEnvironment(); // this could have a font text based renderer
	
	Texture* getTexture(const std::string path);
	Timer* getTimer();

public:
	SDL_Event event;
	SDL_Window* window;
};


std::unique_ptr<Device> createDevice(DriverType driverType, int screen_w, int screen_h, bool fullscreen);


#endif
