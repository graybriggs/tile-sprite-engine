

#include "camera.h"

void Camera::moveTiles(EventList& events, std::vector<std::unique_ptr<Tile>>& tiles, const Player& p) {


// debug
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
		////
		SDL_Rect p_rect = p.getBoundingBox().toSDLRect();
		if (p_rect.x > scroll_collision) {
			for (auto& t : tiles) {
				util::FRect r = t->getBoundingBox();
				r.y_pos -= 10.0;
				t->setBoundingBox(r);
			}
		}


	}
}

void Camera::setScrollCollision(const SDL_Rect r) {
	scroll_collision = r;
}