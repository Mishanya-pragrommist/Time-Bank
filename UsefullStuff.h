//There I will place struct of time, some temporary things and almost all drawing tools
//that will be used in GUI
#ifndef USEFULLSTUFF_H 
#define USEFULLSTUFF_H
#include <fstream>
#include <iostream>
#include "Account.h"
#include "nlohmann/json.hpp"

struct Time;

enum Commands; //Temporary used thing. I guess its won't be usefull in GUI

void addAccount(nlohmann::json& jwrite, std::string name, int accountID,
	int hours, int minutes, int seconds);

void writeToFile(std::string path, nlohmann::json& jwrite);
void readFromFile(std::string path, Account& acc, int accID);

#endif
