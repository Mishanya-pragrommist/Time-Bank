#ifndef TIMEACCOUNT_H
#define TIMEACCOUNT_H
#include <iostream> //Delete this in future
#include <windows.h>
#include "UsefullStuff.h"
#include "Timer.h"

class Account
{
private:
	Time time, wastingTime;
	//long long secondsTime;

	Timer timer;
	std::string name;
	int accountID;
	
public:
	Account(std::string name, int accountID, Time time, Time wastingTime);
	Account(std::string name, int accountID);

	void setName(std::string name);
	void setID(int accountID);
	std::string getName();
	int getAccountID();

	int getHours();
	int getMinutes();
	int getSeconds();

	int getWastingHours();
	int getWastingMinutes();
	int getWastinghSeconds();
	
	//To convert seconds like 4830 to time like 1:20:30
	static Time convertSecondsToTime(int time);

	//To work with the time
	void updateTime(int hours, int minutes, int seconds);

	void addHours(int hours);
	void addMinutes(int minutes);
	void addSeconds(int seconds);

	void substractHours(int hours);
	void substractMinutes(int minutes);
	void substractSeconds(int seconds);
	
	void returnTimeToAccount();

	void startTimer();

	void printAccountData(); //Maybe I will delete it in future or change
};

#endif
