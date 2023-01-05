#pragma once

#ifndef CAMERA_H
#define CAMERA_H

#include <SDL.h>

#include <memory>
#include <vector>

typedef std::vector<SDL_Event> EventList;
class Player;
class Tile;



class Camera {
public:

	enum class CameraType { LOCK_ON, COLLISION };

	Camera(CameraType = CameraType::LOCK_ON);

	void setCameraType(CameraType);
	void moveTiles(EventList& events, std::vector<std::unique_ptr<Tile>>& tiles, Player&);
	void setScrollCollisionBounds(const SDL_Rect);


private:

	CameraType cam_type;
	SDL_Rect camera_position;
	SDL_Rect scroll_collision;
};

#endif

