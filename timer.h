#pragma once

#ifndef TIMER_HPP
#define TIMER_HPP

#include <ctime>
#include <functional>

class Timer {
public:
	std::clock_t getTime() const;

private:
	std::clock_t current_time;
};


/*
class Timer {
public:
	Timer(bool);

	void start();
	void setInterval(int i);
	bool intervalReached();

private:

	std::clock_t currentTime;
	std::clock_t begin, end;
	std::clock_t interval, nextInterval;
	bool running;
};

*/

class CallbackTimer {
public:
	CallbackTimer(std::function<void()> func, int duration, bool repeated);

	void start_timer();
	void stop_timer();
	void reset_timer();
	void update(float dt);
	bool is_active() const;
private:

	bool active;
	int start_time;
	int current_time;
	int duration;
	bool repeated;
	std::function<void()> func;
};

#endif