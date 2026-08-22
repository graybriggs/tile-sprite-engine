#pragma once

#include <SDL2/SDL.h>

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

enum class Side { TOP, BOTTOM, LEFT, RIGHT, NONE };

//bool aabb_collision(const SDL_Rect& A, const SDL_Rect& B);
Side aabb_collision(const SDL_Rect& A, const SDL_Rect& B);
//bool tri_rect_intersection();

void print_collision_info(Side side);