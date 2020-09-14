
#include <vector>

#include "input.h"

#include "tile.h"


void Input::moveTiles(EventList& events, std::vector<std::unique_ptr<Tile>>& tiles) {

	for (auto& e : events) {
		switch (e.key.keysym.sym) {
		case SDLK_UP: {
			for (auto& t : tiles) {
				util::FRect r = t->getBoundingBox();
				r.y_pos -= 10.0;
				t->setBoundingBox(r);
			}
			break;
		}
		case SDLK_DOWN: {
			for (auto& t : tiles) {
				util::FRect r = t->getBoundingBox();
				r.y_pos += 10.0;
				t->setBoundingBox(r);
			}
			break;
		}
		case SDLK_LEFT: {
			for (auto& t : tiles) {
				util::FRect r = t->getBoundingBox();
				r.x_pos -= 10.0;
				t->setBoundingBox(r);
			}
			break;
		}
		case SDLK_RIGHT: {
			for (auto& t : tiles) {
				util::FRect r = t->getBoundingBox();
				r.x_pos += 10.0;
				t->setBoundingBox(r);
			}
			break;
		}
		default:
			break;
		}
	}
}


