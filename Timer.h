#ifndef TIMER_H
#define TIMER_H
#include <iostream> //Also delete this in future
#include <windows.h> //Only for imitating work of timer
#include "UsefullStuff.h"

//This class especially needs to be changed in GUI 
//since for now it works directly with console (clearing console, Sleep() func etc)
class Timer
{
private:
	void printTimerData();
	Time timeLeft;

public:
	Timer();
	
	void setTimeLeft(Time timeLeft);
	Time getTimeLeft();
	
	void addHours(int hours);
	void addMinutes(int minutes);
	void addSeconds(int seconds);

	int getHours();
	int getMinutes();
	int getSeconds();

	void resetTime();
	void start();
};

#endif
