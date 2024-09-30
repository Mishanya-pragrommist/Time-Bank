#include "Account.h"

Account::Account(std::string name, int accountID, Time time, Time wastingTime)
    : name(name), accountID(accountID), time(time), wastingTime(wastingTime) {}

Account::Account(std::string name, int accountID) {
    this->name = name;
    this->accountID = accountID;

    time = { 0, 0, 0 };
    wastingTime = { 0, 0, 0 };
}

Time Account::convertSecondsToTime(int seconds) {
    Time convTime;
    convTime.hours = seconds / 3600;
    seconds -= convTime.hours * 3600;

    convTime.minutes = seconds / 60;
    seconds -= convTime.minutes * 60;

    convTime.seconds = seconds;
    return convTime;
}

//Getters and setters
void Account::setName(std::string name) { this->name = name; }
void Account::setID(int accountID) { this->accountID = accountID; }

std::string Account::getName() { return name; }
int Account::getAccountID() { return accountID; }

int Account::getHours() { return time.hours; }
int Account::getMinutes() { return time.minutes; }
int Account::getSeconds() { return time.seconds; }

int Account::getWastingHours() { return wastingTime.hours; }
int Account::getWastingMinutes() { return wastingTime.hours; }
int Account::getWastinghSeconds() { return wastingTime.seconds; }

void Account::updateTime(int hours, int minutes, int seconds) {
    time = { hours, minutes, seconds };
}
void Account::addHours(int hours) { time.hours += hours; }

void Account::addMinutes(int minutes) {
    Time temp = convertSecondsToTime(minutes * 60);
    time.seconds += temp.seconds;
    time.minutes += temp.minutes;
    time.hours += temp.hours;
    
    if (time.seconds >= 60) {
        time.minutes++;
        time.seconds -= 60;
    }
    if (time.minutes >= 60) {
        time.hours++;
        time.minutes -= 60;
    }
}
void Account::addSeconds(int seconds) {
    Time temp = convertSecondsToTime(seconds);
    time.seconds += temp.seconds;
    time.minutes += temp.minutes;
    time.hours += temp.hours;

    if (time.seconds >= 60) {
        time.minutes++;
        time.seconds -= 60;
    }
    if (time.minutes >= 60) {
        time.hours++;
        time.minutes -= 60;
    }
}

void Account::substractHours(int hours) {
    if (hours > time.hours) {
        std::cout << "Error: I dont have enough hours for you\n";
        return;
    }
    time.hours -= hours;
    wastingTime.hours += hours;
}
void Account::substractMinutes(int minutes) {
    //Adding time we want to waste with the timer
    wastingTime.minutes += minutes;
    if (wastingTime.minutes >= 60) {
        wastingTime.hours++;
        wastingTime.minutes -= 60;
    }

    if (minutes > time.minutes) {
        if (time.hours > 0) {
            minutes -= time.minutes; //Adding minutes from 1 hour
            time.minutes = 60 - minutes;
            time.hours--;
            return;
        }
        else {
            std::cout << "Error: I dont have enough minutes for you\n";
            return;
        }
    }
    else { time.minutes -= minutes; }
}
void Account::substractSeconds(int seconds) {
    wastingTime.seconds += seconds;
    if (wastingTime.seconds >= 60) {
        wastingTime.minutes++;
        wastingTime.seconds -= 60;
        if (wastingTime.minutes >= 60) {
            wastingTime.hours++;
            wastingTime.minutes -= 60;
        }
    }

    if (seconds > time.seconds) {
        seconds -= time.seconds;
        time.seconds = 60 - seconds;
        if (time.minutes > 0) {
            time.minutes--;
        }
        else if (time.hours > 0) {
            time.hours--;
            seconds -= time.seconds;
        }
        else {
            std::cout << "Error: I dont have enough seconds for you\n";
            return;
        }
    }
    else { time.seconds -= seconds; }
}

void Account::printAccountData() { //Again, print funcs will be changed so they can show data in GUI.
                                   //Maybe I'll even replace this func into a some class like Scene so
                                   //it will draw numbers etc in window
    std::cout << "---Account #" << accountID << " " << name << "---\n";
    std::cout << "Current time resourses: " 
        << time.hours << ":" 
        << time.minutes << ":" 
        << time.seconds << "\n";
    
    std::cout << "Wasting time: "
        << wastingTime.hours << ":" 
        << wastingTime.minutes << ":"
        << wastingTime.seconds << "\n";
}

void Account::returnTimeToAccount() {
    addHours(wastingTime.hours);
    addMinutes(wastingTime.minutes);
    addSeconds(wastingTime.seconds);
    
    wastingTime = { 0, 0, 0 };

    timer.resetTime(); //It will be useful when I add some way to stop timer while its working
                        //Rn this func is useless since timer will 
                        //waste all time anyway due to no interrupting
}

void Account::startTimer() {
    timer.setTimeLeft(wastingTime);
    timer.start();
    wastingTime = timer.getTimeLeft();
}
