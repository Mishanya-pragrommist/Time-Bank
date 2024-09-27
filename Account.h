#ifndef TIMEACCOUNT_H
#define TIMEACCOUNT_H
#include <iostream> //Delete this in future
#include "UsefullStuff.h"
#include "Timer.h"

class Account
{
private:
	Time TimeResourse;
	Timer* timer;
	
	std::string name;
	int accountID;

public:
	Account(std::string name, int ID, int hours, int minutes, int second);
	Account(std::string name);
	void setName(std::string name);
	void setID(int numberOfAccount);
	std::string getName();
	int getAccountID();

	int getHours();
	int getMinutes();
	int getSeconds();

	//To work with the time
	void updateTimeResourse(int hours, int minutes, int secs);

	void addHours(int hours);
	void addMinutes(int minutes);
	void addSeconds(int seconds);

	void substractHours(int hours);
	void substractMinutes(int minutes);
	void substractSeconds(int seconds);

	void printDataAboutAccount(); //Maybe I will delete it in future

	void startTimer();
};

#endif
