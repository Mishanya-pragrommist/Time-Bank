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
