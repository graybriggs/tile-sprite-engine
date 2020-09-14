#pragma once

#include "SDL.h"

class Entity;
class ImageAssetResource;
class Texture;

class VideoDriver {
public:

	~VideoDriver();

	void beginScene();
	void beginScene(int r, int g, int b); // later
	void endScene();
	SDL_Renderer* getRenderer() const;
	void drawAll();

	void drawSprite(const ImageAssetResource*, const SDL_Rect);
	void drawSprite(const Entity*);
	//void drawImage(Texture* tex, int x, int y, int clipx, int clipy, int colorkey);
	void drawRectangle(int x, int y, int w, int h, int colorkey);
	void drawRotatedSprite(const ImageAssetResource*, const SDL_Rect pos, const double angle, const SDL_Point rot_point);

public:
	SDL_Renderer* renderer;
};