#include "Timer.h"

Timer::Timer() { timeLeft = { 0, 0, 0 }; }

void Timer::setTimeLeft(Time timeLeft) {
	this->timeLeft = { timeLeft.hours, timeLeft.minutes, timeLeft.seconds };
}

int Timer::getHours() { return timeLeft.hours; }
int Timer::getMinutes() { return timeLeft.minutes; }
int Timer::getSeconds() { return timeLeft.seconds; }

Time Timer::getTimeLeft() { return timeLeft; }

void Timer::addHours(int hours) { timeLeft.hours += hours; }
void Timer::addMinutes(int minutes) { TimeHelp::addTime(timeLeft, minutes * 60); }
void Timer::addSeconds(int seconds) { TimeHelp::addTime(timeLeft, seconds); }

void Timer::start() {
	while (timeLeft.hours > 0 || timeLeft.minutes > 0 || timeLeft.seconds > 0) {
		system("cls");
		printTimerData();

		if (timeLeft.hours == 0 && timeLeft.minutes == 0 && timeLeft.seconds == 0) break;

		timeLeft.seconds--;
		Sleep(1000);

		if (timeLeft.seconds < 0) {
			timeLeft.seconds = 59;
			timeLeft.minutes--;
		}
		if (timeLeft.minutes < 0) {
			timeLeft.minutes = 59;
			timeLeft.hours--;
		}

	}
	system("cls");
	printTimerData();
	Sleep(1000);
	std::cout << "Time is over\n";
}

void Timer::resetTime() { timeLeft = { 0, 0, 0 }; }

void Timer::printTimerData() {
	std::cout << "Time: " 
		<< timeLeft.hours << ":" 
		<< timeLeft.minutes << ":" 
		<< timeLeft.seconds << "\n";
}
