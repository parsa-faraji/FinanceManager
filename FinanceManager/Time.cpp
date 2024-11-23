#include "Time.hpp"
#include <stdexcept>

// default constructor
Time::Time() : hour(0), minute(0) {}

// parameterized constructor
Time::Time(short int hour, short int minute) : hour(hour), minute(minute) {
    if (!isValidTime()) {
        throw std::invalid_argument("Invalid time provided.");
    }
}

void Time::setHour(short int newHour) {
    if (newHour < 0 || newHour > 12) {
        throw std::invalid_argument("Hour must be between 0 and 12.");
    }
    hour = newHour;
}

void Time::setMinute(short int newMinute) {
    if (newMinute < 0 || newMinute > 59) {
        throw std::invalid_argument("Minute must be between 0 and 59.");
    }
    minute = newMinute;
}

void Time::setDayOrNight(string newDayOrNight) {
    if (dayOrNight != "pm" && dayOrNight != "am") {
        throw std::invalid_argument("Please pass am or pm in lowercase for day or night.");
    }
    dayOrNight = newDayOrNight;
}
