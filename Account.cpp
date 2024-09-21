#include "Account.h"

Account::Account(std::string name) {
    TimeResourse.hours = 0;
    TimeResourse.minutes = 0;
    TimeResourse.seconds = 0;

    this->name = name;
}

//Getters and setters
void Account::setName(std::string name) { this->name = name; }
void Account::setID(int numberOfAccount) { this->accountID = numberOfAccount; }

std::string Account::getName() { return name; }
int Account::getAccountID() { return accountID; }
Time Account::getTimeResourse() { return TimeResourse; }

void Account::updateTimeResourse(int hours, int minutes, int secs) {
    TimeResourse.hours = hours;
    TimeResourse.minutes = minutes;
    TimeResourse.seconds = secs;
}
void Account::addHours(int hours) {
    TimeResourse.hours += hours;
}
void Account::addMinutes(int minutes) {
    TimeResourse.minutes += minutes;
    if (TimeResourse.minutes >= 60) {
        TimeResourse.hours++;
        TimeResourse.minutes -= 60;
    }
}
void Account::addSeconds(int seconds) {
    TimeResourse.seconds += seconds;
    if (TimeResourse.seconds >= 60) {
        TimeResourse.minutes++;
        TimeResourse.seconds -= 60;
        if (TimeResourse.minutes >= 60) {
            TimeResourse.hours++;
            TimeResourse.minutes -= 60;
        }
    }
}

void Account::substractHours(int hours) {
    if (hours > TimeResourse.hours) {
        std::cout << "Error: I dont have enough hours for you\n";
        return;
    }
    TimeResourse.hours -= hours;
}
void Account::substractMinutes(int minutes) {
    if (minutes > TimeResourse.minutes) {
        if (TimeResourse.hours > 0) {
            minutes -= TimeResourse.minutes; //Adding minutes from 1 hour
            TimeResourse.minutes = 60 - minutes;
            TimeResourse.hours--;
            return;
        }
        else {
            std::cout << "Error: I dont have enough minutes for you\n";
            return;
        }
    }
    TimeResourse.minutes -= minutes;
}
void Account::substractSeconds(int seconds) {
    if (seconds > TimeResourse.seconds) {
        seconds -= TimeResourse.seconds;
        TimeResourse.seconds = 60 - seconds;
        if (TimeResourse.minutes > 0) {
            TimeResourse.minutes--;
        }
        else if (TimeResourse.hours > 0) {
            TimeResourse.hours--;
            seconds -= TimeResourse.seconds;
        }
        else {
            std::cout << "Error: I dont have enough seconds for you\n";
        }
    }
}

void Account::printDataAboutAccount() {
    std::cout << "---Account #" << accountID << " " << name << "---\n";
    std::cout << "Current time resourses:\n";

    if (TimeResourse.hours == 0) { std::cout << "00"; }
    else { std::cout << TimeResourse.hours; }
    std::cout << ":";

    if (TimeResourse.minutes == 0) { std::cout << "00"; }
    else { std::cout << TimeResourse.minutes; }
    std::cout << ":";

    if (TimeResourse.seconds == 0) { std::cout << "00"; }
    else { std::cout << TimeResourse.seconds; }
    std::cout << "\n";
}
