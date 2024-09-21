#ifndef TIMEACCOUNT_H
#define TIMEACCOUNT_H
#include <iostream>
#include "UsefullStuff.h"

class Account
{
private:
	Time TimeResourse;
	std::string name;
	int accountID;

public:
	Account(std::string name);
	void setName(std::string name);
	void setID(int numberOfAccount);
	int getAccountID();
	std::string getName();

	void updateTimeResourse(int hours, int minutes, int secs);

	void addHours(int hours);
	void addMinutes(int minutes);
	void addSeconds(int seconds);

	void substractHours(int hours);
	void substractMinutes(int minutes);
	void substractSeconds(int seconds);

	void printDataAboutAccount(); //Maybe I will delete it in future
	Time getTimeResourse(); //Not that useful thing than I thought, so I probably remove it
};

#endif
