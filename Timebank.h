#ifndef TIMEBANK_H
#define TIMEBANK_H
#include <iostream> //Delete this and all std::cout in future
#include <vector>
#include <fstream>
#include "nlohmann/json.hpp"
#include "Account.h"
#include "UsefullStuff.h"

class Timebank
{
private:
	std::vector<Account*> Accounts;
	Account* currentAccount;
	
	//For saving and reading data
	std::string savingFilePath = "save/savings.json";
	void writeToFile();
	void readFromFile();

	int numberOfAccounts;
	void numerateAccounts(int start);
		
public:
	Timebank();
	~Timebank();

	int getNumberOfAccounts();
	//All methods that takes "index" should be smaller in 1 than real number of acc u r looking for
	//For example, to find acc #3 u need to enter index 2

	//To manage accounts
	void createAccount(std::string name);
	void changeAccount(int index);
	
	void renameCurrentAccount(std::string newname);
	void renameAccount(int index, std::string newname);

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

	//If user doesnt want to waste time
	void returnTimeToAccount();

	void startTimer();
};

#endif
