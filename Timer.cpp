#include "Timer.h"

Timer::Timer() { timeLeft = { 0, 0, 0 }; }

void Timer::setTimeLeft(Time timeLeft) {
	this->timeLeft = { timeLeft.hours, timeLeft.minutes, timeLeft.seconds };
}
Time Timer::getTimeLeft() { return timeLeft; }

void Timer::start() {
	while (timeLeft.hours > 0 || timeLeft.minutes > 0 || timeLeft.seconds > 0) {
		system("cls");
		printTimer();

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
	printTimer();
	Sleep(1000);
	std::cout << "Time is over\n";
}

void Timer::resetTime() { timeLeft = { 0, 0, 0 }; }

void Timer::printTimer() {
	std::cout << "Time: " 
		<< timeLeft.hours << ":" 
		<< timeLeft.minutes << ":" 
		<< timeLeft.seconds << "\n";
}
