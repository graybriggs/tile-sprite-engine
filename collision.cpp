
#include "collision.h"
//#include <iostream>
#include <print>


//bool aabb_collision(const SDL_Rect& one, const SDL_Rect& two) {
Side aabb_collision(const SDL_Rect& one, const SDL_Rect& two) {
	
	// left
	if (one.x + one.w > two.x) {
		//return false;
		return Side::LEFT;
	}
	// right
	else if (two.x + two.w > one.x) {
		//return false;
		return Side::RIGHT;
	}
	// top
	else if (one.y + one.h < two.y) {
		//return false;
		return Side::TOP;
	}
	// bottom
	else if (one.y > two.y + two.h) {
		//return false;
		return Side::BOTTOM;
	}
	else {
		//return true;
		return Side::NONE;
	}
}

void print_collision_info(Side side) {
	if (side == Side::LEFT) {
		//std::cout << "Collision side LEFT" << std::endl;
		std::println("Collision side LEFT");
	}
	else if (side == Side::RIGHT) {
		//std::cout << "Collision side RIGHT" << std::endl;
		std::println("Collision side RIGHT");
	}
	else if (side == Side::TOP) {
		//std::cout << "Collision side TOP" << std::endl;
		std::println("Collision side TOP");
	}
	else if (side == Side::BOTTOM) {
		//std::cout << "Collision side BOTTOM" << std::endl;
		std::println("Collision side BOTTOM");
	}
}