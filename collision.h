#pragma once

#ifndef COLLISION_H
#define COLLISION_H

#include <SDL.h>

struct Triangle {
	int x;
	int y;
	int w;
	int h;
	typedef int TriRotation;
	TriRotation rot = 0;
};

struct col_obj {
	SDL_Rect box;
	Triangle tri;
};

bool aabb_collision(const SDL_Rect& A, const SDL_Rect& B);
//bool tri_rect_intersection();
#endif