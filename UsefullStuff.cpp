#include "UsefullStuff.h"

Time TimeHelp::convertSecondsToTime(int seconds) {
	int secsInHour = 3600, secsInMinute = 60;
	Time convTime;

	convTime.hours = seconds / secsInHour;
	seconds -= convTime.hours * secsInHour;

	convTime.minutes = seconds / secsInMinute;
	seconds -= convTime.minutes * secsInMinute;

	convTime.seconds = seconds;
	return convTime;
}

void TimeHelp::addTime(Time& time, int seconds) {
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

void TimeHelp::substractTime(Time& time, int seconds) {
	Time temp = convertSecondsToTime(seconds);
	if (time.hours < temp.hours ||
		(time.hours == temp.hours && time.minutes < temp.minutes) ||
		(time.hours == temp.hours && time.minutes == temp.minutes && time.seconds < temp.seconds)) {
		throw std::exception("There is not enough time to subtract");
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
