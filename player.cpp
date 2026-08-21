
#include "collision.h"
#include "input.h"
#include "player.h"
#include "tile.h"

#include <iostream>

Player::Player() :
	Entity(nullptr, SDL_Rect{512, 512, 32, 64}),
	state(PlayerStates::STOP)
{
}

//void Player::handleInput(const EventList& events) {
void Player::handleInput() {

	if (input_query_state(KeyCode::INPUT_K_RIGHT) == true) {
		state = PlayerStates::RIGHT;
	}
	else if (input_query_state(KeyCode::INPUT_K_LEFT) == true) {
		state = PlayerStates::LEFT;
	}
	else if (input_query_state(KeyCode::INPUT_K_UP) == true) {
		state = PlayerStates::UP;
	}
	else if (input_query_state(KeyCode::INPUT_K_DOWN) == true) {
		state = PlayerStates::DOWN;
	}
	else {
		state = PlayerStates::STOP;
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
		moveBy(0.0f, -Y_MOVE_SPEED);
	}
	if (state == PlayerStates::DOWN) {
		moveBy(0.0f, Y_MOVE_SPEED);
	}
	if (state == PlayerStates::STOP) {

	}
}

SDL_Rect Player::getBoundingBox() const {
	return Entity::getBoundingBox();
}

void Player::setBoundingBox(const SDL_Rect bb) {
	Entity::setBoundingBox(bb);
}

void Player::setScreenPosition(const int x, const int y) {
	Entity::setPosition(x, y);
}

void Player::stop() {
	state = PlayerStates::STOP;
	std::cout << "stop" << std::endl;
}

void Player::move_back() {
	// there will be a move step each frame
	// something like player velocity * delta
	// move back by this amount

}

void Player::tile_collide(const Tile& tile) {
	// check collision
	const SDL_Rect& pbb = bounding_box;
	const SDL_Rect& tbb = tile.getBoundingBox();

	// if (aabb_collision(pbb, tbb)) {
	// 	std::cout << "box-box collision" << std::endl;
	// 	state = PlayerStates::STOP;
	// }

	Side side = aabb_collision(pbb, tbb);

	// move back ??
	if (side == Side::LEFT) {
		//bounding_box
	}
	if (side == Side::RIGHT) {

	}
	if (side == Side::TOP) {

	}
	if (side == Side::BOTTOM) {

	}


	if (side != Side::NONE) {
		std::cout << "box-box collision - ";
		print_collision_info(side);
	}

}