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
};

#endif
