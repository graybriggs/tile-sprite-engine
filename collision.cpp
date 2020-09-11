
#include "collision.h"


bool aabb_collision(const SDL_Rect& A, const SDL_Rect& B) {

	bool leftA, leftB;
	bool rightA, rightB;
	bool topA, topB;
	bool bottomA, bottomB;

	leftA = A.x;
	rightA = A.x + A.w;
	topA = A.y;
	bottomA = A.y + A.h;

	leftB = B.x;
	rightB = B.x + B.w;
	topB = B.y;
	bottomB = B.y + B.h;

	if (bottomA <= topB)
		return false;

	if (topA >= bottomB)
		return false;

	if (rightA <= leftB)
		return false;

	if (leftA >= rightB)
		return false;

	return true;

}