#ifndef TIMEBANK_H
#define TIMEBANK_H
#include <iostream> //Delete this and all std::cout in future
#include <vector>
#include <exception>
#include "Account.h"
#include "FileHandler.h"
#include "UsefullStuff.h"

class Timebank
{
	friend class FileHandler; //path to saving file is in this class
private:
	std::vector<Account*> Accounts;
	Account* currentAccount;
	int numberOfAccounts;

	//For saving and reading data
	void writeToFile();
	void readFromFile();
	
	void numerateAccounts(int start);
	
public:
	Timebank();
	~Timebank();

	int getNumberOfAccounts();
	//Index given to all methods that takes it should be smaller in 1 
	//than real number of acc u r looking for
	//For example, to find acc #3 u need to enter index 2

	//To manage accounts
	void createAccount(std::string name);
	void changeAccount(int index);
	
	void renameCurrentAccount(std::string newname);
	void renameAccount(int index, std::string newname);

	void clearAccount();
	void deleteAccount(int index);
	void deleteAllAccounts();

	void printCurrentAccount(); //Print functions will be either changed or deleted
	void printAllAccounts();

	//To work with the time exactly
	void updateTime(int hours, int minutes, int seconds); //To re-enter time 
	
	void addHours(int hours); //To add time
	void addMinutes(int minutes);
	void addSeconds(int seconds);

	void substractHours(int hours); //To substract time
	void substractMinutes(int minutes);
	void substractSeconds(int seconds);

	void returnTimeToAccount();	//If user doesnt want to waste time
	
	void startTimer();
};

#endif
