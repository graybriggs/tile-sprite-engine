#pragma once

#include <SDL2/SDL.h>

#include "utility.h"

class Entity;
class ImageAssetResource;
class Texture;


class VideoDriver {
public:

	void beginScene();
	void beginScene(int r, int g, int b); // later
	void endScene();
	SDL_Renderer* getRenderer() const;
	void drawAll();

	void drawSprite(const ImageAssetResource*, const SDL_Rect);
	void drawSprite(Entity*);
	//void drawImage(Texture* tex, int x, int y, int clipx, int clipy, int colorkey);
	void setDrawColor(int r, int g, int b, int a);
	void drawRectangle(int x, int y, int w, int h);
	void drawRectangle(util::Rect rect);
	void drawRotatedSprite(const ImageAssetResource*, const SDL_Rect pos, const double angle, const SDL_Point rot_point);

	void destory();
	
public:
	SDL_Renderer* renderer;
};