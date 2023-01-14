
#include "collision.h"


bool aabb_collision(const SDL_Rect& one, const SDL_Rect& two) {
	if (one.x + one.w < two.x) {
		return false;
	}
	else if (one.x > two.x + two.w) {
		return false;
	}
	else if (one.y + one.h < two.y) {
		return false;
	}
	else if (one.y > two.y + two.h) {
		return false;
	}
	else {
		return true;
	}
}
