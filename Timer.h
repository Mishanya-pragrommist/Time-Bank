#ifndef TIMER_H
#define TIMER_H
#include <iostream> //Also delete this in future
#include <windows.h> //Only for imitating work of timer
#include "UsefullStuff.h"

class Timer
{
private:
	void printTimer();
	Time timeLeft;

public:
	Timer();
	
	void setTimeLeft(Time timeLeft);
	Time getTimeLeft();

	void resetTime();
	void start();
};

#endif
