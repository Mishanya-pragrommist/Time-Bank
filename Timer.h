#ifndef TIMER_H
#define TIMER_H
#include "UsefullStuff.h"

class Timer
{
private:
	Time wastingTime;

public:
	Timer();

	void enterTime(int hours, int minutes, int seconds);
	void addHours(int hours);
	void addMinutes(int minutes);
	void addSeconds(int seconds);

	void start();
};

#endif
