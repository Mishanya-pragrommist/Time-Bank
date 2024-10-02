#include "UsefullStuff.h"

Time TimeHelper::convertSecondsToTime(int seconds) {
	Time convTime;
	convTime.hours = seconds / 3600;
	seconds -= convTime.hours * 3600;

	convTime.minutes = seconds / 60;
	seconds -= convTime.minutes * 60;

	convTime.seconds = seconds;
	return convTime;
}

void TimeHelper::addTime(Time& time, int seconds) {
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

void TimeHelper::substractTime(Time& time, int seconds) {
	Time temp = convertSecondsToTime(seconds);
	if (time.hours < temp.hours
		&& time.minutes < temp.minutes
		&& time.seconds < temp.seconds) {
		throw std::exception("Error: there is not enough time to give you\n");
	}
	time.hours -= temp.hours;
	time.minutes -= temp.minutes;
	time.seconds -= temp.seconds;

	if (time.seconds < 0) {
		time.seconds *= -1;
		time.minutes--;
	}
	if (time.minutes < 0) {
		time.minutes *= -1;
		time.hours--;
	}
}
