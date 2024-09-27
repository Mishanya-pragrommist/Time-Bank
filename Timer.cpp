#include "Timer.h"

Timer::Timer() {
	timeLeft.hours = 0;
	timeLeft.minutes = 0;
	timeLeft.seconds = 0;
}

int Timer::getHours() { return timeLeft.hours; }
int Timer::getMinutes() { return timeLeft.minutes; }
int Timer::getSeconds() { return timeLeft.seconds; }

void Timer::addHours(int hours) { 
	timeLeft.hours += hours;
}
void Timer::addMinutes(int minutes) { 
	timeLeft.minutes += minutes;
	if (timeLeft.minutes >= 60) {
		timeLeft.hours++;
		timeLeft.minutes -= 60;
	}
}
void Timer::addSeconds(int seconds) { 
	timeLeft.seconds += seconds;
	if (timeLeft.seconds >= 60) {
		timeLeft.minutes++;
		timeLeft.seconds -= 60;
		if (timeLeft.minutes >= 60) {
			timeLeft.hours++;
			timeLeft.minutes -= 60;
		}
	}
}

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

void Timer::printTimer() {
	std::cout << "Time: " << timeLeft.hours << ":" << timeLeft.minutes << ":" << timeLeft.seconds << "\n";
}
