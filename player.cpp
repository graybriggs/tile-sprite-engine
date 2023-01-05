
#include "player.h"

Player::Player() 
	: Entity(nullptr, util::Rect(0, 0, 32, 64))
{
}

void Player::handleInput(const EventList& events) {

	for (auto& e : events) {
		if (e.type == SDL_KEYDOWN) {

			switch (e.key.keysym.sym) {
			case SDLK_w: {
				state = PlayerStates::UP;
				break;
			}
			case SDLK_a: {
				state = PlayerStates::LEFT;
				break;
			}
			case SDLK_s: {
				state = PlayerStates::DOWN;
				break;
			}
			case SDLK_d: {
				state = PlayerStates::RIGHT;
				break;
			}
			default:
				break;
			}
		}
		else if (e.type == SDL_KEYUP) {

			state = PlayerStates::STOP;

			switch (e.key.keysym.sym) {
			case SDLK_w: {
				break;
			}
			case SDLK_a: {
				break;
			}
			case SDLK_s: {
				break;
			}
			case SDLK_d: {
				break;
			}
			default:
				break;
			}
		}
	}
}

void Player::update(const float delta) {

	//const float X_MOVE_SPEED = 1.0f;
	//const float Y_MOVE_SPEED = 0.9f;

	if (state == PlayerStates::LEFT) {
		moveBy(-X_MOVE_SPEED, 0.0f);
	}
	if (state == PlayerStates::RIGHT) {
		moveBy(X_MOVE_SPEED, 0.0f);
	}
	if (state == PlayerStates::UP) {
		moveBy(0.0f, Y_MOVE_SPEED);
	}
	if (state == PlayerStates::DOWN) {
		moveBy(0.0f, -Y_MOVE_SPEED);
	}
	if (state == PlayerStates::STOP) {

	}
}

util::Rect Player::getBoundingBox() {
	return Entity::getBoundingBox();
}

void Player::setBoundingBox(const util::Rect bb) {
	Entity::setBoundingBox(bb);
}

void Player::setScreenPosition(const int x, const int y) {
	Entity::setPosition(x, y);
}