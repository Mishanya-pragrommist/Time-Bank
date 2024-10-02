#include <iostream> //In GUI it will be useless, so I'll delete it in future
#include <string>
#include "Timebank.h"

void startWork_handler(Timebank& timebank, int& command);
void updateTime_handler(Timebank& timebank);
void addTime_handler(Timebank& timebank);
void getTime_handler(Timebank& timebank);
void returnTime_handler(Timebank& timebank);
void printAllAccounts_handler(Timebank& timebank);
void createAccount_handler(Timebank& timebank);
void renameCurrentAccount_handler(Timebank& timebank);
void deleteAccount_handler(Timebank& timebank);
void changeAccount_handler(Timebank& timebank);

int main()
{
    int command = 0;
    std::string name; //Name of the new account (used when user wants to create new one)
    Timebank timebank; //It contains all of the accounts where you can handle your time
    
    //Main cycle of programm
    while (command != STOP) {
        startWork_handler(timebank, command);

        //This place will be changed according to GUI (and maybe I'll do it without enums)
        switch (command) {
        case UPDATE:
            updateTime_handler(timebank); break;
        case ADD:
            addTime_handler(timebank); break;
        case GETTIME:
            getTime_handler(timebank); break;
        case RETURNTIME:
            returnTime_handler(timebank); break;
        case PRINTALLACCOUNTS:
            printAllAccounts_handler(timebank); break;
        case STARTTIMER:
            timebank.startTimer(); break;
        case CREATEACCOUNT:
            createAccount_handler(timebank); break;
        case RENAMECURRENTACC:
            renameCurrentAccount_handler(timebank); break;
        case CLEARACC:
            timebank.clearAccount();
            break;
        case DELETEACC:
            deleteAccount_handler(timebank); break;
        case GOTO:
            changeAccount_handler(timebank); break;
        case STOP:
            std::cout << "Programm stopped working succesfully\n"; break;

        default:
            std::cout << "Error: I dont know this command\n"; break;
        }
        std::cout << "\n";
    }

    return 0;
}

void startWork_handler(Timebank& timebank, int& command) {
    timebank.printCurrentAccount();
    std::cout << "Enter command (update time-1, add time-2, get time-3," 
        << " return time - 4, start timer - 5\n"
        << " print all accs-6, create new acc-7, rename cur acc-8,\n" 
        << "go to another acc-9, delete acc-10, clear acc-11, stop-12): ";
    std::cin >> command;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Error: you need to enter number of command, not a word\n";
        return;
    }
}
void updateTime_handler(Timebank& timebank) {
    Time time;
    std::cout << "Update hours, minutes and seconds to current time: ";
    std::cin >> time.hours >> time.minutes >> time.seconds;
    if (time.hours < 0 || time.minutes < 0 || time.seconds < 0) {
        std::cout << "Error: you can't enter negative time\n";
        return;
    }
    timebank.updateTime(time.hours, time.minutes, time.seconds);
}
void addTime_handler(Timebank& timebank) {
    int timeEntered;
    char what;
    std::cout << "Add time (for ex: 30 m or 5 h)(<=0 to cancel): ";
    std::cin >> timeEntered >> what;
    try {
        if (what == 'h') { timebank.addHours(timeEntered); }
        else if (what == 'm') { timebank.addMinutes(timeEntered); }
        else if (what == 's') { timebank.addSeconds(timeEntered); }
        else { std::cout << "Error: it's not h/m/s\n"; }
    }
    catch(std::exception& negativeTime) {
        std::cout << negativeTime.what() << "\n";
    }
}
void getTime_handler(Timebank& timebank) {
    int timeEntered;
    char what;
    std::cout << "How much time u want to get (for ex: 30 h, or 1 m)(<=0 to cancell): ";
    std::cin >> timeEntered >> what;
    try {
        if (what == 'h') { timebank.substractHours(timeEntered); }
        else if (what == 'm') { timebank.substractMinutes(timeEntered); }
        else if (what == 's') { timebank.substractSeconds(timeEntered); }
        else { std::cout << "Error: its not h/m/s\n"; }
    }
    catch (std::exception& timeLack) { std::cout << timeLack.what() << "\n"; }
}
void returnTime_handler(Timebank& timebank) {
    timebank.returnTimeToAccount();
    std::cout << "You returned time back to current time=)\n";
}
void printAllAccounts_handler(Timebank& timebank) {
    std::cout << "\nData about all accounts:\n";
    timebank.printAllAccounts();
    std::cout << "\n";
}
void createAccount_handler(Timebank& timebank) {
    std::string name;
    std::cin.ignore();
    std::cout << "Enter the name of new account: "; std::getline(std::cin, name);
    timebank.createAccount(name);
    std::cout << "You created a new account =)\n";
}
void renameCurrentAccount_handler(Timebank& timebank) {
    std::string name;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "Enter new name of current acc: "; std::getline(std::cin, name);
    timebank.renameCurrentAccount(name);
    std::cout << "You renamed acc successsfully)\n";
}
void deleteAccount_handler(Timebank& timebank) {
    int number;
    std::cout << "Enter number of acc you want to delete (<=0 to cancell): ";
    std::cin >> number;
    if (number <= 0 || number > timebank.getNumberOfAccounts()) {
        std::cout << "You cancelled deleting\n";
        return;
    }
    try {
        timebank.deleteAccount(number - 1); //Index of acc is smaller than its real number
        std::cout << "You deleted account #" << number << "\n";
    }
    catch (std::exception& error) {
        std::cout << error.what() << "\n";
    }
}
void changeAccount_handler(Timebank& timebank) {
    int number;
    std::cout << "Enter the number of account: "; std::cin >> number;
    if (number <= 0 || number > timebank.getNumberOfAccounts()) {
        std::cout << "Error: there is no account with this number\n";
        return;
    }
    try {
        timebank.changeAccount(number - 1);
        std::cout << "You changed account successfully=)\n";
    }
    catch (std::exception& error) {
        std::cout << error.what() << "\n";
    }
}
