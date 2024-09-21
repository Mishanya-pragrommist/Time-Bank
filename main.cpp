#include <iostream>
#include <string>
#include "Timebank.h"
#include "UsefullStuff.h"

void startWork_handler(Timebank& timebank, int& command);
void updateTime_handler(Timebank& timebank);
void addTime_handler(Timebank& timebank);
void getTime_handler(Timebank& timebank);
void printOneAccount_handler(Timebank& timebank);
void printAllAccounts_handler(Timebank& timebank);
void createAccount_handler(Timebank& timebank);
void renameCurrentAccount_handler(Timebank& timebank);
void deleteAccount_handler(Timebank& timebank);
void changeAccount_handler(Timebank& timebank);

int main()
{
    int command = 0;
    std::string name;
    Timebank timebank; //It contains all of the accounts where you can handle your time

    std::cout << "Creating 1st account: enter the name of acc: "; std::getline(std::cin, name);
    timebank.createAccount(name);

    //Main cycle of programm
    while (command != STOP) {
        startWork_handler(timebank, command);

        //This place will be changed according to GUI (and maybe I'll do it without enums)
        switch (command) {
        case UPDATE:
            updateTime_handler(timebank);
            break;
        case ADD:
            addTime_handler(timebank);
            break;
        case GETTIME:
            getTime_handler(timebank);
            break;
        case PRINT:
            printOneAccount_handler(timebank);
            break;
        case PRINTALLACCOUNTS:
            printAllAccounts_handler(timebank);
            break;
        case CREATEACCOUNT:
            createAccount_handler(timebank);
            break;
        case RENAMECURRENTACC:
            renameCurrentAccount_handler(timebank);
            break;
        case DELETE:
            deleteAccount_handler(timebank);
            break;
        case GOTO:
            changeAccount_handler(timebank);
            break;
        case STOP:
            std::cout << "Programm stopped working succesfully\n";
            break;

        default:
            std::cout << "Error: I dont know this command\n";
            break;
        }
    }

    return 0;
}

void startWork_handler(Timebank& timebank, int& command) {
    std::string name;
    if (timebank.getNumberOfAccounts() == 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Create new account and enter name of it: ";
        std::getline(std::cin, name);
        timebank.createAccount(name);
    }
    timebank.printCurrentAccount();
    std::cout << "Enter command (update time-1, add time-2, get time-3, print one acc-4, print all accs-5\n"
        << "create new acc-6, rename cur acc-7, go to another acc-8, delete acc-9, stop-10): ";
    std::cin >> command;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: you need to enter number of command, not a word\n";
        return;
    }
}
void updateTime_handler(Timebank& timebank) {
    Time time;
    std::cout << "Update hours, minutes and seconds to current time: ";
    std::cin >> time.hours >> time.minutes >> time.seconds;
    timebank.updateTime(time.hours, time.minutes, time.seconds);
}
void addTime_handler(Timebank& timebank) {
    int timeEntered;
    char what;
    std::cout << "Add time (for ex: 30 m or 5 h)(<=0 to cancel): ";
    std::cin >> timeEntered >> what;
    if (timeEntered <= 0) {
        std::cout << "You cancelled adding time\n";
        return;
    }

    if (what == 'h') { timebank.addHours(timeEntered); }
    else if (what == 'm') { timebank.addMinutes(timeEntered); }
    else if (what == 's') { timebank.addSeconds(timeEntered); }
    else { std::cout << "Error: its no h/m/s\n"; }
}
void getTime_handler(Timebank& timebank) {
    int timeEntered;
    char what;
    std::cout << "How much time u want to get (for ex: 30 h, or 1 m)(<=0 to cancell): ";
    std::cin >> timeEntered >> what;
    if (timeEntered <= 0) {
        std::cout << "Okey, you cancelled get time\n";
        return;
    }
    if (what == 'h') { timebank.substractHours(timeEntered); }
    else if (what == 'm') { timebank.substractMinutes(timeEntered); }
    else if (what == 's') { timebank.substractSeconds(timeEntered); }
    else { std::cout << "Error: its no h/m/s\n"; }
}
void printOneAccount_handler(Timebank& timebank) {
    int number;
    std::cout << "Enter # of acc you want to print (<=0 to cancell): ";
    std::cin >> number;
    if (number <= 0) {
        std::cout << "Okey, you cancelled printing all accs";
        return;
    }
    if (number > timebank.getNumberOfAccounts()) {
        std::cout << "Error: there is no account with this number\n";
        return;
    }
    timebank.printOneAccount(number - 1);
}
void printAllAccounts_handler(Timebank& timebank) {
    std::cout << "\nData about all accounts:\n";
    timebank.printAllAccounts();
    std::cout << std::endl;
}
void createAccount_handler(Timebank& timebank) {
    std::string name;
    std::cin.ignore();
    std::cout << "Enter the name of new account: ";
    std::getline(std::cin, name);
    timebank.createAccount(name);
    std::cout << "You created a new account =)\n";
}
void renameCurrentAccount_handler(Timebank& timebank) {
    std::string name;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter new name of current acc: ";
    std::getline(std::cin, name);
    timebank.renameCurrentAccount(name);
    std::cout << "You renamed acc successsfully)\n";
}
void deleteAccount_handler(Timebank& timebank) {
    int number;
    std::cout << "Enter number of acc you want to delete (<=0 to cancell): ";
    std::cin >> number;
    if (number <= 0) {
        std::cout << "You cancelled deleting\n";
        return;
    }
    timebank.deleteAccount(number - 1); //Number of acc is bigger than its place in vector
    std::cout << "You deleted account #" << number << std::endl;
}
void changeAccount_handler(Timebank& timebank) {
    int number;
    std::cout << "Enter the number of account: "; std::cin >> number;
    if (number <= 0 || number > timebank.getNumberOfAccounts()) {
        std::cout << "Error: there is no account with this number\n";
        return;
    }
    timebank.changeAccount(number - 1);
    std::cout << "You changed account successfully=)\n";
}
