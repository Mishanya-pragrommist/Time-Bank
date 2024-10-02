#include "FileHandler.h"
#include "Timebank.h"

void FileHandler::writeToFile(Timebank* timebank) {
	std::ofstream fout(savingFilePath);
	if (!fout.is_open()) { std::cout << "Error: fout wasnt open\n"; return; }

	nlohmann::json jwrite;

	//Firstly we need to know how much of accounts there are
	jwrite["Timebank"] = { { "numberOfAccounts", timebank->numberOfAccounts} };

	for (int i = 0; i < timebank->Accounts.size(); i++) {
		//Same as in readFromFile() func
		std::string objectName = "Account #" + std::to_string(i + 1);

		Account* tempAcc = timebank->Accounts[i];
		jwrite[objectName] = {
			{"name", tempAcc->getName()},
			{"accountID", tempAcc->getAccountID()},
			{"hours", tempAcc->getHours()},
			{"minutes", tempAcc->getMinutes()},
			{"seconds", tempAcc->getSeconds()},
			{"hoursLeft", tempAcc->getTimerHours()},
			{"minutesLeft", tempAcc->getTimerMinutes()},
			{"secondsLeft", tempAcc->getTimerSeconds()}
		};
	}

	fout << jwrite.dump(4);
	fout.close();
}

void FileHandler::readFromFile(Timebank* timebank) {
	std::ifstream fin(savingFilePath);
	if (!fin.is_open()) { std::cout << "Error: fin wasn't opened\n"; return; }

	nlohmann::json jread;
	fin >> jread;

	timebank->numberOfAccounts = jread["Timebank"]["numberOfAccounts"].get<int>();
	Time tempTime, tempTimeLeft;
	if (timebank->numberOfAccounts > 0) { //Reading data for each account
		for (int i = 1; i <= timebank->numberOfAccounts; i++) {
			//Each object in .json file has a name "Acocunt #" + its number in list
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

			std::string accName = jread[objectName]["name"].get<std::string>();
			int accID = jread[objectName]["accountID"].get<int>();
			timebank->Accounts.push_back(new Account(accName, accID, tempTime, tempTimeLeft));
		}
	}
	else {
		tempTime = { 0, 0, 0 }; tempTimeLeft = { 0, 0, 0 };
		timebank->Accounts.push_back(new Account("default", 1, tempTime, tempTimeLeft));
	}
	timebank->currentAccount = timebank->Accounts[0];
	fin.close();
}
