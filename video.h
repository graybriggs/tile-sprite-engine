#pragma once

#include "SDL.h"

class Sprite;
class Texture;

class VideoDriver {
public:

	~VideoDriver();

	void beginScene();
	void beginScene(int r, int g, int b); // later
	void endScene();
	SDL_Renderer* getRenderer() const;
	void drawAll();

	void drawSprite(const Sprite*, const SDL_Rect);
	//void drawImage(Texture* tex, int x, int y, int clipx, int clipy, int colorkey);
	void drawRectangle(int x, int y, int w, int h, int colorkey);

public:
	SDL_Renderer* renderer;
};