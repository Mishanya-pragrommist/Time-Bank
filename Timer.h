#ifndef TIMER_H
#define TIMER_H
#include "UsefullStuff.h"

class Timer
{
private:
	Timer wastingTime;

public:
	Timer();

	void enterTime(int hours, int minutes, int seconds);
};

#endif
