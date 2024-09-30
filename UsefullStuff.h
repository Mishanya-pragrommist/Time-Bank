//There I will place struct of time, some temporary things and almost all drawing tools
//that will be used in GUI
#ifndef USEFULLSTUFF_H 
#define USEFULLSTUFF_H
#include <iostream> //Of course, in future I will delete this

struct Time { int hours, minutes, seconds; };

enum Commands //Temporary used thing. I guess its won't be usefull in GUI. But who knows...
{
	UPDATE = 1,
	ADD, //= 2
	GETTIME, // 3
	RETURNTIME, // 4
	STARTTIMER, // 5
	PRINTALLACCOUNTS, // 6
	CREATEACCOUNT, // 7
	RENAMECURRENTACC, // 8
	GOTO, // 9
	DELETEACC, // 10
	CLEARACC, // 11
	STOP // 12
};

class TimeHelper 
{
public:
	static Time convertSecondsToTime(int seconds); //For example, 4830 seconds converts to 1:20:30
	static void addTime(Time& time, int seconds); //Firstly converts seconds to time struct, then
												  //adds it to account/timer time

	static void substractTime(Time& time, int seconds); //Same as addTime() but substracts time
};

#endif
