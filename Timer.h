#ifndef TIMER_H
#define TIMER_H
#include <iostream>
#include <windows.h>
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
	void deleteTime();
	void start();
};

#endif
