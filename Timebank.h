#ifndef TIMEBANK_H
#define TIMEBANK_H
#include <iostream> //Delete this and all std::cout in future
#include <vector>
#include "nlohmann/json.hpp"
#include "Account.h"
#include "Timer.h"
#include "UsefullStuff.h"

class Timebank
{
private:
	std::vector<Account*> Accounts;
	Account* currentAccount;
	Timer* timer;

	//For saving and reading data
	std::string savingFile;
	nlohmann::json jwrite, jread;

	int numberOfAccounts;
	void numerateAccounts(int start); //User dont have to use it

public:
	Timebank();
	~Timebank();

	//To save data in .json file and read from them
	void addAccount(std::string name, int accountID,
		int hours, int minutes, int seconds);
	void writeToFile();
	void readFromFile(Account& acc);

	//To manage accounts
	void createAccount(std::string name);
	void changeAccount(int index);
	int getNumberOfAccounts();
	void renameCurrentAccount(std::string newname);
	void renameAccount(int index, std::string newname);

	void deleteAccount(int index);
	void deleteAllAccounts();

	void printOneAccount(int i); //Print functions will be either changed or deleted
	void printCurrentAccount();
	void printAllAccounts();

	//To work with the time exactly
	void updateTime(int hours, int minutes, int seconds); //To re-enter time 

	void addHours(int hours); //Adding time
	void addMinutes(int minutes);
	void addSeconds(int seconds);

	void substractHours(int hours); //Substracting time
	void substractMinutes(int minutes);
	void substractSeconds(int seconds);
};

#endif
