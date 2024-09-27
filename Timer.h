#ifndef TIMER_H
#define TIMER_H
#include <iostream>
#include <windows.h>
#include "UsefullStuff.h"

class Timer
{
private:
	Time timeLeft;
	void printTimer();

public:
	Timer();

	int getHours();
	int getMinutes();
	int getSeconds();

	void addHours(int hours);
	void addMinutes(int minutes);
	void addSeconds(int seconds);

	void start();
};

#endif
