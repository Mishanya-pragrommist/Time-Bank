#include "Account.h"

Account::Account(std::string name, int accountID, Time accountTime, Time timerTime)
    : name(name), accountID(accountID), accountTime(accountTime) {
    timer.setTimeLeft(timerTime);
}

Account::Account(std::string name, int accountID) {
    this->name = name;
    this->accountID = accountID;

    accountTime = { 0, 0, 0 };
}

//Getters and setters
void Account::setName(std::string name) { this->name = name; }
void Account::setID(int accountID) { this->accountID = accountID; }

std::string Account::getName() { return name; }
int Account::getAccountID() { return accountID; }

int Account::getHours() { return accountTime.hours; }
int Account::getMinutes() { return accountTime.minutes; }
int Account::getSeconds() { return accountTime.seconds; }

int Account::getTimerHours() { return timer.getHours(); }
int Account::getTimerMinutes() { return timer.getMinutes(); }
int Account::getTimerSeconds() { return timer.getSeconds(); }

void Account::clearAccount() {
    updateTime(0, 0, 0);
    timer.resetTime();
    name = "default";
}

void Account::updateTime(int hours, int minutes, int seconds) {
    accountTime = { hours, minutes, seconds };
}

void Account::addHours(int hours) { accountTime.hours += hours; } 
//There's no need to convert hours into Time struct and use addTime()
//However, if I added days for Time struct, this would make sense

void Account::addMinutes(int minutes) { TimeHelper::addTime(accountTime, minutes * 60); }
void Account::addSeconds(int seconds) { TimeHelper::addTime(accountTime, seconds); }

void Account::substractHours(int hours) {
    if (accountTime.hours < hours) {
        std::cout << "Error: I dont have enough hours for you\n";
        return;
    }
    accountTime.hours -= hours;
    timer.addHours(hours);
}
void Account::substractMinutes(int minutes) {
    TimeHelper::substractTime(accountTime, minutes * 60);
    timer.addMinutes(minutes);
}
void Account::substractSeconds(int seconds) {
    TimeHelper::substractTime(accountTime, seconds);
    timer.addSeconds(seconds);
}

void Account::printAccountData() { //Again, print funcs will be changed so they can show data in GUI.
                                   //Maybe I'll even replace this func into a some class like Scene so
                                   //it will draw numbers, text etc in window
    std::cout << "---Account #" << accountID << " " << name << "---\n";
    std::cout << "Current time resourses: " 
        << accountTime.hours << ":"
        << accountTime.minutes << ":"
        << accountTime.seconds << "\n";
    
    std::cout << "Time in timer: "
        << timer.getHours() << ":" 
        << timer.getMinutes() << ":"
        << timer.getSeconds() << "\n";
}

void Account::returnTimeToAccount() {
    addHours(timer.getHours());
    addMinutes(timer.getMinutes());
    addSeconds(timer.getSeconds());
    
    timer.resetTime(); //It will be useful when I add some way to stop timer while its working
                        //Rn this func is useless since timer will 
                        //waste all time anyway due to no interrupting
}

void Account::startTimer() { timer.start(); }
