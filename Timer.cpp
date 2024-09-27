#include "Timer.h"

Timer::Timer() {
	wastingTime.hours = 0;
	wastingTime.minutes = 0;
	wastingTime.seconds = 0;
}

void Timer::enterTime(int hours, int minutes, int seconds) {
	wastingTime.hours = hours;
	wastingTime.minutes = minutes;
	wastingTime.hours = hours;
}

void Timer::addHours(int hours) { wastingTime.hours += hours; }
void Timer::addMinutes(int minutes) { wastingTime.minutes += minutes; }
void Timer::addSeconds(int seconds) { wastingTime.seconds += seconds; }

void Timer::start() {

}
