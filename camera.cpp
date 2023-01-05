

#include "camera.h"
#include "constants.h"
#include "player.h"
#include "tile.h"
#include "utility.h"


Camera::Camera(CameraType ct)
	: cam_type(ct),
	camera_position(util::init_SDL_Rect(0, 0, constants::SCREEN_WIDTH, constants::SCREEN_HEIGHT))
{
}

void Camera::setCameraType(CameraType type) {
	cam_type = type;
}

void Camera::moveTiles(EventList& events, std::vector<std::unique_ptr<Tile>>& tiles, const Player& p) {


	// debug
	for (auto& e : events) {
		switch (e.key.keysym.sym) {
		case SDLK_UP: {
			for (auto& t : tiles) {
				util::Rect r = t->getBoundingBox();
				r.y_pos -= 10.0;
				t->setBoundingBox(r);
			}
			break;
		}
		case SDLK_DOWN: {
			for (auto& t : tiles) {
				util::Rect r = t->getBoundingBox();
				r.y_pos += 10.0;
				t->setBoundingBox(r);
			}
			break;
		}
		case SDLK_LEFT: {
			for (auto& t : tiles) {
				util::Rect r = t->getBoundingBox();
				r.x_pos -= 10.0;
				t->setBoundingBox(r);
			}
			break;
		}
		case SDLK_RIGHT: {
			for (auto& t : tiles) {
				util::Rect r = t->getBoundingBox();
				r.x_pos += 10.0;
				t->setBoundingBox(r);
			}
			break;
		}
		default:
			break;
		}
		////


		if (cam_type == CameraType::LOCK_ON) {
			for (auto& t : tiles) {

				camera_position.x = p.getBoundingBox().toSDL_Rect().x / 2
									+ p.getBoundingBox().toSDL_Rect().w / 2;
				camera_position.y = p.getBoundingBox().toSDL_Rect().y / 2
									+ p.getBoundingBox().toSDL_Rect().h / 2;


				for (auto& t : tiles) {
					//t->moveBy(camera_position.x, camera_position.y);
				}
			}
		}
		else {
			SDL_Rect p_rect = p.getBoundingBox().toSDL_Rect();
			if (p_rect.x + p_rect.w > scroll_collision.w) {
				for (auto& t : tiles) {
					util::Rect r = t->getBoundingBox();
					r.x_pos += p.X_MOVE_SPEED;
					t->setBoundingBox(r);
				}
			}
			else if (p_rect.x < scroll_collision.x) {
				for (auto& t : tiles) {
					util::Rect r = t->getBoundingBox();
					r.x_pos -= p.X_MOVE_SPEED;
					t->setBoundingBox(r);
				}
			}
			else if (p_rect.y < scroll_collision.y) {
				for (auto& t : tiles) {
					util::Rect r = t->getBoundingBox();
					r.y_pos -= p.Y_MOVE_SPEED;
					t->setBoundingBox(r);
				}
			}
			else if (p_rect.y + p_rect.h > scroll_collision.h) {
				for (auto& t : tiles) {
					util::Rect r = t->getBoundingBox();
					r.y_pos += p.Y_MOVE_SPEED;
					t->setBoundingBox(r);
				}
			}
		}

	}
}

void Camera::setScrollCollisionBounds(const SDL_Rect r) {
	scroll_collision = r;
}