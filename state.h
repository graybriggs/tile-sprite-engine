#ifndef STATE_H
#define STATE_H

#include "engine.hpp"

class Sprite;

class GameStates {
public:

	virtual void init(Engine*) = 0;
	virtual void cleanup() = 0;

	virtual void pause() = 0;
	virtual void resume() = 0;

	virtual void input(Engine*) = 0;
	virtual void update(Engine*) = 0;
	virtual void render(Engine*) = 0;

	void changeState(Engine* eng, GameStates* state) {
		eng->changeState(state);
	}

};

#endif#pragma once
