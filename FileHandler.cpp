#include "FileHandler.h"
#include "Timebank.h"

void FileHandler::writeToFile(Timebank* timebank) {
	std::ofstream fout(savingFilePath);
	if (!fout.is_open()) { std::cout << "Error: fout wasnt open\n"; return; }

	nlohmann::json jwrite;

	//Firstly we need to know how much of accounts there are
	jwrite["Timebank"] = { { "numberOfAccounts", timebank->numberOfAccounts} };

	for (int i = 0; i < timebank->Accounts.size(); i++) {
		std::string objectName = "Account #" + std::to_string(i + 1);

		Account* acc = timebank->Accounts[i];
		jwrite[objectName] = {
			{"name", acc->getName()},
			{"accountID", acc->getAccountID()},
			{"hours", acc->getHours()},
			{"minutes", acc->getMinutes()},
			{"seconds", acc->getSeconds()},
			{"hoursLeft", acc->getTimerHours()},
			{"minutesLeft", acc->getTimerMinutes()},
			{"secondsLeft", acc->getTimerSeconds()}
		};
	}

	fout << jwrite.dump(16);
	fout.close();
}

void FileHandler::readFromFile(Timebank* timebank) {
	std::ifstream fin(savingFilePath);
	if (!fin.is_open()) { std::cout << "Error: fin wasn't opened\n"; return; }

	nlohmann::json jread;
	fin >> jread;

	timebank->numberOfAccounts = jread["Timebank"]["numberOfAccounts"].get<int>();
	Time tempTime, tempTimeLeft;
	std::string accName;
	if (timebank->numberOfAccounts > 0) { //Reading data for each account
		for (int i = 1; i <= timebank->numberOfAccounts; i++) {
			//Each object in .json file has a name "Account #" + its number in list
			std::string objectName = "Account #" + std::to_string(i);

			tempTime = {
				jread[objectName]["hours"].get<int>(),
				jread[objectName]["minutes"].get<int>(),
				jread[objectName]["seconds"].get<int>(),
			};
			tempTimeLeft = {
				jread[objectName]["hoursLeft"].get<int>(),
				jread[objectName]["minutesLeft"].get<int>(),
				jread[objectName]["secondsLeft"].get<int>()
			};

			accName = jread[objectName]["name"].get<std::string>();
			int accID = jread[objectName]["accountID"].get<int>();
			timebank->Accounts.push_back(new Account(accName, accID, tempTime, tempTimeLeft));
		}
	}
	else { //If there are no accounts in the file
		tempTime = { 0, 0, 0 }; tempTimeLeft = { 0, 0, 0 };
		accName = "default";
		timebank->Accounts.push_back(new Account(accName, 1, tempTime, tempTimeLeft));
	}
	//At the end we must set the pointer to the account
	//from which the program will start working
	timebank->currentAccount = timebank->Accounts[0]; 
	fin.close();
}
