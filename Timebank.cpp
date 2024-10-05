#include "Timebank.h"

Timebank::Timebank() { readFromFile(); }

Timebank::~Timebank() { 
	writeToFile();
	deleteAllAccounts();
}

//For saving/reading data
void Timebank::readFromFile() {
	FileHandler filehandler;
	filehandler.readFromFile(this);
}
void Timebank::writeToFile() {
	FileHandler filehandler;
	filehandler.writeToFile(this);
}

//Getters (maybe I'll add more ones)
int Timebank::getNumberOfAccounts() { return numberOfAccounts; }

void Timebank::numerateAccounts(int start) {
	for (int i = start; i < Accounts.size(); i++) { Accounts[i]->setID(i + 1); }
}

//To manage accounts (create, delete, change)
void Timebank::createAccount(std::string name) {
	Accounts.push_back(new Account(name, ++numberOfAccounts));

	//When we create first account
	if (numberOfAccounts <= 1) { currentAccount = Accounts[0]; }
}
void Timebank::changeAccount(int index) {
	if (index < 0 || index > Accounts.size()) { 
		throw std::exception("Error: Index is out of range");
	}
	if (index == currentAccount->getAccountID() - 1) { //If we're already in the acc we try to change
		throw std::exception("You are already in this account(=\n");
	}
	currentAccount = Accounts[index];
}

void Timebank::deleteAccount(int index) {
	if (index < 0 || index >= Accounts.size()) {
		throw std::exception("Error: Index is out of range\n");
	}
	if (numberOfAccounts <= 1) {
		throw std::exception("Error: You can't delete account if there's only one acc left\n");
	}
	if (currentAccount->getAccountID() - 1 == index) {
		throw std::exception("Error: You can't delete acount you are in\n");
	}
	
	delete Accounts[index];
	Accounts.erase(Accounts.begin() + index); //To delete pointer in vector
	numberOfAccounts--;
	numerateAccounts(index); //Here it renumerates accs starting from index if deleted one cuz
							 //we don't need to renumerate all accs
}
void Timebank::deleteAllAccounts() { //Used in destructor
	for (Account* acc : Accounts) { delete acc; }
	Accounts.clear();
	numberOfAccounts = 0;
}

void Timebank::clearAccount() { currentAccount->clearAccount(); }

void Timebank::updateTime(int hours, int minutes, int seconds) {
	if (hours < 0 || minutes < 0 || seconds < 0) {
		throw std::exception("Time cannot be negative, y'know=)");
	}
	currentAccount->updateTime(hours, minutes, seconds);
}
void Timebank::renameCurrentAccount(std::string newname) {
	if (newname == "\0") return;
	currentAccount->setName(newname);
}
void Timebank::renameAccount(int index, std::string newname) {
	if (index < 0 || index > Accounts.size() || newname == "\0") { return; }
	Accounts[index]->setName(newname);
}

//To add time
void Timebank::addHours(int hours) {
	if (hours <= 0) { throw std::exception("Entered hours is <= 0"); }
	currentAccount->addHours(hours);
}
void Timebank::addMinutes(int minutes) {
	if (minutes <= 0) { throw std::exception("Entered minutes is <= 0"); }
	currentAccount->addMinutes(minutes);
}
void Timebank::addSeconds(int seconds) {
	if (seconds <= 0) { throw std::exception("Entered seconds is <= 0"); }
	currentAccount->addSeconds(seconds);
}

//To substract time
void Timebank::substractHours(int hours) {
	if (hours <= 0) { throw std::exception("Requested hours is <= 0"); }

	try { currentAccount->substractHours(hours); }
	catch (std::exception& hoursLack) { throw hoursLack; }
}
void Timebank::substractMinutes(int minutes) {
	if (minutes <= 0) { throw std::exception("Requested minutes is <= 0"); }

	try { currentAccount->substractMinutes(minutes); }
	catch (std::exception& error) { throw error; }
}
void Timebank::substractSeconds(int seconds) {
	if (seconds <= 0) { throw std::exception("Requested seconds is <= 0"); }

	try { currentAccount->substractSeconds(seconds); }
	catch (std::exception& error) { throw error; }
}

void Timebank::printCurrentAccount() { currentAccount->printAccountData(); }

void Timebank::printAllAccounts() {
	for (Account* acc : Accounts) {
		acc->printAccountData();
		std::cout << "\n";
	}
}

void Timebank::returnTimeToAccount() { currentAccount->returnTimeToAccount(); }

void Timebank::startTimer() { currentAccount->startTimer(); }
