#include "Account.h"

Account::Account(std::string name, int accountID, int hours, int minutes, int seconds) {
    this->name = name;
    this->accountID = accountID;

    time.hours = hours;
    time.minutes = minutes;
    time.seconds = seconds;

    wastingTime.hours = 0;
    wastingTime.minutes = 0;
    wastingTime.seconds = 0;
    timer = new Timer();
}
Account::Account(std::string name) {
    this->name = name;

    time.hours = 0;
    time.minutes = 0;
    time.seconds = 0;
    
    wastingTime.hours = 0;
    wastingTime.minutes = 0;
    wastingTime.seconds = 0;

    timer = new Timer();
}

//Getters and setters
void Account::setName(std::string name) { this->name = name; }
void Account::setID(int numberOfAccount) { this->accountID = numberOfAccount; }

std::string Account::getName() { return name; }
int Account::getAccountID() { return accountID; }

int Account::getHours() { return time.hours; }
int Account::getMinutes() { return time.minutes; }
int Account::getSeconds() { return time.seconds; }

void Account::updateTime(int hours, int minutes, int secs) {
    time.hours = hours;
    time.minutes = minutes;
    time.seconds = secs;
}
void Account::addHours(int hours) {
    time.hours += hours;
}
void Account::addMinutes(int minutes) {
    time.minutes += minutes;
    if (time.minutes >= 60) {
        time.hours++;
        time.minutes -= 60;
    }
}
void Account::addSeconds(int seconds) {
    time.seconds += seconds;
    if (time.seconds >= 60) {
        time.minutes++;
        time.seconds -= 60;
        if (time.minutes >= 60) {
            time.hours++;
            time.minutes -= 60;
        }
    }
}

void Account::substractHours(int hours) {
    if (hours > time.hours) {
        std::cout << "Error: I dont have enough hours for you\n";
        return;
    }
    time.hours -= hours;
    timer->addHours(hours);
}
void Account::substractMinutes(int minutes) {
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
    timer->addMinutes(minutes);
}
void Account::substractSeconds(int seconds) {
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
    timer->addSeconds(seconds);
}

void Account::printDataAboutAccount() {
    std::cout << "---Account #" << accountID << " " << name << "---\n";
    std::cout << "Current time resourses: " 
        << time.hours << ":" 
        << time.minutes << ":" 
        << time.seconds << "\n";
    
    std::cout << "Wasting time: "
        << timer->getHours() << ":" 
        << timer->getMinutes() << ":" 
        << timer->getSeconds() << "\n";
}

void Account::startTimer() { timer->start(); }
