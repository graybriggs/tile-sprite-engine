
#ifndef CAMERA_H
#define CAMERA_H

#include <SDL.h>

#include <memory>
#include <vector>

typedef std::vector<SDL_Event> EventList;


class Camera {
public:
	void moveTiles(EventList& events, std::vector<std::unique_ptr<Tile>>& tiles, const Player&);
	void setScrollCollision(const SDL_Rect);


private:

	SDL_Rect scroll_collision;

	bool lock_on_center;

};

#endif