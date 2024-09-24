#include "UsefullStuff.h"

enum Commands { //Temporary used thing. I guess its won't be usefull in GUI
    UPDATE = 1,
    ADD, //= 2
    GETTIME, // 3
    PRINT, // 4
    PRINTALLACCOUNTS, // 5
    CREATEACCOUNT, // 6
    RENAMECURRENTACC, //7
    GOTO, //8
    DELETE, // 9
    STOP // 10
};

struct Time { int hours, minutes, seconds; };

void addAccount(nlohmann::json& jwrite, std::string name, int accountID,
    int hours, int minutes, int seconds) {
    std::string objectName = "Account #" + std::to_string(accountID);
    jwrite[objectName] = {
        {"name", name},
        {"hours", hours},
        {"minutes", minutes},
        {"seconds", seconds},
        {"ID", accountID} };
}

void writeToFile(std::string path, nlohmann::json& jwrite) {

    std::ofstream fout;
    fout.open(path);
    if (!fout.is_open()) {
        std::cout << "Error: fout wasnt open\n"; return;
    }

    fout << jwrite.dump(4);
    fout.close();
}

void readFromFile(std::string path, Account& acc, int accID) {
    std::ifstream fin;
    std::string objectName = "Account #" + std::to_string(accID);
    fin.open(path);
    if (!fin.is_open()) {
        std::cout << "Error: fin wasnt open\n"; return;
    }

    nlohmann::json jread;
    fin >> jread;
    acc.name = jread[objectName]["name"].get<std::string>();
    acc.ID = jread[objectName]["ID"].get<int>();
    acc.hours = jread[objectName]["hours"].get<int>();
    acc.minutes = jread[objectName]["minutes"].get<int>();
    acc.seconds = jread[objectName]["seconds"].get<int>();
    fin.close();
}
