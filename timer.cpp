
#include "timer.h"

#include <SDL.h>


std::clock_t Timer::getTime() const {
	return current_time;
}


CallbackTimer::CallbackTimer(std::function<void()> func, int duration, bool repeated = false):
	func(func),
	duration(duration),
	repeated(repeated),
	start_time(0),
	current_time(0)
{

}

void CallbackTimer::start_timer() {
	active = true;
	current_time = SDL_GetTicks();
}

void CallbackTimer::stop_timer() {
	active = false;
}

void CallbackTimer::reset_timer() {
	start_timer();
}

void CallbackTimer::update(float dt) {
	
	current_time = SDL_GetTicks();
	
	if (active) {
		if (current_time - start_time > start_time) {
			if (func) {
				func();
			}
			if (repeated) {
				reset_timer();
			}
			else {
				stop_timer();
			}
		}
	}

}

bool CallbackTimer::is_active() const {
	return is_active;
}