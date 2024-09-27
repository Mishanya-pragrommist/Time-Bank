#ifndef TIMEBANK_H
#define TIMEBANK_H
#include <iostream> //Delete this and all std::cout in future
#include <vector>
#include <fstream>
#include "nlohmann/json.hpp"
#include "Account.h"
#include "Timer.h"
#include "UsefullStuff.h"

class Timebank
{
private:
	std::vector<Account*> Accounts;
	Account* currentAccount;
	
	//For saving and reading data
	std::string savingFilePath = "save/savings.json";
	//nlohmann::json jfile;

	int numberOfAccounts;
	void numerateAccounts(int start);

	//To save data in .json file and read from them
	void writeToFile();
	void readFromFile();
public:
	Timebank();
	~Timebank();

	int getNumberOfAccounts();
	//All methods that takes "index" should be smaller than real number of account you are looking for
	//For example, to find account #3 you need to enter index 2

	//To manage accounts
	void createAccount(std::string name);
	void changeAccount(int index);
	
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

	void startTimer();
};

#endif
