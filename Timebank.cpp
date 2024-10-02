#include "Timebank.h"

Timebank::Timebank() { readFromFile(); }

Timebank::~Timebank() { 
	writeToFile();
	deleteAllAccounts();
}

//For saving/reading data
void Timebank::readFromFile() {
	std::ifstream fin(savingFilePath);
	if (!fin.is_open()) { std::cout << "Error: fin wasn't opened\n"; return; }

	nlohmann::json jread;
	fin >> jread;

	numberOfAccounts = jread["Timebank"]["numberOfAccounts"].get<int>();

	Time tempTime, tempTimeLeft;
	if (numberOfAccounts > 0) { //Reading data for each account
		for (int i = 1; i <= numberOfAccounts; i++) {
			std::string objectName = "Account #" + std::to_string(i);

			tempTime = {
				jread[objectName]["hours"].get<int>(),
				jread[objectName]["minutes"].get<int>(),
				jread[objectName]["seconds"].get<int>() 
			};
			
			tempTimeLeft = {
				jread[objectName]["hoursLeft"].get<int>(),
				jread[objectName]["minutesLeft"].get<int>(),
				jread[objectName]["secondsLeft"].get<int>()
			};
			
			std::string accName = jread[objectName]["name"].get<std::string>();
			int accID = jread[objectName]["accountID"].get<int>();
			Accounts.push_back(new Account(accName, accID, tempTime, tempTimeLeft));
		}
	}
	else { //If there is no accounts yet
		tempTime = { 0, 0, 0 };
		tempTimeLeft = { 0, 0, 0 };
		Accounts.push_back(new Account("default", 1, tempTime, tempTimeLeft));
		numberOfAccounts++;
	}
	currentAccount = Accounts[0];
	fin.close();
}
void Timebank::writeToFile() {
	std::ofstream fout(savingFilePath);
	if (!fout.is_open()) { std::cout << "Error: fout wasnt open\n"; return; }

	nlohmann::json jwrite;

	//Firstly we need to know how much of accounts there are
	jwrite["Timebank"] = { { "numberOfAccounts", numberOfAccounts} };

	for (int i = 0; i < Accounts.size(); i++) {
		//Same as in readFromFile() func
		std::string objectName = "Account #" + std::to_string(i + 1);
		jwrite[objectName] = {
			{"name", Accounts[i]->getName()},
			{"accountID", Accounts[i]->getAccountID()},
			{"hours", Accounts[i]->getHours()},
			{"minutes", Accounts[i]->getMinutes()},
			{"seconds", Accounts[i]->getSeconds()},
			{"hoursLeft", Accounts[i]->getTimerHours()},
			{"minutesLeft", Accounts[i]->getTimerMinutes()},
			{"secondsLeft", Accounts[i]->getTimerSeconds()}
		};
	}
	
	fout << jwrite.dump(4);
	fout.close();
}

//Getters
int Timebank::getNumberOfAccounts() { return numberOfAccounts; }

void Timebank::numerateAccounts(int start) {
	for (int i = start; i < Accounts.size(); i++) { Accounts[i]->setID(i + 1); }
}

//To manage accounts (create, delete, change)
void Timebank::createAccount(std::string name) {
	Accounts.push_back(new Account(name, ++numberOfAccounts));
	
	if (numberOfAccounts <= 1) { 
		currentAccount = Accounts[0]; //When we create first account
	}
}
void Timebank::changeAccount(int index) {
	if (index < 0 || index > Accounts.size()) { //If we are already in the acc we try to change
		throw std::exception("Error: Index is out of range");
	}
	if (index == currentAccount->getAccountID() - 1) {
		throw std::exception("You are already in this account(=\n");
	}
	currentAccount = Accounts[index];
}

void Timebank::deleteAccount(int index) {
	if (index < 0 || index >= Accounts.size()) {
		throw std::exception("Error: Index is out of range\n");
	}
	if (numberOfAccounts <= 1) {
		throw std::exception("Error: You can't delete account if it's only one you have\n");
	}
	if (currentAccount->getAccountID() - 1 == index) {
		throw std::exception("Error: You can't delete acount you are in\n");
	}
	
	delete Accounts[index];
	Accounts.erase(Accounts.begin() + index); //To delete pointer in vector
	numberOfAccounts--;
	numerateAccounts(index);
}
void Timebank::deleteAllAccounts() {
	for (Account* acc : Accounts) { delete acc; }
	Accounts.clear();
	numberOfAccounts = 0;
}

void Timebank::clearAccount() { currentAccount->clearAccount(); }

void Timebank::updateTime(int hours, int minutes, int seconds) {
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
