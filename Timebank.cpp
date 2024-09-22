#include "Timebank.h"

Timebank::Timebank() {
	numberOfAccounts = 0;
	currentAccount = nullptr;
	timer = new Timer();
}

Timebank::~Timebank() { deleteAllAccounts(); delete timer; }

int Timebank::getNumberOfAccounts() { return numberOfAccounts; }

//To manage accounts (create, delete, change)
void Timebank::numerateAccounts(int start) {
	for (int i = start; i < Accounts.size(); i++) {
		Accounts[i]->setID(i + 1);
	}
}
void Timebank::createAccount(std::string name) {
	numberOfAccounts++;
	Accounts.push_back(new Account(name));

	numerateAccounts(numberOfAccounts - 1);

	if (numberOfAccounts <= 1) { 
		currentAccount = Accounts[0]; //If we create first account
	}
}
void Timebank::changeAccount(int index) {
	if (index < 0 || index > Accounts.size()
		|| index == currentAccount->getAccountID() - 1) {
		return;
	}
	//If we are already in the acc we try to change
	currentAccount = Accounts[index];
}

void Timebank::deleteAccount(int index) {
	if (index < 0 || index > Accounts.size()) { return; }

	if (numberOfAccounts > 1) {
		if (currentAccount == Accounts[index]) {
			int newIndex = index + (index == 0 ? 1 : -1); //Decreases index by 1 if there is more than 
														  //1 acc and we are not in the 1st one.
														  //If we are in the 1st acc, we increase index by 1
			currentAccount = Accounts[newIndex];
		}
	}
	else { currentAccount = nullptr; } //If there is only 1 acc

	delete Accounts[index];
	Accounts.erase(Accounts.begin() + index);
	numberOfAccounts--;
	numerateAccounts(index);
}
void Timebank::deleteAllAccounts() {
	for (Account* item : Accounts) { delete item; }
	Accounts.clear();
	numberOfAccounts = 0;
}

void Timebank::updateTime(int hours, int minutes, int seconds) {
	currentAccount->updateTimeResourse(hours, minutes, seconds);
}
void Timebank::renameCurrentAccount(std::string newname) {
	if (newname == "\0") return;
	currentAccount->setName(newname);
}
void Timebank::renameAccount(int index, std::string newname) {
	if (index < 0 || index > Accounts.size()) { return; }
	Accounts[index]->setName(newname);
}

//To add time
void Timebank::addHours(int hours) {
	if (hours == 0) { return; }
	currentAccount->addHours(hours);
}
void Timebank::addMinutes(int minutes) {
	if (minutes == 0) { return; }
	currentAccount->addMinutes(minutes);
}
void Timebank::addSeconds(int seconds) {
	if (seconds == 0) { return; }
	currentAccount->addSeconds(seconds);
}

//To substract time
void Timebank::substractHours(int hours) {
	if (hours == 0) { return; }
	currentAccount->substractHours(hours);
}
void Timebank::substractMinutes(int minutes) {
	if (minutes == 0) { return; }
	currentAccount->substractMinutes(minutes);
}
void Timebank::substractSeconds(int seconds) {
	if (seconds == 0) { return; }
	currentAccount->substractSeconds(seconds);
}

void Timebank::printCurrentAccount() {
	currentAccount->printDataAboutAccount();
}
void Timebank::printOneAccount(int index) {
	if (index < 0 || index > Accounts.size()) { return; }
	Accounts[index]->printDataAboutAccount();
}
void Timebank::printAllAccounts() {
	for (Account* item : Accounts) {
		item->printDataAboutAccount();
		std::cout << std::endl;
	}
}
