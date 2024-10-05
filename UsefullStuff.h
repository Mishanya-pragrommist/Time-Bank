//There I will place struct of time, some temporary things and almost all drawing tools
//that will be used in GUI
#ifndef USEFULLSTUFF_H 
#define USEFULLSTUFF_H
#include <iostream> //It is here only cuz of timer which shows its work in console
					//Of course, in future I will delete this

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
	QUIT // 12
};

namespace TimeHelp //Used in Account class to make handling time easier
{ 
	Time convertSecondsToTime(int seconds); //For example, 4830 seconds converts to 1:20:30
	void addTime(Time& time, int seconds); //Firstly converts seconds to time struct, then
												  //adds it to account/timer time

	void substractTime(Time& time, int seconds); //Same as addTime() but substracts time
};

#endif
