#pragma once

#ifndef TIMER_HPP
#define TIMER_HPP

#include <ctime>

class Timer {
public:

	std::clock_t getTime() const {
		return current_time;
	}

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

#endif