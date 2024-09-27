#include "Timebank.h"

Timebank::Timebank() { readFromFile(); }

Timebank::~Timebank() { 
	writeToFile();
	deleteAllAccounts();
}

//For saving/reading data
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
			{"seconds", Accounts[i]->getSeconds()}
		};
	}
	
	fout << jwrite.dump(4);
	fout.close();
}
void Timebank::readFromFile() {
	std::ifstream fin(savingFilePath);
	if (!fin.is_open()) { std::cout << "Error: fin wasnt opened\n"; return; }

	nlohmann::json jread;
	fin >> jread;

	numberOfAccounts = jread["Timebank"]["numberOfAccounts"].get<int>();
	if (numberOfAccounts > 0) { //Reading data for each account
		for (int i = 1; i <= numberOfAccounts; i++) {
			
			//Each object in .json file has a name "Acocunt #" + its number in list
			std::string objectName = "Account #" + std::to_string(i);
			Accounts.push_back(new Account(jread[objectName]["name"].get<std::string>(),
				jread[objectName]["accountID"].get<int>(),
				jread[objectName]["hours"].get<int>(),
				jread[objectName]["minutes"].get<int>(),
				jread[objectName]["seconds"].get<int>()));
		}
		currentAccount = Accounts[0];
	}
	fin.close();
}

int Timebank::getNumberOfAccounts() { return numberOfAccounts; }

void Timebank::numerateAccounts(int start) {
	for (int i = start; i < Accounts.size(); i++) { Accounts[i]->setID(i + 1); }
}

//To manage accounts (create, delete, change)
void Timebank::createAccount(std::string name) {
	numberOfAccounts++;
	Accounts.push_back(new Account(name));

	numerateAccounts(numberOfAccounts - 1);

	if (numberOfAccounts <= 1) { 
		currentAccount = Accounts[0]; //When we create first account
	}
}
void Timebank::changeAccount(int index) {
	if (index < 0 || index > Accounts.size()
		|| index == currentAccount->getAccountID() - 1) { //If we are already in the acc we try to change
		return;
	}
	currentAccount = Accounts[index];
}

void Timebank::deleteAccount(int index) {
	if (index < 0 || index >= Accounts.size()) { return; }

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

void Timebank::startTimer() {
	currentAccount->startTimer();
}

void Timebank::printCurrentAccount() {
	currentAccount->printDataAboutAccount();
}
void Timebank::printAllAccounts() {
	for (Account* item : Accounts) {
		item->printDataAboutAccount();
		std::cout << std::endl;
	}
}
