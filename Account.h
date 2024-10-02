#ifndef TIMEACCOUNT_H
#define TIMEACCOUNT_H
#include <iostream> //Delete this in future
#include <windows.h>
#include "UsefullStuff.h"
#include "Timer.h"

class Account
{
private:
	Time accountTime;
	Timer timer;
	std::string name;
	int accountID;

public:
	Account(std::string accountName, int accountID, Time time, Time timerTime); //Used when timebank 
																		 //reads data from file
	Account(std::string accountName, int accountID); //Used when user creates new account

	//Setters
	void setName(std::string name);
	void setID(int accountID);

	//Getters
	std::string getName();
	int getAccountID();
	
	int getHours();
	int getMinutes();
	int getSeconds();

	int getTimerHours();
	int getTimerMinutes();
	int getTimerSeconds();

	//To work with the time
	void updateTime(int hours, int minutes, int seconds);
	
	void addHours(int hours);
	void addMinutes(int minutes);
	void addSeconds(int seconds);

	void substractHours(int hours);
	void substractMinutes(int minutes);
	void substractSeconds(int seconds);
	
	void returnTimeToAccount(); //Return time from wastingTime to time an account
	void clearAccount(); //Set all values as 0 and name account as "default"

	void startTimer();

	void printAccountData(); //Maybe I will delete it in future or change
};

#endif
